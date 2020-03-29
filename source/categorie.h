#pragma once
#include <iostream>
#include "bibliotheque.h"
using namespace std;


    class Categorie {
    private:
        QString nom;
        QString description;
        Bibliotheque bibliotheque;
    public:
        Categorie();
        ~Categorie();
        Categorie(QString, QString, Bibliotheque);
        void printCat();
        QString getNom() const;
        void setNom(QString const);
        QString getDescription() const;
        void setDescription(QString const);
        Bibliotheque getBibliotheque() const;
        void setBibliotheque(Bibliotheque const);

    };
