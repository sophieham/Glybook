#include "glybook.h"

//BASE DE DONNEE A IMPLEMENTER!!!!!!!!!!!!!!!!!

int main() {
    Administrateur ao("Mako", "Julie", "jmako", "1234");
    Adherent mi("Kio", "Molly", "16 rue Colombier", "02451246478", 4);

    Bibliotheque ab("Hugo Sorin", "universitaire", "150 rue de Bellair");
    Categorie sf("Science-fiction", "Un genre litteraire assez decale de la realite qui neanmoins souleve parfois des questions reelles", ab);
    //ab.print();
    //sf.print();
    Livre alice("Alice au pays des merveilles", "Robin D", "Hachette", "C'est l'histoire d'une merveille petite fille qui rentre dans un monde minuscule rempli d'animaux", "2-7654-1005-4", sf);
    //alice.print();
    mi.print();

    Emprunt un(mi, alice);
    un.print();
    getchar();
}
