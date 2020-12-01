#include "materiel.h"
#include "logistique.h"
#include "ui_logistique.h"
#include <QApplication>
#include <QMessageBox>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTextStream>
#include "qcustomplot.h"
#include <QFileDialog>
materiel::materiel()
{

}
materiel::materiel (int r,QString t,int c)
{
reference=r;
type=t;
code=c;
}
void materiel:: settype(QString t)
{
type=t;
}
void materiel:: setcode(int c)
{
code=c;
}
bool materiel::ajouter()
{
    QSqlQuery query;
    QString ref= QString::number(reference);
    QString co= QString::number(code);
query.prepare("INSERT INTO materiel(reference,type,code)""VALUES(:reference ,  :type , :code)");
query.bindValue(":reference",ref);
query.bindValue(":type",type);
query.bindValue(":code",co);

return query.exec();
}
QSqlQueryModel * materiel::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("select * from materiel");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));

return model;

}
bool materiel::supprimer(int reff)
{
    QSqlQuery Query;
    QString ref=QString::number(reff);
    Query.prepare("Delete from materiel where reference = :reference"  );
    Query.bindValue(":reference",ref);
    return Query.exec();


}
bool  materiel:: modifier(QString ref)
{
    QSqlQuery query;
    query.prepare("update materiel set type=:type,modele=:modele where reference=:reference");
    query.bindValue(":reference",ref);
    query.bindValue(":type",type);
    query.bindValue(":code",code);

    return    query.exec();
}

QSqlQueryModel *materiel::chercher(int txt)
  {
    QString t= QString::number(txt);
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where reference LIKE '"+t+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));


      return model;
  }
QSqlQueryModel *materiel::chercher1(int txt)
  {
    QString t= QString::number(txt);
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where code LIKE '"+t+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));


      return model;
  }

QSqlQueryModel *materiel::chercher2(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where type LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));

      return model;
  }

QSqlQueryModel *materiel::chercher3(QString txt,int r)
  {
        QString ref= QString::number(r);
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where type LIKE '"+txt+"' and reference = '"+ref+"' " );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));


      return model;
  }
QSqlQueryModel *materiel::chercher4(QString txt1,int txt)
  {
      QString c= QString::number(txt);
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where type LIKE '"+txt1+"' and code = '"+c+"' " );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));


      return model;
  }
QSqlQueryModel *materiel::chercher5(int r,int txt)
  {
      QString ref= QString::number(r);
      QString c= QString::number(txt);
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from materiel where refrence LIKE '"+ref+"' and code = '"+txt+"' " );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));


      return model;
  }
QSqlQueryModel *materiel::chercher6(int r,QString txt1,int txt)
  {

    QString ref= QString::number(r);
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from materiel where reference LIKE '"+ref+"'and type= '"+txt1+"'and co = '"+txt+"' " );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));


    return model;
  }
