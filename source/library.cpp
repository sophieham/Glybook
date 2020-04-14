#include "library.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

    Library::Library(){};
    Library::~Library() {};
    Library::Library(QString nom, QString type, QString adresse){
        this->name = nom;
        this->address = adresse;
        if (type=="community" || "bookshop" || "academic"){
            this->type = type;
        }
        else this->type = "inconnu";

    }

    QString Library::print() const{
        return("Library (" + getType() + ") " + getName() + " situee " + getAddress());
    }

    QString Library::getName() const {
        return name;
    }

    QString Library::getAddress() const {
        return address;
    }

    QString Library::getType() const {
        return type;
    }

    void Library::setName(const QString name)
    {
        this->name = name;
    }

    void Library::setType(const QString type)
    {
        this->type = type;
    }

    void Library::setAddress(const QString address)
    {
        this->address = address;
    }
