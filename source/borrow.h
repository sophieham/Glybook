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

    class Borrow {
    private:
        QString lendingDate;
        QString returnDate;
        User subscriber;
        Book lentBook;
        size_t counter;
      
    public:
        Borrow();
        ~Borrow();
        Borrow(User, Book);
        QString getDateNow();
        QString getDatePlusDays(int n);
        void printBorrow();
        QString getLendingDate() const;
        void setLendingDate(QString const);
        QString getReturnDate() const;
        void setReturnDate(QString const);
        User getSubscriber() const;
        void setSubscriber(User const);
        Book getLentBook() const;
        void setLentBook(Book const);
        size_t getOccurence() const;
        void addBorrow();
    };
