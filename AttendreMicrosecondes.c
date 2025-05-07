#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "AttendreMicrosecondes.h"

/*Pour donner un effet plus naturel au jeu, notamment au niveau de l'IA afin qu'elle ne joue pas rapidement, et qu'il y ait un effet de reflexion */
#define DELAI_IA 1000000L /* 2 secondes en microsecondes*/


void AttendreMicrosecondes(unsigned long microsecondes) {
    unsigned long debut = Microsecondes();
    while (Microsecondes() < debut + microsecondes) {
      /* Attendre*/
    }
}
