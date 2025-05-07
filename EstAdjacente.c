#include "EstAdjacente.h"
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>

/* Fonction pour vérifier si une case cible est adjacente à une case actuelle. Une case est considérée adjacente si elle se trouve à une distance de 1 ou moins en termes de lignes et de colonnes (diagonales incluses).
   - ligne_actuelle : la ligne de la case actuelle.
   - colonne_actuelle : la colonne de la case actuelle.
   - ligne_cible : la ligne de la case cible.
   - colonne_cible : la colonne de la case cible.
  et elle retournera : 1 (vrai) si la case cible est adjacente à la case actuell, et 0 (faux) sinon. */



int EstAdjacente(int ligne_actuelle, int colonne_actuelle, int ligne_cible, int colonne_cible) {
  int delta_ligne, delta_colonne;
  
  delta_ligne = abs(ligne_cible - ligne_actuelle);/* Calcul de la différence absolue entre les lignes. */
  
  delta_colonne = abs(colonne_cible - colonne_actuelle); /* Calcul de la différence absolue entre les colonnes. */
  
  return (delta_ligne <= 1 && delta_colonne <= 1);
}
