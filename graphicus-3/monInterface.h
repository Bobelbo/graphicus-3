/********
 * Fichier: monInterface.h
 * Auteurs: C.-A. Brunet
 * Date: 10 janvier 2024
 * Description: La classe MonInterface teste l'interface usager GraphicusGUI.
 *
 * Copyright 2024 Département de génie électrique et génie informatique
 *                Université de Sherbrooke
 ********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "graphicusGUI.h"
#include "./graphicus-2/canevas.h"

class MonInterface : public GraphicusGUI
{
private:
	Informations info;
	Canevas canevas;

	// Sert a refresh le canevas
	void update();

public:
	MonInterface(const char *theName = nullptr);

	virtual bool ouvrirFichier(const char*);
	virtual bool sauvegarderFichier(const char *);

	// Actions de canevas, de couches et de formes
	virtual void reinitialiserCanevas();
	virtual void coucheAjouter();
	virtual void coucheRetirer();
	virtual void coucheTranslater(int deltaX, int deltaY);
	virtual void ajouterCercle(int x, int y, int rayon);
	virtual void ajouterRectangle(int x, int y, int longueur, int largeur);
	virtual void ajouterCarre(int x, int y, int cote);
	virtual void retirerForme();
	virtual void modePileChange(bool mode);

	// Actions de navigation
	virtual void couchePremiere();
	virtual void couchePrecedente();
	virtual void coucheSuivante();
	virtual void coucheDerniere();
	virtual void formePremiere();
	virtual void formePrecedente();
	virtual void formeSuivante();
	virtual void formeDerniere();
};

#endif // MONINTERFACE_H