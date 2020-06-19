/*
 * Phase_Placemet.h
 *
 *  Created on: 9 déc. 2019
 *      Author: razing
 */
/*Librairie regroupant toutes les fonctions, structures utilisées pour la phase de placement
 *
 */
#ifndef PHASE_PLACEMET_H_
#define PHASE_PLACEMET_H_

typedef struct Position{
	//STructure définissant chaque position par ses coordonées sur la grille, et sont= état (occupé ou pas)
		int etat;
		int x;
		int y;
}position;

typedef struct Pion{
//structure représentant un pion par ses coordonnées sur la grille, le joueur a qui il appartient (type), et s'il est dans un moulin ou pas
		char type;
		int Moul;
		int x;
		int y;
}pion;

typedef struct Niveau{
	//Structure spécifique utilisée dans la fonction moulin
	int stat;
	int pos;
}niveau;

char *color(char c){
	//Fonction de coloriage des pions sur la grille
	char *s;
	if(c=='@'){
	s="\033[31m@\033[m";
	return s;
	}
	else if(c=='X'){
	s="\033[32m@\033[m";
	return s;
	}
	else s="#";
	return s;
}
void Init_Carac(char Carac_Position[]){
	//Initialisation des caractères qui représenteront les pions sur la grille
	int i;
	for(i=0;i<24;i++){
		Carac_Position[i]='#';
	}
}
void init_pos(position *p){
	//Initialisation l'etat et les coordonnées de chaque position de la grille
	int i;
	for (i=0;i<24;i++){ p[i].etat=0;/*Aucune position n'est occupée*/}
	p[0].x=1; p[0].y=1;
	p[1].x=1; p[1].y=4;
	p[2].x=1; p[2].y=7;
	p[3].x=2; p[3].y=2;
	p[4].x=2; p[4].y=4;
	p[5].x=2; p[5].y=6;
	p[6].x=3; p[6].y=3;
	p[7].x=3; p[7].y=4;
	p[8].x=3; p[8].y=5;
	p[9].x=4; p[9].y=1;
	p[10].x=4 ;p[10].y=2;
	p[11].x=4 ;p[11].y=3;
	p[12].x=4 ;p[12].y=5;
	p[13].x=4 ;p[13].y=6;
	p[14].x=4 ;p[14].y=7;
	p[15].x=5; p[15].y=3;
	p[16].x=5; p[16].y=4;
	p[17].x=5; p[17].y=5;
	p[18].x=6; p[18].y=2;
	p[19].x=6; p[19].y=4;
	p[20].x=6; p[20].y=6;
	p[21].x=7; p[21].y=1;
	p[22].x=7; p[22].y=4;
	p[23].x=7; p[23].y=7;

}
void affichage(char *Carac_Position){
	//Affichage de la grille et des pions sur console
	 	 	printf("\n        %s-----------------------%s------------------------%s1",color(Carac_Position[0]),color(Carac_Position[1]),color(Carac_Position[2]));
		    printf("\n  	|                       |                        |");
		    printf("\n  	|                       |                        |");
		    printf("\n  	|                       |                        |");
		    printf("\n  	|       %s---------------%s----------------%s	 |2",color(Carac_Position[3]),color(Carac_Position[4]),color(Carac_Position[5]));
		    printf("\n  	|       |               |                |       |");
		    printf("\n  	|       |               |                |       |");
		    printf("\n  	|       |               |                |       |");
		    printf("\n  	|       |       %s-------%s--------%s       |       |3",color(Carac_Position[6]),color(Carac_Position[7]),color(Carac_Position[8]));
		    printf("\n  	|       |       |                |       |       |");
		    printf("\n  	|       |       |                |       |       |");
		    printf("\n  	|       |       |                |       |       |");
		    printf("\n  	|       |       |                |       |       |");
		    printf("\n  	%s-------%s-------%s                %s-------%s-------%s4",color(Carac_Position[9]),color(Carac_Position[10]),color(Carac_Position[11]),color(Carac_Position[12]),color(Carac_Position[13]),color(Carac_Position[14]));
		    printf("\n  	|       |       |                |       |       |");
		    printf("\n  	|       |       |                |       |       |");
		    printf("\n  	|       |       |                |       |       |");
		    printf("\n  	|       |       |                |       |       |");
		    printf("\n  	|       |       %s-------%s--------%s       |       |5",color(Carac_Position[15]),color(Carac_Position[16]),color(Carac_Position[17]));
		    printf("\n  	|       |               |                |       |");
		    printf("\n  	|       |               |                |       |");
		    printf("\n  	|       |               |                |       |");
		    printf("\n  	|       %s---------------%s----------------%s       |6",color(Carac_Position[18]),color(Carac_Position[19]),color(Carac_Position[20]));
		    printf("\n  	|                       |                        |");
		    printf("\n  	|                       |                        |");
		    printf("\n  	|                       |                        |");
		    printf("\n        %s-----------------------%s------------------------%s7",color(Carac_Position[21]),color(Carac_Position[22]),color(Carac_Position[23]));
		    printf("\n  	1       2       3       4        5       6       7\n");
	    }


