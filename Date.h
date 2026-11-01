#pragma once
#include<iostream>

namespace biblio {
    class Date
    {
    private:
        int jour, mois, annee;

    public:
        Date(int j = 1, int m = 1, int a = 2000); 
        static bool estBissextile(int a);
        static bool estValide(int j, int m, int a);
        bool operator==(const Date& d) const;
        bool operator<(const Date& d) const;
        void afficher() const;
    };
}

