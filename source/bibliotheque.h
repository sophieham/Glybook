#pragma once
#include <iostream>
#include <string>
using namespace std;

    class Bibliotheque {
    private:
        string nom;
        string type;
        string adresse;

    public:
        Bibliotheque();
        Bibliotheque(const string&, const string&, const string&);
        ~Bibliotheque();
        void print();
        string getNom() const;
        void setNom(const string&);
        string getAdresse() const;
        void setAdresse(const string&);
        string getType() const;
        void setType(const string&);
    };
