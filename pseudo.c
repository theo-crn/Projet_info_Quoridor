//
// Created by Gabriel on 31/10/2024.
//
#include <stdio.h>
#include <string.h>
#include "pseudo.h"

void pseudo (char pseudo[nb_pseudo_max+1][longueur_pseudo_max])
{
    int i;
    for (i = 0; i < nb_pseudo_max; i++)
    {
        printf("Entrer le pseudo du joueur %d, avec un maximum de %d caracteres", i + 1,longueur_pseudo_max);
        fgets(pseudo[i],longueur_pseudo_max+1,stdin);
        size_t t = strlen(pseudo[i]);
        if (t > 0 && pseudo[i][t - 1] == '\n') {
            pseudo[i][t - 1] = '\0';
        }

    }
}
