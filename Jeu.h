#ifndef JEU_H
  #define JEU_H

  #include "Debut.h"
  #define TAILLE 100

  typedef struct{
  int val;
  int tab[TAILLE];
}sup;

  
  Game Gravite(Game g);
  sup supprimer(Game g,sup s);
  Game caseSupprime(Game g, sup s, int combo);

#endif
