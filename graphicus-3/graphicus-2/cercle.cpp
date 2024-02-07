#include "cercle.h"
#include "forme.h"
#include <iostream>

Cercle::Cercle() : Forme(0, 0)
{
    _rayon = 1;
}

Cercle::Cercle(int x, int y, float rayon) : Forme(x, y)
{
    if (rayon > 0)
        _rayon = rayon;
    else
        throw invalid_argument("Le rayon doit etre positif et plus grand que 0");
}

Cercle::~Cercle()
{
    cout << "Destruction du cercle" << endl;
}

float Cercle::getRayon()
{
    return _rayon;
}

void Cercle::setRayon(float rayon)
{
    if (rayon > 0)
        _rayon = rayon;
    else 
        cerr << "Le rayon doit etre positif et plus grand que 0" << endl;
}

double Cercle::aire()
{
    return 3.14159 * _rayon * _rayon;
}

void Cercle::afficher(ostream &s)
{
    s << "Cercle (x=" << ancrage.x << ", y=" << ancrage.y << ", r=" << _rayon << ", aire=" << aire() << ")" << endl;
}