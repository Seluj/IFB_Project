//
// Created by jules on 10/05/21.
//
#include "traitement.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * initie la grille et demande le nombre de pions à aligner
 * @param grille grille a modifier
 */
void initialisation_grille(grille* grille){
    int size;
    printf("Entrez le nombre de pionts %c alligner pour gagner :",224);
    scanf("%d",&size);
    fflush((stdin));
    while (size <= 2) {
        printf("Nombre de pionts invalide, veuillez recommencer");
        printf("Entrez le nombre de pionts %c alligner pour gagner :",224);
        scanf("%d",&size);
        fflush((stdin));
    }
    grille->hauteur = size+2;
    grille->largeur = size+2;
    grille->grille = (char**) malloc(sizeof(char*) * grille->hauteur);
    for (int i = 0; i < grille->hauteur; i++) {
        grille->grille[i] = (char*) malloc(sizeof(char) * grille->largeur);
        for (int j = 0; j < grille->largeur; j++) {
            grille->grille[i][j] = '_';
        }
    }
}

/**
 * initialise les joueurs en leur donnant leur numéro et leur pion
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @return le nombre de joueur
 */
int initialisation_joueur(joueur* j1, joueur* j2){
    srand(time(0));
    int couleur, alea, nb_joueur;
    char tab[2] = {'X', 'O'};
    nb_joueur = menu_nb_de_joueur();
    if (nb_joueur == 1) {
        do {
            printf("Voulez-vous être rouge (1) ou jaune (2) :");
            scanf("%d", &couleur);
        }while(couleur != 1 && couleur != 2);

        j1->pions = tab[couleur-1];
        if (couleur-1 == 0) {
            j2->pions = tab[1];
        } else {
            j2->pions = tab[0];
        }
    } else if (nb_joueur == 2) {
        j1->pions = 'X';
        j2->pions = 'O';
        printf("le joueur 1 est rouge (X) et le joueur 2 est jaune (O)\n");
    }

    alea = rand()%2;
    j1->numero_joueur = alea;
    if (alea == 0) {
        j2->numero_joueur = 1;

    } else if (alea == 1) {
        j2->numero_joueur = 0;
    }
    printf("\n"
           "Le joueur 1 joue en %d\n"
           "Le joueur 2 joue en %d\n",
           j1->numero_joueur + 1,
           j2->numero_joueur + 1);
    return nb_joueur;
}

/**
 * ajoute un pion a la grille
 * @param g grille de jeu
 * @param indice numéro de la colonne +1 ou faire "tomber" le jeton
 * @param jeton type de jeton a ajouter X ou O
 * @return 1 si c'est possible et 0 si cela n'est pas
 */
int add_token(grille* g, int indice, char jeton){
    int i = 0;

    while (g->grille[indice-1][i] == '_') {
        i++;
    }

    if (i==0) {
        return 0;
    } else {
        g->grille[indice-1][i-1] = jeton;
        return 1;
    }
}

/**
 * retirer un pion de la grille
 * @param g grille de jeu
 * @param colonne numéro de la colonne +1 où retirer un jeton
 * @return 1 si c'est possible et 0 si cela n'est pas
 */
int remove_token(grille* g, int colonne){
    int i = 0;

    while (g->grille[colonne][i] == '_') {
        i++;
    }

    if (i==g->hauteur) {
        return 0;
    } else {
        g->grille[colonne][i] = '_';
        return 1;
    }
}

/**
 * demande une colonne a l'utilisateur et compare au choix precedent
 * @param g grille de jeu
 * @param col colonne precedente
 * @param choix_mouvement choix de l'utilisateur
 * @param choix_mouvement_precedent choix precendent de l'utilisateur
 * @return retourne le numéro de la colonne chosi
 */
int colonne_utilisateur(grille g, int col_precedente, int choix_mouvement, int choix_mouvement_precedent){
    int resultat;

    //test du choix de l'utilisateur
    switch (choix_mouvement) {
        case 1:
            //test du choix precendent
            if (choix_mouvement_precedent == 2) {
                do {
                    printf("Vous avez choisis la colonne :");
                    scanf("%d", &resultat);
                    fflush(stdin);
                    if (resultat == col_precedente) {
                        printf("Vous ne pouvez pas remettre de pions dans cette case pour ce tour\n");
                    }
                } while (resultat > g.largeur || resultat == col_precedente);
            } else {
                do {
                    printf("Vous avez choisis la colonne :");
                    scanf("%d",&resultat);
                    fflush(stdin);
                } while (resultat > g.largeur);
            }
            break;

        case 2:
            do {
                printf("Vous avez choisis la colonne : ");
                scanf("%d",&resultat);
                fflush(stdin);
            } while (resultat > g.largeur);
            break;
    }
    return resultat;
}

/**
 * sauvegarde la partie en cours
 * @param g grille a sauvegarder
 * @param nb_tour numéro du tour a sauvegarder
 * @param joueur joueur du prochain tour
 */
void save(grille g, int nb_tour, joueur j1, joueur j2, int nb_joueur){
    FILE* fichier;
    fichier = fopen("save.txt", "w+");
    fprintf(fichier, "%d\n", nb_tour);
    fprintf(fichier, "%d\t", g.largeur);
    fprintf(fichier, "%d\n", g.hauteur);
    fprintf(fichier, "%d\n", nb_joueur);
    fprintf(fichier, "%c\t%d\n", j1.pions, j1.numero_joueur);
    fprintf(fichier, "%c\t%d\n", j2.pions, j2.numero_joueur);
    for (int i = 0; i < g.hauteur; i++) {
        for (int j = 0; j < g.largeur; j++) {
            fprintf(fichier, " %c ", g.grille[j][i]);
        }
        fprintf(fichier, "\n");
    }
}

/**
 * initialise une partie sauvegardé
 * @param g grille a charger
 * @param nb_tour numéro du tour a charger
 * @param joueur joueur du prochain tour
 */
void load(grille* g, int* nb_tour, joueur* j1, joueur* j2, int* nb_joueur){
    FILE* fichier;
    fichier = fopen("save.txt", "r");
    fscanf(fichier, "%d\n", nb_tour);
    fscanf(fichier, "%d\t", &g->largeur);
    fscanf(fichier, "%d\n", &g->hauteur);
    fscanf(fichier, "%d\n", nb_joueur);
    fscanf(fichier, "%c\t%d\n", &j1->pions, &j1->numero_joueur);
    fscanf(fichier, "%c\t%d\n", &j2->pions, &j2->numero_joueur);
    g->grille = (char **) malloc(sizeof(char *) * g->hauteur);
    for (int i = 0; i < g->hauteur; ++i) {
        g->grille[i] = (char *) malloc(sizeof(char) * g->largeur);
    }
    for (int i = 0; i < g->hauteur; i++) {
        for (int j = 0; j < g->largeur; j++) {
            fscanf(fichier, " %c ", &g->grille[j][i]);
        }
        fscanf(fichier, "\n");
    }
}

/**
 * vérifie si la grille est pleine en arrête le programme si c'est le cas
 * @param g la grille avec les pions déjà placés
 * @return 0 si elle est pleine et 1 si elle ne l'est pas
 */
int grille_pleine(grille g){
    int s = 0;
    for (int j = 0; j < g.largeur; j++) {
        if (g.grille[j][0] == '_') {
            s++;
        }
    }
    if (s == 0) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * libere la mémoire pour la grille
 * @param grille grille a liberer
 */
void free_memory(grille* grille){
    for (int i = 0; i < grille->hauteur; ++i) {
        free(grille->grille[i]);
    }
    free(grille->grille);
}