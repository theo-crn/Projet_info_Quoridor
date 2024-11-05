#include <stdio.h>
#include "sous_prog.h"

int main(void) {
    char name[2][4];
    //crpseudo(name);
    char plate[N][N]; //plateau de jeu
    int a[3] = {2,10,101}; //pion1 {x;y;identification}
    int b[3] = {18,10,102}; //pion2 {x;y;identification}
    int chact = 0;
    int* poinchact = &chact;
    int choix = 1;
    int nbj = 2; //choix du nombre de joueur

    //regle();


    //menu1(choix);

    //do {
    //choix = quitter;

    plateau(plate); //initialisation plateau
    placement2(plate,a,b); //placement des pions en début de jeu
    affiche(plate); //affichage du plateau avec les pions

    choixact(poinchact);
    printf("%d\n",chact);
    if (chact == 1) {printf("barrieres");}
    else {action(a);}//déplacement du premier joueur

    plateau(plate); //remise a 0 du plateau
    placement2(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
    affiche(plate); //affichage du plateau avec les pions

    printf("\n");

    choixact(poinchact);
    printf("%d\n",chact);
    if (chact == 1) {printf("barrieres");}
    else {action(b);}//déplacement du deuxième joueur

    plateau(plate); //remise a 0 du plateau
    placement2(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
    affiche(plate); //affichage du plateau avec les pions

    //}while (choix != 0);

    return 0;
}
