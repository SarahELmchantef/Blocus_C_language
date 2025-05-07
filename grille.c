#include "grille.h"
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

/*Cette fonction initialise une grille carrée de taille donnée. Toutes les cases de la grille sont remplies avec la valeur 0.*/

void InitialiserGrille(int taille, int grille[9][9]) {
  int i,j;/* Variables utilisées pour parcourir les lignes et colonnes */
  
    for (i = 0; i < taille; i++) {/* Parcourt toutes les cases de la grille */
        for (j = 0; j < taille; j++) {
            grille[i][j] = 0;/* Initialise chaque case à 0 */
        }
    }
}



