#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QString T8KPortName;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Icon.ico"));
    this->setWindowTitle("Melting Calibrator");
    SensorsIsEnabled[0] = 1;
    SensorsIsEnabled[1] = 1;
    SensorsIsEnabled[2] = 1;
    SensorsIsEnabled[3] = 1;
    SensorsIsEnabled[4] = 1;
    SensorsIsEnabled[5] = 1;
    measures = 0;
    is_working = false;
    warming_up = false;
    stop_prog = false;
    time_left = 1;
    count = 0;
    coef_count = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 36; j++)
        {
            all_data[j][i] =0.0;
        }
        realtemp[i] = 0.0;
        sensor_temp[i] = 0.0;
        data_sensors[i] = 0.0;
        xm_temp[i] = 20.0;
        difference[i] = 0.0;
    }

    QObject::connect(ui->pushButtonConnect, SIGNAL(clicked(bool)), SLOT(ConnectDevices())); // Открытие окна с подключением девайсов
    QObject::connect(ui->pushButtonStart, SIGNAL(clicked(bool)), SLOT(StartProgram())); // Кнопка запуска программы плавления
    QObject::connect(ui->pushButtonStop, SIGNAL(clicked(bool)), SLOT(StopProgram())); // Кнопка остановки плавления
    QObject::connect(ui->pushButtonWrite, SIGNAL(clicked(bool)), SLOT(BCALCommand())); // Кнопка записи новых коеф
    QObject::connect(ui->pushButtonExcerpt, SIGNAL(clicked(bool)), SLOT(ExcerptProgram())); // Кнопка программы выдержки
    QObject::connect(this, SIGNAL(SendApprox(double,double, int)), SLOT(SetNewCoef(double,double, int))); // Установка новых коеф

//    enum class IoMode : unsigned char { WRITE = 0x40, READ = 0x41, OPEN_CAN = 0x42, CLOSE_CAN = 0x43, RESET = 0x44, FJ_CNTR = 0x52 };
//    enum class RstMode: unsigned char { RST_THERMO = 0x30, RST_MOTOR = 0x28, RST_BOTH = 0x20, RST_OFF = 0x38};
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    usb->Close();
    SaveLog("Melting Calibrator closed");
}

void MainWindow::ConnectDevices()
{
    connectdialog *cf = new connectdialog;
    QObject::connect(cf, SIGNAL(setupsettings(bool)), SLOT(ApplySettings(bool))); // Подключение T8K
    QObject::connect(cf, SIGNAL(SendIndex(int, bool, QString)), SLOT(ConnectDT(int, bool, QString))); // Подключение DT
    cf->setModal(true);
    cf->exec();
}

void MainWindow::ConnectDT(int index, bool DTConnected, QString name) // Подключение к DT
{
    dt_connected = DTConnected;
    dt_index = index;
    dt_name = name;

    if(dt_connected == true)
    {
        usb = new CyDev(NULL);
        usb->Open(dt_index);
        if(usb->IsOpen())
        {
            QDate pc_date = QDate::currentDate();
            optic = new CANChannels(usb,2);
            temp = new CANChannels(usb,3);
            motor = new CANChannels(usb,4);
            display = new CANChannels(usb,5);
            this->setWindowTitle("Melting Calibrator - " + dt_name);
            ui->labelStatus->setText("Прибор DT подключен");
            ReadOldCoef();
            SaveLog("Date: " +pc_date.toString("dd/MM/yy"));
            SaveLog(dt_name + " connected");
        }
    }
}

void MainWindow::ApplySettings(bool T8Kcon)
{
    if(T8Kcon == true)
    {
        T8KThread *t8k = new T8KThread;
        QObject::connect(t8k, SIGNAL(SendTemperature(QStringList)), SLOT(ReceiveTemperature(QStringList))); // Получение температуры с датчиков
        QObject::connect(t8k, SIGNAL(PortError(QString)), SLOT(SerialPortErrorHandler(QString)));
        QObject::connect(t8k, SIGNAL(PortConnected(QString)), SLOT(PortConnected(QString))); // Подключение порта T8K
        QObject::connect(t8k, SIGNAL(finished()), t8k, SLOT(deleteLater()));
        t8k->start();
    }
}

