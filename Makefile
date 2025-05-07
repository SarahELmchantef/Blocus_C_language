# CHAPITRE 1 : BUT FINAL
but : game

# CHAPITRE 2 : VARIABLES

CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lgraph  

# Fichiers objets
OFILES = main.o \
         AfficherFinDePartie.o \
         DessinerGrille.o \
         EffacerCase.o \
         EstAdjacente.o \
         EstBloque.o \
         grille.o \
         menu.o \
         PlacerPionInitial.o \
         AttendreMicrosecondes.o \
         gestion_joueur1.o \
         gestion_joueur2.o

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

AfficherFinDePartie.o : AfficherFinDePartie.c AfficherFinDePartie.h
	$(CC) $(CFLAGS) -c AfficherFinDePartie.c

DessinerGrille.o : DessinerGrille.c DessinerGrille.h
	$(CC) $(CFLAGS) -c DessinerGrille.c

EffacerCase.o : EffacerCase.c EffacerCase.h
	$(CC) $(CFLAGS) -c EffacerCase.c

EstAdjacente.o : EstAdjacente.c EstAdjacente.h
	$(CC) $(CFLAGS) -c EstAdjacente.c

EstBloque.o : EstBloque.c EstBloque.h
	$(CC) $(CFLAGS) -c EstBloque.c

grille.o : grille.c grille.h
	$(CC) $(CFLAGS) -c grille.c

menu.o : menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c

PlacerPionInitial.o : PlacerPionInitial.c init.h
	$(CC) $(CFLAGS) -c PlacerPionInitial.c

AttendreMicrosecondes.o : AttendreMicrosecondes.c AttendreMicrosecondes.h
	$(CC) $(CFLAGS) -c AttendreMicrosecondes.c

gestion_joueur1.o : gestion_joueur1.c gestion_joueur1.h
	$(CC) $(CFLAGS) -c gestion_joueur1.c

gestion_joueur2.o : gestion_joueur2.c gestion_joueur2.h
	$(CC) $(CFLAGS) -c gestion_joueur2.c

# CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

game : $(OFILES)
	$(CC) $(CFLAGS) -o game $(OFILES) $(LDFLAGS)

# CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) game

# CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean

run : game
	./game
