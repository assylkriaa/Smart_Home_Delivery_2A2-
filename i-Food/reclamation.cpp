#include "reclamation.h"

reclamation::reclamation()
{
    code="";
    sujet="";
    commentaire="";
    date_reclamation="";
}

reclamation::reclamation(QString c, QString s, QString co,QString d)
{
code = c;
sujet=s;
commentaire=co;
date_reclamation=d;
}

bool reclamation::ajouterecl()
{
    QSqlQuery qry;
    qry.prepare("insert into reclamation (code,sujet,commentaire,date_reclamation) values('"+code+"','"+sujet+"','"+commentaire+"','"+date_reclamation+"')");

return qry.exec();
}
QSqlQueryModel * reclamation::afficherecl()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reclamation");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("sujet"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("commentaire"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("date reclamation"));
    return model;
}
bool reclamation::supprimerecl(QString c)
{
    QSqlQuery qry;
    QString code=c;
    qry.prepare("Delete from reclamation where code='"+code+"'");
    return qry.exec();
}
bool reclamation::modifierecl(QString c,QString s,QString co,QString d)
{
    QSqlQuery qry;
    QString code=c;
    QString sujet=s;
    QString commentaire=co;
    QString date_reclamation=d;
    qry.prepare("update reclamation set code='"+code+"',sujet='"+sujet+"',commentaire='"+commentaire+"',date_reclamation='"+date_reclamation+"' where code='"+code+"' ");
    return qry.exec();
}
QSqlQueryModel * reclamation::trierecl()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reclamation order by code");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("sujet"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("commentaire"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("date reclamation"));
    return model;
}
QSqlQueryModel * reclamation::trierecl1()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reclamation order by sujet");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("sujet"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("commentaire"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("date reclamation"));
    return model;
}
QSqlQueryModel * reclamation::trierecl2()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from reclamation order by commentaire");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("sujet"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("commentaire"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("date reclamation"));
    return model;
}

