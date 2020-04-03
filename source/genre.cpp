#include "genre.h"

    Genre::Genre() {};
    Genre::~Genre(){};
    Genre::Genre(QString name, QString description, Library library){
        this->name = name;
        this->description = description;
        this->library = library;
    }
    Genre::Genre(QString name){
        this->name = name;
    }

    void Genre::print(){
        QString(name+ "(" +description + ") de " + library.getName());
    }

    QString Genre::getName() const{
        return name;
    }
    void Genre::setName(QString name) {
        this->name = name;
    }


    QString Genre::getDescription() const {
        return description;
    }
    void Genre::setDescription(QString description) {
        this->description = description;
    }


    Library Genre::getLibrary() const{
        return library;
    }
    void Genre::setLibrary(Library library) {
        this->library = library;
    }
