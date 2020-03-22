#pragma once
#include <iostream>
#include <string>
using namespace std;

	class Utilisateur {
	private:
		string nomUtilisateur;
		string prenomUtilisateur;
		int typeUtilisateur;

	public:
		Utilisateur();
		~Utilisateur();
		Utilisateur(string, string, int);
		string getNomUtilisateur();
		string getPrenomUtilisateur();
		int getTypeUtilisateur();
		void setTypeUtilisateur(int);
		void printUtilisateur();
		
	};

	class Administrateur : public Utilisateur {
	private:
		string usernameAdmin;
		string passwordAdmin;
	public:
		Administrateur(string, string, string, string);
		~Administrateur();

		void printAdmin();
		string getUsernameAdmin();
		void setUsernameAdmin(string);
		string getPasswordAdmin();
		void setPasswordAdmin(string);

	};

	class Adherent : public Utilisateur {
	private:
		string adresseAdh;
		string numtelAdh;
		short nbLivreMaxAdh;
	public:
		Adherent();
		~Adherent();
		Adherent(string, string, string, string, short);
		void print();
		string getAdresseAdh();
		void setAdresseAdh(string);
		string getNumTelAdh();
		void setNumTelAdh(string);
		short getNbLivreMaxAdh();
		void setNbLivreMaxAdh(short);
	};