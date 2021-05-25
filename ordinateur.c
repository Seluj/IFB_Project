//
// Created by jules on 23/05/21.
//
#include "traitement.h"
#include "ordinateur.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mvt_ordi(int nb_tour){
    int choix;
    fflush(stdin);
    srand(time(0));
    int temp = rand()%5;
    if (nb_tour != 0) {//si on n'est pas au tout premier tour de la partie
        if (temp == 0 || temp == 1 || temp == 2 || temp == 3) { //la probabilité que l'ordinateur pose un pion est plus grande que celle d'en retirer un
            choix = 1;//pose un pion
        } else {
            choix = 2;//retire un pion
        }
    } else {//si on est au premier tour de la partie
        choix = 1;//pose un pion
    }
    return choix;
}

int colonne_ordi(grille g, int col_precedent, int choix_mvt, int choix_mvt_precedent){
    int resultat;
    srand(time(0));
    switch (choix_mvt) {
        case 1://l'ordinateur choisi de poser un  pion
            if (choix_mvt_precedent == 2) { //si on a retiré un pion au tour précédent
                do {
                    resultat = (rand()% (g.largeur - 1)) + 1;
                } while (resultat > g.largeur || resultat == col_precedent); //l'ordinateur donne un colonne, tant que
                // elle est trop grande, ou si elle est identique a celle dans laquelle on a retiré un pion au tour précédent
            } else { //si un pion a été ajouté au tour précédent
                do {
                    resultat = (rand()% (g.largeur - 1)) + 1;
                } while (resultat > g.largeur); //l'ordinateur donne une colonne tant qu'elle est trop grande
            }
            break;
        case 2://l'ordinateur choisi de retirer un pion
            do {
                resultat = (rand()% (g.largeur - 1)) + 1;
            } while (resultat > g.largeur);//l'ordinateur donne une colonne tant qu'elle est trop grande
            break;
    }
    return resultat;
}