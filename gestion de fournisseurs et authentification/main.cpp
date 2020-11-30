#include "mainwindow.h"
#include "login.h"
 #include "agent.h"
#include "connexion.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion c;
    bool test=c.createConnection();
    login w;

    if (test)
        qDebug() << "connexion successful";
    else
        qDebug() << "connexion failed";
    w.show();
    return a.exec();
}
