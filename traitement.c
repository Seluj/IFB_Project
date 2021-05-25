//
// Created by jules on 10/05/21.
//
#include "traitement.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialisation_grille(grille* grille){
    int size;
    printf("Entrez le nombre de pionts %c alligner pour gagner :",224);
    scanf("%d",&size);
    fflush((stdin));
    while (size <= 2) {
        printf("Nombre de pions invalide, veuillez recommencer");
        printf("Entrez le nombre de pions %c alligner pour gagner :",224);
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

int initialisation_joueur(joueur* j1, joueur* j2){
    srand(time(0));
    int couleur, alea, nb_joueur;
    char tab[2] = {'X', 'O'};
    nb_joueur = menu_nb_de_joueur();
    if (nb_joueur == 1) {
        do {
            printf("Voulez-vous %ctre rouge (1) ou jaune (2) :",234);
            scanf("%d", &couleur);
        }while(couleur != 1 && couleur != 2);

        j1->pions = tab[couleur-1]; //on attribue la couleur a l'ordinateur en fonction du choix du joueur
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

    alea = rand()%2; //attribution de l'ordre de jeu
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

int add_token(grille* g, int indice, char jeton){
    int i = 0;

    while (g->grille[indice-1][i] == '_') { //"gravité" le pion ajouté va descendre jusqu'a renconter un obstacle
        i++;
    }

    if (i==0) { //on verifie qu'on peut effectivement ajouter un pion dans la colonne selectionné
        return 0;
    } else {
        g->grille[indice-1][i-1] = jeton;
        return 1;
    }
}

int remove_token(grille* g, int colonne){
    int i = 0;

    while (g->grille[colonne][i] == '_') { //on cherche a quel hauteur se situe le dernier pion
        i++;
    }

    if (i==g->hauteur) { //on verifie si le dernier pion de la colonne se situe sur la dernière couche
        return 0;
    } else {
        g->grille[colonne][i] = '_';
        return 1;
    }
}

int colonne_utilisateur(grille g, int col_precedente, int choix_mouvement, int choix_mouvement_precedent){
    int resultat;

    switch (choix_mouvement) { //si l'utilisateur choisi d'ajouter un jeton
        case 1:
            //comparaison avec le choix du tour précedent
            if (choix_mouvement_precedent == 2) {//si on a décidé de retirer un pion au tour précédent
                do {
                    printf("Vous avez choisis la colonne :");//on demande au joueuer dans quelle colonne il veut poser son pion
                    scanf("%d", &resultat);
                    fflush(stdin);
                    if (resultat == col_precedente) { //si c'est la même qu'au tour précédent
                        printf("Vous ne pouvez pas remettre de pions dans cette case pour ce tour\n");
                    }
                } while (resultat > g.largeur || resultat == col_precedente); //on repète l'opération tant que la colonne saisi ne satisfait pas aux critères
            } else { //si on a ajouté un pion au tour précédent
                do {
                    printf("Vous avez choisis la colonne :");
                    scanf("%d",&resultat);
                    fflush(stdin);
                } while (resultat > g.largeur);
            }
            break;

        case 2: //si le joueur décide de retirer un pion
            do {
                printf("Vous avez choisis la colonne : ");
                scanf("%d",&resultat);
                fflush(stdin);
            } while (resultat > g.largeur);//on repete tant que le nombre entré par le joueur ne satisfait pas aux exigences
            break;
    }
    return resultat;
}

void save(grille g, int nb_tour, joueur j1, joueur j2, int nb_joueur){
    FILE* fichier;
    fichier = fopen("save.txt", "w+");//on sauvegarde toute les infos essentiels pour la reprise de la partie
    fprintf(fichier, "%d\n", nb_tour);//le nombre de tour
    fprintf(fichier, "%d\t", g.largeur);//les dimension de la grille
    fprintf(fichier, "%d\n", g.hauteur);
    fprintf(fichier, "%d\n", nb_joueur);//quel joueur était entrain de jouer
    fprintf(fichier, "%c\t%d\n", j1.pions, j1.numero_joueur);//la couleur et le numéro du 1er joueur
    fprintf(fichier, "%c\t%d\n", j2.pions, j2.numero_joueur);//la couleur et le numéro du 2eme joueur
    for (int i = 0; i < g.hauteur; i++) {
        for (int j = 0; j < g.largeur; j++) {
            fprintf(fichier, " %c ", g.grille[j][i]); //sauvegarde de la grille
        }
        fprintf(fichier, "\n");
    }
}

void load(grille* g, int* nb_tour, joueur* j1, joueur* j2, int* nb_joueur){
    FILE* fichier;
    fichier = fopen("save.txt", "r");//opération inverse de la fonction save
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

int grille_pleine(grille g){
    int s = 0;
    for (int j = 0; j < g.largeur; j++) {
        if (g.grille[j][0] == '_') {
            s++; //on parcourt le tableau en cherchant une case vide
        }
    }
    if (s == 0) {
        return 0;
    } else {
        return 1;
    }
}

void free_memory(grille* grille){
    for (int i = 0; i < grille->hauteur; ++i) {
        free(grille->grille[i]);
    }
    free(grille->grille);
}