//
// Created by theop on 18/10/2024.
//

#ifndef SOUS_PROG_H
#define N 19 //taille du plateau
#define SOUS_PROG_H

void plateau(char plate[N][N]);
void placement(char plate[N][N],int piona[3], int pionb[3]);
void affiche(char plate[N][N]);

void deplacer(char plate[N][N], int pion[3]);

void mvt_droite(int tab1[]);
void mvt_gauche(int tab1[]);
void mvt_haut(int tab1[]);
void mvt_bas(int tab1[]);


#endif //SOUS_PROG_H
