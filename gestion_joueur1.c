#include <graph.h>
#include <stdlib.h>
#include <stdio.h>
#include "gestion_joueur1.h"
#include "EstAdjacente.h"
#include "EffacerCase.h"

/* Gère le tour du premier joueur (joueur 1), qui se déplace sur la grille et condamne une case.*/

void gestion_joueur1(int grille[][9], int taille, int taille_case, int pos_rose[2], int *tour) {
    int x_souris, y_souris; /* Coordonnées de la souris */
    int colonne, ligne;/* Indices de colonne et de ligne correspondant */


    /* le premier joueur se déplace et condamne une case*/
    if (SourisCliquee()) {/*Vérifie si un clic souris a eu lieu pour débuter l'action du joueur.*/
      x_souris = _X; /* Récupère la position X de la souris */
      y_souris = _Y; /* Récupère la position Y de la souris */
      colonne = x_souris / taille_case; /* Calcul de la colonne cliquée */
      ligne = y_souris / taille_case;   /* Calcul de la ligne cliquée */

        /* Vérifie si la case cliquée est libre (grille[ligne][colonne] == 0) et si elle est adjacente à la position actuelle du joueur 1.*/
      if (grille[ligne][colonne] == 0 && (pos_rose[0] == -1 || EstAdjacente(pos_rose[1], pos_rose[0], ligne, colonne))) {

            /*Efface l'ancienne position du joueur 1 s'il a déjà joué. */
	if (pos_rose[0] != -1) {
	  EffacerCase(pos_rose[0], pos_rose[1], taille_case);
	  grille[pos_rose[1]][pos_rose[0]] = 0; /* Libère l'ancienne case */
	}

	/* Met à jour la position du joueur 1 */
	pos_rose[0] = colonne;
	pos_rose[1] = ligne;
	grille[ligne][colonne] = 1; /* Marque la case comme occupée */

	/* Dessine la nouvelle position du joueur 1 en rose */
	ChoisirCouleurDessin(CouleurParNom("pink"));
	RemplirRectangle(colonne * taille_case, ligne * taille_case, taille_case, taille_case);

	/* Boucle pour permettre au joueur de condamner une case. */
	while (1) {
	  if (SourisCliquee()) {
	    x_souris = _X; /* Récupère la position X de la souris */
	    y_souris = _Y; /* Récupère la position Y de la souris */
	    colonne = x_souris / taille_case; /* Calcul de la colonne cliquée */
	    ligne = y_souris / taille_case;   /* Calcul de la ligne cliquée */
	    

	    /* Vérifie si la case à condamner est libre.*/
	    if (grille[ligne][colonne] == 0) {
	      /* Dessine une croix pour marquer la case condamnée */
	      ChoisirCouleurDessin(CouleurParNom("pink"));
	      DessinerSegment(colonne * taille_case, ligne * taille_case, (colonne + 1) * taille_case, (ligne + 1) * taille_case);
	      DessinerSegment(colonne * taille_case, (ligne + 1) * taille_case, (colonne + 1) * taille_case, ligne * taille_case);

	      grille[ligne][colonne] = 2; /* Marque la case comme condamnée */
	      break; /* Sort de la boucle */
	    }
	  }
	}

	/* Passe le tour au joueur 2.*/
	*tour = 1;
      }
    }
}
