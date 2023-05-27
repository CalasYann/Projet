#ifndef DEBUT_H
  #define DEBUT_H

  #include <stdlib.h>
  #include <stdio.h>
  #include <time.h>
  #include "Utile.h"

  typedef struct{
    int col;
    int lig;
    int symb;
    int** tab;
    int score;
  }Game;
  Game caracGrille(Game g);
  Game creerGrille(Game g);
  int coupPossibleLigne(Game g,int i,int j,int a);
  int coupPossibleColonne(Game g,int i,int j,int a);
  int coupPossibleDiagGauche(Game g,int i,int j,int a);
  int coupPossibleDiagDroite(Game g,int i,int j,int a);
  int coupPossible(Game g);


#endif
