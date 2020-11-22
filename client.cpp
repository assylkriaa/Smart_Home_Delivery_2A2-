#include "client.h"
//aa
Client::Client()
{
nom ="";
prenom="";
adresse="";
ID=0;
}
Client::Client(int i ,QString a,QString b,QString c)
{
nom =a;
prenom=b;
adresse=c;
ID=i;
}
bool Client::ajouter()
{
    QSqlQuery query;
   QString IDS=QString::number(ID);
    query.prepare("INSERT INTO Clients(ID,nom,prenom,adresse)"
                  "VALUES (:ID,:nom,:prenom,:adresse)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":ID",IDS);
    return query.exec();
}
QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Clients");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));

    return model;
}
bool Client::supprimer(int i)
{
    QSqlQuery query;
    QString IDS=QString::number(i);
    query.prepare("DELETE FROM Clients WHERE ID= :IDS");
    query.bindValue(":IDS",IDS);
    return query.exec();
}
bool Client::modifier()
{
    QSqlQuery query;
   QString IDS=QString::number(ID);

   query.prepare("UPDATE CLIENTS SET nom=:nom,prenom=:prenom,adresse=:adresse WHERE id=:ids");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":ids",IDS);
    return query.exec();



}
QSqlQueryModel * Client::rechercher(QString& choice,QString& a)
{
    QSqlQuery query;

    QSqlQueryModel * model=new QSqlQueryModel();

    if (choice=="ID")
    model->setQuery("SELECT * FROM Clients where ID like '"+a+"%'");

    else if (choice=="nom")
     model->setQuery("SELECT * FROM Clients where nom like '"+a+"%'");

    else if (choice=="prenom")
        model->setQuery("SELECT * FROM Clients where prenom like '"+a+"%'");

   else if (choice=="adresse")
        model->setQuery("SELECT * FROM Clients where adresse like '"+a+"%'");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));

    return model;
}