void affichage_test(char *Carac_Position){
	    printf("\n  	%s ##################### %s ###################### %s 1",color(Carac_Position[0]),color(Carac_Position[1]),color(Carac_Position[2]));
	    printf("\n  	#                       #                        #");
	    printf("\n  	#                       #                        #");
	    printf("\n  	#                       #                        #");
	    printf("\n  	#       %s ############# %s ############## %s       # 2",color(Carac_Position[3]),color(Carac_Position[4]),color(Carac_Position[5]));
	    printf("\n  	#       #               #                #       #");
	    printf("\n  	#       #               #                #       #");
	    printf("\n  	#       #               #                #       #");
	    printf("\n  	#       #       %s ##### %s ###### %s       #       # 3",color(Carac_Position[6]),color(Carac_Position[7]),color(Carac_Position[8]));
	    printf("\n  	#       #       #                #       #       #");
	    printf("\n  	#       #       #                #       #       #");
	    printf("\n  	#       #       #                #       #       #");
	    printf("\n  	#       #       #                #       #       #");
	    printf("\n  	%s ##### %s ##### %s                %s ##### %s ##### %s 4",color(Carac_Position[9]),color(Carac_Position[10]),color(Carac_Position[11]),color(Carac_Position[12]),color(Carac_Position[13]),color(Carac_Position[14]));
	    printf("\n  	#       #       #                #       #       #");
	    printf("\n  	#       #       #                #       #       #");
	    printf("\n  	#       #       #                #       #       #");
	    printf("\n  	#       #       #                #       #       #");
	    printf("\n  	#       #       %s ##### %s ###### %s       #       # 5",color(Carac_Position[15]),color(Carac_Position[16]),color(Carac_Position[17]));
	    printf("\n  	#       #               #                #       #");
	    printf("\n  	#       #               #                #       #");
	    printf("\n  	#       #               #                #       #");
	    printf("\n  	#       %s ############# %s ############## %s       # 6",color(Carac_Position[18]),color(Carac_Position[19]),color(Carac_Position[20]));
	    printf("\n  	#                       #                        #");
	    printf("\n  	#                       #                        #");
	    printf("\n  	#                       #                        #");
	    printf("\n  	%s ##################### %s ###################### %s 7",color(Carac_Position[21]),color(Carac_Position[22]),color(Carac_Position[23]));
	    printf("\n  	1       2       3       4        5       6       7");
	    }
