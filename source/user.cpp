#include "user.h"
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

User::User() {
};
User::~User() {
    bLimit=0;
}

//Administrator
User::User(QString user, QString pass, QString lName, QString fName, short type)
{
    this->user = user;
    this->pass = pass;
    lastName = lName;
    firstName = fName;
    this->type = type;
    address = "";
    phone = "";
    bLimit = 0;

}

//Subscriber
User::User(QString user, QString pass, QString lName, QString fName, short type, QString address, QString phone, int *bLimit)
{
    this->user = user;
    this->pass = pass;
    lastName = lName;
    firstName = fName;
    this->type = type;
    this->address = address;
    this->phone = phone;
    this->bLimit = *bLimit;

};

//***** Getters & setters

// nom d'utilisateur
QString User::getUser() const
{
    return user;
}

void User::setUser(const QString user)
{
    this->user = user;
}

// mot de passe
QString User::getPswd() const
{
    return pass;
}

void User::setPswd(const QString pass)
{
    this->pass = pass;
}

// prénom
QString User::getFirstName() const{
    return firstName;
}

void User::setFirstName(const QString firstName)
{
    this->firstName = firstName;
}

// nom
QString User::getLastName() const{
    return lastName;
}

void User::setLastName(const QString lastName)
{
    this->lastName = lastName;
}

// type de compte (admin=1, abonné=0)
short User::getType() const{
    return type;
}

void User::setType(short t){
    this->type = t;
}

// adresse
QString User::getAddress() const {
    return address;
}
void User::setAddress(QString address) {
    this->address = address;
}

// numero de telephone
QString User::getPhoneNo() const {
    return phone;
}
void User::setPhoneNo(QString phone) {
    this->phone = phone;
}

// retourne le nombre de livre max que l'adherent peut emprunter
int User::getLimit() {
    return bLimit;

}
void User::setLimit(int *bLimit) {
    this->bLimit = *bLimit;
    QSqlQuery userToDb;
    userToDb.prepare("UPDATE `u_subscriber` SET `max_books` = :mBooks WHERE `u_subscriber`.`subscriber_username` = :user ");
    userToDb.bindValue(":mBooks", getLimit());
    userToDb.bindValue(":user", getUser());
    userToDb.exec();
}



