#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class emplacement
{

private:
   QString  nom_secteur;
   QString  ville;
   QString  code_postal;
   QString  date_emplacement;
public:
    emplacement();
    emplacement(QString,QString,QString,QString);
   QString getnom_secteur(){return nom_secteur;};
   QString get_ville(){return ville;};
   QString getcode_postal(){return code_postal;};
   QString getdate_emplacement(){return date_emplacement;};

   bool ajouterempl();
   QSqlQueryModel * afficherempl();
   bool supprimerempl(QString);
bool modifierempl(QString,QString,QString,QString);
QSqlQueryModel *trierempl();

};

#endif // EMPLACEMENT_H
