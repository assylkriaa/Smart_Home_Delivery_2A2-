#ifndef FACTURE_H
#define FACTURE_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>


class facture
{

private:
    int id;
    QString date  ;
    QString montant;
    QString source;
    QString mode;
public:
    facture();
    facture(int,QString,QString,QString,QString);
    int get_id(){return id;};
    QString get_date(){return date;};
    QString get_montant(){return montant;};
    QString get_source(){return source;};
    QString get_mode(){return mode;};

    bool ajouter_facture();
    QSqlQueryModel * afficher();
    bool supprimer_facture(int);
    bool modifier(int);


};

#endif // FACTURE_H
