//
// Created by jules on 20/05/21.
//

#ifndef PROJET_IFB_CHECK_WINER_H
#define PROJET_IFB_CHECK_WINER_H

#include "traitement.h"

int nb_pions_dir(grille g,char pions, int ligne, int colonne, int dir_x, int dir_y);
int nb_pions_alignes(grille g,char pions, int ligne, int colonne);
int maximum(int a, int b);
int check_winner(grille g, char pions, int colonne);

#endif //PROJET_IFB_CHECK_WINER_H
