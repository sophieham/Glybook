#include "bibliotheque.h"

    Bibliotheque::Bibliotheque(){};
    Bibliotheque::~Bibliotheque() {};
    Bibliotheque::Bibliotheque(QString nom, QString type, QString adresse){
        this->nomBiblio = nom;
        this->adresseBiblio = adresse;
        if (type=="municipale" || "mediatheque" || "universitaire"){
            this->typeBiblio = type;
        }
        else this->typeBiblio = "inconnu";

    }

    QString Bibliotheque::printBiblio() const{
        return("Bibliotheque (" + getTypeBiblio() + ") " + getNomBiblio() + " situee " + getAdresseBiblio());
    }
    void Bibliotheque::setAdresseBiblio(const QString adresse)
    {
        adresseBiblio = adresse;
    }
    QString Bibliotheque::getNomBiblio() const {
        return nomBiblio;
    }

    QString Bibliotheque::getAdresseBiblio() const {
        return adresseBiblio;
    }

    QString Bibliotheque::getTypeBiblio() const {
        return typeBiblio;
    }
