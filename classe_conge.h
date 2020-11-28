#ifndef CLASSE_CONGE_H
#define CLASSE_CONGE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class classe_conge
{
public:
    classe_conge();

    classe_conge(QString,QString,QString,QString);
    QString get_nom(){return nom;}
    QString get_date_debut(){return date_debut;}
    QString get_duree(){return duree;}
    QString get_idc(){return idc;}
    bool ajouter_conge();
    bool supprimer_conge(QString);
    bool modifier_conge(QString);
    QSqlQueryModel *afficher_conge();
    QSqlQueryModel *tri_id_conge();
    QSqlQueryModel *tri_nom_conge();
    QSqlQueryModel *tri_prenom_conge();
    QSqlQueryModel *recherche_id_conge(QString );
    QSqlQueryModel *recherche_nom_conge(QString );
     QSqlQueryModel *recherche_date_conge(QString );


private:
    QString nom,date_debut,duree;
    QString idc;
};

#endif // CLASSE_CONGE_H
