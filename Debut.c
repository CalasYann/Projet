
#include "Debut.h"


Game caracGrille(Game g){
  int ret;
  int val=0;
  g.score=0;
  do{  
    do{
      printf("Avec combien de symboles voulez vous jouer(Ce nombre doit être entre 4 et 6 compris) ?\n");
      ret=scanf("%d",&g.symb);
      Poubelle();
    }while((g.symb<4 || g.symb>6) || ret!=1);
  
    do{
      printf("Avec combien de ligne voulez vous jouer(Ce nombre doit être entre 7 et 20) ?\n");
      ret=scanf("%d",&g.lig);
      Poubelle();
    }while((g.lig<7 || g.lig>20) || ret!=1);
  
    do{
      printf("Avec combien de colonne voulez vous jouer(Ce nombre doit être entre 7 et 20) ?\n");
      ret=scanf("%d",&g.col);
      Poubelle();
    }while((g.col<7 || g.col>20) || ret!=1);
    do{
      printf("Vous allez commencé une partie avec une grille %dx%d et %d symboles. Tapez 1 pour commencer et 2 pour changer les paraètres.\n",g.lig,g.col,g.symb);
      ret=scanf("%d",&val);
      Poubelle();
    }while((val!=1&&val!=2) || ret!=1);
  }while(val==2);

  
  g.tab=malloc(g.lig*sizeof(int*));//création d'un tableau avec le nombre de ligne demandé
  int i,j;
  int temp;
  for (i=0;i<g.lig;i++){
    *(g.tab+i)=malloc(g.col*sizeof(int)); //création d'un tableau pour chaque ligne avec le nombre de colonne demandé
  }
  return g;
}






int coupPossibleLigne(Game g, int i, int j,int a){
  if(j>0){
  
    if(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1)){//test coup possible en ligne
      if(i<g.lig-1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j+1)&&(*(*(g.tab+i)+j+1)!=7)){
          a=1;
        }
      }
      if(j<g.col-2){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i)+j+2)&&(*(*(g.tab+i)+j+1)!=7)){
          a=1;
        }
      }if(i>0&&j<g.col-1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1)&&(*(*(g.tab+i)+j+1)!=7)){
          a=1;
        }
      }
      if(j>1){
        if(i>0){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-2)&&(*(*(g.tab+i)+j-2)!=7)){
            a=1;
          }
        }
        if(i<g.lig-1){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j-2)&&(*(*(g.tab+i)+j-2)!=7)){
            a=1;
          }
        }
      }
      if(j>2){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-3)&&(*(*(g.tab+i)+j-2)!=7)){
          a=1;
        }
      }
    }
  }
  if(j>1){
    if(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2)&&(*(*(g.tab+i)+j-1)!=7)){

      if(i<g.lig-1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j-1)){
          a=1;
        }
      }
      if(i>0){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1)){
          a=1;
        }
      }
    }
  }
  return a;
}


int coupPossibleColonne(Game g, int i, int j,int a){

  if(i>0){
    
    if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j)){//check if coup possible en haut en colonne
      if(i>1){ 
        if(j>0){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-1)&&(*(*(g.tab+i-2)+j)!=7)){
            a=1;
          }
        }
        if(j<g.col-1){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+1)&&(*(*(g.tab+i-2)+j)!=7)){
            a=1;
          }
        }
      }if(i>2){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-3)+j)&&(*(*(g.tab+i-2)+j)!=7)){
          a=1;
        }
      }
      if(i<g.lig-1){
        if(j<g.col-1){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j+1)&&(*(*(g.tab+i+1)+j)!=7)){
            a=1;
          }
        }
        if(j>0){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j-1)&&(*(*(g.tab+i+1)+j)!=7)){
            a=1;
          }
        }
      }
      if(i<g.lig-2){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i+2)+j)&&(*(*(g.tab+i+1)+j)!=7)){
          a=1;
        }
      }    
    }
  }
  if(i>1){
    if(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j)&&(*(*(g.tab+i-1)+j)!=7)){ 

      if(j>0){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1)){
          a=1;
        }
      }
      if(j<g.col-1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1)){
          a=1;
        }
      }
    }
  }
  return a;
}


