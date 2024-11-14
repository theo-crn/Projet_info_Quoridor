#include <stdio.h>
#include "sous_prog.h"

int main(void) {
    char name[2][4];

    char plate[N][N]; //plateau de jeu
    int a[3] = {2,10,101}; //pion1 {x;y;identification}
    int b[3] = {18,10,102}; //pion2 {x;y;identification}
    //cas quatre joueurs :
    int c[3] = {10,2,103}; //pion 3
    int d[3] = {10,18,104}; //pion4

    int chact = 0;
    int* poinchact = &chact;
    int choix = 1;
    int* poinchoix = &choix;
    int nbj = 2; //choix du nombre de joueur
    int* pnbj = &nbj;

    regle();


    if(menuprim(poinchoix) == 0) {
        return 0;
    }
    crpseudo(name,pnbj);
    do {
        if(quitter(poinchoix) == 0) {
            return 0;
        }


        plateau(plate); //initialisation plateau
        if (nbj == 2){placement2(plate,a,b);} //placement des pions en début de jeu pour deux joueurs
        else if (nbj == 4){placement4(plate,a,b,c,d);}//placement des pions en début de jeu pour quatre joueurs
        affiche(plate); //affichage du plateau avec les pions


        choixact(poinchact);
        printf("%d\n",chact);
        if (chact == 1) {printf("barrieres");}
        else if (chact == 2){move(nbj,a,b,c,d);}//déplacement du premier joueur

        plateau(plate); //remise a 0 du plateau
        placement2(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
        affiche(plate); //affichage du plateau avec les pions


        choixact(poinchact);
        printf("%d\n",chact);
        if (chact == 1) {printf("barrieres");}
        else if (chact == 2){move(nbj,b,a,c,d);}//déplacement du premier joueur

        plateau(plate); //remise a 0 du plateau
        placement4(plate,a,b,c,d); //initialisation plateau avec nouveau placement des joueurs
        affiche(plate); //affichage du plateau avec les pions
    }while (choix != 0);

    return 0;
}
