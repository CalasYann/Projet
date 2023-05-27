#include "Utile.h"

void Poubelle(){ //permet de vidé l'appuie touche après un scanf
  int ret=0;
  char c='0';
  while(c!='\n'|| ret!=1){
    ret=scanf("%c",&c);
  }
}

void Continuer(){
  int a=0;
  int ret;
  do{
    printf("Taper 1 pour continuer : ");
    ret=scanf("%d",&a);
    Poubelle();
  }while(a!=1||ret!=1);
}


int tourSuivant(){
  int choix=0;
  int ret;
  do{
    printf("\nTaper 1 pour continuer la partie\n Taper 2 pour sauvegarder\n Taper 3 pour Sauvegarder et continuer\n Taper 4 pour Sauvegarder et Quitter\n Taper 5 pour quitter sans Sauvegarder.\n");
    ret=scanf("%d",&choix);
    Poubelle();
  }while((choix!=2 && choix!=1&& choix!=3&& choix!=4&& choix!=5)||ret!=1);
  return choix;
}

void Attendre(){
  sleep(1);
}
