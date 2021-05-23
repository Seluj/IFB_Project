#include "traitement.h"
#include "affichage.h"
#include "jeu.h"
#include <stdio.h>

int main() {
    grille play_grille; //grille où sera stocké le jeu
    joueur j1, j2; //joueurs de la partie
    int nb_tour; //Nombre de tour de la partie
    int nb_joueur; //nombre de joueur reel

    int choix = menu_principal(); //le joueur choisi si il veut faire une nouvelle partie recharger une ancienne , quitter.
    switch (choix) {
        case 1:
            initialisation_grille(&play_grille);
            nb_tour = 0;  //initie le nombre de tour à 0 lorsqu'on commence une nouvelle partie
            nb_joueur = initialisation_joueur(&j1, &j2);
            break;
        case 2:
            printf("Ok, je charge la grille precedente...\n");
            load(&play_grille, &nb_tour, &j1, &j2, &nb_joueur);
            break;
        case 3:
            printf("Vous allez quitter.\n");
            break;
        default:
            break;
    }

    if (choix != 3) {
        affichage_grille(play_grille);
        if (nb_joueur == 2) {
            jeu_multi(play_grille,j1,j2,nb_tour);
        } else if (nb_joueur == 1) {
            jeu_solo(play_grille,j1,j2,nb_tour);
        }
    }

    if (choix==1 || choix == 2) {
        free_memory(&play_grille);
    }
    return 0;
}
