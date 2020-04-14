#pragma once
#include <iostream>
#include <string>
using namespace std;

	class Utilisateur {
	private:
		string nom;
		string prenom;
		int type;

	public:
		Utilisateur();
		~Utilisateur();
		Utilisateur(const string&, const string&, int);
		virtual string getNom() const;
		virtual void setNom(const string&);
		virtual string getPrenom() const;
		virtual void setPrenom(const string&);
		virtual int getType();
		virtual void setType(int);
		virtual void print()=0;
		
	};

	class Administrateur : public Utilisateur {
	private:
		string identifiant;
		string pass;
	public:
		Administrateur(const string&, const string&, const string&, const string&);
		~Administrateur();
		string getIdentifiant() const;
		void setIdentifiant(const string&);
		string getPass() const;
		void setPass(const string&);

		void print();

	};

	class Abonne : public Utilisateur {
	private:
		string adresse;
		string numtel;
		short nbLivreMax;
	public:
		Abonne();
		~Abonne();
		Abonne(const string&, const string&, const string&, const string&, short);
		void print();
		string getAdresse() const;
		void setAdresse(const string&);
		string getNumTel() const;
		void setNumTel(const string&);
		short getNbLivreMax();
		void setNbLivreMax(short);
	};