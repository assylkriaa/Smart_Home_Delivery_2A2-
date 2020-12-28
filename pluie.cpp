#include "pluie.h"
#include "ui_pluie.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include<QPixmap>

pluie::pluie(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pluie)
{

    ui->setupUi(this);





        arduino = new QSerialPort(this);
        serialBuffer = "";
        parsed_data = "";
        temperature_value = 0.0;

        /*
         *  Testing code, prints the description, vendor id, and product id of all ports.
         *  Used it to determine the values for the arduino uno.
         *
         *
        qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            qDebug() << "Description: " << serialPortInfo.description() << "\n";
            qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
            qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
        }
        */


        /*
         *   Identify the port the arduino uno is on.
         */
        bool arduino_is_available = false;
        QString arduino_uno_port_name;
        //
        //  For each available serial port
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            //  check if the serialport has both a product identifier and a vendor identifier
            if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
                //  check if the product ID and the vendor ID match those of the arduino uno
                if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                        && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                    arduino_is_available = true; //    arduino uno is available on this port
                    arduino_uno_port_name = serialPortInfo.portName();
                }
            }
        }

        /*
         *  Open and configure the arduino port if available
         */
        if(arduino_is_available){
            qDebug() << "Found the arduino port...\n";
            arduino->setPortName(arduino_uno_port_name);
            arduino->open(QSerialPort::ReadOnly);
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
        }else{
            qDebug() << "Couldn't find the correct port for the arduino.\n";
            QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
        }
    }




void pluie::readSerial()
{

        serialData = arduino->readAll();

       pluie::updateTemperature(serialData);


}

void pluie::updateTemperature(QString sensor_reading)
{
    //  update the value displayed on the lcdNumber

if(sensor_reading=="1"){
 ui->label->setText("it's wet ");

}
else{
    ui->label->setText("it's dry ");
}

   // ui->temp_lcdNumber->display(sensor_reading);

}

pluie::~pluie()
{
    delete ui;
}



