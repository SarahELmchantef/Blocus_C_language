#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "init.h"

void PlacerPionInitial(int taille_case, int grille[9][9], int pos_rose[2], int pos_vio[2], int mode_de_jeu, int taille) {
  int x, y, colonne, ligne;

  /* Placer le pion rose */
  while (1) {
    if (SourisCliquee()) {
      /* Récupérer la position du clic de la souris */
      x = _X;
      y = _Y;
      
      /* Convertir les coordonnées en indices de la grille */
      colonne = x / taille_case;
      ligne = y / taille_case;
      
      /* Vérifier si la case est libre */
      if (grille[ligne][colonne] == 0) {
	/* Enregistrer la position du pion rose */
	pos_rose[0] = colonne;
	pos_rose[1] = ligne;
	
	/* Marquer la case comme occupée */
	grille[ligne][colonne] = 1;
	
	/* Dessiner le pion rose */
	ChoisirCouleurDessin(CouleurParNom("pink"));
	RemplirRectangle(colonne * taille_case, ligne * taille_case, taille_case, taille_case);
	
	/* Sortir de la boucle une fois le pion placé */
	break;
      }
    }
  }
  
  /* Placer le pion bleu */
  if (mode_de_jeu == 1) {
    /* Mode IA : placer le pion violet de manière aléatoire */
    int trouve = 0;
    
    while (!trouve) {
      /* Générer une position aléatoire */
      colonne = rand() % taille;
      ligne = rand() % taille;

      /* Vérifier si la case est libre */
      if (grille[ligne][colonne] == 0) {
	/* Enregistrer la position du pion violet */
	pos_vio[0] = colonne;
	pos_vio[1] = ligne;
	
	/* Marquer la case comme occupée */
	grille[ligne][colonne] = 1;
	
	/* Dessiner le pion violet */
	ChoisirCouleurDessin(CouleurParNom("purple"));
	RemplirRectangle(colonne * taille_case, ligne * taille_case, taille_case, taille_case);
	
	/* Indiquer que le pion a été placé */
	trouve = 1;
      }
    }
  } else {
    /* Mode deux joueurs : placer le pion violet manuellement */
    while (1) {
      if (SourisCliquee()) {
	/* Récupérer la position du clic de la souris */
	x = _X;
	y = _Y;
	
	/* Convertir les coordonnées en indices de la grille */
	colonne = x / taille_case;
	ligne = y / taille_case;
	
	/* Vérifier si la case est libre */
	if (grille[ligne][colonne] == 0) {
	  /* Enregistrer la position du pion bleu */
	  pos_vio[0] = colonne;
	  pos_vio[1] = ligne;
	  
	  /* Marquer la case comme occupée */
	  grille[ligne][colonne] = 1;
	  
	  /* Dessiner le pion bleu */
	  ChoisirCouleurDessin(CouleurParNom("purple"));
	  RemplirRectangle(colonne * taille_case, ligne * taille_case, taille_case, taille_case);
	  
	  /* Sortir de la boucle une fois le pion placé */
	  break;
	}
      }
    }
  }
}
