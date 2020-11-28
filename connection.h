#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
class connection
{
public:
    connection();
    bool createConnection();
};

#endif // CONNECTION_H
