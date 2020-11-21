#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QString>
#include <QSql>
#include <QSqlDatabase>

class dbconnection
{
public:
    dbconnection();
    ~dbconnection();

    bool connectToDb(QSqlDatabase);
    void deleteConnection(QSqlDatabase);

private:

};

#endif // DBCONNECTION_H
