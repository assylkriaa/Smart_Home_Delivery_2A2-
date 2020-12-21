#ifndef RECETTE_H
#define RECETTE_H
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>

class recette
{

private:
    int id;
    QString date  ;
    QString montant;
    QString source;

public:
    recette();
    recette(int,QString,QString,QString);
    int get_id(){return id;};
    QString get_date(){return date;};
    QString get_montant(){return montant;};
    QString get_source(){return source;};

    bool ajouter_recette();
    QSqlQueryModel * afficher();
    bool supprimer_recette(int);
    bool modifier_recette(int);



};
#endif // RECETTE_H
