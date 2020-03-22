#pragma once
#include <iostream>
#include <string>
#include "categorie.h"
#include <vector>
#include <sstream>
using namespace std;

    class Livre {
    private:
        string nomLivre, auteurLivre, editeurLivre, resumeLivre, isbnLivre;
        bool libre;
        Categorie catLivre;
        size_t compteur;
        vector<string> liste;


    public:
        Livre();
        ~Livre();
        Livre(string, string, string, string, string, Categorie);
        void printLivre();
        string getNomLivre();
        void setNomLivre(string);
        string getAuteurLivre();
        void setAuteurLivre(string);
        string getEditeurLivre();
        void setEditeurLivre(string);
        string getResumeLivre();
        void setResumeLivre(string);
        string getIsbnLivre();
        void setIsbnLivre(string);
        bool getLibre();
        void setLibre(bool);
        Categorie getCatLivre();
        void setCatLivre(Categorie);
        size_t getOccurence();
        void afficherListe();
        friend std::ostream& operator<<(std::ostream& out, Livre l);
        static string to_string(Livre l);
    };