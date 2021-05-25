//
// Created by jules on 23/05/21.
//

#ifndef PROJET_IFB_JEU_H
#define PROJET_IFB_JEU_H

/**
 * fonction principale d'une partie à deux joueurs
 * @param play_grille grille à afficher avec les pions
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @param nb_tour compteur du nombre de tours
 */
void jeu_multi(grille play_grille, joueur j1, joueur j2, int nb_tour);

/**
 * fonction principal d'une partie en solo contre un ordinateur
 * @param play_grille grille à afficher avec les pions
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @param nb_tour compteur du nombre de tours
 */
void jeu_solo(grille play_grille, joueur j1, joueur j2, int nb_tour);

#endif //PROJET_IFB_JEU_H
