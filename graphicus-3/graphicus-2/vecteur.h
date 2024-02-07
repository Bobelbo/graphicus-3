#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include "forme.h"

using namespace std;


class Vecteur
{
private:
    static const int CAPACITE_INITIALE = 2;
    Forme **formes;
    int taille;
    int capacite = CAPACITE_INITIALE;

    void doublerCapacite();

public:
    Vecteur();
    ~Vecteur();

    bool estVide();
    void Vider();

    bool ajouterForme(Forme *forme);
    Forme *supprimerForme(int index);
    Forme *obtenirForme(int index);

    void Afficher(ostream &s);
};

#endif