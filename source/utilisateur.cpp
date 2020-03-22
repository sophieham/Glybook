#include "utilisateur.h"


Utilisateur::Utilisateur() {
    typeUtilisateur = 0;
};
Utilisateur::~Utilisateur() {};
Utilisateur::Utilisateur(string nom, string prenom, int type){
    this->nomUtilisateur = nom;
    this->prenomUtilisateur = prenom;
    this->typeUtilisateur = type;
}

string Utilisateur::getNomUtilisateur(){
    return this->nomUtilisateur;
}

string Utilisateur::getPrenomUtilisateur(){
    return this->prenomUtilisateur;
}

int Utilisateur::getTypeUtilisateur(){
    return this->typeUtilisateur;
}

void Utilisateur::setTypeUtilisateur(int t){
    this->typeUtilisateur = t;
}

void Utilisateur::printUtilisateur(){
    cout << "Nom: " << nomUtilisateur << endl << "Prenom: " << prenomUtilisateur << endl << "Type de compte (1: admin, 2: adh): " << typeUtilisateur << endl;
}


Administrateur::Administrateur(string nom, string prenom, string username, string password)
: Utilisateur::Utilisateur(nom, prenom, 1), usernameAdmin(username), passwordAdmin(password)
{
    cout << "Bienvenue " << prenom << "! Vous etes administrateur." << endl;
}

Administrateur::~Administrateur(){}

void Administrateur::printAdmin(){
    this->Utilisateur::printUtilisateur();
    cout << "Username: " << usernameAdmin << endl << "Pass: " << passwordAdmin << endl;
}
    
string Administrateur::getUsernameAdmin() {
    return usernameAdmin;
}
void Administrateur::setUsernameAdmin(string username) {
    this->usernameAdmin = username;
}


string Administrateur::getPasswordAdmin() {
    return passwordAdmin;
}
void Administrateur::setPasswordAdmin(string password) {
    this->passwordAdmin = password;
}


// implémenter un code de compte (numéro de téléphone) a changer ou pas par l'adherent
Adherent::Adherent() {
        nbLivreMaxAdh = 0;
        Utilisateur::getNomUtilisateur() = "";
        Utilisateur::getPrenomUtilisateur() = "";
        this->adresseAdh = "";
    }
Adherent::~Adherent() {};
Adherent::Adherent(string nom, string prenom, string adresse, string numtel, short nbLivreMax)
: Utilisateur::Utilisateur(nom, prenom, 2), adresseAdh(adresse), numtelAdh(numtel), nbLivreMaxAdh(nbLivreMax)
{
}
void Adherent::print(){
    this->Utilisateur::printUtilisateur();
    cout << "Adresse: " << getAdresseAdh() << endl << "Numero: " << getNumTelAdh() << endl <<
    "Vous pouvez emprunter jusqu'à " << getNbLivreMaxAdh() << " livres." << endl;
}


// adresse
string Adherent::getAdresseAdh() {
	return this->adresseAdh;
}
void Adherent::setAdresseAdh(string adresse) {
	this->adresseAdh = adresse;
}

// numero de telephone
string Adherent::getNumTelAdh() {
    return this->numtelAdh;
}
void Adherent::setNumTelAdh(string numtel) {
    this->numtelAdh = numtel;
}


// retourne le nombre de livre max que l'adherent peut emprunter
short Adherent::getNbLivreMaxAdh() {
    return this->nbLivreMaxAdh;
}
void Adherent::setNbLivreMaxAdh(short nbLivreMax) {
    this->nbLivreMaxAdh = nbLivreMax;
}

