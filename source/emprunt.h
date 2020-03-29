#pragma once
#include <ctime>
#include <iostream>
#include "livre.h"
#include "utilisateur.h"
#include <iterator>
//#include <QMap>

using namespace std;

    class Emprunt {
    private:
        QString datePret;
        QString dateRendre;
        Adherent adherent;
        Livre livreEmprunt;
        //QMap<Livre, QString> mapEmprunt;
        size_t compteur;
      
    public:
        Emprunt();
        ~Emprunt();
        Emprunt(Adherent, Livre);
        QString getDateNow();
        QString getDatePlusDays(int n);
        void printEmprunt();
        QString getDatePret() const;
        void setDatePret(QString const);
        QString getDateRendre() const;
        void setDateRendre(QString const);
        Adherent getAdherent() const;
        void setAdherent(Adherent const);
        Livre getLivreEmprunt() const;
        void setLivreEmprunt(Livre const);
        void afficherListe() const;
        size_t getOccurence() const;
        void afficherListe(Adherent const);
    };
