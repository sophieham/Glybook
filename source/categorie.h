#pragma once
#include <iostream>
#include <string>
#include "bibliotheque.h"
using namespace std;


    class Categorie {
    private:
        string nomCat;
        string descriptionCat;
        Bibliotheque bibliothequeCat;
    public:
        Categorie();
        ~Categorie();
        Categorie(string, string, Bibliotheque);
        void printCat();
        string getNomCat();
        void setNomCat(string);
        string getDescriptionCat();
        void setDescriptionCat(string);
        Bibliotheque getBibliothequeCat();
        void setBibliothequeCat(Bibliotheque);

    };