#include "livre.h"

Livre::Livre(){
        nom = "";
        auteur = "";
        editeur = "";
        resume = "";
        isbn = "";
        libre = true;
    }
    Livre::~Livre() {};

    Livre::Livre(string nom, string auteur, string editeur, string resume, string isbn, Categorie cat){
        this->nom = nom;
        this->auteur = auteur;
        this->editeur = editeur;
        this->resume = resume;
        this->isbn = isbn;
        this->cat = cat;
        libre = true;
    }

    void Livre::print() {
        cout << nom << " de " << auteur << " paru chez " << editeur << " (ISBN: " << isbn << ") Type: " << cat.getNom() << endl 
        << "Appartient a la bibliotheque " << cat.getBibliotheque().getNom() << endl << "Resume: " << resume << endl;
    }

    string Livre::getNom() {
	    return nom;
    }
    void Livre::setNom(string nom) {
	    this->nom = nom;
    }


    string Livre::getAuteur() {
    	return auteur;
    }
    void Livre::setAuteur(string auteur) {
    	this->auteur = auteur;
    }


    string Livre::getEditeur() {
    	return editeur;
    }
    void Livre::setEditeur(string editeur) {
    	this->editeur = editeur;
    }


    string Livre::getResume() {
    	return resume;
    }
    void Livre::setResume(string resume) {
    	this->resume = resume;
    }


    string Livre::getIsbn() {
    	return isbn;
    }
    void Livre::setIsbn(string isbn) {
    	this->isbn = isbn;
    }


    bool Livre::getLibre(){
        if(this->libre == 1)
            return "Le livre est disponible a l'emprunt!";
        else return "Le livre n est actuellement pas disponible.";
    }
    void Livre::setLibre(bool emprunt){
        this->libre = emprunt;
    }


    Categorie Livre::getCat() {
    	return cat;
    }
    void Livre::setCat(Categorie cat) {
    	this->cat = cat;
    }
