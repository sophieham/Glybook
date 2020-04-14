#include "categorie.h"

    Categorie::Categorie() {};
    Categorie::~Categorie(){};
    Categorie::Categorie(const string &nom, const string &description, const Bibliotheque &bibliotheque){
        this->nom = nom;
        this->description = description;
        this->bibliotheque = bibliotheque;
    }

    void Categorie::print(){
        cout << nom << "(" << description << ") de " << bibliotheque.getNom() << endl;
    }

    string Categorie::getNom() const {
    	return nom;
    }
    void Categorie::setNom(const string &nom) {
    	this->nom = nom;
    }

    string Categorie::getDescription() const {
    	return description;
    }
    void Categorie::setDescription(const string &description) {
    	this->description = description;
    }

    Bibliotheque Categorie::getBibliotheque() const {
    	return bibliotheque;
    }
    void Categorie::setBibliotheque(const Bibliotheque &bibliotheque) {
    	this->bibliotheque = bibliotheque;
    }
