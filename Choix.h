#ifndef CHOIX_H
  #define CHOIX_H
  
  #include "Debut.h"
  #include "Afficher.h"



  typedef struct{
    char lettre;
    int chiffre;
  }Case;



  Case choix_case(Case c, Game g);
  int changementPossible(Game g);
  Game choix(Game g);
  



#endif
