#include "livre.h"

Livre::Livre(){
    nom, auteur, editeur, resume, isbn = "";
    libre = true;
    compteur = 0;
}
    Livre::~Livre() {};

    Livre::Livre(const string &nom, const string &auteur, const string &editeur, const string &resume, const string &isbn, const Categorie &cat){
        this->nom = nom;
        this->auteur = auteur;
        this->editeur = editeur;
        this->resume = resume;
        this->isbn = isbn;
        this->cat = cat;
        libre = true;
        static size_t compte;
        ++compte;
        Livre::compteur = compte;
        static vector<string> listeLivres;
        // additionne le nom, l'auteur et l'éditeur dans un string
        string concat;
        if (!(nom == "" || auteur == "" | editeur == "")) {
            concat = nom + " - " + auteur + " - " + editeur + "\n";
        }
        // puis l'ajoute a la liste des livres
        listeLivres.push_back(concat);
        Livre::liste = listeLivres;

    }

    // affiche les données du livre
    void Livre::printLivre() const {
        cout << nom << " de " << auteur << " paru chez " << editeur << " (ISBN: " << isbn << ") Type: " << cat.getNom() << endl
        << "Appartient a la bibliotheque " << cat.getBibliotheque().getNom() << endl << "Resume: " << resume << endl;
    }

    // affiche la liste des livres possédés par la bibliotheque (empruntés ou non)
    void Livre::afficherListe() {
        cout << "---------------- Liste de tous les livres que possède la bibliothèque" << endl;
        for (size_t i = 0; i < liste.size(); i++)
        {
            cout << liste.at(i);
        }
    }

    // nom du livre
    string Livre::getNom() const {
	    return nom;
    }
    void Livre::setNom(const string &nom) {
	    this->nom = nom;
    }

    // auteur
    string Livre::getAuteur() const {
    	return auteur;
    }
    void Livre::setAuteur(const string &auteur) {
    	this->auteur = auteur;
    }

    // editeur
    string Livre::getEditeur() const {
    	return editeur;
    }
    void Livre::setEditeur(const string &editeur) {
    	this->editeur = editeur;
    }

    // resume
    string Livre::getResume() const {
    	return resume;
    }
    void Livre::setResume(const string &resume) {
    	this->resume = resume;
    }

    // isbn (identifiant unique d'un livre)
    string Livre::getIsbn() const {
    	return isbn;
    }
    void Livre::setIsbn(const string &isbn) {
    	this->isbn = isbn;
    }

    // son état (si il est emprunté ou non)
    bool Livre::getLibre() const {
        if(libre == 1)
            return "Le livre est disponible a l'emprunt!";
        else return "Le livre n est actuellement pas disponible.";
    }
    void Livre::setLibre(const bool &emprunt){
        libre = emprunt;
    }

    // son genre
    Categorie Livre::getCat() const {
    	return cat;
    }
    void Livre::setCat(const Categorie &cat) {
    	this->cat = cat;
    }
     
    // le nombre de fois où la classe a été instanciée
    size_t Livre::getOccurence() {
        return Livre::compteur;
    }

    // rédéfinition de l'affichage de l'objet
    ostream& operator<<(ostream& out, Livre l)
    {
        out << l.getNom() << " (" << l.getAuteur() << " - " << l.getIsbn() << ")";
        return out;
    }

    // pour pouvoir l'afficher dans une chaine de caractère
    string Livre::to_string(const Livre &l)
    {
        ostringstream ss;
        ss << l;
        return ss.str();
    }