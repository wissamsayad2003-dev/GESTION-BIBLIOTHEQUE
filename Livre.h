
#include "Date.h"
#include<iostream>
using namespace std;
namespace biblio {

    class Livre {
    private:
        const int id;               
        string titre, auteur;
        Date parution;              
        int* notes;                 
        int nbNotes;
        int capmax;
        static int compteurId;      
        static int nbInstances; 

    public:
        Livre(string titre = "", string auteur = "", Date parution = Date(), int capmax = 10);
        Livre(const Livre& autre);
        Livre& operator=(const Livre& autre);
        ~Livre();

        void ajouterNote(int note);
        double moyenne() const;
        void afficher() const;

        int getId() const;
        string getTitre() const;
        static int getNbInstances();
    };

}