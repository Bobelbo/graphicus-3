/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "canevas.h"

Canevas::Canevas()
{
   for (int i = 0; i < MAX_COUCHES; i++)
   {
      this->couches[i] = *(new Couche());
   }

   this->couches[0].changerEtat(Etat::Active);
}

Canevas::~Canevas()
{
   for (int i = 0; i < MAX_COUCHES; i++)
   {
      delete &this->couches[i];
   }

   delete &this->couches;
}

bool Canevas::reinitialiser()
{
   bool success = true;

   for (int i = 0; i < MAX_COUCHES; i++)
   {
      if (!success)
         break;
      success = success && this->couches[i].reinitialiserCouche();
      if (i == 0)
         this->couches[i].changerEtat(Etat::Active);
   }

   if (success)
      std::cout << "Réinitialisation du canevas avec succès" << std::endl;

   return success;
}

bool Canevas::reinitialiserCouche(int index)
{
   Couche *couche = &this->couches[index];

   return couche != nullptr && couche->getEtat() != Etat::Active && couche->reinitialiserCouche();
}

bool Canevas::activerCouche(int index)
{
   if (index < 0 || index >= MAX_COUCHES)
      return false;

   bool success = true;
   for (int i = 0; i < MAX_COUCHES; i++)
   {
      if (i == index)
      {
         success = success && this->couches[i].changerEtat(Etat::Active);
         if (success)
            std::cout << "Activation de la couche [" << i << "] avec succès" << std::endl;
      }
      else if (this->couches[i].getEtat() == Etat::Active)
      {
         success = success && this->couches[i].changerEtat(Etat::Inactive);
         if (success)
            std::cout << "Désactivation de la couche [" << i << "] avec succès" << std::endl;
      }
   }

   return success;
}

bool Canevas::desactiverCouche(int index)
{
   return &this->couches[index] != nullptr && this->couches[index].changerEtat(Etat::Inactive);
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   Couche *coucheActive = nullptr;

   for (int i = 0; i < MAX_COUCHES; i++)
   {
      if (this->couches[i].getEtat() == Etat::Active)
      {
         coucheActive = &this->couches[i];
         break;
      }
   }

   if (coucheActive == nullptr)
      return false;

   bool success = coucheActive->ajouterForme(p_forme);

   if (success)
      std::cout << "Ajout de la forme [" << typeid(*p_forme).name() << "] avec succès" << std::endl;

   return success;
}

bool Canevas::retirerForme(int index)
{
   Couche *coucheActive = nullptr;

   for (int i = 0; i < MAX_COUCHES; i++)
   {
      if (this->couches[i].getEtat() == Etat::Active)
      {
         coucheActive = &this->couches[i];
         break;
      }
   }

   if (coucheActive == nullptr)
      return false;

   Forme *success = coucheActive->supprimerForme(index);
   if (success != nullptr)
   {
      std::cout << "retrait de la forme [" << typeid(success).name() << "] avec succès" << std::endl;
      return true;
   }
   else
   {
      return false;
   }
}
double Canevas::aire()
{
   double aireTotal = 0;

   for (int i = 0; i < MAX_COUCHES; i++)
   {
      aireTotal += this->couches[i].obtenirAireTotal();
   }

   return aireTotal;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   Couche *coucheActive = nullptr;

   for (int i = 0; i < MAX_COUCHES; i++)
   {
      if (this->couches[i].getEtat() == Etat::Active)
      {
         coucheActive = &this->couches[i];
         break;
      }
   }

   if (coucheActive == nullptr)
      return false;

   bool success = coucheActive->deplacerCouche(deltaX, deltaY);

   if (success)
      std::cout << "Translation de la couche active avec succès" << std::endl;

   return success;
}

void Canevas::afficher(ostream &s)
{
   for (int i = 0; i < MAX_COUCHES; i++)
   {
      s << "----- Couche " << i << " -----" << endl;
      this->couches[i].afficher(s);
   }
}
