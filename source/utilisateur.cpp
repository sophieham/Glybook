#include "utilisateur.h"


Utilisateur::Utilisateur() {
    type = 0;
};
Utilisateur::~Utilisateur() {};
Utilisateur::Utilisateur(const string &nom, const string &prenom, int type){
    this->nom = nom;
    this->prenom = prenom;
    this->type = type;
}

string Utilisateur::getNom() const {
    return nom;
}

void Utilisateur::setNom(const string& nom) {
    this->nom = nom;
}

string Utilisateur::getPrenom() const {
    return prenom;
}

void Utilisateur::setPrenom(const string& prenom) {
    this->prenom = prenom;
}

int Utilisateur::getType(){
    return type;
}

void Utilisateur::setType(int t){
    this->type = t;
}


Administrateur::Administrateur(const string &nom, const string &prenom, const string &identifiant, const string &pass) : Utilisateur::Utilisateur(nom, prenom, 1)
{
    this->identifiant = identifiant,
    this->pass = pass;

    cout << "Bienvenue " << prenom << "! Vous etes administrateur." << endl;
}

Administrateur::~Administrateur() {}

string Administrateur::getIdentifiant() const
{
    return identifiant;
}

string Administrateur::getPass() const
{
    return pass;
}

void Administrateur::setIdentifiant(const string &identifiant)
{
    this->identifiant = identifiant;
}

void Administrateur::setPass(const string &pass)
{
    this->pass = pass;
}

void Administrateur::print()
{
    cout << identifiant << " " << pass << endl;
}


Abonne::Abonne() {
    nbLivreMax = 0;
    adresse = "";
}
Abonne::~Abonne() {};
Abonne::Abonne(const string &nom, const string &prenom, const string &adresse, const string &numtel, short nbLivreMax) : Utilisateur(nom, prenom, 2)
{

    this->adresse = adresse;
    this->numtel = numtel;
    this->nbLivreMax = nbLivreMax;
}
void Abonne::print() {
    cout << "Adresse: " << getAdresse() << endl << "Numero: " << getNumTel() << endl <<
        "Vous pouvez emprunter jusqu'à " << getNbLivreMax() << " livres." << endl;
}


// adresse
string Abonne::getAdresse() const {
    return adresse;
}
void Abonne::setAdresse(const string &adresse) {
    this->adresse = adresse;
}

// numero de telephone
string Abonne::getNumTel() const {
    return numtel;
}
void Abonne::setNumTel(const string &numtel) {
    this->numtel = numtel;
}


// retourne le nombre de livre max que l'abonné peut réserver
short Abonne::getNbLivreMax() {
    return nbLivreMax;
}
void Abonne::setNbLivreMax(short nbLivreMax) {
    this->nbLivreMax = nbLivreMax;
}



