#include "carre.h"
#include "forme.h"
#include <iostream>

Carre::Carre() {}

Carre::Carre(int x, int y, float cote) : Rectangle(x, y, cote, cote) {}

Carre::~Carre()
{
    cout << "Destruction du carre" << endl;
}

void Carre::SetCote(float cote)
{
    if (cote > 0)
    {
        (*this)._largeur = cote;
        (*this)._hauteur = cote;
    }
    else
        cerr << "Le cote doit etre positif et plus grand que 0" << endl;
}

void Carre::setLargeur(float largeur)
{
    SetCote(largeur);
}

void Carre::setHauteur(float hauteur)
{
    SetCote(hauteur);
}

void Carre::afficher(ostream &s)
{
    s << "K " << ancrage.x << " " << ancrage.y << " " << this->getHauteur() << endl;
}
