#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logistique.h"
#include <QFileDialog>
#include  <QString>
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


void MainWindow::on_pushButton_clicked()
{ logistique d;
d.exec();
}
