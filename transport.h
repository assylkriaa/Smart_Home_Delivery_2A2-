#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class transport
{
public:
    transport();
    transport (QString,QString,int);
        int getmatricule(){return matricule;}
        QString gettype(){return type;}
        QString getmodele(){return modele;}
        void  settype(QString t);
        void  setmodele(QString m);


                bool ajouter();
                QSqlQueryModel * afficher();
                bool supprimer(int);
                bool modifier(int);
                void chercher();
                bool   modifier(QString matriculee);
                void statistique(QVector<double>* ticks,QVector<QString> *labels);
                QSqlQueryModel *chercher(QString txt);
                QSqlQueryModel *chercher1(QString txt);
                QSqlQueryModel *chercher2(QString txt);


private :
    QString type,modele;
       int matricule;
};

#endif // TRANSPORT_H
