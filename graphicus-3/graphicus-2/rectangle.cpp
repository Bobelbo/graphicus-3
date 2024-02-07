#include "rectangle.h"
#include "forme.h"
#include <iostream>

Rectangle::Rectangle() : Forme(0, 0)
{
    _largeur = 1;
    _hauteur = 1;
}

Rectangle::Rectangle(int x, int y, float largeur, float hauteur) : Forme(x, y)
{
    if (largeur > 0 && hauteur > 0)
    {
        _largeur = largeur;
        _hauteur = hauteur;
    }
    else
        throw invalid_argument("Les dimensions doivent etre positives et plus grand que 0");
}

Rectangle::~Rectangle()
{
    cout << "Destruction du rectangle" << endl;
}

float Rectangle::getLargeur()
{
    return _largeur;
}

float Rectangle::getHauteur()
{
    return _hauteur;
}

void Rectangle::setLargeur(float largeur)
{
    if (largeur > 0)
        _largeur = largeur;
    else
        cerr << "La largeur doit etre positif et plus grand que 0" << endl;
}

void Rectangle::setHauteur(float hauteur)
{
    if (hauteur > 0)
        _hauteur = hauteur;
    else
        cerr << "La hauteur doit etre positif et plus grand que 0" << endl;
}

double Rectangle::aire()
{
    return _largeur * _hauteur;
}

void Rectangle::afficher(ostream &s)
{
    s << "Rectangle (x=" << ancrage.x << ", y=" << ancrage.y << ", l=" << _largeur << ", h=" << _hauteur << ", aire=" << aire() << ")" << endl;
}