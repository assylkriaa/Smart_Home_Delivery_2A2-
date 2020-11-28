#include "connexion.h"
#include"QSqlDatabase"
connexion::connexion()
{

}
bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("karmandi");//inserer nom de l'utilisateur
db.setPassword("mimo1999");//inserer mot de passe de cet utilisateur

if (db.open())
  {test=true;}

    return  test;
}
