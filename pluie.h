#ifndef PLUIE_H
#define PLUIE_H

#include <QMainWindow>
#include <QSerialPort>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class pluie; }
QT_END_NAMESPACE

class pluie : public QMainWindow
{
    Q_OBJECT

public:
    pluie(QWidget *parent = nullptr);
    ~pluie();

private slots:
    void readSerial();
    void updateTemperature(QString);



private:
    Ui::pluie *ui;
    QSerialPort *arduino;
       static const quint16 arduino_uno_vendor_id = 9025;
       static const quint16 arduino_uno_product_id = 67;
       QByteArray serialData;
       QString serialBuffer;
       QString parsed_data;
       double temperature_value;
};
#endif // PLUIE_H
