all : prouvance

Jeu.o : Jeu.c Jeu.h
	gcc -c Jeu.c -o Jeu.o

Choix.o : Choix.c Choix.h
	gcc -c Choix.c -o Choix.o

Utile.o : Utile.c Utile.h
	gcc -c Utile.c -o Utile.o

Afficher.o : Afficher.c Afficher.h
	gcc -c Afficher.c -o Afficher.o

Fichier.o : Fichier.c Fichier.h
	gcc -c Fichier.c -o Fichier.o

Debut.o : Debut.c Debut.h
	gcc -c Debut.c -o Debut.o

Menu.o : Menu.c Menu.h
	gcc -c Menu.c -o Menu.o

main.o : main.c Afficher.h Debut.h Utile.h Fichier.h Jeu.h Menu.h Choix.h
	gcc -c main.c -o main.o


prouvance : main.o Debut.o Utile.o Afficher.o Menu.o Fichier.o Choix.o Jeu.o
	gcc *.o -o prouvance

clean : 
	rm -f *.o
	rm -f nathan
