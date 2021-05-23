//
// Created by jules on 20/05/21.
//

#include "check_winer.h"
#include "traitement.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

/**
 *
 * @param g grille
 * @param pions pions a tester
 * @param colonne largeur inverse du pions a tester
 * @return 0 si le premier joueur a gagné, 1 si c’est le second, et -1 si aucun des joueurs n’a gagné
 */
int check_winner(grille g, char pions, int colonne, joueur j){
    int ligne=0;
    while(g.grille[colonne][ligne] == '_'){
        ligne++;
    }
    if( pions ==j.pions && nb_pions_alignes(g,pions,ligne,colonne)==g.largeur-1){
        printf("Le joueur 1 a gagn%c",130);
        return 0;
    } else if(nb_pions_alignes(g,pions,ligne,colonne)==g.largeur-1){
        printf("Le joueur 2 a gagn%c",130);
        return 1;
    }
    return -1;
}

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
int nb_pions_dir(grille g,char pions, int ligne, int colonne, int dir_x, int dir_y){
    int l, c, resultat=0;
    l = ligne;
    c = colonne;
    while(position_valide(g, l, c)){
        if (g.grille[c][l] == pions) {
            resultat++;
        } else {
            dir_y = 100;
            dir_x = 100;
        }
        l += dir_y;
        c += dir_x;
    }
    return resultat;
}
/**
 * calcule la maximum entre deux nombres
 * @param a premier nombre
 * @param b second nombre
 * @return retourne le plus grand
 */
int maximum(int a, int b){
    if (a>b) {
        return a;
    } else {
        return b;
    }
}

/**
 * revoie le nombre de pions maximum de la plus grande ligne
 * @param g grille
 * @param pions pions a tester
 * @param ligne Hauteur inverse du pions à tester
 * @param colonne largeur inverse du pions a tester
 * @return retourne le nombre maximum de pions de la plus grande ligne
 */
int nb_pions_alignes(grille g,char pions, int ligne, int colonne){
    int resultat;
    resultat=nb_pions_dir(g,pions,ligne, colonne,0,1)+nb_pions_dir(g,pions,ligne, colonne,0,-1);
    /*
     *  |
     *  |
     *  |
     *  |
     */
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,0) + nb_pions_dir(g,pions,ligne, colonne,-1,0),
                    resultat
            );
    /*
     *  _____
     */
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,1) + nb_pions_dir(g,pions,ligne, colonne,-1,-1),
                    resultat
            );
    /*
     *   \
     *    \
     *     \
     *      \
     */
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,-1) + nb_pions_dir(g,pions,ligne, colonne,-1,1),
                    resultat
            );
    /*
     *      /
     *     /
     *    /
     *   /
     */
    return resultat;
}

/**
 *
 * @param g grille de jeu
 * @param ligne
 * @param colonne
 * @return
 */
int position_valide(grille g, int ligne, int colonne){
    int ret = 1;
    if ((colonne>g.largeur-1 || colonne <0) || (ligne> g.hauteur-1 || ligne<0)) {
        ret = 0;
    }
    return ret;
}