//
// Created by jules on 10/05/21.
//

#include "affichage.h"
#include "traitement.h"

int menu() {
    int i;
    i=0;
    do{
        printf("\n\n ==== Menu ====\n");
        printf("1. D%cmarrer une nouvelle partie\n"
               "2. Charger une partie existante\n"
               "3. Quitter\n", 130);
        scanf("%d",&i);
    } while (i!=1 && i!= 2 && i!=3);
    return i;
}

void affichage_grille (grille Grille){
    for (int i = 0; i < Grille.cote; i++){
        for (int j = 0; j < Grille.cote; j++ ){
            if (j<1){
                printf("%c",179);
            }
            printf("%c", Grille.grille[j][i]);
            if(j<Grille.cote){
                printf("%c",179);
            }
        }
        printf("\n");
    }
}
int move_choice(int round){
    int choice;
    if(round==0){
        printf("Que voulez vous faire :\n1)poser un jeton\n2)sauvegarder et quitter la partie");
    }else{
        printf("Que voulez vous faire :\n1)poser un jeton\n2)enlever un jeton\n3)sauvegarder et quitter la partie");
    }
    scanf("%d",&choice);
    return choice;
}