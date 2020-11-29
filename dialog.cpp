#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    animation= new QPropertyAnimation(ui->pushButton,"geometry");
    animation->setDuration(10000);
    animation->setStartValue(ui->pushButton->geometry());
     animation->setEndValue(QRect(200,200,200,100));
     animation->start();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
   w= new MainWindow(this);
   w->show();
}
