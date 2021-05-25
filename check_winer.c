//
// Created by jules on 20/05/21.
//
#include "check_winer.h"
#include <stdio.h>

int check_winner(grille g, char pions, int colonne, joueur j){
    int ligne=0;
    while(g.grille[colonne][ligne] == '_'){
        ligne++;
    }
    if( pions ==j.pions && nb_pions_alignes(g,pions,ligne,colonne)==g.largeur-1){ //si on considere les pions du joueur, on compte combien de pions sont aligner, pour savoir si on peut déclarer une victoire
        printf("Le joueur 1 a gagn%c",130);
        return 0;//le joueur 1 a gagné
    } else if(nb_pions_alignes(g,pions,ligne,colonne)==g.largeur-1){ //même principe, mais pour l'autre joueur
        printf("Le joueur 2 a gagn%c",130);
        return 1;//le joueur 2/ordinateur a gagné
    }
    return -1;//personne n'a gagné pour l'instant
}
int nb_pions_dir(grille g,char pions, int ligne, int colonne, int dir_x, int dir_y){
    int l, c, resultat=0;
    l = ligne;
    c = colonne;
    while(position_valide(g, l, c)){ //on repete les instructions tant qu'on reste bien dans la grille
        if (g.grille[c][l] == pions) { //si on rencontre un pion, qu'importe son type
            resultat++;//on incremente le resultat de 1
        } else { //sinon on sort de la fonction
            dir_y = 100;
            dir_x = 100;
        }
        l += dir_y;
        c += dir_x;
    }
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
    resultat=nb_pions_dir(g,pions,ligne, colonne,0,1)+nb_pions_dir(g,pions,ligne, colonne,0,-1);//nombre de pions alignés verticalement
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,0) + nb_pions_dir(g,pions,ligne, colonne,-1,0),
                    resultat
            );//on verifie si il y a plus de pions aligner verticalement, ou horizontalement
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,1) + nb_pions_dir(g,pions,ligne, colonne,-1,-1),
                    resultat
            );//on verifie si il y a plus de pions aligné en diagonal gauche-droite/haut-bas que verticalement ou horizontalement
    resultat=
            maximum(
                    nb_pions_dir(g,pions,ligne, colonne,1,-1) + nb_pions_dir(g,pions,ligne, colonne,-1,1),
                    resultat
            );//on verifie si il y a plus de pions aligné en diagonal gauche-droite/bas-haut que verticalement ou horizontalement
    return resultat;//on renvoi le plus grand nombre de pion aligné
}

int position_valide(grille g, int ligne, int colonne){
    int ret = 1;
    if ((colonne>g.largeur-1 || colonne <0) || (ligne> g.hauteur-1 || ligne<0)) {
        ret = 0;
    }
    return ret;
}