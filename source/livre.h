#pragma once
#include <iostream>
#include <string>
#include "categorie.cpp"
using namespace std;

namespace {
    class Livre {
    private:
        string nom, auteur, editeur, resume, isbn;
        bool libre;
        Categorie cat;

    public:
        Livre();
        ~Livre();
        Livre(string nom, string auteur, string editeur, string resume, string isbn, Categorie cat);
        void print();
        string getNom();
        void setNom(string nom);
        string getAuteur();
        void setAuteur(string auteur);
        string getEditeur();
        void setEditeur(string editeur);
        string getResume();
        void setResume(string resume);
        string getIsbn();
        void setIsbn(string isbn);
        bool getLibre();
        void setLibre(bool emprunt);
        Categorie getCat();
        void setCat(Categorie cat);

    };
}