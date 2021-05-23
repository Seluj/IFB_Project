//
// Created by jules on 23/05/21.
//

#include "traitement.h"
#include "affichage.h"
#include "check_winer.h"
#include "jeu.h"
#include "ordinateur.h"
#include <stdio.h>


/**
 * fonction principale d'un jeu à deux joueurs
 * @param play_grille grille à afficher avec les pions
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @param nb_tour compteur du nombre de tours
 */
void jeu_multi(grille play_grille, joueur j1, joueur j2, int nb_tour){

    int test, choix_mvt_utilisateur, col_precedent, choix_mvt_utilisateur_precedent = 1;
    int col_choisi = 2;

    while (
            check_winner(play_grille, 'X', col_choisi - 1, j1) == -1
            && check_winner(play_grille, 'O', col_choisi - 1, j1) == -1
            && grille_pleine(play_grille)
            && choix_mvt_utilisateur != 3) {

        if (nb_tour % 2 == j1.numero_joueur) {
            couleur(4, 0);
        } else if (nb_tour % 2 == j2.numero_joueur) {
            couleur(14, 0);
        }

        choix_mvt_utilisateur = menu_mvt(nb_tour);

        switch (choix_mvt_utilisateur) {
            case 1:
                do {
                    col_choisi = colonne_utilisateur(play_grille, col_precedent, choix_mvt_utilisateur,
                                                     choix_mvt_utilisateur_precedent);

                    if (nb_tour % 2 == j1.numero_joueur) {
                        test = add_token(&play_grille, col_choisi, j1.pions);
                    } else if (nb_tour % 2 == j2.numero_joueur) {
                        test = add_token(&play_grille, col_choisi, j2.pions);
                    }
                } while (test == 0);
                break;
            case 2:
                do {
                    col_choisi = colonne_utilisateur(play_grille, col_precedent, choix_mvt_utilisateur,
                                                     choix_mvt_utilisateur_precedent);
                    test = remove_token(&play_grille, col_choisi - 1);
                } while (test == 0);
                break;
            case 3:
                save(play_grille, nb_tour, j1, j2, 2);
                break;
            default:
                break;
        }
        couleur(15, 0);
        choix_mvt_utilisateur_precedent = choix_mvt_utilisateur;
        col_precedent = col_choisi;
        affichage_grille(play_grille);
        nb_tour++;
    }
}

/**
 * fonction principal d'un jeu en solo contre un ordinateur
 * @param play_grille grille à afficher avec les pions
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @param nb_tour compteur du nombre de tours
 */
void jeu_solo(grille play_grille, joueur j1, joueur j2, int nb_tour) {
    int test, choix_mvt, col_precedent, choix_mvt_precedent = 1;
    int col_choisi = 2;
    while (
            check_winner(play_grille, 'X', col_choisi - 1, j1) == -1
            && check_winner(play_grille, 'O', col_choisi - 1, j1) == -1
            && grille_pleine(play_grille)
            && choix_mvt != 3) {

        if (nb_tour % 2 == j1.numero_joueur) {
            if (j1.pions == 'X') {
                couleur(4, 0);
            } else {
                couleur(14, 0);
            }
            choix_mvt = menu_mvt(nb_tour);
            switch (choix_mvt) {
                case 1:
                    do {
                        col_choisi = colonne_utilisateur(play_grille, col_precedent, choix_mvt,
                                                         choix_mvt_precedent);
                        test = add_token(&play_grille, col_choisi, j1.pions);
                    } while (test == 0);
                    break;
                case 2:
                    do {
                        col_choisi = colonne_utilisateur(play_grille, col_precedent, choix_mvt,
                                                         choix_mvt_precedent);
                        test = remove_token(&play_grille, col_choisi - 1);
                    } while (test == 0);
                    break;
                case 3:
                    save(play_grille, nb_tour, j1, j2, 1);
                    break;
                default:
                    break;
            }
            couleur(15, 0);
        } else if (nb_tour % 2 == j2.numero_joueur) {
            if (j2.pions == 'X') {
                couleur(4,0);
            } else {
                couleur(14,0);
            }
            choix_mvt = mvt_ordi(nb_tour);
            switch (choix_mvt) {
                case 1:
                    col_choisi = colonne_ordi(play_grille, col_precedent, choix_mvt, choix_mvt_precedent);
                    test = add_token(&play_grille, col_choisi, j2.pions);
                    printf("L'ordinateur a decid%c de mettre un pion dans la colonne %d\n\n", 130, col_choisi);
                    break;
                case 2:
                    col_choisi = colonne_ordi(play_grille, col_precedent, choix_mvt, choix_mvt_precedent);
                    test = remove_token(&play_grille, col_choisi - 1);
                    printf("L'ordinateur a decid%c d'enlever un pion dans la colonne %d\n\n", 130, col_choisi);
                    break;
            }
            couleur(15, 0);
        }
        choix_mvt_precedent = choix_mvt;
        col_precedent = col_choisi;
        affichage_grille(play_grille);
        nb_tour++;
    }
}