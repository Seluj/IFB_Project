//
// Created by jules on 20/05/21.
//

#include "check_winer.h"
#include "traitement.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int check_winner(grille g, char pions, int colonne){
    int ligne=0;
    while(g.grille[colonne][ligne] == '_'){
        ligne++;
    }
    ligne++;
    //printf("\n%d\n",colonne);
    //printf("\n\t%d\n",i);
    if(nb_pions_alignes(g,pions,ligne,colonne)==g.largeur-2){
        printf("Bravo");
        return 0;
    }
    return -1;
}

int nb_pions_dir(grille g,char pions, int ligne, int colonne, int dir_x, int dir_y){
    int l, c, resultat=1;
    l = ligne + dir_y;
    c = colonne + dir_x;
    //if((c>=0 && c<=colonne) && (l>=0 && l<=colonne)) {
        while (g.grille[c][l] == pions) {
            resultat++;
            l += dir_y;
            c += dir_x;
            //printf("\t1\n");
        }
    //}

    l = ligne - dir_y;
    c = colonne - dir_x;
    //if((c>=0 && c<=colonne) && (l>=0 && l<=colonne)) {
        while (g.grille[c][l] == pions) {
            resultat++;
            l = l - dir_y;
            c = c - dir_x;
            //printf("\t1\n");
        }
    //}
    /*
    while(position_valide(g, l, c)){
        if (g.grille[c][l]==pions){
            resultat++;
            printf("\n\t\t1\n");
        }
        printf("\n\t1\n");
        l = ligne + dir_x;
        c = colonne + dir_y;
    }*/
    return resultat;
}
int maximum(int a, int b){
    if (a>b) {
        return a;
    } else {
        return b;
    }
}

int nb_pions_alignes(grille g,char pions, int ligne, int colonne){
    int resultat;
    resultat =
            maximum(
                    maximum(
                            nb_pions_dir(g, pions, ligne, colonne, 1, 1),
                            nb_pions_dir(g, pions, ligne, colonne, 1, 0)
                            ),
                    maximum(
                            nb_pions_dir(g, pions, ligne, colonne, 1, -1),
                            nb_pions_dir(g, pions, ligne, colonne, 0, 1)
                            )
                    );
    /*
    resultat=nb_pions_dir(g,pions,ligne, colonne,0,1)/+nb_pions_dir(g,pions,ligne, colonne,0,-1);
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,0) + nb_pions_dir(g,pions,ligne, colonne,-1,0),
                    resultat
            );
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,1) + nb_pions_dir(g,pions,ligne, colonne,-1,-1),
                    resultat
            );
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,-1) + nb_pions_dir(g,pions,ligne, colonne,-1,1),
                    resultat
            );*/
    return resultat;
}