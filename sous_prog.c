//
// Created by theop on 18/10/2024.
//
#include <stdio.h>
#include "sous_prog.h"

void plateau(char plat[N][N]) {
    int i,j;
    char murv = '|'; //mur vertical
    char murh = '-' ; //mur horizontal
    char murc = '+'; //coin
    char esp = ' '; //espace pour placer les pions

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++) {
            if (i == 0 || i == N-1){plat[i][j] = murh;} //ligne 0 et N

            else if (i%2 == 0 && i !=0 && i != N) //ligne murs horizontals
            {
                if (j==0 || j==N-1){plat[i][j] = murv;}
                else if (j%2==0){plat[i][j] = murc;}
                else {plat[i][j] = murh;}
            }

            else if (i%2 != 0 && i != N) //ligne alternant espaces et murs verticals
            {
                if (j==0 || j==N-1){plat[i][j] = murv;}
                else if (j%2 != 0){plat[i][j] = esp;}
                else {plat[i][j] = murv;} //bon courage :)
            }
        }
    }
}
void placement(char plate[N][N],int piona[3], int pionb[3]) {
    int i,j;
    plate[piona[0]][piona[1]] = '1';
    plate[pionb[0]][pionb[1]] = '2';
}
void affiche(char plat[N][N]) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", plat[i][j]);
        }
        printf("\n");
    }
}

void deplacer(char plat[N][N], int pionuti[3]) {
    int fin = 1;
    int uti = 1;
    char mvtp;
    if (pionuti[2] == 102){uti =2;}

    do {
        printf("Au tour du joueur %d \n",uti);
        printf("Si vous voulez deplacer le pion a droite, entrer 'd'\n");
        printf("Si vous voulez deplacer le pion a gauche, entrer 'g'\n");
        printf("Si vous voulez deplacer le pion vers le haut, entrer 'h'\n");
        printf("Si vous voulez deplacer le pion vers le bas, entrer 'b'\n");
        scanf("%c", &mvtp);

        if (mvtp == 'd') {
            if (pionuti[1]+1 < N) {
                pionuti[1] = pionuti[1]+2;
                fin = 0;
            }
            else {
                printf("coup interdit\n");
            }
        }

        else if (mvtp == 'g') {
            if (pionuti[1]-1 > 0) {
                pionuti[1] = pionuti[1]-2;
                fin = 0;
            }
            else {
                printf("coup interdit\n");
            }
        }

        else if (mvtp == 'h') {
            if (pionuti[0]-1 > 0) {
                pionuti[0] = pionuti[0]-2;
                fin = 0;
            }
            else {
                printf("coup interdit\n");
            }
        }

        else if (mvtp == 'b') {
            if (pionuti[0]+1 < N-1) {
                pionuti[0] = pionuti[0]+2;
                fin = 0;
            }
            else {
                printf("coup interdit\n");
            }
        }


        else {
            printf("coup non valide\n");
        }

    }while (fin != 0);
}

void mvt_droite(int tab[]) {
    if(tab[0] > 1) {
        tab[0] = tab[0] + 2;
    }
    else {
        printf("Cette action n'est pas possible");
    }
}
void mvt_gauche(int tab[]) {
    if(tab[0] < 17) {
        tab[0] = tab[0] + 2;
    }
    else {
        printf("Cette action n'est pas possible");
    }
}
void mvt_haut(int tab[]) {
    if(tab[1] > 1) {
        tab[0] = tab[0] + 2;
    }
    else {
        printf("Cette action n'est pas possible");
    }
}
void mvt_bas(int tab[]) {
    if(tab[1] < 17) {
        tab[0] = tab[0] + 2;
    }
    else {
        printf("Cette action n'est pas possible");
    }
}



