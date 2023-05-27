#include "Utile.h"

void Poubelle(){ //permet de vider l'appuie touche après un scanf
  int ret=0;
  char c='0';
  while(c!='\n'|| ret!=1){
    ret=scanf("%c",&c);
  }
}

void Continuer(){ //permet de mettre le programme en pause en attendant que le joueur veuille continuer (en appuyany sur 1)
  int a=0;
  int ret;
  do{
    printf("Taper 1 pour continuer : ");
    ret=scanf("%d",&a);
    Poubelle();
  }while(a!=1||ret!=1);
}


int tourSuivant(){ // affiche les options possibles à la fin de chaque tour et demande à l'utilisateur laquelle il souhaite faire (renvoie un int entre 1 et 5
  int choix=0;
  int ret;
  do{
    printf("\nTaper 1 pour continuer la partie\n Taper 2 pour Sauvegarder et continuer\n Taper 3 pour Sauvegarder et Quitter\n Taper 4 pour quitter sans Sauvegarder.\n");
    ret=scanf("%d",&choix);
    Poubelle();
  }while((choix!=2 && choix!=1&& choix!=3&& choix!=4)||ret!=1);
  return choix;
}

void Attendre(){
  sleep(1);
}
