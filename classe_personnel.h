#ifndef CLASSE_PERSONNEL_H
#define CLASSE_PERSONNEL_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class classe_personnel
{
public:
    classe_personnel();
    classe_personnel(QString,QString,QString,QString);
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_adress(){return adress;}
    QString get_idp(){return idp;}
    bool ajouter_employe();
    bool supprimer_employe(QString);
    bool modifier_employe(QString);
    QSqlQueryModel *afficher_employe();
    QSqlQueryModel *afficher_employe_1(QString);
    QSqlQueryModel *tri_id_employe();
    QSqlQueryModel *tri_nom_employe();
    QSqlQueryModel *tri_prenom_employe();
    QSqlQueryModel *recherche_id_employe(QString );
    QSqlQueryModel *recherche_nom_employe(QString );
    QSqlQueryModel *recherche_prenom_employe(QString );
  // bool print_employee();
private:
    QString nom,prenom,adress;
    QString idp;
};

#endif // CLASSE_PERSONNEL_H
