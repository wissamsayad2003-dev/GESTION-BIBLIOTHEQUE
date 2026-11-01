#include "Bibliotheque.h"
#include <iostream>
using namespace std;

namespace biblio {

    int Bibliotheque::nbBibliotheques = 0;

    // Constructeur
    Bibliotheque::Bibliotheque(string n, int cap) {
        this->nom = n;
        this->capacite = cap;
        this->nbLivres = 0;
        this->livres = new Livre * [capacite];
        nbBibliotheques++;
    }

    // Constructeur de recopie : on copie aussi chaque livre
    Bibliotheque::Bibliotheque(const Bibliotheque& autre) {
        nom = autre.nom;
        capacite = autre.capacite;
        nbLivres = autre.nbLivres;
        livres = new Livre * [capacite];
        for (int i = 0; i < nbLivres; i++)
            livres[i] = new Livre(*autre.livres[i]);
        nbBibliotheques++;
    }

    // Affectation
    Bibliotheque& Bibliotheque::operator=(const Bibliotheque& autre) {
        if (this != &autre) {
            for (int i = 0; i < nbLivres; i++)
                delete livres[i];
            delete[] livres;

            nom = autre.nom;
            capacite = autre.capacite;
            nbLivres = autre.nbLivres;
            livres = new Livre * [capacite];
            for (int i = 0; i < nbLivres; i++)
                livres[i] = new Livre(*autre.livres[i]);
        }
        return *this;
    }

    // Destructeur : on libere chaque livre, puis le tableau
    Bibliotheque::~Bibliotheque() {
        for (int i = 0; i < nbLivres; i++)
            delete livres[i];
        delete[] livres;
        nbBibliotheques--;
    }

    // Ajout refuse si la capacite est atteinte
    bool Bibliotheque::ajouterLivre(string titre, string auteur, Date parution, int capmax) {
        if (nbLivres >= capacite) {
            cerr << "Capacite atteinte : ajout refuse de " << titre << endl;
            return false;
        }
        livres[nbLivres] = new Livre(titre, auteur, parution, capmax);
        nbLivres++;
        return true;
    }

    // Recherche par id (nullptr si introuvable)
    Livre* Bibliotheque::rechercher(int id) const {
        for (int i = 0; i < nbLivres; i++)
            if (livres[i]->getId() == id)
                return livres[i];
        return nullptr;
    }

    // Recherche par titre (nullptr si introuvable)
    Livre* Bibliotheque::rechercher(string titre) const {
        for (int i = 0; i < nbLivres; i++)
            if (livres[i]->getTitre() == titre)
                return livres[i];
        return nullptr;
    }

    void Bibliotheque::afficherCatalogue() const {
        cout << "=== Catalogue de " << nom << " (" << nbLivres << "/" << capacite << ") ===" << endl;
        for (int i = 0; i < nbLivres; i++)
            livres[i]->afficher();
    }

    int Bibliotheque::getNbBibliotheques() { return nbBibliotheques; }

}