void MainWindow::ReceiveTemperature(QStringList t)
{
    if(is_working == true)
    {
        for(int i=0; i<6; i++)
        {
            QLabel *l = new QLabel();
            l->setFont(QFont("MS Shell", 10, 65));
            l->setText("<font color='red'>"+QString::number(t[i].toDouble(), 'f', 2)+"</font>");
            l->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidgetMeasuredTemp->setCellWidget(i,1, l); // Отображение показания датчиков
        }
        for(int i=0; i<6; i++)
        {
            realtemp[i] = t[i].toDouble();
        }
        StartXGSChecking();
    }
}

void MainWindow::SerialPortErrorHandler(QString err)
{
    QMessageBox::information(this, tr("Ошибка порта!"), err);
}

void MainWindow::PortConnected(QString sNumber)
{
     T8KSN = sNumber.split(" ")[0];
     if(dt_connected)
         this->setWindowTitle("Melting Calibrator - " + dt_name + " - " + T8KSN);
     else
         this->setWindowTitle("Melting Calibrator - DT not connected " + T8KSN);
}

void MainWindow::ReadOldCoef()
{
    if(dt_connected)
    {
        QEventLoop loop;
        ReadCoefThread *rct = new ReadCoefThread(&mutex, dt_index);
        QObject::connect(rct, SIGNAL(finished()), &loop, SLOT(quit()));
        QObject::connect(rct, SIGNAL(SendOldCoef(QString, int)), SLOT(SetOldCoef(QString, int))); // Чтение коэффициентов, записанных в прибор
        rct->start();
        loop.exec();
    }
}

void MainWindow::SetOldCoef(QString old_coef, int i)
{
    QStringList coef_list;
    QTableWidgetItem *coef1 = new QTableWidgetItem();
    QTableWidgetItem *coef2 = new QTableWidgetItem();
    if(old_coef.split(' ').length() > 3)
    {
        coef_list = old_coef.split(' ');
        coef_value20[i] = coef_list[2].toDouble();
        coef_value90[i] = coef_list[3].toDouble();
        coef1->setText(QString::number(coef_value20[i]));
        coef2->setText(QString::number(coef_value90[i]));
        coef1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        coef2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        coef1->setFont(QFont("MS Shell", 10, 65));
        coef2->setFont(QFont("MS Shell", 10, 65));
        ui->tableWidgetOldCoef->setItem(i, 0, coef1); // Отображение коэф для 20
        ui->tableWidgetOldCoef->setItem(i, 1, coef2); // Отображение коэф для 90
        SaveLog("Old coef 20 [" + QString::number(i +1) + "]: " + QString::number(coef_value20[i]));
        SaveLog("Old coef 90 [" + QString::number(i +1) + "]: " + QString::number(coef_value90[i]));
    }
}

void MainWindow::SetNewCoef(double a, double b, int count)
{
    double coef_low, coef_high;
    coef_low= coef_value20[count] + b * 256.0;
    coef_high = coef_value90[count] + a  * 100.0 * 256.0;

    QTableWidgetItem *coef1 = new QTableWidgetItem();
    QTableWidgetItem *coef2 = new QTableWidgetItem();

    coef1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    coef2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    coef1->setFont(QFont("MS Shell", 10, 65));
    coef2->setFont(QFont("MS Shell", 10, 65));

    coef1->setText(QString::number(floor(coef_low)));
    coef2->setText(QString::number(floor(coef_high)));

    ui->tableWidgetNewCoef->setItem(count, 0, coef1);
    ui->tableWidgetNewCoef->setItem(count, 1, coef2);
    SaveLog("New coef 20 [" + QString::number(count + 1) + "]: " + QString::number(coef_low));
    SaveLog("New coef 90 [" + QString::number(count + 1) + "]: " + QString::number(coef_high));
}

void MainWindow::StartProgram()
{
    if(dt_connected)
    {
        QEventLoop loop;
        WriteStartProg *wsp = new WriteStartProg(&mutex, dt_index);
        QObject::connect(wsp, SIGNAL(finished()), &loop, SLOT(quit()));
        QObject::connect(wsp, SIGNAL(SendStatus(bool,bool)), SLOT(GetStatus(bool,bool))); // Запуск программы плавления
        wsp->start();
        loop.exec();
    }
    else
    {
        QMessageBox::critical(this, "Melting Calibrator", "Чтобы запустить программу нужно подключить устройство!");
    }
}

