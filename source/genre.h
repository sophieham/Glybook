#pragma once
#include <iostream>
#include "library.h"
using namespace std;


    class Genre {
    private:
        QString name;
        QString description;
        Library library;
    public:
        Genre();
        ~Genre();
        Genre(QString, QString, Library);
        Genre(QString nom);
        void print();
        QString getName() const;
        void setName(QString const);
        QString getDescription() const;
        void setDescription(QString const);
        Library getLibrary() const;
        void setLibrary(Library const);

    };
