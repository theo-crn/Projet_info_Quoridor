//
// Created by theop on 18/10/2024.
//
#include <stdio.h>
#include <string.h>
#include "sous_prog.h"

//menu de base du jeu
int menuprim(int *ch) {
    int fin = 0;
    do {
        printf("\t\tMENU PRINCIPAL\n");
        printf("Entrer 0 pour quitter \n");
        printf("Entrer 1 pour lancer le jeu \n");
        printf("Entrer 2 pour voir les scores \n");
        fflush(stdin);
        scanf("%d", &*ch);
        if (*ch == 0 || *ch == 1 || *ch == 2) {fin = 1;}
        if(*ch == 0) {return 0;}
        else if (*ch == 1 || *ch == 2){return 1;}
        else{printf("Entree invalide\n");}

    }while (fin !=1);
    return 0;
}
int quitter(int *ch) {
    char strch;
    printf("\t\tEntrer 'q' pour quitter, 'c' pour continuer la partie\n");
    fflush(stdin);
    scanf("%c", &strch);
    if (strch == 'q'){return 0;}
}

void choixact(int *ch) {
    int fin = 0;
    do {
        printf("Voulez-vous placer une barriere ou vous deplacer ?\n");
        printf("Pour placer une barriere taper : 1 \n");
        printf("Pour vous deplacer taper : 2 \n");
        fflush(stdin);
        scanf("%d", &*ch);
        if (*ch == 1 || *ch == 2){fin = 1;}
        else {printf("Entree invalide\n");}
    }while (fin != 1);
}

//création du plateau de jeu, utilisation de N car défini dans sous_prog.h
void plateau(char plate[N][N]) {
    int i,j;
    char murv = '|'; //mur vertical
    char murh = '-' ; //mur horizontal
    char murc = '+'; //coin
    char esp = ' '; //espace pour placer les pions

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++) {

            if (i == 0) { //coordonnées horizontales
                if(j==0 || j == 1 || j == N-1 || j%2 ==0) {
                    plate[i][j] = esp;
                } else {
                    plate[i][j] = 'a' + j/2 -1;
                }
            }

            else if (i == 1) { //bord horizontale haut
                for (j = 0; j < N; j++) {
                    if (j==0) {plate[i][j] = esp;}
                    else {
                        plate[i][j] = murh;
                    }
                }
            }

            else if (i == N-1) { //bord horizontale bas
                for (j = 0; j < N; j++) {
                    if (j==0) {plate[i][j] = esp;}
                    else {
                        plate[i][j] = murh;
                    }
                }
            }

            else if (j == 0 && i > 1) { //coordonnées verticales
                if (i%2 == 0) {
                    plate[i][j] = esp;
                }
                else {
                    plate[i][j] = 'A' + i/2 - 1;
                }
            }

            else if (i%2 != 0) //ligne murs horizontals
            {
                if (j==1 || j==N-1){plate[i][j] = murv;}
                else if (j%2!=0){plate[i][j] = murc;}
                else {plate[i][j] = murh;}
            }

            else if (i%2 == 0 && i != N-1) //ligne alternant espaces et murs verticals
            {
                if (j==1 || j==N-1){plate[i][j] = murv;}
                else if (j%2 == 0){plate[i][j] = esp;}
                else {plate[i][j] = murv;}
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
void affiche(char plate[N][N]) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", plate[i][j]);
        }
        printf("\n");
    }
}

