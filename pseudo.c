//
// Created by Gabriel on 31/10/2024.
//
#include <stdio.h>
#include "pseudo.h"

void pseudo(char pseudo[nb_pseudo_max][longueur_pseudo_max])
{
    int i;
    for (i = 0; i < nb_pseudo_max; i++)
    {
        printf("Entrer le pseudo du joueur %d:", i + 1);
        scanf("%s", pseudo[i]);
    }
    printf("Pseudos enregistrees: \n");
    for(i = 0; i < nb_pseudo_max; i++)
    {
        printf("joueurs %d: %s\n",i + 1,pseudo[i]);
    }
}