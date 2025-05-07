#include <graph.h>
#include <stdlib.h>
#include <stdio.h>
#include "gestion_joueur2.h"
#include "EstAdjacente.h"
#include "EffacerCase.h"

/* Gère le tour du deuxième joueur (joueur 2), qui se déplace sur la grille et condamne une case. On n'utilisera cette notation, la case prendra les valeurs: 0 = pour libre, 1 = pour occupé par un joueur, 2 = pour condamnée*/

void gestion_joueur2(int grille[][9], int taille, int taille_case, int pos_vio[2], int *tour) {
  int x_souris, y_souris; /* Coordonnées de la souris */
  int colonne, ligne;     /* Indices de colonne et de ligne correspondants */

  /* Vérifie si un clic souris a eu lieu pour débuter l'action du joueur.*/
  if (SourisCliquee()) {
    x_souris = _X; /* Récupère la position X de la souris */
    y_souris = _Y; /* Récupère la position Y de la souris */
    colonne = x_souris / taille_case; /* Calcul de la colonne cliquée */
    ligne = y_souris / taille_case;   /* Calcul de la ligne cliquée */

    /* Vérifie si la case cliquée est libre (grille[ligne][colonne] == 0) et si elle est adjacente à la position actuelle du joueur violet. */
    if (grille[ligne][colonne] == 0 && (pos_vio[0] == -1 || EstAdjacente(pos_vio[1], pos_vio[0], ligne, colonne))) {

      /* Efface l'ancienne position du joueur violet s'il a déjà joué.*/
      
      if (pos_vio[0] != -1) {
	EffacerCase(pos_vio[0], pos_vio[1], taille_case);
	grille[pos_vio[1]][pos_vio[0]] = 0; /* Libère l'ancienne case */
      }

      /* Met à jour la position du joueur violet */
      pos_vio[0] = colonne;
      pos_vio[1] = ligne;
      grille[ligne][colonne] = 1; /* Marque la case comme occupée */

      /* Dessine la nouvelle position du joueur 2 en violet */
      ChoisirCouleurDessin(CouleurParNom("purple"));
      RemplirRectangle(colonne * taille_case, ligne * taille_case, taille_case, taille_case);

      /* Boucle pour permettre au joueur de condamner une case. */
      while (1) {
	if (SourisCliquee()) {
	  x_souris = _X; /* Récupère la position X de la souris */
	  y_souris = _Y; /* Récupère la position Y de la souris */
	  colonne = x_souris / taille_case; /* Calcul de la colonne cliquée */
	  ligne = y_souris / taille_case;   /* Calcul de la ligne cliquée */
	  
	  /*Vérifie si la case à condamner est libre.  */
	  if (grille[ligne][colonne] == 0) {
	    /* Dessine une croix pour marquer la case condamnée */
	    ChoisirCouleurDessin(CouleurParNom("purple"));
	    DessinerSegment(colonne * taille_case, ligne * taille_case,(colonne + 1) * taille_case, (ligne + 1) * taille_case);
	    DessinerSegment(colonne * taille_case, (ligne + 1) * taille_case, (colonne + 1) * taille_case, ligne * taille_case);

	    grille[ligne][colonne] = 2; /* Marque la case comme condamnée */
	    break; /* Sort de la boucle */
	  }
	}
      }

      /*Passe le tour au joueur 1. */
      *tour = 0;
    }
  }
}
