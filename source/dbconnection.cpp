#include "dbconnection.h"
#include "QDebug"


dbconnection::dbconnection()
{
}

dbconnection::~dbconnection(){

}

bool dbconnection::connectToDb(QSqlDatabase dbc){
    dbc = QSqlDatabase::addDatabase("QMYSQL");
    dbc.setHostName("localhost");
    dbc.setDatabaseName("glybook");
    dbc.setUserName("root");
    dbc.setPassword("");
    dbc.open();
    return dbc.isOpen();
}
