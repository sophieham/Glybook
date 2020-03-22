#pragma once
#include <iostream>
#include <string>
using namespace std;

    class Bibliotheque {
    private:
        string nomBiblio;
        string typeBiblio;
        string adresseBiblio;

    public:
        Bibliotheque();
        Bibliotheque(string, string, string);
        ~Bibliotheque();
        void printBiblio();
        string getNomBiblio();
        string getAdresseBiblio();
        string getTypeBiblio();
    };
