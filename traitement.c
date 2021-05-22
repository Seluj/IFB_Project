//
// Created by jules on 10/05/21.
//
#include "traitement.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
/*
int acquisition_taille_grille(){
    int size;
    printf("Entrez la taille de la grille :");
    scanf("%d",&size);
    while(size<=2){
        printf("Dimension entre invalide, veuillez recommencer");
        scanf("%d",&size);
    }
    fflush((stdin));
    return size+2;
}
*/

void initialisation_grille(grille* grille){
    int size;
    printf("Entrez le nombre de pionts %c alligner pour gagner : ",224);
    scanf("%d",&size);
    fflush((stdin));
    while(size<=2){
        printf("Dimension entr%ce invalide, veuillez recommencer",233);
        scanf("%d",&size);
        fflush((stdin));
    }
    grille->longueur = size+2;
    grille->largeur = size+2;
    grille->grille = (char**) malloc(sizeof(char*) * grille->longueur);
    for (int i = 0; i < grille->longueur; ++i) {
        grille->grille[i] = (char*) malloc(sizeof(char) * grille->longueur);
        for (int j = 0; j < grille->longueur; ++j) {
            grille->grille[i][j] = '_';
        }
    }
}

int add_token(grille* g, int indice, char jeton){
    int i=0;

    while(g->grille[indice-1][i] == '_'){
        i++;
    }

    if (i==0){
        return 0;
    } else {
        g->grille[indice-1][i-1] = jeton;
        return 1;
    }
}

void couleur(int couleurDuTexte,int couleurDeFond){ // fonction d'affichage de couleurs
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void free_memory(grille* grille){
    for (int i = 0; i < grille->longueur; ++i) {
        free(grille->grille[i]);
    }
    free(grille->grille);
}
int colonne(grille g){
    int resultat;
    do {
        printf("Vous avez choisis la colonne : ");
        scanf("%d",&resultat);
        fflush(stdin);
    }while(resultat>g.longueur);
    return resultat;
}

int position_valide(grille g, int ligne, int colonne){
    int rep = 1;
    if ((colonne>=g.longueur || colonne <0) || (ligne>= g.longueur || ligne<0)) {
        rep = 0;
        printf("\n\t1\n");
    }
    /*else if (ligne>= g.longueur || ligne<0){
        rep = 0;
    }*/
    return rep;
}