/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "tests.h"
#include "cercle.h"
#include "carre.h"

void Tests::tests_unitaires_formes()
{
   // Tests sur la classe cercle
   std::cout << "TESTS - CERCLE" << std::endl;
   Cercle *cercle = new Cercle();
   try
   {
      Cercle *cercle = new Cercle(10, -10, -5);
   }
   catch (std::invalid_argument &e)
   {
      std::cout << "Test réussi! " << std::endl;
   }

   // Tests sur la classe carre
   std::cout << "TESTS - CARRE" << std::endl;
   Carre *carre = new Carre();
   try
   {
      Carre *carre = new Carre(10, -10, -5);
   }
   catch (std::invalid_argument &e)
   {
      std::cout << "Test réussi! " << std::endl;
   }
}

void Tests::tests_unitaires_vecteur()
{
   std::cout << "TESTS - VECTEUR" << std::endl;
   // Tests sur la classe Vecteur
   Vecteur vecteur = *(new Vecteur());
   Cercle *cercle = new Cercle();
   Carre *carre = new Carre();
   vecteur.ajouterForme(cercle);
   vecteur.ajouterForme(carre);
   vecteur.Afficher(std::cout);
   vecteur.supprimerForme(0);
   vecteur.Afficher(std::cout);
   vecteur.supprimerForme(0);
   vecteur.Afficher(std::cout);
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
   std::cout << "TESTS - COUCHE" << std::endl;
   Couche couche = *(new Couche());
   Cercle *cercle = new Cercle();
   Carre *carre = new Carre();
   couche.ajouterForme(cercle);
   couche.ajouterForme(carre);
   couche.afficher(std::cout);
   couche.supprimerForme(0);
   couche.afficher(std::cout);
   couche.supprimerForme(0);
   couche.afficher(std::cout);
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
   std::cout << "TESTS - CANEVAS" << std::endl;
   Canevas canevas = *(new Canevas());
   Cercle *cercle = new Cercle();
   Carre *carre = new Carre();
   canevas.ajouterForme(cercle);
   canevas.ajouterForme(carre);
   canevas.afficher(std::cout);
   canevas.retirerForme(0);
   canevas.afficher(std::cout);
   canevas.retirerForme(0);
   canevas.afficher(std::cout);
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   std::cout << "TESTS UNITAIRES" << std::endl;
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   std::cout << "TESTS APPLICATION" << std::endl;
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl;
   // Bloc 1
   Canevas canevas = *(new Canevas());

   canevas.activerCouche(2);
   canevas.ajouterForme(new Cercle(0, 1, 5));
   canevas.ajouterForme(new Carre(1, 2, 6));
   canevas.ajouterForme(new Rectangle(2, 3, 4, 9));

   canevas.activerCouche(1);
   canevas.ajouterForme(new Rectangle(0, 0, 12, 3));

   std::cout << "Affichage du bloc de test 1" << std::endl;
   canevas.afficher(std::cout);
   std::cout << "Aire du canevas: " << canevas.aire() << std::endl;

   // Bloc 2
   canevas.activerCouche(0);
   canevas.ajouterForme(new Rectangle());
   canevas.ajouterForme(new Carre());
   canevas.ajouterForme(new Cercle());

   canevas.activerCouche(2);
   canevas.translater(2, 1);

   std::cout << "Affichage du bloc de test 2" << std::endl;
   canevas.afficher(std::cout);
   std::cout << "Aire du canevas: " << canevas.aire() << std::endl;

   // Bloc 3
   canevas.activerCouche(0);
   canevas.retirerForme(1);

   canevas.reinitialiserCouche(1);
   canevas.activerCouche(4);

   std::cout << "Affichage du bloc de test 3" << std::endl;
   canevas.afficher(std::cout);
   std::cout << "Aire du canevas: " << canevas.aire() << std::endl;

   // Bloc 4
   canevas.reinitialiser();

   std::cout << "Affichage du bloc de test 4" << std::endl;
   canevas.afficher(std::cout);
   std::cout << "Aire du canevas: " << canevas.aire() << std::endl;

   // Bloc 5
   canevas.activerCouche(3);
   canevas.ajouterForme(new Carre(10, 10, 10));
   canevas.ajouterForme(nullptr);

   canevas.activerCouche(6);

   std::cout << "Affichage du bloc de test 5" << std::endl;
   canevas.afficher(std::cout);
   std::cout << "Aire du canevas: " << canevas.aire() << std::endl;
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;
   // Il faut ajouter les operations realisant ce scenario de test.
}
