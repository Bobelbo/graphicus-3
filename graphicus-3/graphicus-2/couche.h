#include "forme.h"
#include "etat.h"
#include "vecteur.h"

/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef COUCHE_H
#define COUCHE_H

class Couche
{
private:
   Vecteur<Forme> formes; // Vecteur de pointeurs de formes geometriques
   Etat etat;             // Etat de la couche

public:
   // Constructeur
   Couche();
   ~Couche();

   // Manipulation Formes
   bool ajouterForme(Forme *forme);
   Forme *supprimerForme(int index);
   Forme *obtenirForme(int index);

   // Manipulation Couche
   bool deplacerCouche(int deltaX, int deltaY);

   // Manipulation Etat
   bool changerEtat(Etat nouvelEtat);
   bool reinitialiserCouche();

   // Divers
   double obtenirAireTotal();
   void afficher(ostream &s);
   friend ostream &operator<<(ostream &s, Couche &couche)
   {
       cout << "couche" << endl;
       couche.afficher(s);
       cout << "fini couche" << endl;
       return s;
   }
   // Getter / setter
   Etat getEtat();
};

#endif
