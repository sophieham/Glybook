#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace {
	class Utilisateur {
	private:
		string nom;
		string prenom;
		int type;

	public:
		Utilisateur();
		~Utilisateur();
		Utilisateur(string nom, string prenom, int type);
		string getNom();
		string getPrenom();
		int getType();
		void setType(int t);
		void print();
	};

	class Administrateur : public Utilisateur {
	private:
		string username;
		string password;
	public:
		Administrateur(string nom, string prenom, string username, string password);
		~Administrateur();

		void print();
		string getUsername();
		void setUsername(string username);
		string getPassword();
		void setPassword(string password);

	};

	class Adherent : public Utilisateur {
	private:
		string adresse;
		string numtel;
		short nbLivreMax;
	public:
		Adherent();
		~Adherent();
		Adherent(string nom, string prenom, string adresse, string numtel, short nbLivreMax);
		void print();
		string getAdresse();
		void setAdresse(string adresse);
		string getNumTel();
		void setNumTel(string numtel);
		short getNbLivreMax();
		void setNbLivreMax(short nbLivreMax);
	};
}