#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connectdialog.h"
#include "globalvariable.h"
#include "t8kthread.h"
#include "CypressUsb.h"
#include "CANChannels.h"
#include "Utility.h"
#include "math.h"

#include <stdlib.h>
#include <stdio.h>
//#include <gsl/gsl_rng.h>
//#include <gsl/gsl_randist.h>
//#include <gsl/gsl_vector.h>
//#include <gsl/gsl_blas.h>
//#include <gsl/gsl_multifit_nlin.h>


#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QThread>
#include <QMutex>
#include <QEventLoop>
#include <QLabel>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ConnectDevices();
    void SerialPortErrorHandler(QString err);
    void PortConnected(QString sNumber);
    void ReadOldCoef();
    void StartProgram();
    void ExcerptProgram();
    void CheckTempTimer();
    void BCALCommand();
    void GetStatus(bool working, bool warming);
    void StartXGSChecking();
    void XGSAnswer(QString answer,  QStringList answer_xm);
    void StopProgram();
    void SaveSensorsTemp(QStringList answer_xm);
    void Approx(double y[]);
    void CalcNewCoef();
    void SaveLog(QString message);
    void closeEvent(QCloseEvent *);

public slots:
    void ApplySettings(bool T8Kcon);
    void ReceiveTemperature(QStringList t);
    void ConnectDT(int index, bool  DTConnected, QString name);
    void SetOldCoef(QString old_coef, int i);
    void SetNewCoef(double a, double b, int count);

signals:
    void sendSettings(QStringList);
    void SendApprox(double, double, int);

private:
    Ui::MainWindow *ui;
    QString T8KSN;
    QString dt_name;
    UCHAR dstate;
    bool dt_connected;
    bool is_working;
    bool warming_up;
    bool stop_prog;
    int dt_index;
    int measures;
    int vector_value;
    int time_left;
    int count;
    int coef_count;
    CyDev *usb;
    CANChannels *temp;
    CANChannels *motor;
    CANChannels *optic;
    CANChannels *display;
    QMutex mutex;
    QTimer *timer;
    double sensor_temp[6];
    double xm_temp[6];
    double difference[6];
    double data_sensors[6];
    double all_data[36][6];
    double coef_value20[6];
    double coef_value90[6];
};

class ReadCoefThread : public QThread
{
    Q_OBJECT

public:
    ReadCoefThread(QMutex* mu, int ind)
    {
        mutex = mu;
        index = ind;
    }
protected:
    void run()
    {
        QString outs;
        usb = new CyDev(NULL);
        usb->Open(index);
        if(usb->IsOpen())
        {
            temp = new CANChannels(usb,3);
            for(int i=0; i<6; i++)
            {
                mutex->lock();
                USBCy_RW("DLRS "+QString::number(i), outs, usb, temp); // Чтение коэффициентов
                QThread::msleep(60);
                mutex->unlock();
                emit SendOldCoef(outs, i);
            }
        }
    }
public slots:
signals:
    void SendOldCoef(QString, int);
private:
    CyDev *usb;
    CANChannels *temp;
    QMutex *mutex;
    int index;
};

class XGSCheck : public QThread
{
    Q_OBJECT

public:
    XGSCheck(QMutex* mu, int ind)
    {
        mutex = mu;
        index = ind;
    }
protected:
    void run()
    {
        QString outs, xgs;
        usb = new CyDev(NULL);
        usb->Open(index);
        if(usb->IsOpen())
        {
            temp = new CANChannels(usb,3);
            mutex->lock();
            USBCy_RW("XGS", outs, usb, temp); // Проверка состояния
            QThread::msleep(60);
            mutex->unlock();
            xgs = outs;
            mutex->lock();
            USBCy_RW("XM", outs, usb, temp); // Проверка температуры
            QThread::msleep(60);
            mutex->unlock();
            xm = outs.split(" ");
            emit SendAnswer(xgs, xm);
        }
    }
public slots:
signals:
    void SendAnswer(QString, QStringList);
private:
    CyDev *usb;
    CANChannels *temp;
    QMutex *mutex;
    QStringList xm;
    int index;
};

class WriteStartProg : public QThread
{
    Q_OBJECT

public:
    WriteStartProg(QMutex* mu, int ind)
    {
        mutex = mu;
        index = ind;
    }
protected:
    void run()
    {
        QString outs;
        QStringList sl;
        is_working = false;
        warming_up = false;
        usb = new CyDev(NULL);
        usb->Open(index);
        if(usb->IsOpen())
        {
            temp = new CANChannels(usb,3);
            mutex->lock();
            USBCy_RW("XPRG 0 25 0", outs, usb, temp);
            USBCy_RW("XLEV 1800 30 200 0 0 0", outs, usb, temp);  // Установка программы плавления
            if(outs == "0")
            {
                USBCy_RW("XCYC 37", outs, usb, temp);  // Количество циклов плавления
                USBCy_RW("XSAV Melting Program", outs, usb, temp); // Название программы плавления
                USBCy_RW("RN", outs, usb, temp); // Запуск плавления
                QThread::msleep(5000);
            }
            USBCy_RW("XGS", outs, usb, temp);  // Статус прибора;
            QThread::msleep(60);
            mutex->unlock();

            sl = outs.split(' ');
            outs = sl[0];
            if(outs == "4")
            {
                is_working = false;
                warming_up = true;
                emit SendStatus(is_working, warming_up);
            }
            if(outs == "1")
            {
                is_working = true;
                if(warming_up == true)
                {
                    warming_up = false;
                }
                emit SendStatus(is_working, warming_up);
            }
            if(outs == "0")
            {
                is_working = false;
                emit SendStatus(is_working, warming_up);
            }
        }
    }
public slots:
signals:
    void SendStatus(bool, bool);
private:
    CyDev *usb;
    CANChannels *temp;
    QMutex *mutex;
    int index;
    bool is_working;
    bool warming_up;
};
#endif // MAINWINDOW_H
