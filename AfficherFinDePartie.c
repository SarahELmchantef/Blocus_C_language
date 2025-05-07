#include "AfficherFinDePartie.h"
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

/*Pour afficher la 3 eme fentre qui affcihe le gagnant et la possibilité de rejouer ou non*/
void AfficherFinDePartie(int *recommencer, int gagnant) {
    int x, y;
    int rejouerSprite, fermerSprite,helloSprite;
    *recommencer = 0; /* Par défaut, on ne recommence pas*/

    

    /* Initialiser le mode graphique*/
    InitialiserGraphique();
   
    CreerFenetre(0, 0, 700, 700);


    /* Charger l'image de fond*/
    ChargerImageFond("images/fond.png");

    /* Charger les sprites pour "Rejouer" et "Fermer"*/
    rejouerSprite = ChargerSprite("images/rejouer.jpg");
    fermerSprite = ChargerSprite("images/fermer.jpg");
    helloSprite = ChargerSprite("images/mhellov.png");

 
    if (rejouerSprite == -1 || fermerSprite == -1) {
        FermerGraphique();
        return;
    }


    /* Afficher le texte du gagnant*/
    if (gagnant == 1) {
        EcrireTexte(50, 150, "Le joueur 1 gagne!", 2);
    } else {
        EcrireTexte(50, 150, "Le joueur 2 gagne!", 2);
    }
  

    /*Afficher les sprites pour "Rejouer" et "Fermer"*/
    AfficherSprite(rejouerSprite, 50, 200);
    AfficherSprite(fermerSprite, 50, 300);
    AfficherSprite(helloSprite, 350,300);
   

    /* Boucle pour attendre un clic de la souris*/
    while (1) {
      /*Vérifier si la souris a été cliquée*/
        if (SourisCliquee()) {
	  /*Obtenir les coordonnées de la souris*/
            x = _X;
            y = _Y;
    
            /*Vérifier si le clic est dans la zone "Rejouer"*/
            if (x >= 50 && x <= 150 && y >= 190 && y <= 240) {
                *recommencer = 1;
                break;
            }
	    
            /* Vérifier si le clic est dans la zone "Fermer"*/
            else if (x >= 50 && x <= 150 && y >= 290 && y <=350) {
                *recommencer = 0;
                break;
            }
        }
    }

    /* Libérer les sprites*/
    LibererSprite(rejouerSprite);
    LibererSprite(fermerSprite);

    /*Fermer le mode graphique*/
    FermerGraphique();
}
