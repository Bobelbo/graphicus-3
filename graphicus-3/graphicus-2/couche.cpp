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
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"
#include <iostream>
#include "graphicusGUI.h"

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
    for (int i = 0; i < this->formes.obtenirTaille(); i++)
    {
        this->formes.obtenirElement(i)->afficher(cout);
        this->formes.obtenirElement(i)->afficher(s);
    }
}

Etat Couche::getEtat()
{
    return this->etat;
}

Informations Couche::changeInformations(Informations info)
{
    switch (this->getEtat())
    {
    case Etat::Active:
        strcpy(info.etatCouche, "Active");
    case Etat::Inactive:
        strcpy(info.etatCouche, "Inactive");
    default:
        strcpy(info.etatCouche, "Initialise");
    }

    info.nbFormesCouche = this->formes.obtenirTaille();
    info.aireCouche = this->obtenirAireTotal();
    info.formeActive = this->formes.estVide() ? -1 : 0;

    return info;
}

ostream &operator<<(ostream &s, Couche &c)
{
    c.afficher(s);
    return s;
}

istream &operator>>(istream &s, Couche &c)
{
    string line;
    std::getline(s, line);
    Forme *nouvelleForme;
    switch (line[0])
    {
    case 'C':
        nouvelleForme = new Cercle(line[2], line[4], line[6]);
        break;
    case 'R':
        nouvelleForme = new Rectangle(line[2], line[4], line[6], line[8]);
        break;
    case 'K':
        nouvelleForme = new Carre(line[2], line[4], line[6]);
        break;
    default:
        nouvelleForme = nullptr;
    }
    if (nouvelleForme != nullptr)
    {
        c.ajouterForme(nouvelleForme);
    }

    return s;
}

int Couche::obtenirNombreFormes()
{
    return this->formes.obtenirTaille();
}