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
        free = true;
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
        free = true;
    }

    // affiche les donn?es du livre
    void Book::printLivre() {
        QString(name + " de " + author + " paru chez " + publisher + " (ISBN: " + isbn + ") Type: " + genre.getName()
        + "Appartient a la bibliotheque " + genre.getLibrary().getName() + "Resume: " + summary);
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

    // son ?tat (si il est emprunt? ou non)
    bool Book::getFree() const{
        if(free == 1)
            return "Le livre est disponible a l'emprunt!";
        else return "Le livre n est actuellement pas disponible.";
    }
    void Book::setFree(bool free){
        QSqlQuery bookToDb("UPDATE `books` SET `free` = '0' WHERE `books`.`ISBN` = '"+getIsbn()+"' ");
        bookToDb.exec();
        this->free = free;
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
