//
// Created by theop on 18/10/2024.
//
#include <stdio.h>
#include <string.h>
#include "sous_prog.h"
//menu de base du jeu
void menu1(int ch) {
    char strch;
    int fin = 0;
    do {
        printf("\t\tMENU PRINCIPAL\n");
        printf("\t\tEntrer 'q' pour quitter \n");
        printf("\t\tEntrer 'l' pour lancer le jeu \n");
        printf("\t\tEntrer 'v' pour voir les scores \n");
        scanf("%c", &strch);

        if (strch == 'q') {ch = 0; fin = 1;}
        else if (strch == 'l') {ch = 1; fin = 1;}
        else if (strch == 'v') {ch = 2; fin = 1;}

        else (printf("\t\tEntree invalide\n"));

    }while (fin !=1);
}
int quitter() {
    char strch;
    int fin = 1;
    printf("\t\tEntrer 'q' pour quitter, 'c' pour continuer la partie\n");
    scanf("%c", &strch);
    if (strch == 'q'){fin = 0;}
    return fin;
}
//création du plateau de jeu, utilisation de N car défini dans sous_prog.h
void plateau(char plat[N][N]) {
    int i,j;
    char murv = '|'; //mur vertical
    char murh = '-' ; //mur horizontal
    char murc = '+'; //coin
    char esp = ' '; //espace pour placer les pions

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++) {
            if (i == 0) {
                if(j==0 || j == 1 || j == 2 || j == N-1 || j == N-2) {
                    plat[i][j] = esp;
                } else {
                    plat[i][j] = 'a' + j - 3;
                }
            }

            else if (i == 1) {
                for (j = 0; j < N; j++) {
                    plat[i][j] = murh;
                }
            }

            else if (i == N-1) {
                for (j = 0; j < N; j++) {
                    plat[i][j] = murh;
                }
            }

            else if (j == 0 && i > 1) {
                plat[i][j] = 'A' + i - 2;
            }

            else if (i%2 != 0) //ligne murs horizontals
            {
                if (j==1 || j==N-1){plat[i][j] = murv;}
                else if (j%2==0){plat[i][j] = murc;}
                else {plat[i][j] = murh;}
            }

            else if (i%2 == 0 && i != N-1) //ligne alternant espaces et murs verticals
            {
                if (j==1 || j==N-1){plat[i][j] = murv;}
                else if (j%2 != 0){plat[i][j] = esp;}
                else {plat[i][j] = murv;}
            }
        }
    }
}
//module dé placement
void placement(char plate[N][N],int piona[3], int pionb[3]) {
    int i,j;
    plate[piona[0]][piona[1]] = '1';
    plate[pionb[0]][pionb[1]] = '2';
}
//module d'affichage
void affiche(char plat[N][N]) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", plat[i][j]);
        }
        printf("\n");
    }
}

//module pseudo
void pseudo (char pseudo[nb_pseudo_max+1][longueur_pseudo_max])
{
    int j;
    printf("combien il y a-t-il de joueurs?( 2 ou 4 )\n");
    scanf("%d",&j);
    //il ne peut y avoir que 2 ou 4 joueurs
    while ((j!=2)&&(j!=4)) {
        printf("il ne peut y avoir que 2 ou 4 joueurs, combien il y en t-il?");
        scanf("%d",&j);
    }

    int i;

    for (i = 0; i < j; i++)
    {
        printf("Entrer le pseudo du joueur %d, avec un maximum de %d caracteres\n", i + 1,longueur_pseudo_max);
        //utilisation de fgets qui lit et met un texte dans un tableau jusqu'au \n et ne lit jusqu'au n-1ieme terme
        //stdin comme un scanf, va avec le fgets
        fgets(pseudo[i],longueur_pseudo_max+1,stdin);
        //strlen calcul la longeur du pseudo et size_t calcul la longeur du pseudo et la met dans la variable t
        size_t t = strlen(pseudo[i]);
        //on enleve le \n et on met un \0 pour que ce soit la fin des caracteres du pseudo dans le tableau
        if (t > 0 && pseudo[i][t - 1] == '\n') {
            pseudo[i][t - 1] = '\0';
        }

    }
}

//module déplacer
void deplacer(int pionuti[3]) {
    int fin = 1;
    int uti = 1;
    char mvtp;
//toutes les possibilités du joueurs
    do {
        printf("Au tour du joueur %d \n",uti);
        printf("Si vous voulez deplacer le pion a droite, entrer 'd'\n");
        printf("Si vous voulez deplacer le pion a gauche, entrer 'g'\n");
        printf("Si vous voulez deplacer le pion vers le haut, entrer 'h'\n");
        printf("Si vous voulez deplacer le pion vers le bas, entrer 'b'\n");
        printf("si vous voulez mettre un mur, entrer 'm'\n");
        scanf("%c", &mvtp);

//aller à droite
        if (mvtp == 'd') {
            if (pionuti[1]+1 < N) {
                pionuti[1] = pionuti[1]+2;
                fin = 0;
            }
            else {
                printf("coup interdit\n");
            }
        }
//aller à gauche
        else if (mvtp == 'g') {
            if (pionuti[1]-1 > 0) {
                pionuti[1] = pionuti[1]-2;
                fin = 0;
            }
            else {
                printf("coup interdit\n");
            }
        }
//aller en haut
        else if (mvtp == 'h') {
            if (pionuti[0]-1 > 1) {
                pionuti[0] = pionuti[0]-2;
                fin = 0;
            }
            else {
                printf("coup interdit\n");
            }
        }
//aller en bas
        else if (mvtp == 'b') {
            if (pionuti[0]+1 < N) {
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
//changement de joueur
        if(fin == 0)
        {
            if (uti!=4){
                uti++;
            }
            else{
                uti = 1;
            }
        }

    }while (fin != 0); //la c'est infini, il faudrai mettre dès qu'un pion arrive de l'autre coté du plateau
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



