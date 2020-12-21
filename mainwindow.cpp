#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facrec.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_FACREC_clicked()
{
   FACREC d;
   d.exec();
}
