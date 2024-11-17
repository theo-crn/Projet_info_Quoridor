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
    int posmin[8][2] = {{3,'a'},{5,'b'},{7,'c'},{9,'d'},{11,'e'},{13,'f'},{15,'g'},{17,'h'}};  //8 lettres minuscules, {colonne X ;id} / id : 201 = a ... 208 = h
    int posMAJ[8][2] = {{3,'A'},{5,'B'},{7,'C'},{9,'D'},{11,'E'},{13,'F'},{15,'G'},{17,'H'}}; //8 lettres majuscules, {ligne Y;id} /  id : 301 = A ... 308 = H

    //Les pions auront toujours des positions paires
    int a[3] = {2,10,101}; //pion1 {y,x;identification}
    int b[3] = {18,10,102}; //pion2 {y,x;identification}
    //cas quatre joueurs :
    int c[3] = {10,2,103}; //pion 3
    int d[3] = {10,18,104}; //pion4

    char name[2][4];//liste des pseudos
    int coordb[2];//cordonnées des barrières

    int chact = 0;//choix de l'action effectuée par le joueur
    int* poinchact = &chact;

    int choix = 1;//choix du menu (0 == quitter)
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
        if (chact == 1) {barrieres(coordb,posmin,posMAJ);}
        else if (chact == 2){move(nbj,a,b,c,d);}//déplacement du premier joueur

        plateau(plate); //remise a 0 du plateau
        placement2(plate,a,b); //initialisation plateau avec nouveau placement des joueurs
        placementb(plate,coordb);
        affiche(plate); //affichage du plateau avec les pions


        choixact(poinchact);
        printf("%d\n",chact);
        if (chact == 1) {
            barrieres(coordb,posmin,posMAJ);
        }
        else if (chact == 2){move(nbj,b,a,c,d);}//déplacement du premier joueur

        plateau(plate); //remise a 0 du plateau
        placement4(plate,a,b,c,d); //initialisation plateau avec nouveau placement des joueurs
        affiche(plate); //affichage du plateau avec les pions
    }while (choix != 0);

    return 0;
}
