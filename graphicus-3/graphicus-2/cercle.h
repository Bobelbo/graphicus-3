#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "forme.h"

using namespace std;

class Cercle : public Forme
{
private:
   float _rayon;

public:
   Cercle();
   Cercle(int x, int y, float rayon);
   ~Cercle();

   float getRayon();
   void setRayon(float rayon);

   double aire();
   void afficher(ostream &s);
};

#endif