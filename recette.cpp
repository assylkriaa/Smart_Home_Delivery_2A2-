#include "recette.h"

recette::recette()
{
     id=0;
     date="";
     montant="";
     source="";

}
recette::recette(int i,QString d,QString m,QString s) {
    id=i;
    date=d;
    montant=m;
    source=s;

}

bool recette::ajouter_recette() {
    QSqlQuery qry;
    QString ids=QString::number(id);
    qry.prepare("insert into recette (ID_R,DATE_R,MONTANT_R,SOURCE_R)" "values(:id,:date,:montant,:source)" );
    qry.bindValue(":id",ids);
    qry.bindValue(":date",date);
    qry.bindValue(":montant",montant);
    qry.bindValue(":source",source);
 return qry.exec();
}
QSqlQueryModel * recette::afficher(){
    QSqlQueryModel * modal=new QSqlQueryModel();
    modal->setQuery("select * from recette");
    modal->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    modal->setHeaderData(1,Qt::Horizontal, QObject::tr("Date"));
    modal->setHeaderData(2,Qt::Horizontal, QObject::tr("Montant"));
    modal->setHeaderData(3,Qt::Horizontal, QObject::tr("Depense"));
    return modal;
}
bool recette::supprimer_recette(int selected2){

    QSqlQuery query;
    query.prepare("Delete from RECETTE where ID_R = :sele ");
    query.bindValue(":sele", selected2);
    return query.exec();



}
bool recette::modifier_recette(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE RECETTE SET DATE_R= :date ,MONTANT_R= :montant,SOURCE_R= :source ,where ID_R= :id");
    query.bindValue(":id", selected);
    query.bindValue(":date",date); //remplir la valeur d'une maniere securisée
    query.bindValue(":montant",montant);
    query.bindValue(":source", source);

    return    query.exec();

}

