#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "forme.h"

using namespace std;

class Rectangle : public Forme
{
protected:
    float _largeur;
    float _hauteur;

public:
    Rectangle();
    Rectangle(int x, int y, float largeur, float hauteur);
    ~Rectangle();

    float getLargeur();
    float getHauteur();
    virtual void setLargeur(float largeur);
    virtual void setHauteur(float hauteur);

    double aire();
    virtual void afficher(ostream &s);
    virtual ostream &operator<<(ostream &s) override;
};

#endif