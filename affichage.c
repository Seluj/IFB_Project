//
// Created by jules on 10/05/21.
//

#include "affichage.h"
#include "traitement.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
int menu() {
    int i;
    i=0;
    do{
        fflush(stdin);
        couleur(14,0);
        printf("\n\n\t==== Menu ====\n\n");
        couleur(1,0);
        printf("1. D%cmarrer une nouvelle partie\n"
               "2. Charger une partie existante\n"
               "3. Quitter\n", 130);
        couleur(15,0);
        scanf("%d",&i);
        fflush(stdin);
    } while (i!=1 && i!= 2 && i!=3);
    return i;
}

void affichage_grille (grille Grille){
    printf("%c", 201);
    for (int i = 0; i <= Grille.largeur - 2; i++){
        printf("%c%c%c%c", 205, 205, 205 ,203);
    }
    printf("%c%c%c%c\n", 205, 205, 205, 187);


    // "Milieu" de grille
    for (int i = 0; i < Grille.largeur; i++){
        printf("%c", 186);
        for (int j = 0; j < Grille.largeur; j++){
            printf(" %c ",Grille.grille[j][i]);
            printf("%c", 186);
        }
        if (i < Grille.largeur - 1){
            printf("\n%c", 204);
            for (int k = 0; k <= Grille.largeur - 2; k++) {
                printf("%c%c%c%c", 205, 205, 205, 206);
            }
            printf("%c%c%c%c", 205, 205, 205, 185);
        }
        printf("\n");
    }

    // "Bas" de la grille
    printf("%c", 200);
    for (int i = 0; i <= Grille.largeur - 2; i++){
        printf("%c%c%c%c", 205, 205, 205 ,202);
    }
    printf("%c%c%c%c\n", 205, 205, 205, 188);
}

int move_choice(int round){
    int choice;
    if(round==0){
        do {
            printf("Que voulez vous faire :\n"
                   "1)poser un jeton\n"
                   "2)sauvegarder et quitter la partie");
            scanf("%d",&choice);
        }while(choice != 1 && choice !=2);
    }else{
        do {
            printf("Que voulez vous faire :\n"
                   "1)poser un jeton\n"
                   "2)enlever un jeton\n"
                   "3)sauvegarder et quitter la partie");
            scanf("%d",&choice);
        }while(choice != 1 && choice != 2 && choice != 3);
    }
    return choice;
}