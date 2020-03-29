#include "categorie.h"

    Categorie::Categorie() {};
    Categorie::~Categorie(){};
    Categorie::Categorie(QString nom, QString description, Bibliotheque bibliotheque){
        this->nom = nom;
        this->description = description;
        this->bibliotheque = bibliotheque;
    }

    void Categorie::printCat(){
        QString(nom+ "(" +description + ") de " + bibliotheque.getNomBiblio());
    }

    QString Categorie::getNom() const{
        return nom;
    }
    void Categorie::setNom(QString nom) {
        this->nom = nom;
    }


    QString Categorie::getDescription() const {
        return description;
    }
    void Categorie::setDescription(QString description) {
        this->description = description;
    }


    Bibliotheque Categorie::getBibliotheque() const{
        return bibliotheque;
    }
    void Categorie::setBibliotheque(Bibliotheque bibliotheque) {
        this->bibliotheque = bibliotheque;
    }
