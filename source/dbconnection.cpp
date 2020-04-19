#include "dbconnection.h"
#include "QDebug"


dbconnection::dbconnection(){
}

dbconnection::~dbconnection(){

}

// connecte a la base de donn�e
// renvoit l'etat de la connection
bool dbconnection::connectToDb(QSqlDatabase dbc){
    dbc = QSqlDatabase::addDatabase("QMYSQL");
    dbc.setHostName("localhost");
    dbc.setDatabaseName("glybook");
    dbc.setUserName("root");
    dbc.setPassword("");
    dbc.open();
    return dbc.isOpen();
}

// supprime une connection donn�e
void dbconnection::deleteConnection(QSqlDatabase db){
    db.removeDatabase(db.connectionName());
}
