#pragma once
#include <ctime>
#include <iostream>
#include "book.h"
#include "user.h"
#include <iterator>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QMessageBox>

using namespace std;

    class Reservation {
    protected:
        QString startDate;
        QString endDate;
        User subscriber;
        Book lentBook;
        size_t counter;

    public:
        Reservation();
        ~Reservation();
        Reservation(User, Book);
        virtual QString getDateNow();
        virtual QString getDatePlusDays(int n);
        virtual void printBooking();
        virtual QString getStartDate() const;
        virtual void setStartDate(QString const);
        virtual QString getEndDate() const;
        virtual void setEndDate(QString const);
        virtual User getSubscriber() const;
        virtual void setSubscriber(User const);
        virtual Book getLentBook() const;
        virtual void setLentBook(Book const);
        virtual size_t getOccurence() const;
        virtual void saveDb()=0;
    };

    class Booking : public Reservation {
    public:
        Booking();
        Booking(User, Book);
        ~Booking();
        void saveDb();
    };

    class Loan : public Reservation {
    public:
        Loan();
        Loan(User, Book);
        ~Loan();
        void saveDb();
    };
