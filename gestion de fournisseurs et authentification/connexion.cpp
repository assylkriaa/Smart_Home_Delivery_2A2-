#include "connexion.h"
#include "QSqlDatabase"
connexion::connexion()
{

}

bool connexion::createConnection()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("chayma");
    db.setPassword("system");

    if (db.open())
        test=true;



    return test;
}
