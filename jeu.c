//
// Created by jules on 23/05/21.
//

#include "traitement.h"
#include "affichage.h"
#include "check_winer.h"
#include "jeu.h"
#include "ordinateur.h"
#include <stdio.h>

void jeu_multi(grille play_grille, joueur j1, joueur j2, int nb_tour){

    int test, choix_mvt_utilisateur, col_precedent, choix_mvt_utilisateur_precedent = 1;
    int col_choisi = 2;

    while (
            check_winner(play_grille, 'X', col_choisi - 1, j1) == -1
            && check_winner(play_grille, 'O', col_choisi - 1, j1) == -1
            && grille_pleine(play_grille)
            && choix_mvt_utilisateur != 3) { //on repete le contenu de la boucle, tant que personne n'a gagné, et que on
                                            // peut insérer des jetons dans la grille, et qu'aucun des joueur ne veut sauvegarder
        if (nb_tour % 2 == j1.numero_joueur) {
            couleur(4, 0);//on adapte la couleur en fonction du tour
        } else if (nb_tour % 2 == j2.numero_joueur) {
            couleur(14, 0);
        }
        choix_mvt_utilisateur = menu_mvt(nb_tour);

        switch (choix_mvt_utilisateur) {
            case 1: //l'utilisateur choisi d'ajouter un jeton
                do {
                    col_choisi = colonne_utilisateur(play_grille, col_precedent, choix_mvt_utilisateur,
                                                     choix_mvt_utilisateur_precedent);//l'utilisateur choisi la colonne dans laquelle ajouter un pion

                    if (nb_tour % 2 == j1.numero_joueur) { //on verifie si le jeton peut être insérer
                        test = add_token(&play_grille, col_choisi, j1.pions);
                    } else if (nb_tour % 2 == j2.numero_joueur) {
                        test = add_token(&play_grille, col_choisi, j2.pions);
                    }
                } while (test == 0);//on répete toute ces étapes tant que la colonne ne peut pas accepter plus de jeton (colonne pleine)
                break;
            case 2: //l'utilisateur choisi de retirer un pion
                do {
                    col_choisi = colonne_utilisateur(play_grille, col_precedent, choix_mvt_utilisateur,
                                                     choix_mvt_utilisateur_precedent);//l'utilisateur choisi la colonne dans laquelle enlever un pion
                    test = remove_token(&play_grille, col_choisi - 1);//on teste si on peut effectivement enlever un pion
                } while (test == 0);//on repete l'opération tant qu'on ne peut pas enlever de jeton dans la colonne choisi
                break;
            case 3: //l'utilisateur choisi de sauvegarder la partie
                save(play_grille, nb_tour, j1, j2, 2);
                break;
            default:
                break;
        }
        couleur(15, 0);
        choix_mvt_utilisateur_precedent = choix_mvt_utilisateur;//on met a jour les informations utile pour le tour suivant
        col_precedent = col_choisi;
        affichage_grille(play_grille);//affichage de la grille dans son état actuel
        nb_tour++;
    }
}

void jeu_solo(grille play_grille, joueur j1, joueur j2, int nb_tour) {
    int test, choix_mvt, col_precedent, choix_mvt_precedent = 1;
    int col_choisi = 2;
    while (
            check_winner(play_grille, 'X', col_choisi - 1, j1) == -1
            && check_winner(play_grille, 'O', col_choisi - 1, j1) == -1
            && grille_pleine(play_grille)
            && choix_mvt != 3) {//on repete le contenu de la boucle, tant que personne n'a gagné, et que on
                                // peut insérer des jetons dans la grille, et que le joueur ne veut pas  sauvegarder
        if (nb_tour % 2 == j1.numero_joueur) { //si c'est a l'utilisateur de jouer
            if (j1.pions == 'X') { //on change la couleur en fonction du choix de pion de l'utilisateur
                couleur(4, 0);
            } else {
                couleur(14, 0);
            }
            choix_mvt = menu_mvt(nb_tour);
            switch (choix_mvt) { //même fonctionnement que dans jeu_multi
                case 1://ajout
                    do {
                        col_choisi = colonne_utilisateur(play_grille, col_precedent, choix_mvt,
                                                         choix_mvt_precedent);
                        test = add_token(&play_grille, col_choisi, j1.pions);
                    } while (test == 0);
                    break;
                case 2: //retrait
                    do {
                        col_choisi = colonne_utilisateur(play_grille, col_precedent, choix_mvt,
                                                         choix_mvt_precedent);
                        test = remove_token(&play_grille, col_choisi - 1);
                    } while (test == 0);
                    break;
                case 3://sauvegarde
                    save(play_grille, nb_tour, j1, j2, 1);
                    break;
                default:
                    break;
            }
            couleur(15, 0);
        } else if (nb_tour % 2 == j2.numero_joueur) {//si c'est au tour de l'ordinateur
            if (j2.pions == 'X') { //on change la couleur en fonction de la couleur de l'utilisateur
                couleur(4,0);
            } else {
                couleur(14,0);
            }
            choix_mvt = mvt_ordi(nb_tour);
            switch (choix_mvt) {//même fonctionement que pour l'utilisateur, sans la sauvegarde
                case 1:
                    col_choisi = colonne_ordi(play_grille, col_precedent, choix_mvt, choix_mvt_precedent);
                    printf("L'ordinateur a decid%c de mettre un pion dans la colonne %d\n\n", 130, col_choisi);
                    break;
                case 2:
                    col_choisi = colonne_ordi(play_grille, col_precedent, choix_mvt, choix_mvt_precedent);
                    printf("L'ordinateur a decid%c d'enlever un pion dans la colonne %d\n\n", 130, col_choisi);
                    break;
            }
            couleur(15, 0);
        }
        choix_mvt_precedent = choix_mvt; //mise a jour des informations pour le prochain tour
        col_precedent = col_choisi;
        affichage_grille(play_grille);//affichage de la grille dans son état actuel
        nb_tour++;
    }
}