void Init_Pions(pion *jeu){
	//Initlaise les pions des joueurs
	int i;
	for(i=0;i<9;i++){
		jeu[i].type='@';
		jeu[i].x=0;
		jeu[i].y=0;
		jeu[i].Moul=0;
	}
	for(i=9;i<18;i++){
			jeu[i].type='X';
			jeu[i].x=0;
			jeu[i].y=0;
			jeu[i].Moul=0;
		}

}
void affiche_Pions_Libres(pion *jeu,int s){
	//Affichage de tous les pions libres pour un joueur donné
	int j,i;
	i=s;
	int count=0;
	if(i==1){
		for(j=0;j<9;j++){
			if(jeu[j].x==0 && jeu[j].y==0){count+=1;}
		}
	}
	if(i==2){
			for(j=9;j<18;j++){
				if(jeu[j].x==0 && jeu[j].y==0){count+=1;}
			}
		}

		printf("\n****JOUEUR %i: Il vous reste %i Pions à placer\n",i,count);
}
void affiche_Positions_Libres(position *p){
	//Affichage des positions libres sur la grille
	int i,count=0;
	for(i=0;i<24;i++){
		if(p[i].etat==0){count++;}
	}
	printf("\n***POSITIONS LIBRES:%i ****\n",count);
	for(i=0;i<24;i++){
			if(p[i].etat==0){
				printf("(%i,%i)\t",p[i].x,p[i].y);
				if(i==5 ||i==11 ||i==17 ){printf("\n");}
			}
		}

}
int Position_est_Libre(position *p,int ab,int or){
	//Fonction retournant 1 si une position dont les coordonnées ont été définies est libre
	int i;
	for(i=0;i<24;i++){
		if(p[i].x==ab && p[i].y==or){
			if(p[i].etat==0) {return 1;}
		}
	}
	return 0;
}
niveau POJ(pion *joueur,int ab, int or,int player){
	//Fonction déterminant si sur une position donnée , il existe un pion d'un certain joueur ,en retournant 1
	int j,i;
	niveau s,d;
	d.stat=0;
	d.pos=0;

	if(player==1){
		for(j=0;j<9;j++){
				if(joueur[j].x==ab && joueur[j].y==or ){
				s.pos=j;
				s.stat=1;
				return s;

			}
		}
	}
	else if(player==2){
		for(i=9;i<18;i++){
				if(joueur[i].x==ab && joueur[i].y==or ){
					s.pos=i;
					s.stat=1;
					return s;

			}
		}
	}
	return d;
}
void retirer(pion *jeu,char *Carac_position,position *p,int i){
	/*Procédure de retrait d'un pion de la grille
	 * Affichage des pions pouvant etre retirés
	 * Validation du retrait
	 */
	int ab,or,j;
	int n=0;
	int c=0;
	if(i==1){
		printf("Vous pouvez retirer un de ces pions de votre adversaire\n");
		for(j=0;j<9;j++){
			if(jeu[j].Moul==0 && jeu[j].x>0){
				c++;
				printf("(%d,%d)\t",jeu[j].x,jeu[j].y);
			}
		}

		if(c==0){printf("\n*******Il n'y a aucun pion que vous pouvez retirer*****");
		getchar();

		}
		else{
			while(n==0){
				printf("\nEntrez les coordonnées du pion à enlever du jeu:\nLIGNE:");
				scanf("%d",&ab);
				printf("\nCOLONNE:");
				scanf("%d",&or);
				for(j=0;j<9;j++){
					if(jeu[j].x==ab && jeu[j].y==or && jeu[j].Moul==0){
						n=1;
						jeu[j].x=-1;
						jeu[j].y=-1;
					}
				}

			}
		}
	}
	if(i==2){
			printf("Vous pouvez retirer un de ces pions de votre adversaire\n");
			for(j=9;j<18;j++){
				if(jeu[j].Moul==0 && jeu[j].x>0){
					c++;
					printf("(%i,%i)\t",jeu[j].x,jeu[j].y);
				}
			}
			if(c==0){printf("\n*******Il n'a aucun pion que vous pouvez retirer*****");
				getchar();
					}
			else{
				while(n==0){
					printf("\nEntrez les coordonnées du pion à enlever du jeu:\nLIGNE:");
					scanf("%i",&ab);
					printf("\nCOLONNE:");
					scanf("%i",&or);
					for(j=9;j<18;j++){
						if(jeu[j].x==ab && jeu[j].y==or && jeu[j].Moul==0){n=1;
							jeu[j].x=-1;
							jeu[j].y=-1;
						}
					}
				}
			}
	}

	for(j=0;j<24;j++){
		if(p[j].x==ab && p[j].y==or){
			p[j].etat=0;
			Carac_position[j]='#';
		}

	}

}
void moulin (pion *joueur,position *p,char *Carac_position,int *score,int player){
	/*Fonction parcourant tous les triplets de moulin possibles afin de decéler s'il exite un moulin nouvellement créé pour un joueur
	 * Gère l'attricution de score en cas de moulin
	 * Permet au joueur ayant obtenu un moulin de retirer un pion de son adversaire si cela est possible
	 */
int i,j,k,l,c;
int a,b,d;
niveau moul;
moul.stat=0;
    printf("\nmoulin test start!!!!!!!!!!!!\n");
	for(c=0;c<8;c++){
		switch(c){
			case 0: i=1;j=1;k=4;l=7; break;
			case 1: i=2;j=2;k=4;l=6; break;
			case 2: i=3;j=3;k=4;l=5; break;
			case 3: i=4;j=1;k=2;l=3; break;
			case 4: i=4;j=5;k=6;l=7; break;
			case 5: i=5;j=3;k=4;l=5; break;
			case 6: i=6;j=2;k=4;l=6; break;
			case 7: i=7;j=1;k=4;l=7; break;
			default :break;
			}

		if((POJ(joueur,i,j,player).stat+POJ(joueur,i,k,player).stat+POJ(joueur,i,l,player).stat)==3){
			a=POJ(joueur,i,j,player).pos;
			b=POJ(joueur,i,k,player).pos;
			d=POJ(joueur,i,l,player).pos;
			if((joueur[a].Moul+joueur[b].Moul+joueur[d].Moul)<3){
				moul.stat=i;
				joueur[a].Moul++;
				joueur[b].Moul++;
				joueur[d].Moul++;
			}
		}

		else if((POJ(joueur,j,i,player).stat+POJ(joueur,k,i,player).stat+POJ(joueur,l,i,player).stat)==3){
			a=POJ(joueur,j,i,player).pos;
			b=POJ(joueur,k,i,player).pos;
			d=POJ(joueur,l,i,player).pos;
			if((joueur[a].Moul+joueur[b].Moul+joueur[d].Moul)<3){
				moul.stat=i;
				joueur[a].Moul++;
				joueur[b].Moul++;
				joueur[d].Moul++;
			}
		}
	}
		if(moul.stat!=0){
			score[player-1]+=1;
			printf("*****Congratulation!!!!\n*****Vous avez un Moulin\n");
			printf("Vous obtenez un point.\nVotre nouveau score est de %i\n",score[player-1]);
			if(player==1){retirer(joueur,Carac_position,p,2);}
			if(player==2){retirer(joueur,Carac_position,p,1);}
			}


}

