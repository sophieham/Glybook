#include "borrow.h"
#include "dbconnection.h"
#include <QSqlError>

Borrow::Borrow() {
    Borrow::counter = 0;
}
Borrow::~Borrow(){
}
Borrow::Borrow(User sub, Book book) {
    //static QMap <Livre, QString> temp;
    static size_t count;

        lendingDate = getDateNow();
        returnDate = getDatePlusDays(14);
        subscriber = sub;
        lentBook = book;
        book.setFree(0);

        ++count;
        Borrow::counter = count;
    }

// affiche la date et l'heure actuelle au format yyyy-mm-dd hh::mm::ss
QString Borrow::getDateNow() {
    QString res;
    time_t t = time(nullptr);
    char datePret[20];
    strftime(datePret, sizeof(datePret), "%Y-%m-%d %H:%M:%S", localtime(&t));
    res.push_back(datePret);
    return res;
}

// afficher la date apr�s un nombre de jour donn�
QString Borrow::getDatePlusDays(int n) {
    QString res;
    time_t t = time(nullptr);
    t = t + (86400 * n); // n: temps de pret
    char dateRendre[20];
    strftime(dateRendre, sizeof(dateRendre), "%Y-%m-%d", localtime(&t));
    res.push_back(dateRendre);
    return res;
}

// retourne le nombre de fois o� la classe a �t� instanci�e
size_t Borrow::getOccurence() const {
    return counter;
}

// retourne l'objet adherent
User Borrow::getSubscriber() const {
    return subscriber;
}

void Borrow::setSubscriber(User sub) {
    subscriber = sub;
}

// retourne l'objet livre
Book Borrow::getLentBook() const {
    return lentBook;
}

void Borrow::setLentBook(Book b) {
    this->lentBook = b;
}

// affiche les donn�es li�s � l'emprunt
void Borrow::printBorrow(){
    QString ("Emprunt: " + lentBook.getName() + " par " + subscriber.getFirstName() + " " + subscriber.getLastName() + " le " + getLendingDate() + ", a rendre avant le " + getReturnDate());
}

// retourne la date auquel le livre � �t� emprunt�
QString Borrow::getLendingDate() const {
    return returnDate;
}

void Borrow::setLendingDate(QString lendingDate) {
    this->lendingDate = lendingDate;
}

// retourne la date limite de pret
QString Borrow::getReturnDate() const {
    return returnDate;
}
void Borrow::setReturnDate(QString returnDate) {
    this->returnDate = returnDate;
}

// ajoute l'emprunt a la bdd, rend le livre emprunt� et d�cremente la limite de livre empruntables pour l'emprunteur
void Borrow::addBorrow()
{
    QSqlQuery q;
    q.prepare("INSERT INTO `borrow` (`lendingID`, `username`, `bookID`, `lending_date`, `return_date`) VALUES (NULL, :user, :book, :lending, :return)  ");
    q.bindValue(":user", subscriber.getUser());
    q.bindValue(":book", lentBook.getIsbn());
    q.bindValue(":lending", lendingDate);
    q.bindValue(":return", returnDate);
    q.exec();

    lentBook.setFree(0);
    subscriber.setLimit(new int(subscriber.getLimit()-1));

}
