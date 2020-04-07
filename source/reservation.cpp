#include "reservation.h"
#include "dbconnection.h"
#include <QSqlError>

Reservation::Reservation() {
    Reservation::counter = 0;
}
Reservation::~Reservation(){
};
Reservation::Reservation(User sub, Book book) {
    static size_t count;

        startDate = getDateNow();
        endDate = getDatePlusDays(14);
        subscriber = sub;
        lentBook = book;
        book.setFree(0);

        ++count;
        Reservation::counter = count;
    }

// affiche la date et l'heure actuelle au format yyyy-mm-dd hh::mm::ss
QString Reservation::getDateNow() {
    QString res;
    time_t t = time(nullptr);
    char datePret[20];
    strftime(datePret, sizeof(datePret), "%Y-%m-%d %H:%M:%S", localtime(&t));
    res.push_back(datePret);
    return res;
}

// afficher la date après un nombre de jour donné
QString Reservation::getDatePlusDays(int n) {
    QString res;
    time_t t = time(nullptr);
    t = t + (86400 * n); // n: temps de pret
    char dateRendre[20];
    strftime(dateRendre, sizeof(dateRendre), "%Y-%m-%d", localtime(&t));
    res.push_back(dateRendre);
    return res;
}

// retourne le nombre de fois où la classe a été instanciée
size_t Reservation::getOccurence() const {
    return counter;
}

// retourne l'objet adherent
User Reservation::getSubscriber() const {
    return subscriber;
}

void Reservation::setSubscriber(User sub) {
    subscriber = sub;
}

// retourne l'objet livre
Book Reservation::getLentBook() const {
    return lentBook;
}

void Reservation::setLentBook(Book b) {
    this->lentBook = b;
}

// affiche les données liés à l'emprunt
void Reservation::printBorrow(){
    QString ("Emprunt: " + lentBook.getName() + " par " + subscriber.getFirstName() + " " + subscriber.getLastName() + " le " + getStartDate() + ", a rendre avant le " + getEndDate());
}

// retourne la date auquel le livre à été emprunté
QString Reservation::getStartDate() const {
    return startDate;
}

void Reservation::setStartDate(QString startDate) {
    this->startDate = startDate;
}

// retourne la date limite de pret
QString Reservation::getEndDate() const {
    return endDate;
}
void Reservation::setEndDate(QString endDate) {
    this->endDate = endDate;
}

// ajoute l'emprunt a la bdd, rend le livre emprunté et décremente la limite de livre empruntables pour l'emprunteur
void Reservation::addReservation()
{
    QSqlQuery q;
    q.prepare("INSERT INTO `reservations` (`reservationID`, `username`, `bookID`, `start_date`, `end_date`) VALUES (NULL, :user, :book, :start, :end)  ");
    q.bindValue(":user", subscriber.getUser());
    q.bindValue(":book", lentBook.getIsbn());
    q.bindValue(":start", startDate);
    q.bindValue(":end", endDate);
    q.exec();

    lentBook.setFree(0);
    subscriber.setLimit(new int(subscriber.getLimit()-1));

}
