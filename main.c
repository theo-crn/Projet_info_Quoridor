#include <stdio.h>
#include "sous_prog.h"

int main(void) {
    //Dans le plateau les ligne sont la premières valeur du plateau et les colonnes la deuxième, donc des postions : y;x
    //les minuscule correspondent aux colonnes : x
    //les majuscules aux lignes : y

    //chaque point sur le tableau est représenté par un tableau contenant sa position en x, sa position en y et son num d'id
    //les pions on pour id 10n avec n entre 1 et 4

    char plate[N][N]; //plateau de jeu
    //les minuscule et MAJUSCULE auront toujours des positions impaires
    int posmin[8][2] = {{3,97},{5,98},{7,99},{9,100},{11,101},{13,102},{15,103},{17,104}};  //8 lettres minuscules, {colonne X ;id} / id : 201 = a ... 208 = h
    int posMAJ[8][2] = {{3,65},{5,66},{7,67},{9,68},{11,69},{13,70},{15,71},{17,72}}; //8 lettres majuscules, {ligne Y;id} /  id : 301 = A ... 308 = H

    //Les pions auront toujours des positions paires
    int a[3] = {2,10,101}; //pion1 {y,x;identification}
    int b[3] = {18,10,102}; //pion2 {y,x;identification}
    //cas quatre joueurs :
    int c[3] = {10,2,103}; //pion 3
    int d[3] = {10,18,104}; //pion4

    char name[nb_pseudo_max][longueur_pseudo_max];//liste des pseudos
    int coordb[2];//cordonnées des barrières

    int chact = 0;//choix de l'action effectuée par le joueur
    int* poinchact = &chact;

    int choix = 1;//choix du menu (0 == quitter)
    int* poinchoix = &choix;

    int nbj = 2; //choix du nombre de joueur
    int* pnbj = &nbj;

    int gagn[2] = {1,0};//fin du jeu si un joueur arrive a l'opposé du terrain
    int idjg = 0; //numero du joueur gagnant

    int score[4][2] = {{101,0},{102,0},{103,0},{104,0}};//sauvegarde des scores de chacun des joueurs, {id,score}

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
        if (nbj == 2) {
            placement2(plate,a,b); //placement des pions en début de jeu pour deux joueurs
        }
        else if (nbj == 4) {
            placement4(plate,a,b,c,d);
        }//placement des pions en début de jeu pour quatre joueurs
        affiche(plate); //affichage du plateau avec les pions


        choixact(poinchact);
        printf("%d\n",chact);
        if (chact == 1) {barrieres(coordb,posmin,posMAJ);}
        else if (chact == 2){move(plate,nbj,a,b,c,d,gagn);}//déplacement du premier joueur

        plateau(plate); //remise a 0 du plateau
        placement2(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
        placementb(plate,coordb);
        affiche(plate); //affichage du plateau avec les pions


        choixact(poinchact);
        printf("%d\n",chact);
        if (chact == 1) {barrieres(coordb,posmin,posMAJ);}
        else if (chact == 2){move(plate,nbj,b,a,c,d,gagn);}//déplacement du premier joueur
        plateau(plate); //remise a 0 du plateau
        placement2(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
        placementb(plate,coordb);
        affiche(plate); //affichage du plateau avec les pions

        plateau(plate); //remise a 0 du plateau
        placement4(plate,a,b,c,d); //initialisation plateau avec nouveau placement des joueurs
        affiche(plate); //affichage du plateau avec les pions
    }while (choix != 0 || gagn[0] != 0);
    if (gagn[0] == 0) {printf("Bravo aux joueur ");}
    return 0;
}


