//
// Created by theop on 18/10/2024.
//

#ifndef SOUS_PROG_H
#define N 20 //taille du plateau
#define longueur_pseudo_max 20 //taille maximum des pseudos
#define nb_pseudo_max 4 //nombre de pseudo maximum

#define SOUS_PROG_H

//FONCTION MENU :
int menuprim(int *ch); //premier menu affiché, il ne sera utiliser qu'une fois par lancement
int quitter(int *ch); //menu utiliser à chaque tour de boucle du programme permettant de quitter le jeu
void choixact(int *ch); //menu pour que le joueur choisisse s'il veut poser une barrière ou se déplacer

//FONCTIONS SUR LE PLATEAU :
void plateau(char plate[N][N]);//fonction qui cree le plateau de jeu
void placement2(char plate[N][N],int piona[3], int pionb[3]);//fonction qui met a jour le plateau pour deux joueurs
void placement4(char plate[N][N],int piona[3], int pionb[3], int pionc[3], int piond[3]);//fonction qui met a jour le plateau pour quatre joueurs
void affiche(char plate[N][N]);//fonction qui affiche le plateau de jeu

//FONCTIONS REGLE ET SCORE :
void regle();//fonction qui affiche les regles du jeu

//FONCTIONS POUR LES PSEUDOS ET LE NOMBRE DE JOUEURS :
void crpseudo(char pseudo[nb_pseudo_max+1][longueur_pseudo_max],int *pnbj);//fonction qui demande et enregistre les pseudos des joueurs

//FONCTIONS POUR JOUER :
void joueurmalp(int nbj, int pionuti[3],int pionpres1[3], int pionpres2[3], int pionpres3[3]);//cas si le pion joué arrive au même endroit qu'un pion présent (fct appelée seulement dans 'move')
void move(int nbj, int pionuti[3],int pionpres1[3], int pionpres2[3], int pionpres3[3]);//fonction qui affiche les actions du pion, contient lenb de joueurs et leur positions à tous
void barrieres(int nbj, int pionpres1[3],int pionpres2[3],int pionpres3[3],int pionpres4[3]);
#endif //SOUS_PROG_H
