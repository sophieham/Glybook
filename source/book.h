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
        bool booked;
        Genre genre;
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
        bool isBooked() const;
        void setBooked(bool const);
        void updateBooking(bool const);
        Genre getGenre();
        void setGenre(Genre const);
        int getYear() const;
        void setYear(int const);
    };
