#pragma once
#include <iostream>
#include <QString>
using namespace std;

    class User {
	private:
        QString user;
        QString pass;
        QString lastName;
        QString firstName;
        short type;
        QString address;
        QString phone;
        int bLimit; // limitation d'emprunt


	public:
        User();
        ~User();
        User(QString user, QString pass, QString lName, QString fName, short);
        User(QString user, QString pass, QString lName, QString fName, short, QString address, QString phone, int *bLimit);
        QString getUser() const;
        void setUser(const QString);
        QString getPswd() const;
        void setPswd(const QString);
        QString getFirstName() const;
        void setFirstName(const QString);
        QString getLastName() const;
        void setLastName(const QString);
        short getType() const;
        void setType(short const);
        QString getAddress() const;
        void setAddress(QString const);
        QString getPhoneNo() const;
        void setPhoneNo(QString const);
        int getLimit();
        void setLimit(int*) ;

		
	};
