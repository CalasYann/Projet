#include "Fichier.h"

Game save(Game g){

  FILE *f=NULL;
  int i,j;

  f=fopen("Sauvegarde/save.txt","w");
  if(f==NULL){
    printf("Echec de l'ouverture du fichier.\n");
    printf("Code d'erreur : %d\n",errno);
    printf("! Sauvegarde non fait !\n " );
    return g;
  }else {
    fprintf(f,"%d ",g.col);
    fprintf(f,"%d ",g.lig);
    fprintf(f,"%d ",g.symb);
    fprintf(f,"%d ",g.score);
    for(i=0;i<g.lig;i++){
      for(j=0;j<g.col;j++){
        fprintf(f,"%d ",*(*(g.tab+i)+j));
      }
    }
  }
  
  fclose(f);
  return g;
}

Game openSave(Game g){
  FILE*f=NULL;
  int ret1, ret2, ret3, ret4, ret5;
  int i,j;
  f=fopen("Sauvegarde/save.txt","r");
  if(f==NULL){
    printf("Echec de l'ouverture du fichier.\n");
    if(errno==2){
      printf("Aucun fichier de sauvegarde\n");
    }
    else{
      printf("Code d'erreur : %d\n",errno);
    }
    return g;
  }else {
    ret1=fscanf(f,"%d",&g.col);
    ret2=fscanf(f,"%d",&g.lig);
    ret3=fscanf(f,"%d",&g.symb);
    ret5=fscanf(f,"%d",&g.score);
    g.tab=malloc(sizeof(int*)*g.lig);
    for(i=0;i<g.lig;i++){
      *(g.tab+i)=malloc(sizeof(int)*g.col);
      for(j=0;j<g.col;j++){
        ret4=fscanf(f,"%d",(*(g.tab+i)+j));
        if(ret4!=1){
          j=100;
          i=100;
        }
      }
    }
  
    if(ret1!=1||ret2!=1||ret3!=1||ret4!=1||ret5!=1){
      printf("Erreur dans la récupération de la grille");
      g.col=0;
    }
  }
  fclose(f);
  return g;
}


void HighScore(Game g){
  FILE* f=NULL;
  int highscore;
  int ret;
  
  f=fopen("Sauvegarde/Highscore.txt","r");
  if(f==NULL){
    printf("Echec de l'ouverture du fichier.\n");
    printf("Code d'erreur : %d\n",errno);
    
  }
  ret=fscanf(f,"%d",&highscore);
  if(ret!=1){
    printf("Echec de la sauvegarde du Highscore");
  }
  else if(highscore<g.score){
    printf(" Vous avez battu le Records! Le nouveau highsocre est %d\n",g.score);
    fclose(f);
    f=fopen("Sauvegarde/Highscore.txt","w");
    if(f==NULL){
    printf("Echec de l'ouverture du fichier.\n");
    printf("Code d'erreur : %d\n",errno);
    }
    fprintf(f,"%d ",g.score);
    fclose(f);
  }else{

    printf(" Vous n'avez pas battu le record du jeu. Peut-être la prochaine fois\n");
    fclose(f);
  }

}
