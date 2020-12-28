#include "fournisseurs.h"
#include <QDebug>

fournisseurs::fournisseurs(){};
bool fournisseurs::ajouter()
{
    QSqlQuery query;

    ///QString res= QString::number(Numero);

    query.prepare("INSERT INTO fournisseurs ( numero,email,nom,adresse,type)"
                  "VALUES (:numero,:email,:nom,:adresse,:type)");
    query.bindValue(":numero",Numero);
    query.bindValue(":nom",Nom);
    query.bindValue(":adresse",Adresse);
    query.bindValue(":email",Email);
    query.bindValue(":type",Type);

    return query.exec();
}


QSqlQueryModel * fournisseurs::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("select * from fournisseurs");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

    return model;
}


bool fournisseurs::supprimer(QString numero)
{
    QSqlQuery qry;
    qry.prepare("Delete from FOURNISSEURS where numero = :numero");
    qry.bindValue(":numero",numero);
    return qry.exec();
}

QSqlQueryModel *fournisseurs::recherche(QString numero)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from FOURNISSEURS where numero LIKE '"+numero+"%' or nom LIKE '"+numero+"%' or adresse LIKE '"+numero+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));


 return model;
}
bool fournisseurs::modifier(QString Nom,QString Adresse,QString Numero,QString Type,QString Email)
{
QSqlQuery query;

query.prepare("Update FOURNISSEURS set  NOM=:Nom , ADRESSE=:Adresse , TYPE=:Type , EMAIL=:Email   where NUMERO=:Numero ");

query.bindValue(":Numero",Numero);
query.bindValue(":Nom",Nom);
query.bindValue(":Adresse",Adresse);
query.bindValue(":Email",Email);
query.bindValue(":Type",Type);


return    query.exec();
}
