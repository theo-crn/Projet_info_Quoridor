//
// Created by theop on 18/10/2024.
//
#include <stdio.h>
#include "sous_prog.h"




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



