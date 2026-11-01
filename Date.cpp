#include "Date.h"
#include<iostream>
using namespace std;
namespace biblio {


    bool Date::estBissextile(int a) {
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
            cout << a << " est bissextile";
                return true;
        }
        cout << a << " n'est pas bissextile";
        return false;
    }

    bool Date::estValide(int j, int m, int a) {
        if (a < 1 || m < 1 || m > 12 || j < 1 || a >2026) {
            cout << "la date n'est pas valide";
            return false;
        }  

        int nbJours = 31;
        if (m == 4 || m == 6 || m == 9 || m == 11)
            nbJours = 30;
        if (m == 2) {
            if (estBissextile(a))
                nbJours = 29;
            else
                nbJours = 28;
        }
        return j <= nbJours;
    }

    bool Date::operator==(const Date& d) const
    {
        if (jour == d.jour && mois == d.mois && annee == d.annee)
            return true;
        return false;
    }

    bool Date::operator<(const Date& d) const
    {
        if (annee < d.annee) return true;
        if (annee > d.annee) return false;
        if (mois < d.mois) return true;
        if (mois > d.mois) return false;
        return jour < d.jour;
    }


    Date::Date(int j, int m, int a) {
        if (estValide(j, m, a)) {
            jour = j;
            mois = m;
            annee = a;
        }
        else {
            cout << "Date invalide, remplacee par 01/01/2000" << endl;
            jour = 1;
            mois = 1;
            annee = 2000;
        }
    }

    void Date::afficher() const {  
       cout << jour << "/" << mois << "/" << annee;
    }


}
