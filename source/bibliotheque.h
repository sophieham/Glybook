#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace {
    class Bibliotheque {
    private:
        string nom;
        string type;
        string adresse;

    public:
        Bibliotheque();
        Bibliotheque(string nom, string type, string adresse);
        ~Bibliotheque();
        void print();
        string getNom();
        string getAdresse();
        string getType();
    };
}