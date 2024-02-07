#include "vecteur.h"

Vecteur::Vecteur()
{
    this->formes = new Forme *[this->capacite];
    this->taille = 0;
}

Vecteur::~Vecteur()
{
    this->Vider();

    delete[] this->formes;
}

bool Vecteur::estVide()
{
    return this->taille == 0;
}

void Vecteur::Vider()
{
    for (int i = 0; i < this->taille; i++)
    {
        delete this->formes[i];
    }

    this->taille = 0;
}

void Vecteur::doublerCapacite()
{
    this->capacite *= 2;
    Forme **nouvellesFormes = new Forme *[this->capacite];

    for (int i = 0; i < this->taille; i++)
    {
        nouvellesFormes[i] = this->formes[i];
    }

    delete[] this->formes;
    this->formes = nouvellesFormes;
}

bool Vecteur::ajouterForme(Forme *forme)
{
    if (forme == nullptr)
    {
        return false;
    }

    if (this->taille == this->capacite)
    {
        this->doublerCapacite();
    }

    this->formes[this->taille] = forme;
    this->taille++;

    return true;
}

Forme *Vecteur::supprimerForme(int index)
{
    if (index < 0 || index >= this->taille)
    {
        return nullptr;
    }

    Forme *forme = this->formes[index];

    for (int i = index; i < this->taille - 1; i++)
    {
        this->formes[i] = this->formes[i + 1];
    }

    this->taille--;

    return forme;
}

Forme *Vecteur::obtenirForme(int index)
{
    if (index < 0 || index >= this->taille)
    {
        return nullptr;
    }

    return this->formes[index];
}

void Vecteur::Afficher(ostream &s)
{
    for (int i = 0; i < this->taille; i++)
    {
        this->formes[i]->afficher(s);
    }
}
