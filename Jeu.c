#include "Jeu.h"


Game Gravite(Game g) { //produit l'effet de gravité vers le haut sur les cases de la grille (renvoie la structure Game de la partie)
  int i, j,w;
  int temp=0;
  for(w=0;w<g.col;w++){
    for (i = 1; i < g.lig; i++){
      for (j = 0; j < g.col; j++){
        if (*(*(g.tab + i-1) + j) == 7){
          temp = *(*(g.tab + i - 1) + j);
          *(*(g.tab + i - 1) + j) = *(*(g.tab + i) + j);
          *(*(g.tab + i) + j) = temp;
        }
      }
    }
  }
  return g;
}


sup supprimer(Game g, sup s){ //détecte les séries de 3 ou plus de cases du même type et les ajoute à s.tab sous forme d'un int
  int i;
  int j;
  int val=1;
  int com;
  com=0;
  int c1,c2,c3;
  for(i=0;i<TAILLE;i++){
    s.tab[i]=-1;
  }
  for (i=0;i<g.lig;i++){
      for(j=0;j<g.col;j++){
        if(*(*(g.tab+i)+j)!=7){

          if((i==0||i==1) &&(j==0 || j==1)){
        
          }else if(i==1 ||i==0){
            if(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1)){
            
            }
            if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){//verifie si 3 symboles sont alignés en ligne vers la gauche"
              val=0;
              c1=i*10+j;
              c2=i*10+j-1;
              c3=i*10+j-2;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }
          }else if(j==1 ||j==0){
            if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
              val=0;
              c1=(i*10)+j;
              c2=((i-1)*10)+j;
              c3=((i-2)*10)+j;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }
            else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+2))){//verifie si 3 symboles sont alignés en diagonale vers le haut droit"
              val=0;
              c1=i*10+j;
              c2=(i-1)*10+j+1;
              c3=(i-2)*10+j+2;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }
          }else if(j==g.col-1 ||j==g.col-2){
            if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){//verifie si 3 symboles sont alignés en ligne vers la gauche"
              val=0;
              c1=i*10+j;
              c2=i*10+j-1;
              c3=i*10+j-2;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
              val=0;
              c1=i*10+j;
              c2=(i-1)*10+j;
              c3=(i-2)*10+j;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-2))){//verifie si 3 symboles sont alignés en diagonale vers le haut gauche"
              val=0;
              c1=i*10+j;
              c2=(i-1)*10+j-1;
              c3=(i-2)*10+j-2;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }
          }else{
            if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){ //verifie si 3 symboles sont alignés en ligne vers la gauche"
              val=0;
              c1=i*10+j;
              c2=i*10+j-1;
              c3=i*10+j-2;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
              val=0;
              c1=i*10+j;
              c2=(i-1)*10+j;
              c3=(i-2)*10+j;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-2))){//verifie si 3 symboles sont alignés en diagonale vers le haut gauche"
              val=0;
              c1=i*10+j;
              c2=(i-1)*10+j-1;
              c3=(i-2)*10+j-2;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+2))){//verifie si 3 symboles sont alignés en diagonale vers le haut droit"
              val=0;
              c1=i*10+j;
              c2=(i-1)*10+j+1;
              c3=(i-2)*10+j+2;
              s.tab[com]=c1;
              com++;
              c2=s.tab[com]=c2;
              com++;
              c3=s.tab[com]=c3;
              com++;
            }
          }
        }
      }
    }
  s.val=val;
  return s;
}

Game caseSupprime(Game g, sup s, int combo){ //supprime toutes les cases contenues dans s (qui font donc partie d'une serie de 3 ou +) et calcule le combo
  int w;
  int i,j;
  for(w=0;w<TAILLE;w++){
    if(s.tab[w]>=0){
      j=s.tab[w]%10;
      i=(s.tab[w]-j)/10;
      if(*(*(g.tab+i)+j)!=7){
        *(*(g.tab+i)+j)=7;
        g.score=g.score+(50*combo);
      }
    }else{
      w=TAILLE;
    }
  }
  return g;
}

void finGame(Game g){
  printf("Partie Terminée, Aucun coup n'est possible. Votre score finale est de %d. ",g.score);
  Continuer();
}
