#
# Auteur: C.-A. Brunet
# Date: 04 janvier 2024
# Modifie par : ...
# Date : ...
# Description: compilation de graphicus-02. Ce fichier fait partie de 
#	la distribution de Graphicus.
#


graphicus-02: graphicus-02.o tests.o canevas.o couche.o forme.o rectangle.o cercle.o carre.o vecteur.o
	g++ -o graphicus-02 graphicus-02.o tests.o canevas.o couche.o forme.o rectangle.o cercle.o carre.o vecteur.o

graphicus-02.o: graphicus-02.cpp canevas.h couche.h forme.h 
	g++ -c -g graphicus-02.cpp

tests.o: tests.cpp tests.h canevas.h couche.h forme.h
	g++ -c -g  tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h etat.h
	g++ -c -g  canevas.cpp

couche.o: couche.cpp couche.h forme.h etat.h
	g++ -c -g  couche.cpp

forme.o: forme.cpp forme.h
	g++ -c -g  forme.cpp
	
rectangle.o: rectangle.cpp rectangle.h forme.h
	g++ -c -g  rectangle.cpp
	
carre.o: carre.cpp rectangle.h carre.h
	g++ -c -g  carre.cpp
	
vecteur.o: vecteur.cpp vecteur.h forme.h
	g++ -c -g vecteur.cpp
	
cercle.o: cercle.cpp cercle.h forme.h
	g++ -c -g  cercle.cpp

clean:
	rm  -f *.o graphicus-02
