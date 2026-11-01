#include <iostream>
#include "Bibliotheque.h"
using namespace std;
using namespace biblio;

int main() {
    {
        // 1. Bibliotheque + livres avec des dates differentes
        Bibliotheque b("Bibliotheque FST", 3);

        // 2. Ajout des livres
        b.ajouterLivre("Le Petit Prince", "Saint-Exupery", Date(6, 4, 1943), 5);
        b.ajouterLivre("L'Etranger", "Camus", Date(19, 5, 1942), 5);
        b.ajouterLivre("Les Miserables", "Hugo", Date(3, 4, 1862), 5);
        b.ajouterLivre("Livre en trop", "Inconnu", Date(1, 1, 2020));  // refuse

        // Notes
        Livre* l = b.rechercher("Le Petit Prince");
        l->ajouterNote(5);
        l->ajouterNote(4);
        l->ajouterNote(3);
        l->ajouterNote(9);   // note invalide

        // 3. Recherche reussie et recherche infructueuse
        Livre* trouve = b.rechercher("L'Etranger");
        if (trouve != nullptr)
            cout << "Livre trouve : " << trouve->getTitre() << endl;

        if (b.rechercher("Inexistant") == nullptr)
            cout << "Livre introuvable" << endl;

        if (b.rechercher(3) != nullptr)
            cout << "Le livre d'id 3 existe" << endl;

        // 4. Affichage et nombre de livres
        b.afficherCatalogue();
        cout << "Livres existants : " << Livre::getNbInstances() << endl;

        // 5. La destruction s'affiche a la fin du bloc
    }
    cout << "Livres existants apres destruction : " << Livre::getNbInstances() << endl;
    return 0;
}