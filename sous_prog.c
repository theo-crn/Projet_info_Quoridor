//
// Created by theop on 18/10/2024.
//
#include <stdio.h>
#include "sous_prog.h"
char plateau()
{
    int i,j;
    char murv = '|'; //mur vertical
    char murh = '-' ; //mur horizontal
    char murc = '+'; //coin
    char esp = ' '; //espace pour placer les pions
    char plat[N][N];
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
                else {plat[i][j] = murv;}
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", plat[i][j]);
        }
        printf("\n");
    }
    return plat[N][N];
}

