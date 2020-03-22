#include "emprunt.h"



Emprunt::Emprunt() {
    Emprunt::compteur = 0;
}
Emprunt::~Emprunt(){}
Emprunt::Emprunt(Adherent adh, Livre livre) {
    static map <string, string> temp;
    static size_t compte;
    if (livre.getLibre() & (adh.getNbLivreMaxAdh() > 0)) {
        datePretEmprunt = getDateNow();
        dateRendreEmprunt = getDatePlusDays(14);
        adherentEmprunt = adh;
        livreEmprunt = livre;
        livre.setLibre(0);
        
        temp.insert(pair<string, string>(livre.to_string(livre), adh.getPrenomUtilisateur() + " " + adh.getNomUtilisateur()));
        Emprunt::mapEmprunt = temp;
        
        ++compte;
        Emprunt::compteur = compte;
    }
        else
        {
            datePretEmprunt = "";
            dateRendreEmprunt = "";
            adh = Adherent();
            livre = Livre();
            Emprunt::~Emprunt();
        }
          

    }

// affiche la date et l'heure actuelle au format yyyy-mm-dd hh::mm::ss
string Emprunt::getDateNow() {
    string res;
    time_t t = time(nullptr);
    char datePret[20];
    #pragma warning(suppress : 4996)
    strftime(datePret, sizeof(datePret), "%Y-%m-%d %H:%M:%S", localtime(&t));
    res.assign(datePret);
    return res;
}

// afficher la date après un nombre de jour donné
string Emprunt::getDatePlusDays(int n) {
    string res;
    time_t t = time(nullptr);
    t = t + (86400 * n); // n: temps de pret
    char dateRendre[20];
    #pragma warning(suppress : 4996)
    strftime(dateRendre, sizeof(dateRendre), "%Y-%m-%d", localtime(&t));
    res.assign(dateRendre);
    return res;
}

// retourne le nombre de fois où la classe a été instanciée
size_t Emprunt::getOccurence() {
    return compteur;
}

// retourne l'objet adherent
Adherent Emprunt::getAdherentEmprunt() {
    return adherentEmprunt;
}

void Emprunt::setAdherentEmprunt(Adherent adh) {
    this->adherentEmprunt = adh;
}

// retourne l'objet livre
Livre Emprunt::getLivreEmprunt() {
    return livreEmprunt;
}

void Emprunt::setLivreEmprunt(Livre l) {
    this->livreEmprunt = l;
}

// affiche les données liés à l'emprunt
void Emprunt::printEmprunt(){
    cout << "Emprunt: " << livreEmprunt.getNomLivre() << " par " << adherentEmprunt.getPrenomUtilisateur() << " " << adherentEmprunt.getNomUtilisateur() << " le " << getDatePretEmprunt() << ", a rendre avant le " << getDateRendreEmprunt() << endl;
}

// retourne la date auquel le livre à été emprunté
string Emprunt::getDatePretEmprunt() {
    return datePretEmprunt;
}

void Emprunt::setDatePretEmprunt(string datePret) {
    this->datePretEmprunt = datePret;
}

// retourne la date limite de pret
string Emprunt::getDateRendreEmprunt() {
    return dateRendreEmprunt;
}
void Emprunt::setDateRendreEmprunt(string dateRendre) {
    this->dateRendreEmprunt = dateRendre;
}

// affiche la liste de tous les livres disponibles à l'emprunt
void Emprunt::afficherListe(){
    static map<string, string>::iterator itr;
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
    
}

// affiche la liste des livres empruntés pour un adherent donné
void Emprunt::afficherListe(Adherent a) {
    int i = 0;
    static map<string, string>::iterator itl;
    string nomprenom = a.getPrenomUtilisateur() + " " + a.getNomUtilisateur();
    cout << "---------------- Liste des livres empruntes par " << nomprenom 
         << "\n~ Il vous reste " << a.getNbLivreMaxAdh() << " emprunts max." << endl;

    for (itl = Emprunt::mapEmprunt.begin(); itl != Emprunt::mapEmprunt.end(); ++itl) {
        if (itl->second == nomprenom) {
            if(!(itl->first == " ( - )")) // instanciation de l'objet emprunt sans parametres
            cout << itl->first << " -----> a rendre avant le: " << dateRendreEmprunt << '\n';
            ++i;
        }
    }
    if (i < 1)
        cout << "~ Vous n'avez pas d'emprunts en cours!" << endl;

}
