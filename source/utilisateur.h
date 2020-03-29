#pragma once
#include <iostream>
#include <QString>
using namespace std;

	class Utilisateur {
	private:
        QString lastName;
        QString firstName;
		int type;

	public:
		Utilisateur();
		~Utilisateur();
        Utilisateur(QString, QString, int);
        virtual QString getFirstName() const;
        virtual QString getLastName() const;
        virtual int getType() const;
        virtual void setType(int const);
        virtual QString print()=0;
		
	};

	class Administrateur : public Utilisateur {
	private:
        QString user;
        QString pass;
	public:
        Administrateur(QString firstName, QString LastName, QString user, QString pass);
		~Administrateur();
        QString getUser() const;
        QString getPswd() const;
        void setUser(const QString);
        void setPswd(const QString);

        QString print();


	};

	class Adherent : public Utilisateur {
	private:
        QString address;
        QString phone;
        short maxBooks; // le nombre de livres que peut emprunter l'adherent
	public:
		Adherent();
		~Adherent();
        Adherent(QString firstName, QString lastName, QString address, QString phoneNo, short);
        QString print();
        QString getAddress() const;
        void setAddress(QString const);
        QString getPhoneNo() const;
        void setPhoneNo(QString const);
        short getMaxBooks() const;
        void setMaxBooks(short const);
	};
