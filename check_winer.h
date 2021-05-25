//
// Created by jules on 20/05/21.
//

#ifndef PROJET_IFB_CHECK_WINER_H
#define PROJET_IFB_CHECK_WINER_H
#include "traitement.h"
/**
 * Verifie si suffisament de pions sont aligner pour déclarer une victoire
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
 * @return retourne le nombre de pion aligné dans la direction donnée
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
 * renvoi le plus grand nombre de pion aligné, qu'importe la direction
 * @param g grille
 * @param pions pions a tester
 * @param ligne Hauteur inverse du pions à tester
 * @param colonne largeur inverse du pions a tester
 * @return retourne le nombre maximum de pions de la plus grande ligne
 */
int nb_pions_alignes(grille g,char pions, int ligne, int colonne);
/**
 * Verifie si les verifications restent bien dans la grille
 * @param g grille de jeu
 * @param ligne index de ligne
 * @param colonne index de colonne
 * @return
 */
int position_valide(grille g, int ligne, int colonne);

#endif //PROJET_IFB_CHECK_WINER_H
