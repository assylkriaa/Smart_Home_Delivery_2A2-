#include "classe_personnel.h"

classe_personnel::classe_personnel()
{
    idp="";
     nom="";
     prenom="";
     adress="";
}
 classe_personnel:: classe_personnel(QString id ,QString n,QString p,QString ads)
{
     idp=id;
     nom=n;
     prenom=p;
     adress=ads;
}
 bool classe_personnel::ajouter_employe()
 {
     QSqlQuery query;
     //QString res=QString::number(idp);
     query.prepare("INSERT INTO EMPLOYEE(idp,nom,prenom,adress)VALUES(:idp,:nom,:prenom,:adress)");
     query.bindValue(":idp",idp);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":adress",adress);
     return query.exec();
 }
 bool classe_personnel::supprimer_employe(QString id)
 {
     QSqlQuery query;
    // QString res=QString::number(id);
     query.prepare("Delete from employee where idp=:idp");
     query.bindValue(":idp",id);
     return query.exec();
 }
  bool classe_personnel::modifier_employe(QString id)
  {
      QSqlQuery query;
      //QString res=QString::number(id);
      query.prepare("Update employee set nom=:nom,prenom=:prenom,adress=:adress where idp=:idp");
      query.bindValue(":idp",id);
      query.bindValue(":nom",nom);
      query.bindValue(":prenom",prenom);
      query.bindValue(":adress",adress);
      return query.exec();
  }
  QSqlQueryModel *classe_personnel::afficher_employe()
  {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from employee");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("adress"));

      return model;
  }
  QSqlQueryModel *classe_personnel::afficher_employe_1(QString txt)
  {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select nom  from employee where idp LIKE '"+txt+"'");


      return model;
  }
  QSqlQueryModel *classe_personnel::tri_id_employe()
  {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from employee order by idp");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("adress"));
      return model;
  }
  QSqlQueryModel *classe_personnel::tri_nom_employe()
  {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from employee order by nom");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("adress"));
      return model;
  }
  QSqlQueryModel *classe_personnel::tri_prenom_employe()
  {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from employee order by prenom");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("adress"));
      return model;
  }
  QSqlQueryModel *classe_personnel::recherche_id_employe(QString txt)
    {

        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from employee where idp LIKE '"+txt+"'" );
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("adress"));

        return model;
    }
    QSqlQueryModel *classe_personnel::recherche_nom_employe(QString txt)
    {

        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from employee where nom LIKE '"+txt+"'" );
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("adress"));
        return model;
    }
    QSqlQueryModel *classe_personnel::recherche_prenom_employe(QString txt)
    {

        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from employee where prenom LIKE '"+txt+"'" );
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("adress"));

        return model;
    }



