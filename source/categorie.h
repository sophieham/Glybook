#pragma once
#include <iostream>
#include <string>
#include "bibliotheque.h"
using namespace std;


    class Categorie {
    private:
        string nom;
        string description;
        Bibliotheque bibliotheque;
    public:
        Categorie();
        ~Categorie();
        Categorie(const string &, const string &, const Bibliotheque &);
        void print();
        string getNom() const;
        void setNom(const string&);
        string getDescription() const;
        void setDescription(const string&);
        Bibliotheque getBibliotheque() const;
        void setBibliotheque(const Bibliotheque&);

    };