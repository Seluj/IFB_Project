#include "traitement.h"
#include "affichage.h"

int main() {
    grille play_grille;
    int choix = menu();
    int test,round,choice;
    if (choix == 1){
        play_grille.cote=acquisition_taille_grille();
        initialisation_grille(&play_grille);
        affichage_grille(play_grille);
        choice=move_choice(round);
        if(choice==1) {
            test = ajout_pion(&play_grille, 2, 'X');
            if (test == 0) {
                printf("Mouvement impossible");
            }
        }
        affichage_grille(play_grille);


        free_memory(play_grille);
    } else if(choix == 2){

    }
    return 0;
}
