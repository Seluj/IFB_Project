#include "traitement.h"
#include "affichage.h"
#include "check_winer.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    grille play_grille;
    int choix = menu();
    int test, nb_tour, choix_mouvement;
    int col=2;

    switch (choix) {
        case 1:
            //play_grille.longueur = acquisition_taille_grille();
            initialisation_grille(&play_grille);
            nb_tour=0;
            break;
        case 2:
            printf("Ok");
            break;
        case 3:
            printf("Vous voulez quitter.");
            break;
        default:
            break;
    }

    if(choix != 3) {
        affichage_grille(play_grille);
        while (check_winner(play_grille, 'X', col - 1) == -1 && choix_mouvement!=3) {
            choix_mouvement = move_choice(nb_tour);
            switch (choix_mouvement) {
                case 1:
                    col = colonne(play_grille);
                    test = add_token(&play_grille, col, 'X');
                    break;
                case 2:

                    break;
                case 3:

                    break;
            }
            if (test == 0) {
                printf("Mouvement impossible");
            }

            affichage_grille(play_grille);
            nb_tour++;
        }
    }

    if(choix==1 || choix == 2){
        free_memory(&play_grille);
    }
    return 0;
}
