#ifndef MVT_H
#define MVT_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class mvt; }
QT_END_NAMESPACE

class mvt : public QDialog
{
    Q_OBJECT

public:
    mvt(QWidget *parent = nullptr);
    ~mvt();

private slots:
    void readSerial();
    void updateTemperature(QString);

private:
    Ui::mvt *ui;
    QSerialPort *arduino;
       static const quint16 arduino_uno_vendor_id = 9025;
       static const quint16 arduino_uno_product_id = 67;
       QByteArray serialData;
       QString serialBuffer;
       QString parsed_data;
       double temperature_value;
};
#endif // MVT_H
