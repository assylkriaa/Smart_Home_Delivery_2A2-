#ifndef COMMANDE_H
#define COMMANDE_H
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class Commande
{
private:
    int nb,id;
    QString nom_commande;
public:
    Commande();
    Commande(QString,int,int);
    int get_id(){return id;}
    QString get_nomc(){return nom_commande;}
    int get_nb(){return nb;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
        QSqlQueryModel * trier(QString&,QString&);
        QSqlQueryModel * enregistrer();

};

#endif // COMMANDE_H
