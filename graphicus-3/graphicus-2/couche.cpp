/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "couche.h"
#include <iostream>

Couche::Couche()
{
    this->etat = Etat::Initialise;
    this->formes = *(new Vecteur<Forme>());
}

Couche::~Couche()
{
    delete &this->formes;
}

bool Couche::ajouterForme(Forme *forme)
{
    return this->formes.ajouterElement(forme);
}

Forme *Couche::supprimerForme(int index)
{
    if (this->etat != Etat::Active)
    {
        return nullptr;
    }

    return this->formes.supprimerElement(index);
}

Forme *Couche::obtenirForme(int index)
{
    return this->formes.obtenirElement(index);
}

bool Couche::deplacerCouche(int deltaX, int deltaY)
{
    if (this->etat != Etat::Active)
    {
        return false;
    }
    int index = 0;
    while (true)
    {
        Forme *forme = this->obtenirForme(index);
        if (forme == nullptr)
        {
            break;
        }
        Coordonnee nouvellePos = {
            forme->getAncrage().x + deltaX,
            forme->getAncrage().y + deltaY,
        };
        forme->setAncrage(nouvellePos);
        index++;
    }

    return true;
}

bool Couche::changerEtat(Etat nouvelEtat)
{
    switch (nouvelEtat)
    {
    case Etat::Active:
        this->etat = Etat::Active;
        return true;
    case Etat::Inactive:
        this->etat = Etat::Inactive;
        return true;
    default:
        return false;
    }
}

bool Couche::reinitialiserCouche()
{
    this->etat = Etat::Initialise;
    this->formes.Vider();
    return true;
}

double Couche::obtenirAireTotal()
{
    if (this->etat == Etat::Initialise)
        return 0;

    double aireTotal = 0;
    int index = 0;
    while (true)
    {
        Forme *forme = this->obtenirForme(index);
        if (forme == nullptr)
        {
            break;
        }
        aireTotal += forme->aire();

        index++;
    }
    return aireTotal;
}

void Couche::afficher(ostream &s)
{
    string etat;
    switch (this->etat)
    {
    case Etat::Initialise:
        etat = "Initialisée";
        break;
    case Etat::Active:
        etat = "Active";
        break;
    case Etat::Inactive:
        etat = "Inactive";
        break;
    default:
        etat = "Inconnu";
        break;
    }
    s << "État=" << etat << endl;

    if (this->formes.estVide())
    {
        s << "Couche Vide" << endl;
    }
    else
    {
        this->formes.Afficher(s);
    }
}

Etat Couche::getEtat()
{
    return this->etat;
}

ostream &Couche::operator<<(ostream &s)
{
    for (int i = 0; i < this->formes.obtenirTaille(); i++)
    {
        s << this->formes.obtenirElement(i) << endl;
    }

    return s;
}