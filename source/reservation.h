#pragma once
#include <ctime>
#include <iostream>
#include "livre.h"
#include "utilisateur.h"
#include <string>
#include <iterator>
#include <map>

using namespace std;

    class Reservation {
    private:
        string dateDebut;
        string dateFin;
        Abonne abonne;
        Livre livre;
        map<string, string> mapReservation;
        size_t compteur;
      
    public:
        Reservation();
        ~Reservation();
        Reservation(Abonne, Livre);
        string getDateNow() const;
        string getDatePlusDays(int n);
        void print();
        string getDateDebut() const;
        void setDateDebut(const string&);
        string getDateFin() const;
        void setDateFin(const string&);
        Abonne getAbonne() const;
        void setAbonne(const Abonne&);
        Livre getLivre() const;
        void setLivre(const Livre&);
        void afficherListe() const;
        size_t getOccurence();
        void afficherListe(Abonne &);
    };