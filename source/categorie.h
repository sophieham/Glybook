#pragma once
#include <iostream>
#include <string>
#include "bibliotheque.cpp"
using namespace std;

namespace{
    class Categorie {
    private:
        string nom;
        string description;
        Bibliotheque bibliotheque;
    public:
        Categorie();
        ~Categorie();
        Categorie(string nom, string description, Bibliotheque bibliotheque);
        void print();
        string getNom();
        void setNom(string nom);
        string getDescription();
        void setDescription(string getDescription);
        Bibliotheque getBibliotheque();
        void setBibliotheque(Bibliotheque bibliotheque);

    };
}