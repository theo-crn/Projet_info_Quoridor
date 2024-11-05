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
void choixact(int *ch) {

    printf("Voulez-vous placer une barriere ou vous deplacer ?\n");
    printf("Pour placer une barriere taper : 1 \n");
    printf("Pour vous deplacer taper : 2 \n");
    scanf("%d", &*ch);
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
                if(j==0 || j == 1 || j == N-1 || j%2 ==0) {
                    plat[i][j] = esp;
                } else {
                    plat[i][j] = 'a' + j/2 -1;
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
                if (i%2 == 0) {
                    plat[i][j] = esp;
                }
                else {
                    plat[i][j] = 'A' + i/2 - 1;
                }
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

//module de placement des joueurs
void placement2(char plate[N][N],int piona[3], int pionb[3]) {
    plate[piona[0]][piona[1]] = '1';
    plate[pionb[0]][pionb[1]] = '2';
}
void placement4(char plate[N][N],int piona[3], int pionb[3], int pionc[3], int piond[3]) {
    plate[piona[0]][piona[1]] = '1';
    plate[pionb[0]][pionb[1]] = '2';
    plate[pionc[0]][pionc[1]] = '3';
    plate[piond[0]][piond[1]] = '4';
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
void crpseudo(char pseudo[nb_pseudo_max+1][longueur_pseudo_max], int nbj)
{
    int j;
    printf("combien il y a-t-il de joueurs?( 2 ou 4 )\n");
    scanf("%d",&j);

    //il ne peut y avoir que 2 ou 4 joueurs
    while ((j!=2)&&(j!=4)) {
        printf("il ne peut y avoir que 2 ou 4 joueurs, combien il y en t-il?");
        scanf("%d",&j);
    }
    nbj = j;
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
//affichage des regles du jeu
void regle() {
    char regle;
    printf("Si vous voulez afficher les regles, entrer 'r'\n");
    scanf("%c", &regle);

    if(regle == 'r') {
        printf("        REGLE DU JEU DU QUORIDOR:\n -Le but du jeu: ammener son pion de l'autre cote du plateau de jeu\n -Le jeu se joue a 2 ou 4 joueurs,au debut de la partie, chaque joueur place son pion au centre de sa ligne de depart\n -Le plateau est un rectangle compose de 81 cases entre lesquels on peut placer des barrieres pour bloquer le passage\n -Il y a 20 barrieres(longues de 2 cases, verticale ou horizontale) au total dans chaque partie (10 par joueur s'il y a 2 joueurs et 5 s'il y a 4 joueurs)\n -Attention cependant la partie se termine si une ligne ou une colonne est completement bloquee par des barrieres\n -Chacun son tour les joueurs peuvent se deplacer,poser une barriere ou ne pas jouer et si deux pions sont en face,\n le pion peut sauter au dessus de l'autre et ratterrir une case derriere sauf s'il y a une barriere et dans ce cas \n le joueur choisit si son pion atterrit a droite ou a gauche de l'autre pion\n -Dans ce jeu qui allie stratageme et reflexion, qui saura trouver le bon chemin ?\n\n");
    }
}

//module déplacement
void action(int pionuti[3]) {
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
            if (uti!= 4){//s'il n'y a que 2 joeurs=> uti!= 2
                uti++;
            }
            else{
                uti = 1;
            }
        }

    }while (fin != 0); //la c'est infini, il faudrai mettre dès qu'un pion arrive de l'autre coté du plateau
}
void barrieres(){}





