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

    Livre::Livre(QString nom, QString auteur, QString editeur, QString resume, QString isbn, Categorie cat){
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
        static QVector<QString> listeLivres;
        QString concat;
        if (!(nom == "" || auteur == "" | editeur == "")) {
            concat = nom + " - " + auteur + " - " + editeur + "\n";
        }
        listeLivres.push_back(concat);
        Livre::liste = listeLivres;

    }

    // affiche les données du livre
    void Livre::printLivre() {
        QString(nomLivre + " de " + auteurLivre + " paru chez " + editeurLivre + " (ISBN: " + isbnLivre + ") Type: " + catLivre.getNom()
        + "Appartient a la bibliotheque " + catLivre.getBibliotheque().getNomBiblio() + "Resume: " + resumeLivre);
    }

    // affiche la liste des livres possédés par la bibliotheque (empruntés ou non)
    void Livre::afficherListe() const{
        cout << "---------------- Liste de tous les livres que possède la bibliothèque" << endl;
        for (int i = 0; i < liste.size(); i++)
        {
            QString(liste.at(i));
        }
    }

    // nom du livre
    QString Livre::getNomLivre() const {
	    return nomLivre;
    }
    void Livre::setNomLivre(QString nom) {
	    this->nomLivre = nom;
    }

    // auteur
    QString Livre::getAuteurLivre() const {
    	return auteurLivre;
    }
    void Livre::setAuteurLivre(QString auteur){
    	this->auteurLivre = auteur;
    }

    // editeur
    QString Livre::getEditeurLivre() const {
    	return editeurLivre;
    }
    void Livre::setEditeurLivre(QString editeur) {
    	this->editeurLivre = editeur;
    }

    // resume
    QString Livre::getResumeLivre() const {
    	return resumeLivre;
    }
    void Livre::setResumeLivre(QString resume) {
    	this->resumeLivre = resume;
    }

    // isbn (identifiant unique d'un livre)
    QString Livre::getIsbnLivre() const {
    	return isbnLivre;
    }
    void Livre::setIsbnLivre(QString isbn) {
    	this->isbnLivre = isbn;
    }

    // son état (si il est emprunté ou non)
    bool Livre::getLibre() const{
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

    /*
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
    }*/