int coupPossibleDiagGauche(Game g, int i, int j, int a){
  if(i>0&&j>0){
    if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1)){//check if coup possible en diagonale haut gauche
      if(i>2&&j>1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-3)+j-2)&&(*(*(g.tab+i-2)+j-2)!=7)){
          a=1;
        }
      }
      if(i>1&&j>2){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-3)&&(*(*(g.tab+i-2)+j-2)!=7)){
          a=1;
        }
      }
      if(i<g.lig-1&&j<g.col-2){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j+2)&&(*(*(g.tab+i+1)+j+1)!=7)){
          a=1;
        }
      }
      if(i<g.lig-2&&j<g.col-1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i+2)+j+1)&&(*(*(g.tab+i+1)+j+1)!=7)){
          a=1;
        }
      }     
    }
  }
  if(i>1&&j>1){
    if(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-2)&&(*(*(g.tab+i-1)+j-1)!=7)){ 
      if(i>0){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j)){
          a=1;
        }
        if(j>1){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-2)){
            a=1;
          }
        }
      }
      if(j>0){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1)){
          a=1;
        }
        if(i>1){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-1)){
            a=1;
          }
        }
      }
    }
  }
  return a;
}

int coupPossibleDiagDroit(Game g, int i,int j,int a){
  if(i>0&&j<g.col-1){
    
    if(*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1)){ //check if coup possible en diagonale haut droit
      if(i>2&&j>1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-3)+j+2)&&(*(*(g.tab+i-2)+j+2)!=7)){
          a=1;
        }
      }if(i>1&&j>2){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+3)&&(*(*(g.tab+i-2)+j+2)!=7)){
          a=1;
        }
      }
      if(i<g.lig-1&&j>1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j-2)&&(*(*(g.tab+i+1)+j-1)!=7)){
          a=1;
        }
      }if(i<g.lig-2&&j>0){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i+2)+j-1)&&(*(*(g.tab+i+1)+j-1)!=7)){
          a=1;
        }
      }  
    }
  }
  if(i>1&&j<g.col-2){
    if(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+2)&&(*(*(g.tab+i-1)+j+1)!=7)){ 
      if(i<g.lig-1){
        if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j)){
          a=1;
        }
        if(j<g.col-2){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i+1)+j+2)){
            a=1;
          }
        }
      }
      if(j<g.col-1){
            if(*(*(g.tab+i)+j)==*(*(g.tab+i)+j+1)){
              a=1;
            }
        if(i<g.lig-2){
          if(*(*(g.tab+i)+j)==*(*(g.tab+i+2)+j+1)){
            a=1;
          }
        }     
      } 
    } 
  }
  return a;
}



int coupPossible(Game g){
  int a=0;
  int b=0;
  int c=0;
  int d=0;
  int i,j;
  for(i=0;i<g.lig;i++){
    for(j=0;j<g.col;j++){
      if(*(*(g.tab+i)+j)!=7){
        a=coupPossibleLigne(g,i,j,a);
        b=coupPossibleColonne(g, i, j,b);
        c=coupPossibleDiagDroit(g, i, j,c);
        d=coupPossibleDiagGauche(g, i, j,d);
        if(a==1||b==1||c==1||d==1){
          printf("a=%d ,b=%d,c=%d, d=%d",a,b,c,d);
          printf("i=%d, j=%d",i,j);
          return 1;
        }
      }
    }
  }
  return 0;
}


Game creerGrille(Game g){// permet de remplir aléatoirement la grille avec des chiffres de 0 au nombre de symboles demandé sans présence de triplets alignés

  int i,j;
  int val;
  int com;
  int a=0;
  do{
    for (i=0;i<g.lig;i++){
      for(j=0;j<g.col;j++){
        do{
          val=1;
          com=0;
          *(*(g.tab+i)+j)=rand()%g.symb;
          if((i==0||i==1) &&(j==0 || j==1)){
        
          }else if(i==1 ||i==0){
            if(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1)){
            
            }
            if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){//verifie si 3 symboles sont alignés en ligne vers la gauche"
              val=0;
            }
          }else if(j==1 ||j==0){
            if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
              val=0;
            }
            else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+2))){//verifie si 3 symboles sont alignés en diagonale vers le haut droit"
              val=0;
            }
          }else if(j==g.col-1 ||j==g.col-2){
            if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){//verifie si 3 symboles sont alignés en ligne vers la gauche"
              val=0;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
              val=0;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-2))){//verifie si 3 symboles sont alignés en diagonale vers le haut gauche"
              val=0;
            }
          }else{
            if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){ //verifie si 3 symboles sont alignés en ligne vers la gauche"
              val=0;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
              val=0;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-2))){//verifie si 3 symboles sont alignés en diagonale vers le haut gauche"
              val=0;
            }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+2))){//verifie si 3 symboles sont alignés en diagonale vers le haut droit"
              val=0;
            }
          }
        
        }while(val==0);
      }
    }
    a=coupPossible(g);
  }while(a==0);
  return g;
}
