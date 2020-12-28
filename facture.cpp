#include "facture.h"



facture::facture()
{
     id=0;
     date="";
     montant="";
     source="";
     mode="";
}
facture::facture(int i,QString d,QString m,QString s,QString mo) {
    id=i;
    date=d;
    montant=m;
    source=s;
    mode=mo;
}

bool facture::ajouter_facture() {
    QSqlQuery qry;
    QString ids=QString::number(id);
    qry.prepare("insert into facturee (ID,DATE_P,MONTANT,SOURCE,MODE_P)" "values(:id,:date,:montant,:source,:mode)" );
    qry.bindValue(":id",ids);
    qry.bindValue(":date",date);
    qry.bindValue(":montant",montant);
    qry.bindValue(":source",source);
    qry.bindValue(":mode",mode);
 return qry.exec();
}
QSqlQueryModel * facture::afficher(){
    QSqlQueryModel * modal=new QSqlQueryModel();
    modal->setQuery("select * from facturee");
    modal->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    modal->setHeaderData(1,Qt::Horizontal, QObject::tr("Date"));
    modal->setHeaderData(2,Qt::Horizontal, QObject::tr("Montant"));
    modal->setHeaderData(3,Qt::Horizontal, QObject::tr("Source"));
    modal->setHeaderData(4,Qt::Horizontal, QObject::tr("Mode de paiement"));
    return modal;
}
bool facture::supprimer_facture(int selected){

    QSqlQuery query;
    query.prepare("Delete from facturee where id = :sel ");
    query.bindValue(":sel", selected);
    return query.exec();

}

bool facture::modifier(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE FACTUREE SET DATE_P= :date ,MONTANT= :montant,SOURCE= :source ,  MODE_P= :mode where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":date",date); //remplir la valeur d'une maniere securisée
    query.bindValue(":montant",montant);
    query.bindValue(":source", source);
    query.bindValue(":mode", mode);

    return    query.exec();

}
