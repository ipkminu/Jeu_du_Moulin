/*
 ============================================================================
 Name        : Projet_Eclipse.c
 Author      : PATRICK
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Phase_Placemet.h"
#include "PHASE_JEU.h"
#include "HEU_H_M1.h"
#include "IA.h"
#include "ACCEUIL.h"


int main(int argc,char *argv[]){
	int score[2]={0,0};
		char Carac_Position[24]; //Tableau de caractères définissant le typê de pion à afficher sur la grille initialisé à '#'
		position p[24]; //Creation du tableau de 24 positions
		pion jeu[18]; //Tableau de structures definissant les 18 pions des joueurs
		Init_Carac(Carac_Position);
		init_pos(p);
		Init_Pions(jeu);
		srand(time(NULL));
		//jeu_H_M2(jeu,p,Carac_Position,score);
		//JEU_H_M(jeu,p,Carac_Position,score);
		//JEU_H_H(jeu,p,Carac_Position,score);
		//Placement(Carac_Position,jeu,p,score);
		Acceuil(jeu, p,score,Carac_Position);
 return 0;
}
