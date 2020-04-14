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
        dateFin = getDatePlusDays(7); // additionne la dur�e de la r�servation a la date actuelle
        abonne = abo;
        this->livre = livre;
        livre.setLibre(0);
        
        // ajoute la r�servation a la liste des r�servations
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

// afficher la date apr�s un nombre de jour donn�
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

// retourne le nombre de fois o� la classe a �t� instanci�e
size_t Reservation::getOccurence() {
    return compteur;
}

// retourne l'objet abonn�
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

// affiche les donn�es li�s � la r�servation
void Reservation::print(){
    cout << "Reservation: " << livre.getNom() << " par " << abonne.getNom() << " " << abonne.getPrenom()
         << " le " << dateDebut << ", prend fin le " << dateFin<< endl;
}

// retourne la date auquel le livre � �t� reserv�
string Reservation::getDateDebut() const {
    return dateDebut;
}

void Reservation::setDateDebut(const string &dateDebut) {
    this->dateDebut = dateDebut;
}

// retourne la date de fin de la r�servation
string Reservation::getDateFin() const {
    return dateFin;
}
void Reservation::setDateFin(const string &dateFin) {
    this->dateFin = dateFin;
}

// affiche la liste de tous les livres disponibles � la r�servation
void Reservation::afficherListe() const{
    static map<string, string>::iterator itr;
    int i=0;
    cout << "---------------- Liste des livres libres � la r�servation \n---- Nom du livre (Auteur - ISBN) ----> Abonn�" << endl;
    for (itr == Reservation::mapReservation.begin(); itr != Reservation::mapReservation.end(); ++itr) {
        if (!livre.getLibre()) {
            cout << itr->first << " ---->  " << itr->second << '\n';
            ++i;
        }
    }
    if (i < 1)
        cout << "~ Aucun livre de disponible malheuresement, revenez plus tard!" << endl;
    
}

// affiche la liste des livres r�serv�s pour un abonn� donn�
void Reservation::afficherListe(Abonne &a) {
    int i = 0;
    static map<string, string>::iterator itl;
    string nomprenom = a.getNom() + " " + a.getPrenom();
    cout << "---------------- Liste des livres r�serv�s par " << nomprenom 
         << "\n~ Il vous reste " << a.getNbLivreMax() << " r�servations max." << endl;

    for (itl = Reservation::mapReservation.begin(); itl != Reservation::mapReservation.end(); ++itl) {
        if (itl->second == nomprenom) {
            if(!(itl->first == " ( - )")) // instanciation de l'objet reservation sans parametres
                cout << itl->first << " -----> prend fin le: " << dateFin << '\n';
            ++i;
        }
    }
    if (i < 1)
        cout << "~ Vous n'avez pas de r�servations en cours!" << endl;

}
