//
// Created by jules on 10/05/21.
//

#include "affichage.h"
#include <stdio.h>
#include <windows.h>

int menu_principal(){
    int i;
    i = 0;
    do {
        fflush(stdin);
        couleur(14,0);
        printf("\n\n\t==== Menu ====\n\n");
        couleur(1,0);
        printf("1. D%cmarrer une nouvelle partie\n"
               "2. Charger une partie existante\n"
               "3. Quitter\n", 130);
        couleur(15,0);
        scanf("%d", &i);
    } while ( (i != 1) && (i != 2) && (i != 3) );//on repète l'acquisition tant que l'input ne satisfait pas aux critères
    return i;
}

int menu_mvt(int numero_du_tour){
    int choix;
    fflush(stdin);
    if (numero_du_tour == 0) { //si on débute un nouvelle partie, l'option de retirer un jeton n'est pas proposée
        do {
            printf("Que voulez vous faire :\n"
                   "1)poser un jeton\n"
                   "2)sauvegarder et quitter la partie\n");
            scanf("%d",&choix);
            if (choix == 2){
                choix++;//pour la suite du traitement, la sauvegarde doit être associée a la valeur 3
            }
        } while (choix != 1 && choix !=3);//on repète l'acquisition tant que l'input ne satisfait pas aux critères
    } else {
        do {
            printf("Que voulez vous faire :\n"
                   "1)poser un jeton\n"
                   "2)enlever un jeton\n"
                   "3)sauvegarder et quitter la partie\n");
            scanf("%d", &choix);
        } while ( (choix != 1) && (choix != 2) && (choix != 3) );//on repète l'acquisition tant que l'input ne satisfait pas aux critères
    }
    return choix;
}

int menu_nb_de_joueur(){
    int nb_joueur;
     do{
        printf("Voulez-vous jouer a deux (2) ou tout seul (1)? :");
        scanf("%d", &nb_joueur);
        fflush(stdin);
    }while (nb_joueur != 1 && nb_joueur != 2);
    return nb_joueur;
}

void affichage_grille(grille Grille){
    // "Haut" de grille
    couleur(1, 0);
    printf("%c", 201);
    for (int i = 0; i <= Grille.largeur - 2; i++) {
        printf("%c%c%c%c", 205, 205, 205 ,203);
    }
    printf("%c%c%c%c\n", 205, 205, 205, 187);
    couleur(15,0);

    // "Milieu" de grille
    for (int i = 0; i < Grille.hauteur; i++) {//affichage de la grille en fonction des dimension saisi par l'utilisateur
        couleur(1,0);
        printf("%c", 186);
        couleur(15,0);


        for (int j = 0; j < Grille.largeur; j++) {
            if (Grille.grille[j][i] == 'X') {
                couleur(4,0);
            } else if (Grille.grille[j][i] == 'O') {
                couleur(14, 0);
            }
            printf(" %c ",Grille.grille[j][i]);
            couleur(1,0);
            printf("%c", 186);
            couleur(15,0);
        }

        if (i < Grille.largeur - 1) {
            couleur(1,0);
            printf("\n%c", 204);
            for (int k = 0; k <= Grille.largeur - 2; k++) {
                printf("%c%c%c%c", 205, 205, 205, 206);
            }
            printf("%c%c%c%c", 205, 205, 205, 185);
            couleur(15,0);
        }

        printf("\n");
    }

    couleur(1,0);


    // "Bas" de la grille
    printf("%c", 200);
    for (int i = 0; i <= Grille.largeur - 2; i++) {
        printf("%c%c%c%c", 205, 205, 205 ,202);
    }
    printf("%c%c%c%c\n", 205, 205, 205, 188);
    for (int i = 0; i <= Grille.largeur - 1; i++) {
        printf("  %d ", i+1);
    }
    couleur(15,0);
    printf("\n");
}

void couleur(int couleur_du_texte, int couleur_de_fond){ //permet d'afficher en couleur dans le terminal
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleur_de_fond*16+couleur_du_texte);
}

