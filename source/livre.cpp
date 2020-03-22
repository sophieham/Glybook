#include "livre.h"

Livre::Livre(){
        nomLivre = "";
        auteurLivre = "";
        editeurLivre = "";
        resumeLivre = "";
        isbnLivre = "";
        libre = true;
        compteur = 0;
    }
    Livre::~Livre() {};

    Livre::Livre(string nom, string auteur, string editeur, string resume, string isbn, Categorie cat){
        nomLivre = nom;
        auteurLivre = auteur;
        editeurLivre = editeur;
        resumeLivre = resume;
        isbnLivre = isbn;
        catLivre = cat;
        libre = true;
        static size_t compte;
        ++compte;
        Livre::compteur = compte;
        static vector<string> listeLivres;
        string concat;
        if (!(nom == "" || auteur == "" | editeur == "")) {
            concat = nom + " - " + auteur + " - " + editeur + "\n";
        }
        listeLivres.push_back(concat);
        Livre::liste = listeLivres;

    }

    // affiche les données du livre
    void Livre::printLivre() {
        cout << nomLivre << " de " << auteurLivre << " paru chez " << editeurLivre << " (ISBN: " << isbnLivre << ") Type: " << catLivre.getNomCat() << endl
        << "Appartient a la bibliotheque " << catLivre.getBibliothequeCat().getNomBiblio() << endl << "Resume: " << resumeLivre << endl;
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
    string Livre::getNomLivre() {
	    return nomLivre;
    }
    void Livre::setNomLivre(string nom) {
	    this->nomLivre = nom;
    }

    // auteur
    string Livre::getAuteurLivre() {
    	return auteurLivre;
    }
    void Livre::setAuteurLivre(string auteur) {
    	this->auteurLivre = auteur;
    }

    // editeur
    string Livre::getEditeurLivre() {
    	return editeurLivre;
    }
    void Livre::setEditeurLivre(string editeur) {
    	this->editeurLivre = editeur;
    }

    // resume
    string Livre::getResumeLivre() {
    	return resumeLivre;
    }
    void Livre::setResumeLivre(string resume) {
    	this->resumeLivre = resume;
    }

    // isbn (identifiant unique d'un livre)
    string Livre::getIsbnLivre() {
    	return isbnLivre;
    }
    void Livre::setIsbnLivre(string isbn) {
    	this->isbnLivre = isbn;
    }

    // son état (si il est emprunté ou non)
    bool Livre::getLibre(){
        if(libre == 1)
            return "Le livre est disponible a l'emprunt!";
        else return "Le livre n est actuellement pas disponible.";
    }
    void Livre::setLibre(bool emprunt){
        libre = emprunt;
    }

    // son genre
    Categorie Livre::getCatLivre() {
    	return catLivre;
    }
    void Livre::setCatLivre(Categorie cat) {
    	catLivre = cat;
    }
     
    // le nombre de fois où la classe a été instanciée
    size_t Livre::getOccurence() {
        return Livre::compteur;
    }

    // rédéfinition de l'affichage de l'objet
    ostream& operator<<(ostream& out, Livre l)
    {
        out << l.getNomLivre() << " (" << l.getAuteurLivre() << " - " << l.getIsbnLivre() << ")";
        return out;
    }

    // pour pouvoir l'afficher dans une chaine de caractère
    string Livre::to_string(Livre l)
    {
        ostringstream ss;
        ss << l;
        return ss.str();
    }