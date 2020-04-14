#include "reservation.h"

Reservation::Reservation() {
    Reservation::compteur = 0;
}
Reservation::~Reservation(){}
Reservation::Reservation(Abonne abo, Livre livre) {
    static map <string, string> temp;
    static size_t compte;
    if (livre.getLibre() && (abo.getNbLivreMax() > 0)) {
        dateDebut= getDateNow();
        dateFin = getDatePlusDays(7); // additionne la durée de la réservation a la date actuelle
        abonne = abo;
        this->livre = livre;
        livre.setLibre(0);
        
        // ajoute la réservation a la liste des réservations
        temp.insert(pair<string, string>(livre.to_string(livre), abo.getNom() + " " + abo.getPrenom()));
        Reservation::mapReservation = temp;
        
        ++compte;
        Reservation::compteur = compte;
    }
        else{
            dateDebut= "";
            dateFin = "";
            abo = Abonne();
            livre = Livre();
            Reservation::~Reservation();
        }
    }

// affiche la date et l'heure actuelle au format yyyy-mm-dd hh::mm::ss
string Reservation::getDateNow() const {
    string res;
    time_t t = time(nullptr);
    char dateDebut[20];
    #pragma warning(suppress : 4996)
    strftime(dateDebut, sizeof(dateDebut), "%Y-%m-%d %H:%M:%S", localtime(&t));
    res.assign(dateDebut);
    return res;
}

// afficher la date après un nombre de jour donné
string Reservation::getDatePlusDays(int n) {
    string res;
    time_t t = time(nullptr);
    t = t + (86400 * n); // n: temps de pret
    char dateFin[20];
    #pragma warning(suppress : 4996)
    strftime(dateFin, sizeof(dateFin), "%Y-%m-%d", localtime(&t));
    res.assign(dateFin);
    return res;
}

// retourne le nombre de fois où la classe a été instanciée
size_t Reservation::getOccurence() {
    return compteur;
}

// retourne l'objet abonné
Abonne Reservation::getAbonne() const {
    return abonne;
}

void Reservation::setAbonne(const Abonne &abo) {
    abonne = abo;
}

// retourne l'objet livre
Livre Reservation::getLivre() const {
    return livre;
}

void Reservation::setLivre(const Livre &livre) {
    this->livre = livre;
}

// affiche les données liés à la réservation
void Reservation::print(){
    cout << "Reservation: " << livre.getNom() << " par " << abonne.getNom() << " " << abonne.getPrenom()
         << " le " << dateDebut << ", prend fin le " << dateFin<< endl;
}

// retourne la date auquel le livre à été reservé
string Reservation::getDateDebut() const {
    return dateDebut;
}

void Reservation::setDateDebut(const string &dateDebut) {
    this->dateDebut = dateDebut;
}

// retourne la date de fin de la réservation
string Reservation::getDateFin() const {
    return dateFin;
}
void Reservation::setDateFin(const string &dateFin) {
    this->dateFin = dateFin;
}

// affiche la liste de tous les livres disponibles à la réservation
void Reservation::afficherListe() const{
    static map<string, string>::iterator itr;
    int i=0;
    cout << "---------------- Liste des livres libres à la réservation \n---- Nom du livre (Auteur - ISBN) ----> Abonné" << endl;
    for (itr == Reservation::mapReservation.begin(); itr != Reservation::mapReservation.end(); ++itr) {
        if (!livre.getLibre()) {
            cout << itr->first << " ---->  " << itr->second << '\n';
            ++i;
        }
    }
    if (i < 1)
        cout << "~ Aucun livre de disponible malheuresement, revenez plus tard!" << endl;
    
}

// affiche la liste des livres réservés pour un abonné donné
void Reservation::afficherListe(Abonne &a) {
    int i = 0;
    static map<string, string>::iterator itl;
    string nomprenom = a.getNom() + " " + a.getPrenom();
    cout << "---------------- Liste des livres réservés par " << nomprenom 
         << "\n~ Il vous reste " << a.getNbLivreMax() << " réservations max." << endl;

    for (itl = Reservation::mapReservation.begin(); itl != Reservation::mapReservation.end(); ++itl) {
        if (itl->second == nomprenom) {
            if(!(itl->first == " ( - )")) // instanciation de l'objet reservation sans parametres
                cout << itl->first << " -----> prend fin le: " << dateFin << '\n';
            ++i;
        }
    }
    if (i < 1)
        cout << "~ Vous n'avez pas de réservations en cours!" << endl;

}
