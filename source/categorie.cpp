#include "categorie.h"

    Categorie::Categorie() {};
    Categorie::~Categorie(){};
    Categorie::Categorie(string nom, string description, Bibliotheque bibliotheque){
        this->nom = nom;
        this->description = description;
        this->bibliotheque = bibliotheque;
    }

    void Categorie::print(){
        cout << nom << "(" << description << ") de " << bibliotheque.getNom() << endl;
    }

    string Categorie::getNom() {
    	return nom;
    }
    void Categorie::setNom(string nom) {
    	this->nom = nom;
    }


    string Categorie::getDescription() {
    	return description;
    }
    void Categorie::setDescription(string description) {
    	this->description = description;
    }


    Bibliotheque Categorie::getBibliotheque() {
    	return bibliotheque;
    }
    void Categorie::setBibliotheque(Bibliotheque bibliotheque) {
    	this->bibliotheque = bibliotheque;
    }
