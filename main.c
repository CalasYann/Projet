#include "Afficher.h"
#include "Choix.h"
#include "Debut.h"
#include "Fichier.h"
#include "Jeu.h"
#include "Menu.h"
#include "Utile.h"

int main(void) {
  srand(time(NULL));
  Game g;
  g.tab = NULL;
  int choice;
  int erreur = 0;
  int next;
  int count = 0;
  int **cases_a_supprimer;
  int x;
  int y;
  int combo;
  sup s;

  int coups = 0;
  /*cases_a_supprimer = malloc(100 * sizeof(int *));
  for (int i = 0; i < 100; i++) {
    cases_a_supprimer[i] =
        malloc(2 * sizeof(int)); // un tableau 2D de 100 tableaux de 2 cases
                                 // (coordonnées des cases à supprimer)
  }
*/
  do {
    next = 0;
    erreur = 0;
    choice = Menu(choice);
    if (choice == 3) {
      Parametre();
    } else if (choice == 1 || choice == 2) {
      if (choice == 1) { // l'utilisateur créer une nouvelle grille
        g = caracGrille(g);
        g = creerGrille(g);
        afficherGrille(g);
      } else if (choice == 2) { // l'utilisateur reprend une ancienne grille
        g = openSave(g); // faire les fichiers de sauvegarde et avoir la nouvelle grille

        if (g.col < 0 || g.col > 20 || g.lig < 0 || g.lig > 20 || g.symb < 4 || g.symb > 6 || g.tab == NULL || g.score < 0) {
          printf("! ERREUR !\n ");
          Continuer();
          erreur = 1;
        }
        if (erreur == 0) {
          printf("Partie récupérée !");
          afficherGrille(g);
        }
      }
      if (erreur == 0) {
        do { // boucle qui va servir au déroulement de la partie
          Nettoyage();
          afficherGrille(g);
          g = choix(g);
          coups++;
          combo=1;
          s.val=1;
          do {
            s=supprimer(g,s);
            g=caseSupprime(g,s,combo);
            g = Gravite(g);
            afficherGrille(g);
            if(combo>1){
              printf("\nCombo x%d\n",combo);
            }
            Attendre();
            combo++;
          }while (s.val==0);

          afficherGrille(g);
          if(coupPossible(g)==0){
            next=5;
            HighScore(g);
            Continuer();
          }
          else {
            next = tourSuivant();
            if (next == 3 || next == 4) {
              g = save(g);
            }
          }
        } while (next != 4 &&
                 next != 5); // mettre dans le while les conditions d'arrêt du
                             // jeu et de retour au menu principal.
      }
    }

  } while (choice != 4); // Le jeu se ferme

  Nettoyage();
  return 0;
}
