#include "transport.h"

transport::transport()
{

}
transport::transport (QString t,QString mm,int m)
{
modele=mm;
type=t;
matricule=m;
}
void transport:: settype(QString t)
{
type=t;
}
void transport:: setmodele(QString m)
{
modele=m;
}
bool transport::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(matricule);
query.prepare("INSERT INTO transport(modele,type,matricule)""VALUES(:modele ,  :type , :matricule)");
query.bindValue(":modele",modele);
query.bindValue(":type",type);
query.bindValue(":matricule",res);

return query.exec();
}

QSqlQueryModel * transport::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("select * from transport");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("modele"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("matricule"));

return model;

}

bool transport::supprimer(int matriculee)
{
    QSqlQuery Query;
    QString res=QString::number(matriculee);
    Query.prepare("Delete from transport where matricule = :matricule"  );
    Query.bindValue(":matricule",res);
    return Query.exec();


}
bool  transport:: modifier(QString matriculee)
{
    QSqlQuery query;
    query.prepare("update transport set type=:type,modele=:modele where matricule=:matricule");
    query.bindValue(":matricule",matriculee);
    query.bindValue(":type",type);
    query.bindValue(":modele",modele);

    return    query.exec();
}




void transport::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select matricule from transport");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}
QSqlQueryModel *transport::chercher(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where matricule LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("modele"));


      return model;
  }
QSqlQueryModel *transport::chercher1(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where type LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("modele"));


      return model;
  }
QSqlQueryModel *transport::chercher2(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where modele LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("modele"));


      return model;
  }

