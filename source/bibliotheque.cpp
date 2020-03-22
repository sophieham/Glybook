#include "bibliotheque.h"

    Bibliotheque::Bibliotheque(){};
    Bibliotheque::~Bibliotheque() {};
    Bibliotheque::Bibliotheque(string nom, string type, string adresse){
        this->nomBiblio = nom;
        this->adresseBiblio = adresse;
        if (type=="municipale" || "mediatheque" || "universitaire"){
            this->typeBiblio = type;
        }
        else this->typeBiblio = "inconnu";
    }

    void Bibliotheque::printBiblio(){
        cout << "Bibliotheque (" << getTypeBiblio() << ") " << getNomBiblio() << " situee " << getAdresseBiblio() << endl;
    }
    string Bibliotheque::getNomBiblio(){
        return nomBiblio;
    }

    string Bibliotheque::getAdresseBiblio(){
        return adresseBiblio;
    }

    string Bibliotheque::getTypeBiblio(){
        return typeBiblio;
    }
