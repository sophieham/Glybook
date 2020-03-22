#pragma once
#include <ctime>
#include <iostream>
#include "livre.h"
#include "utilisateur.h"
#include <string>
#include <iterator>
#include <map>

using namespace std;

    class Emprunt {
    private:
        string datePretEmprunt;
        string dateRendreEmprunt;
        Adherent adherentEmprunt;
        Livre livreEmprunt;
        map<string, string> mapEmprunt;
        size_t compteur;
      
    public:
        Emprunt();
        ~Emprunt();
        Emprunt(Adherent, Livre);
        string getDateNow();
        string getDatePlusDays(int n);
        void printEmprunt();
        string getDatePretEmprunt();
        void setDatePretEmprunt(string);
        string getDateRendreEmprunt();
        void setDateRendreEmprunt(string);
        Adherent getAdherentEmprunt();
        void setAdherentEmprunt(Adherent);
        Livre getLivreEmprunt();
        void setLivreEmprunt(Livre);
        void afficherListe();
        size_t getOccurence();
        void afficherListe(Adherent a);
    };