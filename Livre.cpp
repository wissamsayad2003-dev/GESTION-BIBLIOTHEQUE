#include "Livre.h"
#include <iostream>
using namespace std;

namespace biblio {

    int Livre::compteurId = 0;
    int Livre::nbInstances = 0;

    Livre::Livre(string t, string a, Date p, int max)
        : id(++compteurId)
    {
        this->capmax = max;
        this->titre = t;
        this->auteur = a;
        this->parution = p;
        this->notes = new int[capmax];
        this->nbNotes = 0;
        nbInstances++;
        cout << "Construction du livre " << id << endl;
    }

    // Constructeur de recopie : nouvel id + nouveau tableau
    Livre::Livre(const Livre& autre)
        : id(++compteurId)
    {
        capmax = autre.capmax;
        titre = autre.titre;
        auteur = autre.auteur;
        parution = autre.parution;
        nbNotes = autre.nbNotes;
        notes = new int[capmax];
        for (int i = 0; i < nbNotes; i++)
            notes[i] = autre.notes[i];
        nbInstances++;
        cout << "Copie du livre " << autre.id << " vers " << id << endl;
    }

    // Affectation (l'id ne change pas, il est const)
    Livre& Livre::operator=(const Livre& autre) {
        if (this != &autre) {
            delete[] notes;
            capmax = autre.capmax;
            titre = autre.titre;
            auteur = autre.auteur;
            parution = autre.parution;
            nbNotes = autre.nbNotes;
            notes = new int[capmax];
            for (int i = 0; i < nbNotes; i++)
                notes[i] = autre.notes[i];
        }
        return *this;
    }

    // Destructeur
    Livre::~Livre() {
        delete[] notes;
        nbInstances--;
        cout << "Destruction du livre " << id << endl;
    }

    // Ajouter une note entre 0 et 5
    void Livre::ajouterNote(int note) {
        if (note < 0 || note > 5) {
            cerr << "Note invalide : " << note << endl;
            return;
        }
        if (nbNotes >= capmax) {
            cerr << "Tableau de notes plein" << endl;
            return;
        }
        notes[nbNotes] = note;
        nbNotes++;
    }

    double Livre::moyenne() const {
        if (nbNotes == 0)
            return 0;
        int somme = 0;
        for (int i = 0; i < nbNotes; i++)
            somme += notes[i];
        return (double)somme / nbNotes;
    }

    void Livre::afficher() const {
        cout << "Livre " << id << " | " << titre << " | " << auteur << " | ";
        parution.afficher();
        cout << " | moyenne = " << moyenne() << endl;
    }

    int Livre::getId() const { return id; }
    string Livre::getTitre() const { return titre; }
    int Livre::getNbInstances() { return nbInstances; }

}



