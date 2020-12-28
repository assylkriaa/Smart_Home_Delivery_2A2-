#ifndef TEMP_H
#define TEMP_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>


namespace Ui {
class TEMP;
}

class TEMP : public QDialog
{
    Q_OBJECT

public:
    explicit TEMP(QWidget *parent = 0);
    ~TEMP();

private slots:
    void readSerial();
    void updateTemperature(QString);

private:
    Ui::TEMP *ui;

    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    float temperature_value;
};

#endif // TEMP_H
