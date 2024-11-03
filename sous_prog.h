//
// Created by theop on 18/10/2024.
//

#ifndef SOUS_PROG_H
#define N 20 //taille du plateau
#define longueur_pseudo_max 20 //taille maximum des pseudos
#define nb_pseudo_max 4 //nombre de pseudo maximum

#define SOUS_PROG_H

void menu1(int ch); //premier menu affiché, il ne sera utiliser qu'une fois par lancement
int quitter(); //menu utiliser à chaque tour de boucle du programme permettant de quitter le jeu

void plateau(char plate[N][N]);//fonction qui cree le plateau de jeu
void placement2(char plate[N][N],int piona[3], int pionb[3]);//fonction qui met a jour le plateau
void affiche(char plate[N][N]);//fonction qui affiche le plateau de jeu

void regle();//fonction qui affiche les regles du jeu

void crpseudo(char pseudo[nb_pseudo_max+1][longueur_pseudo_max],int nbj);//fonction qui demande et enregistre les pseudos des joueurs


void action(int pion[3]);//fonction qui affiche les actions possibles du pion

//différentes fonctions des mouvements du pion
void mvt_droite(int tab1[]);
void mvt_gauche(int tab1[]);
void mvt_haut(int tab1[]);
void mvt_bas(int tab1[]);


void barrieres();
#endif //SOUS_PROG_H
