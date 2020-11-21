#include "book.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

Book::Book(){
        name = "";
        author = "";
        publisher = "";
        summary = "";
        isbn = "";
        booked = false;
    }
    Book::~Book() {
    };

    Book::Book(QString name, QString author, QString publisher, QString summary, QString isbn, Genre genre, int year){
        this->name = name;
        this->author = author;
        this->publisher = publisher;
        this->summary = summary;
        this->isbn = isbn;
        this->genre = genre;
        this->year = year;
        booked = false;
    }

    // nom du livre
    QString Book::getName() const {
        return name;
    }
    void Book::setName(QString name) {
        this->name = name;
    }

    // auteur
    QString Book::getAuthor() const {
        return author;
    }
    void Book::setAuthor(QString author){
        this->author = author;
    }

    // editeur
    QString Book::getPublisher() const {
        return publisher;
    }
    void Book::setPublisher(QString publisher) {
        this->publisher = publisher;
    }

    // resume
    QString Book::getSummary() const {
        return summary;
    }
    void Book::setSummary(QString summary) {
        this->summary = summary;
    }

    // isbn (identifiant unique d'un livre)
    QString Book::getIsbn() const {
        return isbn;
    }
    void Book::setIsbn(QString isbn) {
        this->isbn = isbn;
    }

    // son état (si il est reservé ou non)
    bool Book::isBooked() const{
        return booked;
    }
    void Book::setBooked(bool booked){
        this->booked = booked;
    }

    // modifie l'état de reservation dans la base de donnée
    void Book::updateBooking(bool b){
        if(b){
            QSqlQuery bookToDb("UPDATE `books` SET `booked` = '1' WHERE `books`.`ISBN` = '"+getIsbn()+"' ");
            bookToDb.exec();
            setBooked(b);
        }
    }

    // son genre
    Genre Book::getGenre() {
        return genre;
    }
    void Book::setGenre(Genre g) {
        genre = g;
    }

    int Book::getYear() const
    {
        return year;
    }

    void Book::setYear(const int year)
    {
        this->year = year;
    }
