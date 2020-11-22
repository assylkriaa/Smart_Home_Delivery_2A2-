#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class Client
{
private:
    int ID;
    QString nom,prenom,adresse;
public:
    Client();
    Client(int,QString,QString,QString);
    QString get_nomcl(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_adresse(){return adresse;}
    int get_id(){return ID;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(QString&,QString&);

};

#endif // CLIENT_H
