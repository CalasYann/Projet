#include "Afficher.h"

void afficherGrille(Game g){
  printf("\x1B[1;1H"); //mettre le curseur en haut a droite
  printf("\x1B[0J"); //Effecer ce qui se trouve sous le curseur
  int i,j;
  int temp;
  char c='A';
  printf("     ");
  for(i=0;i<g.col;i++){ // créer l'affichage de la grille
  printf("%c ",c+i);
  }
  printf("\n");
  printf("     ");
  for(i=0;i<g.col;i++){
  printf("_ ");
  }
  printf("\n");
  
  for (i=0;i<g.lig;i++){
    printf("%2d | ",i+1);
    for(j=0;j<g.col; j++){
      temp=g.tab[i][j];
      
      switch (temp) { //Remplace les numéros de la grille par les lettres qui leur correspond
        case 0 :
          printf("\x1B[38;2;255;0;0m"); //ROUGE
          printf("X ");
          printf("\x1B[0m");
        break;
        
        case 1 :
          printf("\x1B[38;2;0;255;0m"); //VERT
          printf("E ");
          printf("\x1B[0m");
        break;
        
        case 2 :
          printf("\x1B[38;2;0;0;255m"); //BLEU
          printf("M ");
          printf("\x1B[0m");
        break;
        
        case 3 :
          printf("\x1B[38;2;255;0;255m"); //ROSE
          printf("G ");
          printf("\x1B[0m");
        break;
        
        case 4 :
          printf("\x1B[38;2;255;255;0m"); //JAUNE
          printf("S ");
          printf("\x1B[0m");
        break;
        
        case 5 :
          printf("\x1B[38;2;0;255;255m"); //CYAN
          printf("W ");
          printf("\x1B[0m");
        break;

        case 7 :
          printf("  ");
        break;
      
      }
    }
    printf("\n");
  }
  printf("\n Votre Score: %d Spikes\n",g.score);
}


void Nettoyage(){
  printf("\x1B[1;1H"); //mettre le curseur en haut a droite
  printf("\x1B[0J"); //Effecer ce qui se trouve sous le curseur
}
