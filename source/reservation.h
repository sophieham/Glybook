#pragma once
#include <ctime>
#include <iostream>
#include "book.h"
#include "user.h"
#include <iterator>
//#include <QMap>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>

using namespace std;

    class Reservation {
    private:
        QString startDate;
        QString endDate;
        User subscriber;
        Book lentBook;
        size_t counter;

    public:
        Reservation();
        ~Reservation();
        Reservation(User, Book);
        QString getDateNow();
        QString getDatePlusDays(int n);
        void printBorrow();
        QString getStartDate() const;
        void setStartDate(QString const);
        QString getEndDate() const;
        void setEndDate(QString const);
        User getSubscriber() const;
        void setSubscriber(User const);
        Book getLentBook() const;
        void setLentBook(Book const);
        size_t getOccurence() const;
        void addReservation();
    };
