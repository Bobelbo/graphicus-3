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
#include "couche.h"

Canevas::Canevas()
{
   this->couches.ajouterElement(new Couche());

   (*this->couches.obtenirElement(0)).changerEtat(Etat::Active);
}

Canevas::~Canevas()
{
   this->couches.Vider();

   delete &this->couches;
}

bool Canevas::reinitialiser()
{
   bool success = true;

   for (int i = 0; i < this->couches.obtenirTaille(); i++)
   {
      if (!success)
         break;
      success = success && (*this->couches.obtenirElement(i)).reinitialiserCouche();
      if (i == 0)
         (*this->couches.obtenirElement(i)).changerEtat(Etat::Active);
   }

   if (success)
      std::cout << "Réinitialisation du canevas avec succès" << std::endl;

   return success;
}

bool Canevas::reinitialiserCouche(int index)
{
   Couche *couche = &(*this->couches.obtenirElement(index));

   return couche != nullptr && couche->getEtat() != Etat::Active && couche->reinitialiserCouche();
}

bool Canevas::activerCouche(int index)
{
   if (index < 0 || index >= this->couches.obtenirTaille())
      return false;

   bool success = true;
   for (int i = 0; i < this->couches.obtenirTaille(); i++)
   {
      if (i == index)
      {
         success = success && (*this->couches.obtenirElement(i)).changerEtat(Etat::Active);
         if (success)
            std::cout << "Activation de la couche [" << i << "] avec succès" << std::endl;
      }
      else if ((*this->couches.obtenirElement(i)).getEtat() == Etat::Active)
      {
         success = success && (*this->couches.obtenirElement(i)).changerEtat(Etat::Inactive);
         if (success)
            std::cout << "Désactivation de la couche [" << i << "] avec succès" << std::endl;
      }
   }

   return success;
}

bool Canevas::desactiverCouche(int index)
{
   return &(*this->couches.obtenirElement(index)) != nullptr && (*this->couches.obtenirElement(index)).changerEtat(Etat::Inactive);
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   Couche *coucheActive = nullptr;

   for (int i = 0; i < this->couches.obtenirTaille(); i++)
   {
      if ((*this->couches.obtenirElement(i)).getEtat() == Etat::Active)
      {
         coucheActive = &(*this->couches.obtenirElement(i));
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

   for (int i = 0; i < this->couches.obtenirTaille(); i++)
   {
      if ((*this->couches.obtenirElement(i)).getEtat() == Etat::Active)
      {
         coucheActive = &(*this->couches.obtenirElement(i));
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

   for (int i = 0; i < this->couches.obtenirTaille(); i++)
   {
      aireTotal += (*this->couches.obtenirElement(i)).obtenirAireTotal();
   }

   return aireTotal;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   Couche *coucheActive = nullptr;

   for (int i = 0; i < this->couches.obtenirTaille(); i++)
   {
      if ((*this->couches.obtenirElement(i)).getEtat() == Etat::Active)
      {
         coucheActive = &(*this->couches.obtenirElement(i));
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
    cout << this->couches.obtenirTaille() << endl;
   for (int i = 0; i < this->couches.obtenirTaille(); i++)
   {
       cout << i << endl;
      Couche couche = *this->couches.obtenirElement(i);
      char etatCouche = couche.getEtat() == Etat::Active     ? 'a'
                        : couche.getEtat() == Etat::Inactive ? 'x'
                                                             : 'i';
      s << "L " << etatCouche << endl;
      s << couche;
   }
}

void Canevas::ajouterCouche()
{
   this->couches.ajouterElement(new Couche());
}

void Canevas::retirerCouche(int index)
{
   Couche *couche = this->couches.obtenirElement(index);
   if (couche != nullptr && this->couches.obtenirTaille() > 1)
   {
      this->couches.supprimerElement(index);
   }
}

int Canevas::obtenirNombreCouches()
{
   return this->couches.obtenirTaille();
}