void MainWindow::ExcerptProgram()
{
    if(dt_connected)
    {
        QString outs;
        mutex.lock();
        USBCy_RW("XPRG 0 36 0", outs, usb, temp);
        USBCy_RW("XLEV 2000 420 0 0 0 0", outs, usb, temp);
        USBCy_RW("XLEV 4000 420 0 0 0 0", outs, usb, temp);
        USBCy_RW("XLEV 6400 420 0 0 0 0", outs, usb, temp);
        USBCy_RW("XLEV 7000 420 0 0 0 0", outs, usb, temp);
        USBCy_RW("XLEV 8000 420 0 0 0 0", outs, usb, temp);
        USBCy_RW("XLEV 9000 420 0 0 0 0", outs, usb, temp);
        USBCy_RW("XCYC 2", outs, usb, temp);
        USBCy_RW("XSAV Excerpt", outs, usb, temp);
        mutex.unlock();
        timer = new QTimer();
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(CheckTempTimer()));
        timer->start(419000);
    }
}

void MainWindow::CheckTempTimer()
{
    for(int i = 0; i < 6; i++)
    {
        SaveLog("Excerpt = " + QString::number(realtemp[i]));
    }
}

void MainWindow::GetStatus(bool working, bool warming)  // Получение ответа на запуск программы плавления
{
    is_working = working;
    warming_up = warming;
    if(is_working == true)
    {
        ui->labelStatus->setText("В работе");
        SaveLog("Melting program started");
        StartXGSChecking();
    }
    else if(is_working == false)
    {
        if(warming_up == false)
        {
            QString outs;
            QMessageBox::critical(this,"Melting Calibrator", "Произошла ошибка старта программы!");
            mutex.lock();
            USBCy_RW("ST", outs, usb, temp); // Остановка программы плавления
            mutex.unlock();
            SaveLog("Melting program critical stopped");
        }
    }
    else if(warming_up == true)
    {
        ui->labelStatus->setText("Прогрев");
    }
}

void MainWindow::StopProgram()
{
    if(dt_connected)
    {
        QString outs;
        mutex.lock();
        USBCy_RW("ST", outs, usb, temp); // Остановка программы плавления
        mutex.unlock();
        QMessageBox::information(this,"Melting Calibrator","Программа плавления остановленна.");
        ui->labelStatus->setText("DT подключен");
        is_working = false;
        SaveLog("Melting program stopped");
    }
}

void MainWindow::BCALCommand()
{
    if(dt_connected == true)
    {
        QMessageBox m(QMessageBox::Question,
                        "Внимание! ",
                        "Вы уверены что хотите записать коэффициенты?",
                        QMessageBox::Yes|QMessageBox::No);
        m.setButtonText(QMessageBox::Yes, "Да");
        m.setButtonText(QMessageBox::No, "Нет");
        if(m.exec() == QMessageBox::Yes)
        {
            QString cmd, out;
            temp = new CANChannels(usb, 3);
            for (int i=0; i<6; i++)
            {
                QTableWidgetItem *q20 = ui->tableWidgetNewCoef->item(i, 0);
                QTableWidgetItem *q90 = ui->tableWidgetNewCoef->item(i, 1);

                if(q20 != NULL && q90 != NULL)
                {
                    if(q20->text() != "" && q90->text() != "")
                    {
                        cmd = "dlws BCAL "+QString::number(i)+" "+q20->text()+" "+q90->text();
                        USBCy_RW(cmd, out, usb, temp);
                        SaveLog("Write new coef - " + cmd);
                    }
                }
            }

            if(out == "0")
            {
                QMessageBox::information(this, tr("Внимание"), tr("Для того, чтобы новые коэффициенты стали действительны"
                                                                 " требуется перезапустить устройство"));

            }
            else
            {
                QMessageBox::information(this, tr("Error"), tr("Ошибка при записи коэффициентов"));
            }
        }
    }
}

