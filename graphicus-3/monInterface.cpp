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
#include <fstream>
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
	this->canevas.reinitialiser();
	this->canevas.setModePile(false);
	this->update();
	cout << "Reset TOTAL" << endl;
}

void MonInterface::coucheAjouter()
{
	this->canevas.ajouterCouche();
}

void MonInterface::coucheRetirer()
{
	this->canevas.retirerCouche(this->info.coucheActive);
	this->update();
}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	this->canevas.translater(deltaX, deltaY);
	this->update();
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	this->canevas.ajouterForme(new Cercle(x, y, rayon));
	this->info.nbFormesCanevas = this->info.nbFormesCanevas += 1;
	this->update();
}

void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	this->canevas.ajouterForme(new Rectangle(x, y, longueur, largeur));
	this->info.nbFormesCanevas = this->info.nbFormesCanevas += 1;
	this->update();
}

void MonInterface::ajouterCarre(int x, int y, int cote)
{
	this->canevas.ajouterForme(new Carre(x, y, cote));
	this->info.nbFormesCanevas = this->info.nbFormesCanevas += 1;
	this->update();
}

void MonInterface::retirerForme()
{
	this->canevas.retirerForme(0);
	this->info.nbFormesCanevas = this->info.nbFormesCanevas -= 1;
	this->update();
}

void MonInterface::modePileChange(bool mode)
{
	this->canevas.setModePile(mode);
	this->update();
}

// Actions de navigation
void MonInterface::couchePremiere()
{
	this->canevas.activerCouche(0);
	this->info = this->canevas.obtenirCouche(0)->changeInformations(this->info);

	this->info.coucheActive = 0;
	this->setInformations(this->info);
}

void MonInterface::couchePrecedente()
{
	if (this->info.coucheActive > 0)
	{
		this->canevas.activerCouche(this->info.coucheActive - 1);
		this->info = this->canevas.obtenirCouche(this->info.coucheActive - 1)->changeInformations(this->info);
		this->info.coucheActive = this->info.coucheActive - 1;
		this->setInformations(this->info);
	}
}

void MonInterface::coucheSuivante()
{
	if (this->info.coucheActive < this->canevas.obtenirNombreCouches() - 1)
	{
		this->canevas.activerCouche(this->info.coucheActive + 1);
		this->info = this->canevas.obtenirCouche(this->info.coucheActive + 1)->changeInformations(this->info);
		this->info.coucheActive = this->info.coucheActive + 1;
		this->setInformations(this->info);
	}
}

void MonInterface::coucheDerniere()
{
	this->canevas.activerCouche(this->canevas.obtenirNombreCouches() - 1);
	this->info = this->canevas.obtenirCouche(this->canevas.obtenirNombreCouches() - 1)->changeInformations(this->info);
	this->info.coucheActive = this->canevas.obtenirNombreCouches() - 1;
	this->setInformations(this->info);
}

void MonInterface::formePremiere()
{
	if (this->canevas.obtenirCouche(this->info.coucheActive)->obtenirNombreFormes() > 0)
	{
		this->info.formeActive = 0;
	}
	else
	{
		this->info.formeActive = 0;
	}

	this->setInformations(this->info);
}

void MonInterface::formePrecedente()
{
	if (this->canevas.obtenirCouche(this->info.coucheActive)->obtenirNombreFormes() == 0)
	{
		this->info.formeActive = -1;
	}
	else
	{
		if (this->info.formeActive > 0)
		{
			this->info.formeActive = this->info.formeActive - 1;
		}
		else
		{
			this->info.formeActive = 0;
		}
	}
	this->setInformations(this->info);
}

void MonInterface::formeSuivante()
{
	if (this->canevas.obtenirCouche(this->info.coucheActive)->obtenirNombreFormes() == 0)
	{
		this->info.formeActive = -1;
	}
	else
	{
		if (this->info.formeActive < this->canevas.obtenirCouche(this->info.coucheActive)->obtenirNombreFormes() - 1)
		{
			this->info.formeActive = this->info.formeActive + 1;
		}
		else
		{
			this->info.formeActive = this->canevas.obtenirCouche(this->info.coucheActive)->obtenirNombreFormes() - 1;
		}
	}

	this->setInformations(this->info);
}

void MonInterface::formeDerniere()
{
	this->info.formeActive = this->canevas.obtenirCouche(this->info.coucheActive)->obtenirNombreFormes() - 1;
	this->setInformations(this->info);
}

bool MonInterface::ouvrirFichier(const char *nomFichier)
{
	cout << "Ouverture du fichier " << nomFichier << " ..." << endl;
	ifstream fichier(nomFichier);
	if (fichier.fail())
	{
		return false;
	}
	fichier >> this->canevas;
	fichier.close();
	this->update();
	cout << "Fermeture du fichier " << nomFichier << " ..." << endl;
	return true;
}

bool MonInterface::sauvegarderFichier(const char *nomFichier)
{
	ofstream fichier(nomFichier);
	fichier << this->canevas;
	fichier.close();
	return true;
}

void MonInterface::update()
{
	ostringstream os;
	os << canevas;
	cout << os.str();
	dessiner(os.str().c_str());

	this->info.aireCanevas = this->canevas.aire();
	this->setInformations(this->info);
}
