/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "forme.h"
#include "couche.h"
#include "vecteur.h"

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();

   void nuke();

   bool reinitialiser();
   bool reinitialiserCouche(int index);

   void ajouterCouche();
   void retirerCouche(int index);

   bool activerCouche(int index);
   bool desactiverCouche(int index);

   bool ajouterForme(Forme *p_forme);
   bool retirerForme(int index);

   void setModePile(bool mode);

   Couche *obtenirCouche(int index);

   int obtenirNombreCouches();

   double aire();
   bool translater(int deltaX, int deltaY);
   void afficher(ostream &s);

   friend ostream &operator<<(ostream &s, Canevas &c);
   friend istream &operator>>(istream &s, Canevas &c);

private:
   bool modePile;
   Vecteur<Couche> couches;
};

#endif
