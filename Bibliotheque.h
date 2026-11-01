#pragma once
#include <string>
#include "Livre.h"
using namespace std;

namespace biblio {

    class Bibliotheque {
    private:
        string nom;
        Livre** livres;     // tableau de pointeurs vers les livres
        int nbLivres;
        int capacite;
        static int nbBibliotheques;

    public:
        Bibliotheque(string nom = "", int capacite = 10);
        Bibliotheque(const Bibliotheque& autre);
        Bibliotheque& operator=(const Bibliotheque& autre);
        ~Bibliotheque();

        bool ajouterLivre(string titre, string auteur, Date parution, int capmax = 10);
        Livre* rechercher(int id) const;
        Livre* rechercher(string titre) const;
        void afficherCatalogue() const;

        static int getNbBibliotheques();
    };

}