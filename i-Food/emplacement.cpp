#include "emplacement.h"


emplacement::emplacement()
{
    nom_secteur="";
    ville="";
    code_postal="";
    date_emplacement="";

}
emplacement::emplacement(QString n, QString v, QString c,QString d)
{
nom_secteur = n;
ville=v;
code_postal=c;
date_emplacement=d;
}

bool emplacement::ajouterempl()
{
    QSqlQuery qry;
    qry.prepare("insert into emplacement (nom_secteur,ville,code_postal,date_ajout) values('"+nom_secteur+"','"+ville+"','"+code_postal+"','"+date_emplacement+"')");

return qry.exec();
}

QSqlQueryModel * emplacement::afficherempl()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from emplacement");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Nom secteur"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("date Emplacement"));
    return model;
}

bool emplacement::supprimerempl(QString nom_sec)
{
    QSqlQuery qry;
    QString nom_secteur=nom_sec;
    qry.prepare("Delete from emplacement where nom_secteur='"+nom_secteur+"'");
    return qry.exec();
}

bool emplacement::modifierempl(QString nom_sec,QString v,QString c,QString d)
{
    QSqlQuery qry;
    QString nom_secteur=nom_sec;
    QString ville=v;
    QString code_postal=c;
    QString date_emplacement=d;
    qry.prepare("update emplacement set nom_secteur='"+nom_secteur+"',ville='"+ville+"',code_postal='"+code_postal+"',date_ajout='"+date_emplacement+"' where nom_secteur='"+nom_secteur+"' ");
    return qry.exec();
}

QSqlQueryModel * emplacement::trierempl()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from emplacement order by nom_secteur ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Nom secteur"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("date Emplacement"));
    return model;
}
QSqlQueryModel * emplacement::trierempl1()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from emplacement order by ville ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Nom secteur"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("date Emplacement"));
    return model;
}
QSqlQueryModel * emplacement::trierempl2()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from emplacement order by code_postal ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Nom secteur"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("date Emplacement"));
    return model;
}
