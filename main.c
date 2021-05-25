#include "traitement.h"
#include "affichage.h"
#include "jeu.h"
#include <stdio.h>

int main() {
    grille play_grille; //grille où sera stocké le jeu
    joueur j1, j2; //joueurs de la partie
    int nb_tour; //Nombre de tour de la partie
    int nb_joueur; //nombre de joueur humain

    int choix = menu_principal(); //le joueur choisi si il veut faire une nouvelle partie recharger une ancienne , quitter.
    switch (choix) {
        case 1: //on débute une nouvelle partie
            initialisation_grille(&play_grille);
            nb_tour = 0;  //initialise le nombre de tour à 0 lorsqu'on commence une nouvelle partie
            nb_joueur = initialisation_joueur(&j1, &j2);
            break;
        case 2: //on reprend une partie précédente
            printf("Ok, je charge la grille precedente...\n");
            load(&play_grille, &nb_tour, &j1, &j2, &nb_joueur);
            break;
        case 3: //on quitte le programme
            printf("Vous allez quitter.\n");
            break;
        default:
            break;
    }

    if (choix != 3) { //si on décide de commencer une nouvelle partie/reprendre une partie précédente
        affichage_grille(play_grille);
        if (nb_joueur == 2) { //si on fait une partie a deux joueur
            jeu_multi(play_grille,j1,j2,nb_tour);
        } else if (nb_joueur == 1) {//si on fait une partie contre l'ordinateur
            jeu_solo(play_grille,j1,j2,nb_tour);
        }
    }

    if (choix==1 || choix == 2) {
        free_memory(&play_grille);
    }
    return 0;
}
