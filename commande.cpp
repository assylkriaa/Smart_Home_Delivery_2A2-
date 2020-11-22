#include "commande.h"

Commande::Commande()
{
    nb=0;
    nom_commande="";
    id=0;
}
Commande::Commande(QString n ,int i,int j)
{
    nb=i;
    nom_commande=n;
    id=j;
}
bool Commande::ajouter()
{
    QSqlQuery query;
   QString nbs=QString::number(nb);
   QString ids=QString::number(id);
    query.prepare("INSERT INTO COMMANDES(id,nom_commande,nbc)"
                  "VALUES (:id,:nom_commande,:nb)");
    query.bindValue(":id",ids);
    query.bindValue(":nom_commande",nom_commande);
    query.bindValue(":nb",nbs);
    return query.exec();
}
QSqlQueryModel * Commande::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMMANDES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_commande"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nbc"));
    return model;
}
bool Commande::supprimer(int i)
{
    QSqlQuery query;
    QString IDS=QString::number(i);
    query.prepare("DELETE FROM Commandes WHERE id= :IDS");
    query.bindValue(":IDS",IDS);
    return query.exec();
}
bool Commande::modifier()
{
    QSqlQuery query;
   QString nbs=QString::number(nb);
   QString ids=QString::number(id);
    query.prepare("UPDATE COMMANDES SET nom_commande=:nom_commande,nbc=:nbs WHERE id=:ids");
    query.bindValue(":ids",ids);
    query.bindValue(":nom_commande",nom_commande);
    query.bindValue(":nbs",nbs);
    return query.exec();

}
QSqlQueryModel * Commande::trier(QString& choice,QString& a)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if ((choice=="ID")and(a=="decroissant"))
        model->setQuery("SELECT * FROM COMMANDES ORDER BY ID Desc ");

        else if ((choice=="nom_commande")and(a=="decroissant"))
          model->setQuery("SELECT * FROM COMMANDES ORDER BY nom_commande Desc ");

        else if ((choice=="nbc")and(a=="decroissant"))
             model->setQuery("SELECT * FROM COMMANDES ORDER BY nbc Desc ");

    if ((choice=="ID")and(a=="croissant"))
        model->setQuery("SELECT * FROM COMMANDES ORDER BY ID ASC ");

        else if ((choice=="nom_commande")and(a=="croissant"))
          model->setQuery("SELECT * FROM COMMANDES ORDER BY nom_commande ASC ");

        else if ((choice=="nbc")and(a=="croissant"))
             model->setQuery("SELECT * FROM COMMANDES ORDER BY nbc ASC");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_commande"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nbc"));
    return model;
}
