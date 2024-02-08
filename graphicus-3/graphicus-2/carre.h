#ifndef CARRE_H
#define CARRE_H

#include <iostream>
#include "rectangle.h"

using namespace std;

class Carre : public Rectangle
{
private:
    void SetCote(float cote);

public:
    Carre();
    Carre(int x, int y, float cote);
    ~Carre();

    virtual void setLargeur(float largeur) override;
    virtual void setHauteur(float hauteur) override;
    virtual void afficher(ostream &s) override;
};

#endif