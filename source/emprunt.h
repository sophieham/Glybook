#pragma once
#include <ctime>
#include <iostream>
#include "livre.cpp"
#include "utilisateur.cpp"
#include <string>
using namespace std;

namespace {
    class Emprunt {
    private:
        string datePret;
        string dateRendre;
         Adherent adherent;
        static Livre livre;

    public:
        ~Emprunt();
        Emprunt(Adherent adh, Livre livre);
         void print();
         string getDatePret();
         void setDatePret(string datePret);
         string getDateRendre();
         void setDateRendre(string dateRendre);
    };
}