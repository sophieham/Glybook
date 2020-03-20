#include "emprunt.h"


Emprunt::~Emprunt(){}
Emprunt::Emprunt(Adherent adh, Livre livre){
        if (livre.getLibre() & (adh.getNbLivreMax() > 0)) {
            time_t t = time(nullptr);
            char datePret[20];
            #pragma warning(suppress : 4996)
            strftime(datePret, sizeof(datePret), "%Y-%m-%d %H:%M:%S", localtime(&t));
            this->datePret = datePret;

            t = t + (86400 * 14); // 14: temps de pret
            char dateRendre[20];
            #pragma warning(suppress : 4996)
            strftime(dateRendre, sizeof(dateRendre), "%Y-%m-%d", localtime(&t));
            this->dateRendre = dateRendre;
            adherent = adh;
            this->livre = livre;
            livre.setLibre(0);
            adh.setNbLivreMax(adh.getNbLivreMax() - 1);
        }
        else
        {
            datePret = "";
            dateRendre = "";
            Emprunt::~Emprunt();
        }
            
        
    }
void Emprunt::print(){
    cout << "Emprunt: " << livre.getNom() << " par " << adherent.getPrenom() << " " << adherent.getNom() << " le " << getDatePret() << ", a rendre avant le " << getDateRendre() << endl;
}
string Emprunt::getDatePret() {
    return datePret;
}
void Emprunt::setDatePret(string datePret) {
    this->datePret = datePret;
}


string Emprunt::getDateRendre() {
    return dateRendre;
}
void Emprunt::setDateRendre(string dateRendre) {
    this->dateRendre = dateRendre;
}
