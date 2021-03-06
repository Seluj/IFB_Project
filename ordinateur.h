//
// Created by jules on 23/05/21.
//

#ifndef PROJET_IFB_ORDINATEUR_H
#define PROJET_IFB_ORDINATEUR_H
#include "traitement.h"

/**
 * \brief choix du mouvement de l'ordinateur
 * \details la probabilité que l'ordinateur ajoute un pion est bien plus grande que celle d'ne retirer
 * @param nb_tour compteur du nombre de tour
 * @return le choix du mouvement 1 pour poser un pions, 2 pour en retirer un
 */
int mvt_ordi(int nb_tour);

/**
 * choisi dans quel colonne l'ordinateur va ajouter/retirer un pion
 * @param g grille de jeu
 * @param col colonne precedente
 * @param choix_mouvement choix voulu
 * @param choix_mouvement_precedent choix precendent
 * @return retourne le numéro de la colonne choisi
 */
int colonne_ordi(grille g, int  col_precedent,int choix_mvt, int choix_mvt_precedent);

#endif //PROJET_IFB_ORDINATEUR_H
