#include "connection.h"
#include <QSqlDatabase>
connection::connection()
{

}
bool connection::createConnection(){
   bool test=false;
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("projet");//inserer le nom de la source de données ODBC
   db.setUserName("xayah");
   db.setPassword("xayah");
   if(db.open())
test=true;
return test;
}