//void MainWindow::on_pushButtonReset_clicked()
//{
//    usb->VendRead(&dstate, 0, 0x52, 0, 0x30);   //выключение термоконтроллера
//    QThread::msleep(200);
//    temp->Reset();
//    QThread::msleep(200);
//    usb->VendRead(&dstate, 0, 0x52, 0, 0x38); //включение термоконтроллера
//    qDebug() << &dstate;
//}

void MainWindow::StartXGSChecking()
{
    if(is_working == true)
    {
        QEventLoop loop;
        XGSCheck *xgs = new XGSCheck(&mutex, dt_index);
        QObject::connect(xgs, SIGNAL(finished()), &loop, SLOT(quit()));
        QObject::connect(xgs, SIGNAL(SendAnswer(QString, QStringList)), SLOT(XGSAnswer(QString, QStringList)));
        xgs->start();
        loop.exec();
    }
}

void MainWindow::XGSAnswer(QString answer, QStringList answer_xm)  // Сохранение показаний в определенный момент
{
    if(is_working == true)
    {
        if(answer.right(1) == "1")
        {
            Polka = 25;
        }
        if(answer.right(1) == "4" || answer.right(1) == "5")
        {
            Polka--;
            if(Polka <= 0)
            {
                for(int i = 0; i < 6; i++)
                {
                    answer_xm[i].insert(2,".");
                }
                SaveSensorsTemp(answer_xm);
                Polka = 25;
            }
        }
        if(answer.split(" ")[0] == "0")
        {
            if(is_working == true)
            {
                is_working = false;
                QMessageBox::information(this,"Melting Calibrator", "Измерения закончены. Программа остановлена.");
                CalcNewCoef();
                SaveLog("Program completed");
            }
        }
    }
}

void MainWindow::SaveSensorsTemp(QStringList answer_xm) // Создание двумерного массива с измеренными показаниями
{
    if(is_working)
    {
        for(int i = 0; i < 6; i++)
        {
            xm_temp[i] = answer_xm[i].toDouble();
            difference[i] = realtemp[i] - xm_temp[i];
            all_data[count][i] += difference[i];
            SaveLog("Sensor temperature - " + QString::number(realtemp[i]));
        }
        count ++;
    }
}

void MainWindow::Approx(double y[])  // Аппроксимация полученных значений
{
    double a = 0.0;
    double b = 0.0;
    double sumx = 0.0;
    double sumy = 0.0;
    double sumx2 = 0.0;
    double sumxy = 0.0;
    double x[36];
    int temperature = 20;
    for(int i = 0; i < 36; i++)
    {
        x[i] = temperature;
        temperature += 2;
    }
    for (int i = 0; i<36; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumx2 += x[i] * x[i];
        sumxy += x[i] * y[i];
    }
    a = (36*sumxy - sumx*sumy) / (36*sumx2 - sumx*sumx);
    b = (sumy - a*sumx) / 36;
    SaveLog("[" + QString::number(coef_count) + "] a - " + QString::number(a));
    SaveLog("[" + QString::number(coef_count) + "] b - " + QString::number(b));
    emit SendApprox(a, b, coef_count);
    coef_count++;
}

void MainWindow::CalcNewCoef()
{
    double channel1[36];
    double channel2[36];
    double channel3[36];
    double channel4[36];
    double channel5[36];
    double channel6[36];

    for(int i = 0; i < 36; i ++)
    {
        channel1[i] = all_data[i][0];
        channel2[i] = all_data[i][1];
        channel3[i] = all_data[i][2];
        channel4[i] = all_data[i][3];
        channel5[i] = all_data[i][4];
        channel6[i] = all_data[i][5];
    }
    Approx(channel1);
    QThread::msleep(100);
    Approx(channel2);
    QThread::msleep(100);
    Approx(channel3);
    QThread::msleep(100);
    Approx(channel4);
    QThread::msleep(100);
    Approx(channel5);
    QThread::msleep(100);
    Approx(channel6);
    QThread::msleep(100);
}

void MainWindow::SaveLog(QString message) // Диагностический логгер
{
    QTime pc_time = QTime::currentTime();
    QString log_message = "[" + pc_time.toString("hh:mm:ss") + "] " + message + "\n";
    QFile logger("Log " + dt_name +".xml");
    if(logger.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream write_stream(&logger);
        write_stream << log_message;
        logger.close();
    }
}


