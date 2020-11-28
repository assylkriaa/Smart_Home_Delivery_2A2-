#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class materiel
{
    QString type;
    int reference,code;
public:
    materiel();

    materiel (int,QString,int);
        int getrereference(){return reference;}
        QString gettype(){return type;}
        int getcode(){return code;}
        void  settype(QString t);
        void  setcode(int c);


                bool ajouter();
                QSqlQueryModel * afficher();
                bool supprimer(int);
                bool modifier(int);
                void chercher();
                bool   modifier(QString ref);

                QSqlQueryModel *chercher(QString txt);
                QSqlQueryModel *chercher1(QString txt);
                QSqlQueryModel *chercher2(QString txt);
};

#endif // MATERIEL_H
