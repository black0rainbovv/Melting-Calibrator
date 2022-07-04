#ifndef T8KTHREAD
#define T8KTHREAD

#include "myport.h"
#include "connectdialog.h"
#include "mainwindow.h"
#include "globalvariable.h"
#include <QThread>

class T8KThread : public QThread
{
    Q_OBJECT

    void run();

public slots:
    QString ConvertAnswer(QByteArray answer);   

signals:
    void SendTemperature(QStringList t);
    void PortError(QString err);
    void PortConnected(QString sNumber);
    void DataLost();

private:   
    QStringList templist;
    bool running;
};



#endif // T8KTHREAD

