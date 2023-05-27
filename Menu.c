#include"Menu.h"
#include <string.h>


int Menu(int choix){ // Menu de notre jeu
  int ret;
  FILE* f=NULL;
  int highscore;
  

  
  do{
    printf("\x1B[1;1H"); //mettre le curseur en haut a droite
    printf("\x1B[0J"); //Effecer ce qui se trouve sous le curseur


  
    printf("\x1B[38;2;229;123;190m");
    printf("              \x1B[4m");
    printf("CY PROUVANCE™️\n");
    printf("\x1B[0m");
    printf("       Bienvenue sur ");
    printf("\x1B[38;2;229;123;190m");
    printf("\x1B[4m");
    printf("CY PROUVANCE™️ :\n");
    printf("\x1B[0m");
    printf("         Que voulez vous faire ?\n");
    printf("           \x1B[38;2;230;213;150m1) Nouvelle Partie\x1B[0m\n");
    printf("     \x1B[38;2;115;200;140m2) Reprendre une Partie Commencée\x1B[0m\n");
    printf("            \x1B[38;2;123;129;209m3) Règles du Jeu\x1B[0m\n");
    printf("            \x1B[38;2;158;115;189m4) Quitter le Jeu\x1B[0m\n");
    
    f=fopen("Sauvegarde/Highscore.txt","r");
    if(f==NULL){
      printf("Echec de l'ouverture du fichier.\n");
      printf("Code d'erreur : %d\n",errno);
    }
    ret=fscanf(f,"%d",&highscore);
    if(ret!=1){
      printf("Echec de l'affichage du Highscore");
      printf("test");
    }
    else{
      printf("        Le Highscore est de ");
      printf("\x1B[38;2;211;44;90m%d\x1B[0m\n\n", highscore);
    }
    ret=scanf("%d",&choix);
    Poubelle();
  }while(ret!=1 || choix<0 || choix>4);
  return choix;
}

void Parametre(){
  
    Nettoyage();
    printf("  Les regles de CY PROUVANCE™️ sont simples. Terminer votre grille en accumulant le maximum de Spikes.\n  Pour ce faire vous devez aligner des caractères identiques afin de réaliser des lignes de trois ou plus en ligne, colonne ou diagonale comme ceci:\n");
    printf("\x1B[38;2;255;0;0m"); //ROUGE
    printf(" X X X\n");
    printf("\x1B[0m");
    printf("  OU\n");
    printf("\x1B[38;2;255;0;0m"); //ROUGE
    printf("   X \n");
    printf("   X \n");
    printf("   X \n");
    printf("\x1B[0m");
    printf("  OU\n");
    printf("\x1B[38;2;255;0;0m"); //ROUGE
    printf(" X\n");
    printf("   X \n");
    printf("     X \n");
    printf("\x1B[0m");
    printf("  OU\n");
    printf("\x1B[0m");printf("\x1B[38;2;255;0;0m"); //ROUGE
    printf("     X \n"); 
    printf("   X \n");
    printf(" X\n");
    printf("\x1B[0m");
    printf("  Pour réaliser des combinaisons vous allez devoir échanger des cases qui sont à coté en ligne, en colonne ou en diagonale comme ceci: \n");
    printf("\x1B[0m");printf("\x1B[38;2;255;0;0m"); //ROUGE
    printf(" X X"); 
    printf("\x1B[38;2;0;255;255m"); //CYAN
    printf(" W \n");
    printf(" W W");
    printf("\x1B[38;2;255;0;0m"); //ROUGE
    printf(" X \n");
    printf("\x1B[0m");
    printf("  Le W et le X\n");
    printf("  Pour maximiser vos Spikes, Réalisez des combinaisons plus longues avec des réactions et des combos. \n Si malheureseument, plus aucun coup n'est posssible dans votre grille, la partie est finie et votre score est sauvegardée si c'est le HighScore.\n");
  Continuer();
}
