#include "dbconnection.h"
#include "QDebug"


dbconnection::dbconnection(){
}

dbconnection::~dbconnection(){

}

// connecte a la base de donn�e
// renvoit l'etat de la connection
bool dbconnection::connectToDb(QSqlDatabase dbc){
    dbc = QSqlDatabase::addDatabase("QODBC");
    dbc.setDatabaseName("Mysql");
    dbc.setHostName("localhost");
    dbc.setUserName("root");
    dbc.setPort(3306);
    dbc.setPassword("");
    dbc.open();
    return dbc.isOpen();
}

// supprime une connection donn�e
void dbconnection::deleteConnection(QSqlDatabase db){
    db.removeDatabase(db.connectionName());
}
