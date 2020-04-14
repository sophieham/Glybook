#pragma once
#include <iostream>
#include <string>
#include "categorie.h"
#include <vector>
#include <sstream>
using namespace std;

    class Livre {
    private:
        string nom, auteur, editeur, resume, isbn;
        bool libre;
        Categorie cat;
        size_t compteur;
        vector<string> liste;


    public:
        Livre();
        ~Livre();
        Livre(const string&, const string&, const string&, const string&, const string&, const Categorie&);
        void printLivre() const;
        string getNom() const;
        void setNom(const string&);
        string getAuteur() const;
        void setAuteur(const string&);
        string getEditeur() const;
        void setEditeur(const string&);
        string getResume() const;
        void setResume(const string&);
        string getIsbn() const;
        void setIsbn(const string&);
        bool getLibre() const;
        void setLibre(const bool&);
        Categorie getCat() const;
        void setCat(const Categorie&);
        size_t getOccurence();
        void afficherListe();
        friend std::ostream& operator<<(std::ostream& out, Livre l);
        static string to_string(const Livre &l);
    };