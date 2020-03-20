#include "utilisateur.h"


Utilisateur::Utilisateur() {
    type = 0;
};
Utilisateur::~Utilisateur() {};
Utilisateur::Utilisateur(string nom, string prenom, int type){
    this->nom = nom;
    this->prenom = prenom;
    this->type = type;
}

string Utilisateur::getNom(){
    return this->nom;
}

string Utilisateur::getPrenom(){
    return this->prenom;
}

int Utilisateur::getType(){
    return this->type;
}

void Utilisateur::setType(int t){
    this->type = t;
}

void Utilisateur::print(){
    cout << "Nom: " << nom << endl << "Prenom: " << prenom << endl << "Type de compte (1: admin, 2: adh): " << type << endl;
}


Administrateur::Administrateur(string nom, string prenom, string username, string password)
: Utilisateur::Utilisateur(nom, prenom, 1), username(username), password(password)
{
    cout << "Bienvenue " << prenom << "! Vous etes administrateur." << endl;
}

Administrateur::~Administrateur(){}

void Administrateur::print(){
    this->Utilisateur::print();
    cout << "Username: " << username << endl << "Pass: " << password << endl;
}
    
string Administrateur::getUsername() {
    return this->username;
}
void Administrateur::setUsername(string username) {
    this->username = username;
}


string Administrateur::getPassword() {
    return this->password;
}
void Administrateur::setPassword(string password) {
    this->password = password;
}


// implémenter un code de compte (numéro de téléphone) a changer ou pas par l'adherent
Adherent::Adherent() {
        nbLivreMax = 0;
    }
Adherent::~Adherent() {};
Adherent::Adherent(string nom, string prenom, string adresse, string numtel, short nbLivreMax)
: Utilisateur::Utilisateur(nom, prenom, 2), adresse(adresse), numtel(numtel), nbLivreMax(nbLivreMax)
{
    cout << "Bienvenue " << getPrenom() << "! Vous etes adherent." << endl;
}
void Adherent::print(){
    this->Utilisateur::print();
    cout << "Adresse: " << getAdresse() << endl << "Numero: " << getNumTel() << endl << 
    "Vous pouvez emprunter jusqu'à " << getNbLivreMax() << " livres." << endl;
}

string Adherent::getAdresse() {
	return this->adresse;
}
void Adherent::setAdresse(string adresse) {
	this->adresse = adresse;
}

string Adherent::getNumTel() {
    return this->numtel;
}
void Adherent::setNumTel(string numtel) {
    this->numtel = numtel;
}


short Adherent::getNbLivreMax() {
    return this->nbLivreMax;
}
void Adherent::setNbLivreMax(short nbLivreMax) {
    this->nbLivreMax = nbLivreMax;
    cout << "nb livre modifie" << endl;
}


/*
// Adherent : membre + adresse, numero de téléphone
// admin : membre + pseudo, mdp
// Membre : typeCompte, nom, prenom

*/