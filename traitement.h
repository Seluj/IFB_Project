//
// Created by jules on 10/05/21.
//

#ifndef PROJET_IFB_TRAITEMENT_H
#define PROJET_IFB_TRAITEMENT_H
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct {
    char** grille;
    int cote;
}grille;

int acquisition_taille_grille();
void initialisation_grille(grille* grille);
int ajout_pion(grille* g, int indice, char jeton);
void free_memory(grille grille);
#endif //PROJET_IFB_TRAITEMENT_H
