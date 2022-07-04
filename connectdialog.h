#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include"t8kthread.h"
#include"globalvariable.h"
#include"CypressUsb.h"
#include"CANChannels.h"

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QSignalMapper>
#include <QAction>
#include <QFile>
#include <QTextStream>

namespace Ui {
class connectdialog;
}

class connectdialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectdialog(QWidget *parent = 0);
    ~connectdialog();

private slots:
    void FindT8K();
    void FindDT();
    void on_pushButtonConnect_clicked();

public slots:

signals:
    void setupsettings(bool);
    void SendIndex(int, bool, QString);

private:
    Ui::connectdialog *ui;
    CyDev *usb;
    CANChannels *Optic_uC;
    QString DTSN;
};

#endif // CONNECTDIALOG_H
