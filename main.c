#include <stdio.h>
#include "sous_prog.h"

int main(void) {
    char name[2][4];
    //crpseudo(name);
    char plate[N][N]; //plateau de jeu
    int a[3] = {2,9,101}; //pion1 {x;y;identification}
    int b[3] = {18,9,102}; //pion2 {x;y;identification}

    int choix = 1;
    int nbj = 2; //choix du nombre de joueur

    regle();


    //menu1(choix);

    do {
        choix = quitter;

        plateau(plate); //initialisation plateau
        placement2(plate,a,b); //placement des pions en début de jeu
        affiche(plate); //affichage du plateau avec les pions

        action(a); //déplacement du premier joueur
        plateau(plate); //remise a 0 du plateau
        placement2(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
        affiche(plate); //affichage du plateau avec les pions

        printf("\n");

        action(b); //déplacement du deuxième joueur
        plateau(plate); //remise a 0 du plateau
        placement2(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
        affiche(plate); //affichage du plateau avec les pions

    }while (choix != 0);

    return 0;
}
