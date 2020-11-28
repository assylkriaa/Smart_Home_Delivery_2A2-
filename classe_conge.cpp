#include "classe_conge.h"
#include <QString>
classe_conge::classe_conge()
{
idc="";
nom="";
date_debut="";
duree="";
}
classe_conge::classe_conge(QString id ,QString n,QString d,QString dr)
{
idc=id;
nom=n;
date_debut=d;
duree=dr;
}
bool classe_conge:: ajouter_conge()
{
    QSqlQuery query;
    //QString res=QString::number(idp);
    query.prepare("INSERT INTO congé(idp,nom,date_debut,duree)VALUES(:idc,:nom,:date_debut,:duree)");
    query.bindValue(":idc",idc);
    query.bindValue(":nom",nom);
    query.bindValue(":date_debut",date_debut);
    query.bindValue(":duree",duree);
    return query.exec();
}
bool  classe_conge:: supprimer_conge(QString id)
{
    QSqlQuery query;
   // QString res=QString::number(id);
    query.prepare("Delete from congé where idp= :idp");
    query.bindValue(":idp",id);
    return query.exec();
}
bool classe_conge:: modifier_conge(QString id)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    query.prepare("Update congé set nom=:nom,date_debut=:date_debut,duree=:duree where idp=:idp");
    query.bindValue(":idp",id);
    query.bindValue(":nom",nom);
    query.bindValue(":date_debut",date_debut);
    query.bindValue(":duree",duree);
    return query.exec();
}
 QSqlQueryModel *classe_conge::afficher_conge()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select * from congé");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_debut"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("duree"));

     return model;
 }
 QSqlQueryModel *classe_conge:: recherche_id_conge(QString txt )
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select * from congé where idp LIKE '"+txt+"'" );
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_debut"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("duree"));

     return model;
 }
 QSqlQueryModel *classe_conge ::recherche_nom_conge(QString txt )
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select * from congé where nom LIKE '"+txt+"'" );
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_debut"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("duree"));
     return model;

 }
 QSqlQueryModel *classe_conge::recherche_date_conge(QString txt)
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select * from congé where date_debut LIKE '"+txt+"'" );
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_debut"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("duree"));

     return model;
 }
