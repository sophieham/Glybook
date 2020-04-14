#include "glybook.h"

//compte le nombre d'instances d'un objet
template <typename T>
size_t nbOccurence(T type) {
    static int decompte=0;
    decompte++; // compte le nombre de fois que la fonction a été appellée
    size_t r = type.getOccurence(); // et le décompte du nombre d'occurence (-> appelle une nouvelle instance à chaque fois)
    return r;
}

// affiche la liste de tous les livres/emprunts
template <typename T>
void liste(T type) {
    type.afficherListe();
}

// affiche la liste de tous les emprunts d'un adherent
void liste(Abonne a) {
    Reservation e(a, Livre());
    e.afficherListe(a);
}

int main() {
    Administrateur julie("Delapierre", "Julie", "dlp.julie", "1234");
    Abonne lucie("Marret", "Lucie", "16 rue Colombier", "02451246478", 4);
    Abonne francois("Durand", "Francois", "3 avenue du Docteur Martin", "0633487518", 4);
    Abonne albert("Zuker", "Albert", "35 rue de la Mirabelle", "0237475709", 4);
    Bibliotheque HS("Hugo Sorin", "universitaire", "150 rue de Bellair");
    Categorie comte("Comte", "De magnifiques histoires qui se finissent bien", HS);
    Livre alice("Alice au pays des merveilles", "Lewis Caroll", "Hachette", "C'est l'histoire d'une merveille petite fille qui rentre dans un monde minuscule rempli d'animaux", "2-7654-1005-4", comte);
    Livre belle("La belle et la bete", "Gabrielle de Villeneuve", "Hachette", "Il était une fois une princesse...", "3-1145-1005-4", comte);
    Livre poucet("Le petit poucet", "Charles Perrault", "Hachette", "C'est l'histoire du petit poucet", "1-7354-1014-8", comte);
    
    Reservation luciealice(lucie, alice);
    Reservation luciebelle(lucie, belle);

    Livre livreLL("", "", "", "", "", Categorie());
    Reservation empruntEE(Abonne("","","","",1), livreLL);

    cout << "Nombre de livres total: " << nbOccurence(livreLL) << " - Nombre d'emprunts totaux: " << nbOccurence(empruntEE) << endl;
    liste(livreLL); // affiche la liste des livres
    liste(lucie); // affiche la liste des livres réservés par lucie
    

   getchar(); // pour pouvoir ouvrir le .exe
}

