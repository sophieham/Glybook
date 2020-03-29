#include "emprunt.h"



Emprunt::Emprunt() {
    Emprunt::compteur = 0;
}
Emprunt::~Emprunt(){}
Emprunt::Emprunt(Adherent adh, Livre livre) {
    //static QMap <Livre, QString> temp;
    static size_t compte;
    if (livre.getLibre() && (adh.getMaxBooks() > 0)) {
        datePret = getDateNow();
        dateRendre = getDatePlusDays(14);
        adherent = adh;
        livreEmprunt = livre;
        livre.setLibre(0);
        //temp.insert(livre, adh.getName() + " " + adh.getFirstName());
        //temp.insert(pair<string, string>(livre.to_string(livre), adh.getName() + " " + adh.getFirstName()));
        //Emprunt::mapEmprunt = temp;
        
        ++compte;
        Emprunt::compteur = compte;
    }
        else
        {
            datePret = "";
            dateRendre = "";
            adh = Adherent();
            livre = Livre();
            //Emprunt::~Emprunt();
        }
          

    }

// affiche la date et l'heure actuelle au format yyyy-mm-dd hh::mm::ss
QString Emprunt::getDateNow() {
    QString res;
    time_t t = time(nullptr);
    char datePret[20];
    strftime(datePret, sizeof(datePret), "%Y-%m-%d %H:%M:%S", localtime(&t));
    res.push_back(datePret);
    return res;
}

// afficher la date après un nombre de jour donné
QString Emprunt::getDatePlusDays(int n) {
    QString res;
    time_t t = time(nullptr);
    t = t + (86400 * n); // n: temps de pret
    char dateRendre[20];
    strftime(dateRendre, sizeof(dateRendre), "%Y-%m-%d", localtime(&t));
    res.push_back(dateRendre);
    return res;
}

// retourne le nombre de fois où la classe a été instanciée
size_t Emprunt::getOccurence() const {
    return compteur;
}

// retourne l'objet adherent
Adherent Emprunt::getAdherent() const {
    return adherent;
}

void Emprunt::setAdherent(Adherent adh) {
    this->adherent = adh;
}

// retourne l'objet livre
Livre Emprunt::getLivreEmprunt() const {
    return livreEmprunt;
}

void Emprunt::setLivreEmprunt(Livre l) {
    this->livreEmprunt = l;
}

// affiche les données liés à l'emprunt
void Emprunt::printEmprunt(){
    QString ("Emprunt: " + livreEmprunt.getNomLivre() + " par " + adherent.getFirstName() + " " + adherent.getLastName() + " le " + getDatePret() + ", a rendre avant le " + getDateRendre());
}

// retourne la date auquel le livre à été emprunté
QString Emprunt::getDatePret() const {
    return datePret;
}

void Emprunt::setDatePret(QString datePret) {
    this->datePret = datePret;
}

// retourne la date limite de pret
QString Emprunt::getDateRendre() const {
    return dateRendre;
}
void Emprunt::setDateRendre(QString dateRendre) {
    this->dateRendre = dateRendre;
}

// affiche la liste de tous les livres disponibles à l'emprunt
void Emprunt::afficherListe() const{
    /*
    static QMap<string, string>::iterator itr;
    int i=0;
    cout << "---------------- Liste des livres libres à l'emprunt \n---- Nom du livre (Auteur - ISBN) ----> Emprunteur" << endl;
    for (itr = Emprunt::mapEmprunt.begin(); itr != Emprunt::mapEmprunt.end(); ++itr) {
        if (!livreEmprunt.getLibre()) {
            cout << itr->first << " ---->  " << itr->second << '\n';
            ++i;
        }
    }
    if (i < 1)
        cout << "~ Aucun livre de disponible malheuresement, revenez plus tard!" << endl;
    */
}

// affiche la liste des livres empruntés pour un adherent donné
void Emprunt::afficherListe(Adherent a) {
    a.print();
    /*
    int i = 0;
    static map<string, string>::iterator itl;
    QString nomprenom = a.getName() + " " + a.getFirstName();
    cout << "---------------- Liste des livres empruntes par " << nomprenom 
         << "\n~ Il vous reste " << a.getNbLivreMaxAdh() << " emprunts max." << endl;

    for (itl = Emprunt::mapEmprunt.begin(); itl != Emprunt::mapEmprunt.end(); ++itl) {
        if (itl->second == nomprenom) {
            if(!(itl->first == " ( - )")) // instanciation de l'objet emprunt sans parametres
            cout << itl->first << " -----> a rendre avant le: " << dateRendre << '\n';
            ++i;
        }
    }
    if (i < 1)
        cout << "~ Vous n'avez pas d'emprunts en cours!" << endl;
    */

}