void Placement(char *Carac_Position,pion *jeu,position *p,int *score){
	/*Procédure de placement des pions sur la grille
	 * Le placement se faire à tour de rôle
	 * Affichage du nombre de pions restant a placer
	 * affichage des positions libres
	 * Validation du placement
	 * Test Moulin
	 */
	int n,i,j,k,ab,or;
    i=0;
	j=9;
	n=0;
for(i=0;i<9;i++){

	n=0;

	affichage(Carac_Position);
	printf("\n\n****JOUEUR1:*****\n");
	affiche_Pions_Libres(jeu,1);
	affiche_Positions_Libres(p);
	while(n==0){
	printf("\n**Entrez LIGNE:\n\n");
	scanf("%d",&ab);
	printf("**\nEntrez COLONNE:\n\n");
	scanf("%d",&or);
	n=Position_est_Libre(p,ab,or);
	if(n==0){printf("\n****Position Inexistante ou occupée.\n************RÉESSAYEZ!!!****");}
	}
	jeu[i].x=ab;
	jeu[i].y=or;
	for(k=0;k<24;k++){
		if(p[k].x==ab && p[k].y==or){
			p[k].etat=1;
			Carac_Position[k]='@';
		}
	}

	n=0;
	moulin(jeu,p,Carac_Position,score,1);
	affichage(Carac_Position);

	printf("\n****JOUEUR2:*****\n");

		affiche_Pions_Libres(jeu,2);
		affiche_Positions_Libres(p);
		while(n==0){
		printf("\n**Entrez LIGNE:\n");
		scanf("%d",&ab);
		printf("\n**Entrez COLONNE:\n");
		scanf("%d",&or);
		n=Position_est_Libre(p,ab,or);
		if(n==0){printf("\n****Position Inexistante ou occupée.\n************RÉESSAYEZ!!!****");}
		}
		jeu[j].x=ab;
		jeu[j].y=or;
		for(k=0;k<24;k++){
			if(p[k].x==ab && p[k].y==or){
				p[k].etat=1;
				Carac_Position[k]='X';
			}
		}

	moulin(jeu,p,Carac_Position,score,2);
	j++;
	}

}
#endif /* PHASE_PLACEMET_H_ */
