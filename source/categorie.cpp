#include "categorie.h"

    Categorie::Categorie() {};
    Categorie::~Categorie(){};
    Categorie::Categorie(string nom, string description, Bibliotheque bibliotheque){
        this->nomCat = nom;
        this->descriptionCat = description;
        this->bibliothequeCat = bibliotheque;
    }

    void Categorie::printCat(){
        cout << nomCat << "(" << descriptionCat << ") de " << bibliothequeCat.getNomBiblio() << endl;
    }

    string Categorie::getNomCat() {
    	return nomCat;
    }
    void Categorie::setNomCat(string nom) {
    	this->nomCat = nom;
    }


    string Categorie::getDescriptionCat() {
    	return descriptionCat;
    }
    void Categorie::setDescriptionCat(string description) {
    	this->descriptionCat = description;
    }


    Bibliotheque Categorie::getBibliothequeCat() {
    	return bibliothequeCat;
    }
    void Categorie::setBibliothequeCat(Bibliotheque bibliotheque) {
    	this->bibliothequeCat = bibliotheque;
    }
