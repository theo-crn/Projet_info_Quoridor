//
// Created by Gabriel on 31/10/2024.
//
#include <stdio.h>
#include "pseudo.h"

void pseudo (char pseudo [][longueur_pseduo_max], int nombre_joueurs_max)
{
    int i;
    for (i = 0; i < nombre_joueurs_max; i++)
    {
        printf ("entrer le pseudo d'un joueur%d:", i++);
        scanf ("%s", pseudo[i]);
    }
    printf ("^les pseudos enregistreés sont:");
    for (i = 0; i < nombre_joueurs_max; i++)
    {
        printf ("joueurs %d: %s/n",i++,pseudo[i]);
    }
}