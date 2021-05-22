//
// Created by jules on 10/05/21.
//

#ifndef PROJET_IFB_TRAITEMENT_H
#define PROJET_IFB_TRAITEMENT_H


typedef struct {
    char** grille;
    int largeur;
    int longueur;
}grille;


//int acquisition_taille_grille();
void initialisation_grille(grille* grille);
int add_token(grille* g, int indice, char jeton);
void couleur(int couleurDuTexte,int couleurDeFond);
void free_memory(grille* grille);
int colonne(grille g);
int position_valide(grille g, int ligne, int colonne);
#endif //PROJET_IFB_TRAITEMENT_H
