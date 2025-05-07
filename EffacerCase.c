
#include "EffacerCase.h"
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

/* Fonction pour effacer une case de la grille. Cette fonction remplit la case avec une couleur blanche (fond), puis redessine les bordures noires pour maintenir la grille intacte.*/

void EffacerCase(int colonne, int ligne, int taille_case) {
   /* Change la couleur de dessin à blanc pour effacer le contenu de la case. */
    ChoisirCouleurDessin(CouleurParNom("white"));
    RemplirRectangle(colonne * taille_case, ligne * taille_case, taille_case, taille_case);

    /* Change la couleur de dessin à noir pour redessiner les bordures de la grille. */
    ChoisirCouleurDessin(CouleurParNom("black"));

    /* Dessine le segment supérieur de la case. */
    DessinerSegment(colonne * taille_case, ligne * taille_case, (colonne + 1) * taille_case, ligne * taille_case);

    /* Dessine le segment inférieur de la case. */
    DessinerSegment(colonne * taille_case, (ligne + 1) * taille_case, (colonne + 1) * taille_case, (ligne + 1) * taille_case);

     /* Dessine le segment gauche de la case. */
    DessinerSegment(colonne * taille_case, ligne * taille_case, colonne * taille_case, (ligne + 1) * taille_case);

     /* Dessine le segment droit de la case. */
    DessinerSegment((colonne + 1) * taille_case, ligne * taille_case, (colonne + 1) * taille_case, (ligne + 1) * taille_case);
}
