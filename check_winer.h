//
// Created by jules on 20/05/21.
//

#ifndef PROJET_IFB_CHECK_WINER_H
#define PROJET_IFB_CHECK_WINER_H

#include "traitement.h"
/**
 *
 * @param g grille
 * @param pions pions a tester
 * @param colonne largeur inverse du pions a tester
 * @return 0 si le premier joueur a gagné, 1 si c’est le second, et -1 si aucun des joueurs n’a gagné
 */
int check_winner(grille g, char pions, int colonne, joueur j);

/**
 * Compte le nombre de pions dans une direction donnée
 * @param g grille
 * @param pions pions a tester
 * @param ligne Hauteur inverse du pions à tester
 * @param colonne largeur inverse du pions a tester
 * @param dir_x direction horizontal
 * @param dir_y direction vertical
 * @return returne le nombre de pion aligné dans la direction donnée
 */
int nb_pions_dir(grille g,char pions, int ligne, int colonne, int dir_x, int dir_y);

/**
 * calcule la maximum entre deux nombres
 * @param a premier nombre
 * @param b second nombre
 * @return retourne le plus grand
 */
int maximum(int a, int b);

/**
 * revoie le nombre de pions maximum de la plus grande ligne
 * @param g grille
 * @param pions pions a tester
 * @param ligne Hauteur inverse du pions à tester
 * @param colonne largeur inverse du pions a tester
 * @return retourne le nombre maximum de pions de la plus grande ligne
 */
int nb_pions_alignes(grille g,char pions, int ligne, int colonne);

int position_valide(grille g, int ligne, int colonne);

#endif //PROJET_IFB_CHECK_WINER_H
