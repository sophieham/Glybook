#include "bibliotheque.h"

    Bibliotheque::Bibliotheque(){};
    Bibliotheque::~Bibliotheque() {};
    Bibliotheque::Bibliotheque(const string &nom, const string &type, const string &adresse){
        this->nom = nom;
        this->adresse = adresse;
        if (type=="municipale" || "mediatheque" || "universitaire"){
            this->type = type;
        }
        else this->type = "inconnu";
    }

    void Bibliotheque::print(){
        cout << "Bibliotheque (" << type << ") " << nom << " situee " << adresse << endl;
    }

    string Bibliotheque::getNom() const {
        return nom;
    }

	void Bibliotheque::setNom(const string &nom)
	{
        this->nom = nom;
	}

    string Bibliotheque::getAdresse() const {
        return adresse;
    }

    void Bibliotheque::setAdresse(const string& adresse)
    {
        this->adresse = adresse;
    }

    string Bibliotheque::getType() const {
        return type;
    }

	void Bibliotheque::setType(const string &type)
	{
        this->type = type;
	}
