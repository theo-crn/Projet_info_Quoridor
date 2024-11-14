#include <stdio.h>
#include "sous_prog.h"

int main(void) {
    //Dans le plateau les ligne sont la premières valeur du plateau et les colonnes la deuxième, donc des postions : y;x
    //les minuscule correspondent aux colonnes : x
    //les majuscules aux lignes : y

    //chaque point sur le tableau est représenté par un tableau contenant sa position en x, sa position en y et son num d'id
    //les pions on pour id 10n avec n entre 1 et 4
    //les colonne minuscule on pour id 20n avec n entre 1 et 8
    //les ligne MAJUSCULE on pour id 30n avec n entre 1 et 8

    char plate[N][N]; //plateau de jeu
    //les minuscule et MAJUSCULE auront toujours des positions impaires
    int posmin[8][2] = {{3,201},{5,202},{7,203},{9,204},{11,205},{13,206},{15,207},{17,208}};  //8 lettres minuscules, {colonne X ;id} / id : 201 = a ... 208 = h
    int posMAJ[8][2] = {{3,301},{5,302},{7,303},{9,304},{11,305},{13,306},{15,307},{17,308}}; //8 lettres majuscules, {ligne Y;id} /  id : 301 = A ... 308 = H

    //Les pions auront toujours des positions paires
    int a[3] = {2,10,101}; //pion1 {y,x;identification}
    int b[3] = {18,10,102}; //pion2 {y,x;identification}
    //cas quatre joueurs :
    int c[3] = {10,2,103}; //pion 3
    int d[3] = {10,18,104}; //pion4

    char name[2][4];

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
