/*
 * ACCEUIL.h
 *
 *  Created on: 29 déc. 2019
 *      Author: razing
 */

#ifndef ACCEUIL_H_
#define ACCEUIL_H_


/*int controle(){
	char c;
	c=getchar();
	if(c=='q' || c=='Q'){
		printf("\n*******Message d'aurrevoir*******\n");
		exit(0);
	}
	else if(c=='r' || c=='R'){
		Acceuil();
	}
	return 0;
}*/
void play(){
	int score[2]={0,0};
	char Carac_Position[24]; //Tableau de caractères définissant le typê de pion à afficher sur la grille initialisé à '#'
	position p[24]; //Creation du tableau de 24 positions
	pion jeu[18]; //Tableau de structures definissant les 18 pions des joueurs
	Init_Carac(Carac_Position);
	init_pos(p);
	Init_Pions(jeu);
	srand(time(NULL));
	char c;
	int x;
	printf("Nombre de joueurs:");
	printf("Tapez M pour un joueur ou H pour deux joueurs");
	scanf("%c",&c);

	switch(c){
	case 'm':case'M':{
			printf("\nChoisissez un niveau: tapez 1 pour facile et 2 pour difficile");

			scanf("%i",&x);
			switch(x){
			case 1:JEU_H_M(jeu,p,Carac_Position,score);
				break;
			case 2:jeu_H_M2(jeu,p,Carac_Position,score);
				break;
			}
		}
		break;
	case 'h':case'H':JEU_H_H(jeu,p,Carac_Position,score);
		break;
	}
}
void help(){
	printf("\n• Le jeu se déroule en deux temps : la pose puis");
	printf("\nle mouvement.");
	printf("\n• Dans un premier temps, les joueurs posent à");
	printf("\ntour de rôle chacun de leurs pions sur un point");
	printf("\nvide (intersection) du plateau.");
	printf("\n• Lorsqu’il n’y a plus de pion à poser, les joueurs");
	printf("\ndéplacent leurs pions vers une intersection voi-");
	printf("\nsine libre en suivant un chemin prévu. L’objectif");
	printf("\nest de former des « moulins » ou files de trois");
	printf("\npions alignés. Lorsqu’un des joueurs a réussi à");
	printf("\nréaliser un moulin, il peut capturer un pion de");
	printf("\nson choix à l’adversaire, à la condition que ce");
	printf("\npion ne fasse pas déjà partie d’un moulin. Une");
	printf("\nfois sorti du jeu, un pion ne peut plus y rentrer.");
	printf("\n•Arrêt du jeu: Le jeu s'arrête lorqu'un joueur n'a ");
	printf("\nplus que deux pions sur la grille, ou qu'un joueur ");
	printf("\nne peut bouger aucun de ses pions.");
	printf("\n*****Tapez R pour retourner au menu*****");

	return;

}


void Acceuil(pion *jeu, position *p,int *score,char *Carac_Position){

	char v,c;
	int x,i=0;

	printf("\n");
	printf("\n __     _    _   __     _   ______    __        __   ______   __     _   ______  ");
	printf("\n|  \\   | |  | | |  \\   | | |  ____|  |  \\      /  | |  ____| |  \\   | | /  ____| ");
	printf("\n|   \\  | |  | | |   \\  | | | |       |   \\    /   | | |      |   \\  | | | |___   ");
	printf("\n| |\\ \\ | |  | | | |\\ \\ | | |  ----   | |\\ \\  / /| | |  ----  | |\\ \\ | | \\___  \\ ");
	printf("\n| | \\ \\| |  | | | | \\ \\| | |  ----   | | \\ \\/ / | | |  ----  | | \\ \\| |  _   | | ");
	printf("\n| |  \\   |  | | | |  \\   | | |____   | |  \\  /  | | | |____  | |  \\   | | |__| | ");
	printf("\n|_|   \\__|  |_| |_|   \\__| |______|  |_|   \\/   |_| |______| |_|   \\__| \\_____ / ");
	printf("\n");
	printf("\n             __        __   _______   ______     ______    _   ______          ");
	printf("\n            |  \\      /  | /  ___  \\ / ___  \\   / ___  \\  | | /  ____|         ");
	printf("\n            |   \\    /   | | |   | | | |   \\ |  | |   \\ | | | | |___           ");
	printf("\n            | |\\ \\  / /| | | |   | | | |___/ /  | |___/ / | | \\____  \\         ");
	printf("\n            | | \\ \\/ / | | | |   | | |  ___ \\   |  ___ \\  | |  _   | |         ");
	printf("\n            | |  \\  /  | | | |___| | | |   \\ \\  | |   \\ \\ | | | |__| |         ");
	printf("\n            |_|   \\/   |_| \\_______/ |_|    \\_| |_|    \\_||_| \\_____ /         ");

	while(i==0){
	printf("\n***************JEU DE STRATEGIE*****************");
	printf("\nEntrez H pour afficher l'aide");
	printf("\nEntrez P pour jouer,et Q pour quitter le jeu");
	scanf("%c",&v);
	getchar();
	switch(v){
	case'h':case'H':{help();}
	break;
	case'p':case'P':{
		printf("Nombre de joueurs:");
		printf("Tapez M pour un joueur ou H pour deux joueurs");
		scanf("%c",&c);
		switch(c){
		case 'm':case'M':{
				printf("\nChoisissez un niveau: tapez 1 pour facile et 2 pour difficile");
				scanf("%i",&x);
				switch(x){
				case 1:JEU_H_M(jeu,p,Carac_Position,score);
					break;
				case 2:jeu_H_M2(jeu,p,Carac_Position,score);
					break;
				}
			}
			break;
		case 'h':case'H':JEU_H_H(jeu,p,Carac_Position,score);
			break;


		}
	}
	break;
	case 'q':case'Q':exit(0);
	break;
	}

}
}


#endif /* ACCEUIL_H_ */

