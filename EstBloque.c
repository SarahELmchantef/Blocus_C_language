#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "EstBloque.h"

/*Afin de determiner si une case est bloqué ou bien libre*/
int EstBloque(int pos[2], int grille[9][9], int taille) {
    int x = pos[0];/* Coordonnée x de la position actuelle */
    int y = pos[1];/* Coordonnée y de la position actuelle */

      /* Vérifie les cases adjacentes dans les directions cardinales et diagonales */

    if (y > 0 && grille[y-1][x] == 0){  /* Case au-dessus */
      return 0;/* Case libre */
    }
    if (y < taille-1 && grille[y+1][x] == 0){  /* Case en dessous */
      return 0;
    }
    if (x > 0 && grille[y][x-1] == 0){/* Case à gauche */
      return 0;
    }
    if (x < taille-1 && grille[y][x+1] == 0){/* Case à droite */
      return 0;
    }
    if (x > 0 && y > 0 && grille[y-1][x-1] == 0){ /* Diagonale en haut à gauche */
      return 0;
    }
    if (x < taille-1 && y > 0 && grille[y-1][x+1] == 0){/* Diagonale en haut à droite */
      return 0;
    }
    if (x > 0 && y < taille-1 && grille[y+1][x-1] == 0){/* Diagonale en bas à gauche */
      return 0;
    }
    if (x < taille-1 && y < taille-1 && grille[y+1][x+1] == 0){/* Diagonale en bas à droite */
      return 0;
    }
    /* Si aucune case libre n'est trouvée, la position est bloquée */
    return 1;
}
