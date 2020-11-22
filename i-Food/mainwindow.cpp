#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_principale.h"

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

Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");//inserer le nom de la source de données ODBC
db.setUserName("kriaa");//inserer nom de l'utilisateur
db.setPassword("assyl");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;
    return  test;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog_principale d;
    d.exec();
}
