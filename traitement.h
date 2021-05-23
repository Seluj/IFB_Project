//
// Created by jules on 10/05/21.
//

#ifndef PROJET_IFB_TRAITEMENT_H
#define PROJET_IFB_TRAITEMENT_H

typedef struct {
    char** grille;
    int largeur;
    int hauteur;
}grille;

typedef struct {
    char pions;
    int numero_joueur;
}joueur;

/**
 * initie la grille et demande le nombre de pions à alinger
 * @param grille grille a modifier
 */
void initialisation_grille(grille* grille);

/**
 * initialise les joueurs en leur donnant leur numéro et leur pion
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @return le nombre de joueur
 */
int initialisation_joueur(joueur* j1, joueur* j2);

/**
 * ajoute un pion a la grille
 * @param g grille de jeu
 * @param indice numéro de la colonne +1 ou faire "tomber" le jeton
 * @param jeton type de jeton a ajouter X ou O
 * @return 1 si c'est possible et 0 si cela n'est pas
 */
int add_token(grille* g, int indice, char jeton);

/**
 * retirer un pion de la grille
 * @param g grille de jeu
 * @param colonne numéro de la colonne +1 où retirer un jeton
 * @return 1 si c'est possible et 0 si cela n'est pas
 */
int remove_token(grille* g, int colonne);

/**
 * demande une colonne a l'utilisateur et compare au choix precedent
 * @param g grille de jeu
 * @param col colonne precedente
 * @param choix_mouvement choix de l'utilisateur
 * @param choix_mouvement_precedent choix precendent de l'utilisateur
 * @return retourne le numéro de la colonne chosi
 */
int colonne_utilisateur(grille g, int col_precedente, int choix_mouvement, int choix_mouvement_precedent);

/**
 * sauvegarde la partie en cours
 * @param g grille a sauvegarder
 * @param nb_tour numéro du tour a sauvegarder
 * @param joueur joueur du prochain tour
 */
void save(grille g, int nb_tour, joueur j1, joueur j2, int nb_joueur);

/**
 * initialise une partie sauvegardé
 * @param g grille a charger
 * @param nb_tour numéro du tour a charger
 * @param joueur joueur du prochain tour
 */
void load(grille* g, int* nb_tour, joueur* j1, joueur* j2, int* nb_joueur);

/**
 * vérifie si la grille est pleine en arrête le programme si c'est le cas
 * @param g la grille avec les pions déjà placés
 * @return 0 si elle est pleine et 1 si elle ne l'est pas
 */
int grille_pleine(grille g);

/**
 * libere la mémoire pour la grille
 * @param grille grille a liberer
 */
void free_memory(grille* grille);

#endif //PROJET_IFB_TRAITEMENT_H
