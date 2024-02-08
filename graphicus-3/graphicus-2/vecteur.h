#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include "forme.h"

using namespace std;


template <typename T>
class Vecteur
{
private:
    static const int CAPACITE_INITIALE = 2;
    T **elements;
    int taille;
    int capacite = CAPACITE_INITIALE;

    void doublerCapacite();

public:
    Vecteur();
    ~Vecteur();

    bool estVide();
    void Vider();

    int obtenirTaille();

    bool ajouterElement(T *element);
    T *supprimerElement(int index);
    T *obtenirElement(int index);

    void Afficher(ostream &s);
};

#endif