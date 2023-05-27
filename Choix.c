#include "Choix.h"


Case choix_case(Case c, Game g){
  int l = 0;
  int h = 0;
  int i = 0;
  do{
    if(i > 0){
      printf("La case sélectionnée n'existe pas ! \n");
    }
    printf("\nSélectionner la case à échanger (avec une lettre comprise entre A et %c pour la colonne et un chiffre compris entre 1 et %d pour la ligne) : ", 'A'+g.col-1, g.lig);
    l = scanf("%c", &c.lettre);
    h = scanf("%d", &c.chiffre);
    Poubelle();
    i++;
  }while(('A' > c.lettre) || (c.lettre > ('A'+g.col-1)) || (1 > c.chiffre) || (c.chiffre > g.lig) || (l != 1) || (h != 1));
  return c;
}



int changementPossible(Game g){
  int val=0;
  int i,j;
  for(i=0;i<g.lig;i++){
    for(j=0;j<g.col;j++){
  
      if((i==0||i==1) &&(j==0 || j==1)){
        
        
      }else if(i==1 ||i==0){
        if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){//verifie si 3 symboles sont alignés en ligne vers la gauche"
          val=1;
        }
      } else if(j==1 ||j==0){
        if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
          val=1;
        }
        else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+2))){//verifie si 3 symboles sont alignés en diagonale vers le haut droit"
          val=1;
        }
      }else if(j==g.col-1 ||j==g.col-2){
        if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){//verifie si 3 symboles sont alignés en ligne vers la gauche"
          val=1;
        }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
          val=1;
        }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-2))){//verifie si 3 symboles sont alignés en diagonale vers le haut gauche"
          val=1;
        }
      }else{
        if((*(*(g.tab+i)+j)==*(*(g.tab+i)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i)+j-2))){ //verifie si 3 symboles sont alignés en ligne vers la gauche"
          val=1;
        }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
          val=1;
        }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j-1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j-2))){//verifie si 3 symboles sont alignés en diagonale vers le haut gauche"
          val=1;
        }else if((*(*(g.tab+i)+j)==*(*(g.tab+i-1)+j+1))&&(*(*(g.tab+i)+j)==*(*(g.tab+i-2)+j+2))){//verifie si 3 symboles sont alignés en diagonale vers le haut droit"
          val=1;
        }
      }
    }
  }
  return val;
}


Game choix(Game g){

  int L = 0;
  int C = 0;
  int val = 0;
  int som;
  int tempo2;
  int x,w,i,j;
  int tempo1;
  do{
    Case c1 = choix_case(c1,g);
    Case c2 = choix_case(c2,g);
    printf("\n");
    printf("Les cases choisies sont : %c%d et %c%d\n", c1.lettre,c1.chiffre, c2.lettre, c2.chiffre);
    L = c1.lettre - c2.lettre;
    C = c1.chiffre - c2.chiffre;
    i = c1.chiffre - 1;
    j = c1.lettre - 'A';
    w = c2.chiffre - 1;
    x = c2.lettre - 'A';
    som=L+C;
    if(*(*(g.tab+i)+j)==7||*(*(g.tab+w)+x)==7){
      L=50;
    }
    tempo1 = *(*(g.tab+i)+j);
    *(*(g.tab+i)+j) = *(*(g.tab+w)+x);
    *(*(g.tab+w)+x) = tempo1;
    printf("%c%d et %c%d\n", c1.lettre,c1.chiffre, c2.lettre, c2.chiffre);

    val = changementPossible(g);
    val = changementPossible(g);

    if (som!=1 && som!=-1){
      printf("Les deux cases ne peuvent pas être échangées car elles ne sont pas côte à côte!\n");
      
      tempo2 = *(*(g.tab+w)+x);
      *(*(g.tab+w)+x) = *(*(g.tab+i)+j);
      *(*(g.tab+i)+j) = tempo2;
      Continuer();
    }
    else if(val == 0){
      printf("Les deux cases ne peuvent pas être échangées car elles ne forment pas de trio une fois déplacées!\n");
      
      tempo2 = *(*(g.tab+w)+x);
      *(*(g.tab+w)+x) = *(*(g.tab+i)+j);
      *(*(g.tab+i)+j) = tempo2;
      Continuer();
    }
    else if(L==50){
      printf("Les cases ne peuvent pas être échangées car une est vide.");
      tempo2 = *(*(g.tab+w)+x);
      *(*(g.tab+w)+x) = *(*(g.tab+i)+j);
      *(*(g.tab+i)+j) = tempo2;
      Continuer();
    }
    else{
      printf("Les deux cases peuvent être échangées !\n");
    }
  }while(((val == 0) || ((-1 == L) && (C == 1) || ((L == -1) && (C == -1)) || ((1 == L) && (C == 1)) || ((L == 1) && (C == -1)))));


  return g;
}
