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
QSqlQueryModel * Client::rechercher(QString& choice,QString& a,QString& b)
{
    QSqlQuery query;

    QSqlQueryModel * model=new QSqlQueryModel();


    if (choice=="ID et nom")
    model->setQuery("SELECT * FROM Clients where (ID LIKE '"+a+"%')  AND (nom LIKE '"+b+"%')");

    if (choice=="ID et prenom")
    model->setQuery("SELECT * FROM Clients where (ID LIKE '"+a+"%')  AND (prenom LIKE '"+b+"%')");
    if (choice=="ID et adresse")
    model->setQuery("SELECT * FROM Clients where (ID LIKE '"+a+"%')  AND (adresse LIKE '"+b+"%')");

    else if (choice=="nom et prenom")
     model->setQuery("SELECT * FROM Clients where (nom LIKE '"+a+"%')  AND (prenom LIKE '"+b+"%')");

    else if (choice=="nom et adresse")
        model->setQuery("SELECT * FROM Clients where (nom LIKE '"+a+"%')  AND (adresse LIKE '"+b+"%')");

   else if (choice=="prenom et adresse")
        model->setQuery("SELECT * FROM Clients where (prenom LIKE '"+a+"%')  AND (adresse LIKE '"+b+"%')");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));

    return model;
}
