#include  "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include "client.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ui->setupUi(this);
    animation= new QPropertyAnimation(ui->pushButton,"geometry");
    animation->setDuration(10000);
    animation->setStartValue(ui->pushButton->geometry());
     animation->setEndValue(QRect(200,200,200,100));
     animation->start();}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
        Dialog *w;
   w= new Dialog(this);
   w->show();
}