//module pseudo
void crpseudo(char pseudo[nb_pseudo_max+1][longueur_pseudo_max], int *pnbj)
{
    int j;
    printf("combien il y a-t-il de joueurs?( 2 ou 4 )\n");
    fflush(stdin);
    scanf("%d",&j);

    //il ne peut y avoir que 2 ou 4 joueurs
    while ((j!=2)&&(j!=4)) {
        printf("il ne peut y avoir que 2 ou 4 joueurs, combien il y en t-il?");
        fflush(stdin);
        scanf("%d",&j);
    }
    *pnbj = j;

    int i;
    for (i = 0; i < j; i++)
    {
        printf("Entrer le pseudo du joueur %d, avec un maximum de %d caracteres\n", i + 1,longueur_pseudo_max);
        //utilisation de fgets qui lit et met un texte dans un tableau jusqu'au \n et ne lit jusqu'au n-1ieme terme
        //stdin comme un scanf, va avec le fgets
        fflush(stdin);
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

//cas si le pion joué arrive au même endroit qu'un pion présent (fct appelée seulement dans 'move')
void joueurmalp(int nbj, int pionuti[3],int pionpres1[3], int pionpres2[3], int pionpres3[3]) {
    char mvtp;
    if (nbj == 2){ //cas si le pion joué arrive au même endroit que le pion présent donc deux joueurs
            printf("Votre pion arrive sur le pion adverse.\n");
            printf("Vous pouvez passer par dessus le pion adverse.\n");
            printf("Choisissez dans quelle directions vous voulez aller :\n");
        do{
            printf("Si vous voulez deplacer le pion a droite, entrer 'd'\n");
            printf("Si vous voulez deplacer le pion a gauche, entrer 'g'\n");
            printf("Si vous voulez deplacer le pion vers le haut, entrer 'h'\n");
            printf("Si vous voulez deplacer le pion vers le bas, entrer 'b'\n");
            fflush(stdin);
            scanf("%c", &mvtp);

            //aller à droite
            if (mvtp == 'd') {
                if (pionuti[1]+1 < N) {
                    pionuti[1] = pionuti[1]+2;
                }
                else {
                    printf("coup interdit\n");
                }
            }
            //aller à gauche
            else if (mvtp == 'g') {
                if (pionuti[1]-1 > 0) {
                    pionuti[1] = pionuti[1]-2;
                }
                else {
                    printf("coup interdit\n");
                }
            }
            //aller en haut
            else if (mvtp == 'h') {
                if (pionuti[0]-1 > 1) {
                    pionuti[0] = pionuti[0]-2;
                }
                else {
                    printf("coup interdit\n");
                }
            }
            //aller en bas
            else if (mvtp == 'b') {
                if (pionuti[0]+1 < N) {
                    pionuti[0] = pionuti[0]+2;
                }
                else {
                    printf("coup interdit\n");
                }
            }


            else {
                printf("coup non valide\n");
            }

        }while (pionuti[0] == pionpres1[0] && pionuti[1] == pionpres1[1]);
    }

    else if (nbj == 4) {//cas si le pion joué arrive au même endroit qu'un pion présent donc quatre joueurs
            printf("Votre pion arrive sur un pion adverse.\n");
            printf("Vous pouvez passer par dessus le pion adverse.\n");
            printf("Choisissez dans quelle directions vous voulez aller :\n");
        do{
            printf("Si vous voulez deplacer le pion a droite, entrer 'd'\n");
            printf("Si vous voulez deplacer le pion a gauche, entrer 'g'\n");
            printf("Si vous voulez deplacer le pion vers le haut, entrer 'h'\n");
            printf("Si vous voulez deplacer le pion vers le bas, entrer 'b'\n");
            fflush(stdin);
            scanf("%c", &mvtp);

            //aller à droite
            if (mvtp == 'd') {
                if (pionuti[1]+1 < N) {
                    pionuti[1] = pionuti[1]+2;
                }
                else {
                    printf("coup interdit\n");
                }
            }
            //aller à gauche
            else if (mvtp == 'g') {
                if (pionuti[1]-1 > 0) {
                    pionuti[1] = pionuti[1]-2;
                }
                else {
                    printf("coup interdit\n");
                }
            }
            //aller en haut
            else if (mvtp == 'h') {
                if (pionuti[0]-1 > 1) {
                    pionuti[0] = pionuti[0]-2;
                }
                else {
                    printf("coup interdit\n");
                }
            }
            //aller en bas
            else if (mvtp == 'b') {
                if (pionuti[0]+1 < N) {
                    pionuti[0] = pionuti[0]+2;
                }
                else {
                    printf("coup interdit\n");
                }
            }


            else {
                printf("coup non valide\n");
            }

        }while((pionuti[0] == pionpres1[0] && pionuti[1] == pionpres1[1]) || (pionuti[0] == pionpres2[0] && pionuti[1] == pionpres2[1]) || (pionuti[0] == pionpres3[0] && pionuti[1] == pionpres3[1]));
    }
}
//module déplacement
void move(int nbj, int pionuti[3],int pionpres1[3], int pionpres2[3], int pionpres3[3]){// premier argument = pion à bouger ; deuxieme argument = info du pion présent sur le jeu
    int fin = 1;
    int uti = 1;
    if (pionuti[2] == 102){uti = 2;}
    else if (pionuti[2] == 103){uti = 3;}
    else if (pionuti[2] == 104){uti = 4;}
    char mvtp;

    //toutes les possibilités du joueurs
    do {
        printf("Au tour du joueur %d \n",uti);
        printf("Si vous voulez deplacer le pion a droite, entrer 'd'\n");
        printf("Si vous voulez deplacer le pion a gauche, entrer 'g'\n");
        printf("Si vous voulez deplacer le pion vers le haut, entrer 'h'\n");
        printf("Si vous voulez deplacer le pion vers le bas, entrer 'b'\n");
        fflush(stdin);
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
    }while (fin != 0);//fin du déplacement du joueur

    if(nbj == 2) {
        if((pionuti[0] == pionpres1[0] && pionuti[1] == pionpres1[1])) {
            joueurmalp(nbj, pionuti[3], pionpres1[3], pionpres2[3], pionpres3[3]);
        }
    }
    if (nbj == 4) {
        if ((pionuti[0] == pionpres1[0] && pionuti[1] == pionpres1[1]) || (pionuti[0] == pionpres2[0] && pionuti[1] == pionpres2[1]) || (pionuti[0] == pionpres3[0] && pionuti[1] == pionpres3[1])) {
            joueurmalp(nbj, pionuti[3], pionpres1[3], pionpres2[3], pionpres3[3]);
        }
    }
}
void barrieres(){}





