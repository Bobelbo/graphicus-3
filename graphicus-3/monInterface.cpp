/********
 * Fichier: monInterface.cpp
 * Auteurs: C.-A. Brunet
 * Date: 10 janvier 2024
 * Description: Voir fichier d'entête pour informations.
 *
 * Copyright 2024 Département de génie électrique et génie informatique
 *                Université de Sherbrooke
 ********/

#include <random>
#include <sstream>
#include <iostream>
#include "monInterface.h"
#include "./graphicus-2/canevas.h"
#include "./graphicus-2/cercle.h"
#include "./graphicus-2/rectangle.h"
#include "./graphicus-2/carre.h"

using namespace std;

MonInterface::MonInterface(const char *theName) : GraphicusGUI(theName)
{
	cout << "Création de l'interface graphique" << endl;
	reinitialiserCanevas();
	effacerInformations();
}

void MonInterface::reinitialiserCanevas()
{
	ostringstream os;
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	// On s'amuse à générer aléatoirement un canevas en format texte à chaque
	// fois que la commande de réinitialisation de canevas est choisie par l'usager.
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L a" << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;

	// Ensuite, on dessine ce qui a été généré dans Graphicus
	dessiner(os.str().c_str());
	cout << "reese ette" << endl;
}

void MonInterface::coucheAjouter()
{
	this->canevas.ajouterCouche();
}

void MonInterface::coucheRetirer()
{
	this->canevas.retirerCouche(this->info.coucheActive);
}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	this->canevas.translater(deltaX, deltaY);
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	this->canevas.ajouterForme(new Cercle(x, y, rayon));

	ostringstream os;
	os << &(this->canevas);
	dessiner(os.str().c_str());
}

void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	this->canevas.ajouterForme(new Rectangle(x, y, longueur, largeur));
}

void MonInterface::ajouterCarre(int x, int y, int cote)
{
	this->canevas.ajouterForme(new Carre(x, y, cote));
}

void MonInterface::retirerForme()
{
	this->canevas.retirerForme(0);
}

void MonInterface::modePileChange(bool mode)
{
	// TODO: Implement modePileChange
}

// Actions de navigation
void MonInterface::couchePremiere()
{
	this->canevas.activerCouche(0);
}

void MonInterface::couchePrecedente()
{
	if (this->info.coucheActive > 0)
	{
		this->canevas.activerCouche(this->info.coucheActive - 1);
	}
}

void MonInterface::coucheSuivante()
{
	if (this->info.coucheActive < this->canevas.obtenirNombreCouches() - 1)
	{
		this->canevas.activerCouche(this->info.coucheActive + 1);
	}
}

void MonInterface::coucheDerniere()
{
	this->canevas.activerCouche(this->canevas.obtenirNombreCouches() - 1);
}

void MonInterface::formePremiere()
{
	// TODO: Implement formePremiere
}

void MonInterface::formePrecedente()
{
	// TODO: Implement formePrecedente
}

void MonInterface::formeSuivante()
{
	// TODO: Implement formeSuivante
}

void MonInterface::formeDerniere()
{
	// TODO: Implement formeDerniere
}
