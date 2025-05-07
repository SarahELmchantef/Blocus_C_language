#include <graph.h>
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

void AfficherMenu(int* taille, int* mode_de_jeu) {
  /* Variables de gestion */
  int taille_valide = 0;
  int mode_valide = 0;
  int x, y;
  
  /* Déclaration des sprites */
  int f3Sprite,f4Sprite,f5Sprite,f6Sprite,f7Sprite,f8Sprite,f9Sprite,chatSprite,m1Sprite,m2Sprite;

    

  /* Charger l'image de fond*/
  ChargerImageFond("images/fond.png");
  
  /*Charger les sprites pour les tailles de terrain (dans la premiere page de menu*/
  f3Sprite = ChargerSprite("images/3f33.jpeg");
  f4Sprite = ChargerSprite("images/4f44.jpeg");
  f5Sprite = ChargerSprite("images/5f55.jpeg");
  f6Sprite = ChargerSprite("images/6f66.jpeg");
  f7Sprite = ChargerSprite("images/7f77.jpeg");
  f8Sprite = ChargerSprite("images/8f88.jpeg");
  f9Sprite = ChargerSprite("images/9f99.jpeg");
  chatSprite = ChargerSprite("images/chat.png");
  
  /* Charger les sprites pour les modes de jeu*/
  m1Sprite = ChargerSprite("images/1joueur.jpg");
  m2Sprite = ChargerSprite("images/2joueurs.jpeg");
  
  /* Vérifier si les sprites ont été chargés correctement*/
  if (f3Sprite == -1 || f4Sprite == -1 || f5Sprite == -1 ||
      f6Sprite == -1 || f7Sprite == -1 || f8Sprite == -1 ||
      f9Sprite == -1 || m1Sprite == -1 || m2Sprite == -1) {
    FermerGraphique();
    return;
  }
  
  /*Afficher le texte de bienvenue*/
  EcrireTexte(50, 30, "Bienvenue au jeu Blocus!", 2);
  EcrireTexte(50, 90, "Choisissez la taille de la grille:", 1);
  EcrireTexte(50, 500, "Choisissez votre mode de jeu:", 1);
  
  /*Afficher les sprites pour les tailles de terrain*/
  AfficherSprite(f3Sprite, 50, 120);
  AfficherSprite(f4Sprite, 50, 190);
  AfficherSprite(f5Sprite, 50, 260);
  AfficherSprite(f6Sprite, 50, 330);
  AfficherSprite(f7Sprite, 200, 120);
  AfficherSprite(f8Sprite, 200, 190);
  AfficherSprite(f9Sprite, 200, 260);
  AfficherSprite(chatSprite, 220, 90);
  
  /* Afficher les sprites pour les modes de jeu*/
  AfficherSprite(m1Sprite, 50, 550);
  AfficherSprite(m2Sprite, 200, 550);
  
  /* Attendre que l'utilisateur sélectionne une taille et un mode */
  while (!(taille_valide && mode_valide)) {
    if (SourisCliquee()) {
      x = _X;
      y = _Y;
      
      if (!taille_valide) {/* Vérifier la sélection de la taille de la grille */
	if (y >= 120 && y <= 170 && x >=50 && x <= 140) {
	  *taille = 3;
	  taille_valide = 1;
	} else if (y >= 190 && y <= 240 && x >=50 && x <= 140) {
	  *taille = 4;
	  taille_valide = 1;
	} else if (y >= 260 && y <= 310 && x >=50 && x <= 140) {
	  *taille = 5;
	  taille_valide = 1;
	} else if (y >= 330 && y <= 400 && x >=50 && x <= 140) {
	  *taille = 6;
	  taille_valide = 1;
	} else if (y >= 120 && y <= 170 && x >=200 && x <= 350) {
	  *taille = 7;
	  taille_valide = 1;
	} else if (y >= 190 && y <= 240 && x >=200 && x <= 350) {
	  *taille = 8;
	  taille_valide = 1;
	} else if (y >= 260 && y <= 310 && x >=200 && x <= 350) {
	  *taille = 9;
	  taille_valide = 1;
	}
      }
      
      if (!mode_valide) {/* Vérifier la sélection du mode de jeu */
	if (y >= 550 && y <= 700 && x >= 50 && x <= 150) {
	  *mode_de_jeu = 1;
	  mode_valide = 1;
	} else if (y >= 550 && y <= 700 && x >= 200 && x <= 300) {
	  *mode_de_jeu = 2;
	  mode_valide = 1;
	}
      }
    }
  }
  
  /* Libérer les sprites*/
  LibererSprite(f3Sprite);
  LibererSprite(f4Sprite);
  LibererSprite(f5Sprite);
  LibererSprite(f6Sprite);
  LibererSprite(f7Sprite);
  LibererSprite(f8Sprite);
  LibererSprite(f9Sprite);
  LibererSprite(m1Sprite);
  LibererSprite(m2Sprite);
}
