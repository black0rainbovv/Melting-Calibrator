#include "connectdialog.h"
#include "ui_connectdialog.h"

connectdialog::connectdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectdialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Подключение устройств");
    FindDT();
    FindT8K();
}

connectdialog::~connectdialog()
{
    delete ui;
}

void connectdialog::FindDT() // Поиск доступных приборов DT для подключения
{
    usb = new CyDev(NULL);
    QString check_SN = "";
    for(int i = 0; i < 10; i++)
    {
        usb->Open(i);
        Optic_uC = new CANChannels(usb, 2);
        DTSN = QString::fromUtf16((ushort*)usb->SerNum);
        if(DTSN == check_SN) // Проверка на повторение серийных номеров DT
        {
            if(ui->listWidgetDT->item(i) == NULL){
                continue;
            }
            else
                ui->listWidgetDT->item(i)->font().setStrikeOut(true);

            return;
        }
        ui->listWidgetDT->addItem(DTSN);
        check_SN = DTSN;
    }
}
void connectdialog::FindT8K() // Поиск портов для подключения T8K
{
    foreach(const QSerialPortInfo &pinfo, QSerialPortInfo::availablePorts())
    {
        if(pinfo.hasProductIdentifier())
        {
            if((QByteArray::number(pinfo.productIdentifier())) == "24577")
            {
                T8KPortName = pinfo.portName();
                ui->listWidgetT8K->addItem(T8KPortName);
            }
        }
    }
}

void connectdialog::on_pushButtonConnect_clicked()
{
    if(ui->listWidgetT8K->currentItem() != NULL)
    {
        T8KPortName = ui->listWidgetT8K->currentItem()->text();
        T8Kconnected = true;
        emit setupsettings(T8Kconnected); //Сигнал на подключение T8K
    }
    else
    {
        QMessageBox::critical(this,"Внимание!", "Не удалось подключить устройство T8K!");
    }
    QModelIndex currentIndex= ui->listWidgetDT->currentIndex();
    int index = currentIndex.row();
    usb = new CyDev(NULL);
    usb->Open(index);
    if(usb->IsOpen()){
        DTSN = QString::fromUtf16((ushort*)usb->SerNum);
        bool connection = true;
        emit SendIndex(index, connection, DTSN); //Сигнал на подключение DT
    }
    else
    {
        QMessageBox::critical(this, "Внимание!!", "Устройство DT не было подключено.");
    }
    this->close();
}
