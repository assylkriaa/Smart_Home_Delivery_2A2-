#include "mainwindow.h"
#include"login.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "gestion_perso_conge.h"
#include "dialog_principale.h"
#include"logistique.h"
#include<QTextCodec>
#include<QTranslator>
#include<QInputDialog>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    connexion c;
   // gestion_perso_conge p;
   // logistique l;
   // Dialog_principale e;


   // l.setWindowTitle(" Transport ");
   // e.setWindowTitle(" Emplacement et Reclamation ");
   // p.setWindowTitle(" Personnels ");

    QTranslator t;
    QStringList language;
    language <<"francais"<<"anglais";
      QString lang= QInputDialog::getItem(NULL,"choissisez une langue","Language",language);
     QString locale = QLocale::system().name();
     if(lang=="anglais")
     {
      t.load(QString(":/english.qm")+locale);
     }
     if(lang!="francais")
     {
       a.installTranslator(&t);
     }
     login w;
      //w.setWindowTitle(QObject::tr(" login "));
    bool test=c.createconnect();
    if(test)
    {


 w.show();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
