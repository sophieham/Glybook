#include "utilisateur.h"


Utilisateur::Utilisateur() {
    type = 0;
};
Utilisateur::~Utilisateur() {};
Utilisateur::Utilisateur(QString firstName, QString lastName, int type){
    this->firstName = firstName;
    this->lastName = lastName;
    this->type = type;
}

QString Utilisateur::getFirstName() const{
    return firstName;
}

QString Utilisateur::getLastName() const{
    return lastName;
}

int Utilisateur::getType() const{
    return type;
}

void Utilisateur::setType(int t){
    this->type = t;
}


Administrateur::Administrateur(QString firstName, QString lastName, QString username, QString password) : Utilisateur::Utilisateur(firstName, lastName, 1)
{

        user = username,
        pass = password;

    QString("Bienvenue " + firstName + "! Vous etes administrateur.");
}

Administrateur::~Administrateur() {}


QString Administrateur::getUser() const
{
    return user;
}

QString Administrateur::getPswd() const
{
    return pass;
}

void Administrateur::setUser(const QString user)
{
    this->user = user;
}

void Administrateur::setPswd(const QString pass)
{
    this->pass = pass;
}

QString Administrateur::print()
{
   return QString( user + " " + pass);
}


// implémenter un code de compte (numéro de téléphone) a changer ou pas par l'adherent
Adherent::Adherent() {
    maxBooks = 0;
    address = "";
}
Adherent::~Adherent() {};
Adherent::Adherent(QString firstName, QString lastName, QString address, QString phone, short maxBooks) : Utilisateur(firstName, lastName, 2)
{

    this->address = address;
    this->phone = phone;
    this->maxBooks = maxBooks;
}
QString Adherent::print() {
   return QString( "address: " + getAddress() + "Numero: " + getPhoneNo()+
        "Vous pouvez emprunter jusqu'à " + getMaxBooks() + " livres." );
}


// address
QString Adherent::getAddress() const {
    return address;
}
void Adherent::setAddress(QString address) {
    this->address = address;
}

// numero de telephone
QString Adherent::getPhoneNo() const {
    return phone;
}
void Adherent::setPhoneNo(QString phone) {
    this->phone = phone;
}


// retourne le nombre de livre max que l'adherent peut emprunter
short Adherent::getMaxBooks() const {
    return maxBooks;
}
void Adherent::setMaxBooks(short maxBooks) {
    this->maxBooks = maxBooks;
}



