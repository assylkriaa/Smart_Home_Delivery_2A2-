#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class fournisseurs
{
private:
    QString Nom;
    QString Adresse;
    QString Email;
    QString Numero;
    QString Type;

public:
fournisseurs();
fournisseurs(QString N,QString A,QString E,QString Nu,QString T):Nom(N),Adresse(A),Email(E),Numero(Nu),Type(T){};
bool ajouter();
bool supprimer(QString);
QSqlQueryModel * afficher();
QSqlQueryModel* recherche(QString);
bool modifier(QString,QString,QString,QString,QString);
};

#endif // FOURNISSEURS_H
