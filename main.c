#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "menu.h"
#include "grille.h"
#include "init.h"
#include "EstBloque.h"
#include "EffacerCase.h"
#include "EstAdjacente.h"
#include "DessinerGrille.h"
#include "AfficherFinDePartie.h"
#include "gestion_joueur1.h"
#include "gestion_joueur2.h"
#include "AttendreMicrosecondes.h"

#define DELAI_IA 2000000L /* Délai pour l'IA (2 secondes en microsecondes) */
#define DELAI_FIN 1500000L /* Délai avant de fermer l'écran de fin (3 secondes en microsecondes) */
#define DELAI_CONDEMNER 1000000L /* Délai avant de condamner un pion (1 seconde en microsecondes) */
#define CYCLE 1000000L /* Durée d'un cycle d'attente (1 seconde en microsecondes) */



int main(void) {
    int recommencer = 1;  /* Variable de contrôle pour redémarrer la partie */
    unsigned long suivant = Microsecondes() + CYCLE;  /* Variable pour gérer les cycles de temps */
    int taille, taille_case, mode_de_jeu;  /* Dimensions du jeu */
    int grille[9][9];  /* Grille de jeu */
    int colonne, ligne;  /* Variables pour les coordonnées de la souris et les positions */
    int pos_rose[2];  /* Position du pion rose */
    int pos_vio[2];  /* Position du pion violet */
    int tour = 0;  /* Compteur de tour */
    unsigned long delai_ia, delai_fin;  /* Variables pour gérer les délais de l'IA et de fin de partie */
    int trouve;  /* Variable pour vérifier si un pion a été trouvé */
    int gagnant;  /* Variable pour stocker le gagnant de la partie */
    

    while (recommencer) {  /* Boucle principale du jeu */
        /* Initialisation graphique et création de la fenêtre */
        InitialiserGraphique();
        CreerFenetre(0, 0, 700, 700);
        
        /* Affichage du menu et récupération des paramètres du jeu */
        AfficherMenu(&taille, &mode_de_jeu);
        FermerGraphique();  /* Fermeture de la fenêtre du menu */

        /* Réinitialisation de la fenêtre pour le jeu */
        InitialiserGraphique();
        CreerFenetre(0, 0, 700, 700);

        taille_case = 700 / taille;  /* Calcul de la taille de chaque case en fonction de la taille de la grille */
        InitialiserGrille(taille, grille);  /* Initialisation de la grille */
        DessinerGrille(taille, taille_case);  /* Dessin de la grille */

        /* Placement initial des pions */
        PlacerPionInitial(taille_case, grille, pos_rose, pos_vio, mode_de_jeu, taille);

        srand(Microsecondes());  /* Initialisation du générateur de nombres aléatoires */

        while (1) {  /* Boucle de jeu */
            if (tour == 0) {  /* Si c'est le tour du joueur 1(rose) */
                /* Gestion du tour du joueur 1 */
                gestion_joueur1(grille, taille, taille_case, pos_rose, &tour);
            }
	    else {  /* Si c'est le tour du joueur 2 ou de l'IA */
                if (mode_de_jeu == 2) {  /* Si le mode de jeu est à 2 joueurs */
                    /* Gestion du tour du joueur 2 */
                    gestion_joueur2(grille, taille, taille_case, pos_vio, &tour);
                }
		else {  /* Si le mode de jeu est contre l'IA */
                    delai_ia = Microsecondes() + DELAI_IA;  /* Calcul du délai pour l'IA */
                    while (Microsecondes() < delai_ia) {  /* Attente pendant le délai de l'IA */
                        /* Ne rien faire ici, juste attendre */
                    }

                    trouve = 0;  /* Initialisation de la recherche d'une case vide */
                    while (!trouve) {
                        colonne = rand() % taille;  /* Sélection aléatoire de la colonne */
                        ligne = rand() % taille;  /* Sélection aléatoire de la ligne */
                        /* Vérification si la case est vide et adjacente au pion violet */
                        if (grille[ligne][colonne] == 0 &&
                            (pos_vio[0] == -1 || EstAdjacente(pos_vio[1], pos_vio[0], ligne, colonne))) {
                            trouve = 1;  /* Si trouvé, sortir de la boucle */
                        }
                    }

                    /* Si le pion violet existe déjà, effacer sa position précédente */
                    if (pos_vio[0] != -1) {
                        EffacerCase(pos_vio[0], pos_vio[1], taille_case);
                        grille[pos_vio[1]][pos_vio[0]] = 0;  /* Réinitialisation de la grille */
                    }

                    /* Mise à jour de la position du pion bleu */
                    pos_vio[0] = colonne;
                    pos_vio[1] = ligne;
                    grille[ligne][colonne] = 1;

                    /* Dessin du pion bleu sur la grille */
                    ChoisirCouleurDessin(CouleurParNom("purple"));
                    RemplirRectangle(colonne * taille_case, ligne * taille_case, taille_case, taille_case);

                    /* Attente avant de passer au prochain tour */
                    while (Microsecondes() < suivant) {
                        /* Ne rien faire ici, juste attendre */
                    }
                    suivant = Microsecondes() + CYCLE;  /* Mise à jour du cycle de temps */

                    trouve = 0;  /* Recherche d'une case vide adjacente au pion rose */
                    while (!trouve) {
                        colonne = rand() % taille;
                        ligne = rand() % taille;
                        if (grille[ligne][colonne] == 0 && EstAdjacente(pos_rose[1], pos_rose[0], ligne, colonne)) {
                            trouve = 1;
                        }
                    }
                    
                    /* Condamnation du pion à une nouvelle position */
                    AttendreMicrosecondes(DELAI_CONDEMNER);
                    ChoisirCouleurDessin(CouleurParNom("purple"));
                    DessinerSegment(colonne * taille_case, ligne * taille_case,
                                    (colonne + 1) * taille_case, (ligne + 1) * taille_case);
                    DessinerSegment(colonne * taille_case, (ligne + 1) * taille_case,
                                    (colonne + 1) * taille_case, ligne * taille_case);
                    grille[ligne][colonne] = 2;  /* Mise à jour de la grille avec le pion condamné */

                    tour = 0;  /* Changement de tour */
                }
            }

            /* Vérification si un joueur est bloqué */
            if (EstBloque(pos_rose, grille, taille)) {
                gagnant = 2;  /* Si le joueur 1 est bloqué, le joueur 2 gagne */
                delai_fin = Microsecondes() + DELAI_FIN;
                while (Microsecondes() < delai_fin) {
                    /* Attente avant de terminer la partie */
                }
                FermerGraphique();  /* Fermeture de la fenêtre graphique */
                AfficherFinDePartie(&recommencer, gagnant);  /* Affichage de la fin de partie */
                break;
            } else if (EstBloque(pos_vio, grille, taille)) {
                gagnant = 1;  /* Si le joueur 2 est bloqué, le joueur 1 gagne */
                delai_fin = Microsecondes() + DELAI_FIN;
                while (Microsecondes() < delai_fin) {
                    /* Attente avant de terminer la partie */
                }
                FermerGraphique();  /* Fermeture de la fenêtre graphique */
                AfficherFinDePartie(&recommencer, gagnant);  /* Affichage de la fin de partie */
                break;
            }
        }
    }

    return 0;  /* Fin du programme */
}
