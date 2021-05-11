//
// Created by jules on 10/05/21.
//
#include "traitement.h"
int acquisition_taille_grille(){
    int size;
    printf("Entrez la taille de la grille :");
    scanf("%d",&size);
    while(size<2){
        printf("Dimension entre invalide, veuillez recommencer");
        scanf("%d",&size);
    }
    fflush((stdin));
    return size+2;
}

void initialisation_grille(grille* grille){
    grille->grille = (char**) malloc(sizeof(char*) * grille->cote);
    for (int i = 0; i < grille->cote; ++i) {
        grille->grille[i] = (char*) malloc(sizeof(char) * grille->cote);
        for (int j = 0; j < grille->cote; ++j) {
            grille->grille[i][j] = (char)95;
        }
    }
}

int ajout_pion(grille* g, int indice, char jeton){
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
void free_memory(grille grille){
    for (int i = 0; i < grille.cote; ++i) {
        free(grille.grille[i]);
    }
    free(grille.grille);
}