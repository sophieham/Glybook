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
        counter = 0;
    }
    Book::~Book() {};

    Book::Book(QString name, QString author, QString publisher, QString summary, QString isbn, Genre genre, int year){
        this->name = name;
        this->author = author;
        this->publisher = publisher;
        this->summary = summary;
        this->isbn = isbn;
        this->genre = genre;
        this->year = year;
        free = true;
        static size_t compte;
        ++compte;
        Book::counter = compte;
        static QVector<QString> listeLivres;
        QString concat;
        if (!(name == "" || author == "" | publisher == "")) {
            concat = name + " - " + author + " - " + publisher + "\n";
        }
        listeLivres.push_back(concat);
        Book::list = listeLivres;

    }

    // affiche les donn?es du livre
    void Book::printLivre() {
        QString(name + " de " + author + " paru chez " + publisher + " (ISBN: " + isbn + ") Type: " + genre.getName()
        + "Appartient a la bibliotheque " + genre.getLibrary().getName() + "Resume: " + summary);
    }

    // affiche la liste des livres poss?d?s par la bibliotheque (emprunt?s ou non)
    void Book::printList() const{
        cout << "---------------- Liste de tous les livres que poss?de la biblioth?que" << endl;
        for (int i = 0; i < list.size(); i++)
        {
            QString(list.at(i));
        }
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

    // le nombre de fois o? la classe a ?t? instanci?e
    size_t Book::getOccurence() {
        return Book::counter;
    }

    /*
    // r?d?finition de l'affichage de l'objet
    ostream& operator<<(ostream& out, Livre l)
    {
        out << l.getNomLivre() << " (" << l.getAuteurLivre() << " - " << l.getIsbnLivre() << ")";
        return out;
    }

    // pour pouvoir l'afficher dans une chaine de caract?re
    string Livre::to_string(Livre l)
    {
        ostringstream ss;
        ss << l;
        return ss.str();
    }*/
