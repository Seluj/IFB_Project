//
// Created by jules on 23/05/21.
//
#include "traitement.h"
#include "ordinateur.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * choix du mouvement de l'ordinateur
 * @param nb_tour compteur du nombre de tour
 * @return le choix du mouvement 1 pour poser un pions, 2 pour en retirer un
 */
int mvt_ordi(int nb_tour){
    int choix;
    fflush(stdin);
    srand(time(0));
    int temp = rand()%5;
    if (nb_tour != 0) {
        if (temp == 0 || temp == 1 || temp == 2 || temp == 3) {
            choix = 1;
        } else {
            choix = 2;
        }
    } else {
        choix = 1;
    }
    return choix;
}

/**
 * genere une colonne aléatoire pour l'ordinateur
 * @param g grille de jeu
 * @param col colonne precedente
 * @param choix_mouvement choix voulu
 * @param choix_mouvement_precedent choix precendent
 * @return retourne le numéro de la colonne choisi
 */
int colonne_ordi(grille g, int col_precedent, int choix_mvt, int choix_mvt_precedent){
    int resultat;
    srand(time(0));
    switch (choix_mvt) {
        case 1:
            if (choix_mvt_precedent == 2) {
                do {
                    resultat = (rand()% (g.largeur - 1)) + 1;
                } while (resultat > g.largeur || resultat == col_precedent);
            } else {
                do {
                    resultat = (rand()% (g.largeur - 1)) + 1;
                } while (resultat > g.largeur);
            }
            break;
        case 2:
            do {
                resultat = (rand()% (g.largeur - 1)) + 1;
            } while (resultat > g.largeur);
            break;
    }
    return resultat;
}