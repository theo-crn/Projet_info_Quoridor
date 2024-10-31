#include <stdio.h>
#include "sous_prog.h"
#include "pseudo.h"

int main(void) {
    char name[2][4];
    pseudo(name);
    char plate[N][N]; //plateau de jeu
    int a[3] = {2,9,101}; //pion1 {x;y;identification}
    int b[3] = {18,9,102}; //pion2 {x;y;identification}

    plateau(plate); //initialisation plateau
    placement(plate,a,b); //placement des pions en début de jeu
    affiche(plate); //affichage du plateau avec les pions

    deplacer(plate,a); //déplacement du premier joueur
    plateau(plate); //remise a 0 du plateau
    placement(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
    affiche(plate); //affichage du plateau avec les pions

    printf("\n");

    deplacer(plate,b); //déplacement du deuxième joueur
    plateau(plate); //remise a 0 du plateau
    placement(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
    affiche(plate); //affichage du plateau avec les pions

    return 0;
}
