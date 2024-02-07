/********
 * Fichier: tests.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour les tests de Graphicus.
 *    Ce fichier peut etre adapte a vos besoins de tests. Ce fichier
 *    fait partie de la distribution de Graphicus.
********/

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "canevas.h"

using namespace std;

class Tests
{
public:
   // Methodes pour les tests unitaires des classes
   static void tests_unitaires_formes();
   static void tests_unitaires_vecteur();
   static void tests_unitaires_couche();
   static void tests_unitaires_canevas();
   static void tests_unitaires(); // Appel de tous les tests unitaires

   // Methodes pour les tests unitaires des classes
   static void tests_application_cas_01();
   static void tests_application_cas_02();
   static void tests_application(); // Appel de tous les tests applicatifs
};

#endif
