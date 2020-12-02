#ifndef RECLAMATION_H
#define RECLAMATION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class reclamation
{
private:
   QString  code;
   QString  sujet;
   QString  commentaire;
   QString  date_reclamation;
public:
    reclamation();
    reclamation(QString,QString,QString,QString);
   QString getcode(){return code;};
   QString get_sujet(){return sujet;};
   QString get_commentaire(){return commentaire;};
   QString getdate_reclamation(){return date_reclamation;};

   bool ajouterecl();
   QSqlQueryModel * afficherecl();
   bool supprimerecl(QString);
   bool modifierecl(QString,QString,QString,QString);
   QSqlQueryModel * trierecl();
   QSqlQueryModel * trierecl1();
   QSqlQueryModel * trierecl2();




};

#endif // RECLAMATION_H
