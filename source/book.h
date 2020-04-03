#pragma once
#include <iostream>
#include "genre.h"
#include <QVector>
#include <sstream>
#include <QDebug>
using namespace std;

    class Book {
    private:
        QString name, author, publisher, summary, isbn;
        bool free;
        Genre genre;
        size_t counter;
        QVector<QString> list;
        int year;


    public:
        Book();
        ~Book();
        Book(QString name, QString author, QString publisher, QString summary, QString isbn, Genre genreName, int year);
        void printLivre();
        QString getName() const;
        void setName(QString const);
        QString getAuthor() const;
        void setAuthor(QString const);
        QString getPublisher() const;
        void setPublisher(QString const);
        QString getSummary() const;
        void setSummary(QString const);
        QString getIsbn() const;
        void setIsbn(QString const);
        bool getFree() const;
        void setFree(bool const);
        Genre getGenre();
        void setGenre(Genre const);
        int getYear() const;
        void setYear(int const);
        size_t getOccurence();
        void printList() const;
        /*
        friend std::ostream& operator<<(std::ostream& out, Livre l);
        static QString to_string(Livre const);
        */
    };
