//
// Created by jules on 10/05/21.
//

#ifndef PROJET_IFB_AFFICHAGE_H
#define PROJET_IFB_AFFICHAGE_H

#include "traitement.h"

/**
 * Menu principale du jeu, il se lance qu'une fois au tout début du programme
 * @return retourne ke choix de l'utilisateur,
 *                  1-> nouvelle partie
 *                  2-> charger une partie sauvegarder
 *                  3-> quitter
 */
int menu_principal();

/**
 * Menu du jeu, il se lance au début de chaque tour
 * @return retourne le choix de l'utilisateur,
 *                  1-> ajouter un pion
 *                  2-> enlever un pion
 *                  3-> sauvegarder et quitter
 */
int menu_mvt(int numero_du_tour);

/**
 * menu lorsque l'utilisateur choisi une nouvelle partie
 * @return retourne le nombre de joueur, 1 ou 2
 */
int menu_nb_de_joueur();

/**
 * affichage de la grille avec couleur
 * @param Grille grille à afficher
 */
void affichage_grille(grille Grille);

/**
 * colore le texte
 * @param couleur_du_texte couleur du corps de texte
 * @param couleur_de_fond couleur du fond
 */
void couleur(int couleur_du_texte, int couleur_de_fond);

#endif //PROJET_IFB_AFFICHAGE_H
