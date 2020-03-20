#include "bibliotheque.h"

    Bibliotheque::Bibliotheque(){};
    Bibliotheque::~Bibliotheque() {};
    Bibliotheque::Bibliotheque(string nom, string type, string adresse){
        this->nom = nom;
        this->adresse = adresse;
        if (type=="municipale" || "mediatheque" || "universitaire"){
            this->type = type;
        }
        else this->type = "inconnu";
    }

    void Bibliotheque::print(){
        cout << "Bibliotheque (" << getType() << ") " << getNom() << " situee " << getAdresse() << endl;
    }
    string Bibliotheque::getNom(){
        return nom;
    }

    string Bibliotheque::getAdresse(){
        return adresse;
    }

    string Bibliotheque::getType(){
        return type;
    }
