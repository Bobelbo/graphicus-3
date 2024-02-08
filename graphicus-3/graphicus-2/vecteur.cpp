#include "vecteur.h"
#include "couche.h"

template <typename T>
Vecteur<T>::Vecteur()
{
    this->elements = new T *[this->capacite];
    this->taille = 0;
}

template <typename T>
Vecteur<T>::~Vecteur()
{
    this->Vider();

    delete[] this->elements;
}

template <typename T>
bool Vecteur<T>::estVide()
{
    return this->taille == 0;
}

template <typename T>
void Vecteur<T>::Vider()
{
    for (int i = 0; i < this->taille; i++)
    {
        delete this->elements[i];
    }

    this->taille = 0;
}

template <typename T>
void Vecteur<T>::doublerCapacite()
{
    this->capacite *= 2;
    T **nouveauxElements = new T *[this->capacite];

    for (int i = 0; i < this->taille; i++)
    {
        nouveauxElements[i] = this->elements[i];
    }

    delete[] this->elements;
    this->elements = nouveauxElements;
}

template <typename T>
bool Vecteur<T>::ajouterElement(T *forme)
{
    if (forme == nullptr)
    {
        return false;
    }

    if (this->taille == this->capacite)
    {
        this->doublerCapacite();
    }

    this->elements[this->taille] = forme;
    this->taille++;

    return true;
}

template <typename T>
T *Vecteur<T>::supprimerElement(int index)
{
    if (index < 0 || index >= this->taille)
    {
        return nullptr;
    }

    T *forme = this->elements[index];

    for (int i = index; i < this->taille - 1; i++)
    {
        this->elements[i] = this->elements[i + 1];
    }

    this->taille--;

    return forme;
}

template <typename T>
T *Vecteur<T>::obtenirElement(int index)
{
    if (index < 0 || index >= this->taille)
    {
        return nullptr;
    }

    return this->elements[index];
}

template <typename T>
void Vecteur<T>::Afficher(ostream &s)
{
    for (int i = 0; i < this->taille; i++)
    {
        this->elements[i]->afficher(s);
    }
}

template <typename T>
int Vecteur<T>::obtenirTaille()
{
    return this->taille;
}

template class Vecteur<Forme>;
template class Vecteur<Couche>;