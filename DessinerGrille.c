#include "DessinerGrille.h"
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

/* Fonction pour dessiner une grille de jeu à l'écran. 
   Paramètres :
   - taille : le nombre de cases choisie par l'utilisateur
   - taille_case : la taille d'une case*/
void DessinerGrille(int taille, int taille_case) {
    int i, j; /* Variables pour parcourir les lignes et les colonnes de la grille. */
    
    /* Parcourt chaque ligne de la grille. */
    for (i = 0; i < taille; i++) {
        /* Parcourt chaque colonne de la ligne en cours. */
        for (j = 0; j < taille; j++) {
            /* Dessine un rectangle représentant une case de la grille. */
            DessinerRectangle(j * taille_case, i * taille_case, taille_case, taille_case);
        }
    }
}
