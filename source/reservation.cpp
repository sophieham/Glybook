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
        book.setBooked(1); // d�fini le livre comme reserv�

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

// afficher la date apr�s un nombre de jour donn�
QString Reservation::getDatePlusDays(int n) {
    QString res;
    time_t t = time(nullptr);
    t = t + (86400 * n); // n: temps de pret
    char dateRendre[20];
    strftime(dateRendre, sizeof(dateRendre), "%Y-%m-%d", localtime(&t));
    res.push_back(dateRendre);
    return res;
}

// retourne le nombre de fois o� la classe a �t� instanci�e
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

// affiche les donn�es li�s � la r�servation
void Reservation::printBooking(){
    QString ("Emprunt: " + lentBook.getName() + " par " + subscriber.getFirstName() + " " + subscriber.getLastName() + " le " + getStartDate() + ", a rendre avant le " + getEndDate());
}

// retourne la date auquel le livre � �t� emprunt�
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

Booking::Booking(){

}

Booking::~Booking(){

}

Booking::Booking(User sub, Book book) : Reservation::Reservation(sub, book) {

}

// ajoute la r�servation a la bdd, rend le livre emprunt� et d�cremente la limite de r�servation pour celui qui vient de reserver
void Booking::saveDb()
{
    QSqlQuery q;
    q.prepare("INSERT INTO `reservations` (`reservationID`, `username`, `bookID`, `start_date`, `end_date`) VALUES (NULL, :user, :book, :start, :end)  ");
    q.bindValue(":user", subscriber.getUser());
    q.bindValue(":book", lentBook.getIsbn());
    q.bindValue(":start", startDate);
    q.bindValue(":end", endDate);
    q.exec();

    lentBook.updateBooking(1);
    subscriber.setLimit(new int(subscriber.getLimit()-1));

}

Loan::Loan(){

}

Loan::~Loan(){

}

Loan::Loan(User sub, Book book) : Reservation::Reservation(sub, book){

}

// ajoute l'emprunt a la bdd et on rend le livre emprunt�
void Loan::saveDb()
{
    QSqlQuery q;
    q.prepare("INSERT INTO `loans` (`loanID`, `username`, `isbn`, `start_date`, `return_date`) VALUES (NULL, :user, :isbn, :start, :end) ");
    q.bindValue(":user", subscriber.getUser());
    q.bindValue(":isbn", lentBook.getIsbn());
    q.bindValue(":start", startDate);
    q.bindValue(":end", endDate);

    if(q.exec()){
        q.exec("UPDATE `books` SET `lent` = '1' WHERE `books`.`ISBN` = '"+lentBook.getIsbn()+"'");
    }
    else qDebug() << "ERROR!" << q.lastError().text();
}
