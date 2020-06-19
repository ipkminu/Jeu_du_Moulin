/*
 * IA.H
 *
 *  Created on: 17 janv. 2020
 *      Author: razing
 */
/*Librairie Jeu entre un humain et la machine (Niveau avancé)
 * Le pricipe est de modéliser toutes les possibilités dans un arbre, et de noter chaque possibilité en fonction de plusieurs paramètres
 * avantageux
 * Choisir à la fin le couple ou l'élément le mieux noté
 * NB:A cette étape , la machine est toujours le joueur 2
 * Le joueur 1 commence toujours le jeu
 */

#ifndef IA_H_
#define IA_H_

typedef  struct Arb{
	/*Structure permettant de stocker des informations d'un à deux pions
	 * et une note attribuée à l'ensemble
	 */
	int ligne;
	int colonne;
	int Ligne;
	int Colonne;
	int note;
}arbre;

int occupe_par(position *p,char *Carac_Position,int ab,int or,int player){
	/*retourne un si la position de coordonnées (ab,or) est occupée par le joueur 'player'
	 *
	 */
	int i;
	if(player==1){
		for(i=0;i<24;i++){
				if(p[i].x==ab && p[i].y==or){
					if(Carac_Position[i]=='@'){
						return 1;
					}
				}
			}
	}
	else{
		for(i=0;i<24;i++){
				if(p[i].x==ab && p[i].y==or){
					if(Carac_Position[i]=='X'){
						return 1;
					}
				}
			}
	}
	return 0;
}
int create_arbre_placement(arbre A[],pion *jeu,position *p,char *Carac_position){
	//Remplit le tableau A de toutes les positions libres de la grille et retourne le nombre d'éléments stockées
	int i,j=0;
	int ab,or;
	for(i=0;i<24;i++){
		printf("p[%d].etat=%d",i,p[i].etat);
		if(p[i].etat==0){
			ab=p[i].x;
			or=p[i].y;
			A[j].ligne=ab;
			A[j].colonne=or;
			j++;
		}
		else printf("\nAucune postion libre ");

	}

	return j;
}

void notation_arbre_placement(arbre *A,position *p,char * Carac_Position,int taille){
	/*Notation de chaque élément de l'arbre A, en tenant compte des avantage de placer un pion à cette position
	 *
	 */
	int i,ab,or;
	for(i=0;i<taille;i++){
		ab=A[i].ligne;
		or=A[i].colonne;
		//si a positionest dans une branche occupée par deux autres pions du jouer, faisant donc un moulin si on y place un pion
		if(occupe_par(p,Carac_Position,ab,or-1,2)==1 && occupe_par(p,Carac_Position,ab,or+1,2)==1){A[i].note=4;continue;}
		if(occupe_par(p,Carac_Position,ab,or-1,2)==1 && occupe_par(p,Carac_Position,ab,or-2,2)==1){A[i].note=4;continue;}
		if(occupe_par(p,Carac_Position,ab,or+1,2)==1 && occupe_par(p,Carac_Position,ab,or+2,2)==1){A[i].note=4;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,2)==1 && occupe_par(p,Carac_Position,ab+1,or,2)==1){A[i].note=4;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,2)==1 && occupe_par(p,Carac_Position,ab-2,or,2)==1){A[i].note=4;continue;}
		if(occupe_par(p,Carac_Position,ab+1,or,2)==1 && occupe_par(p,Carac_Position,ab+2,or,2)==1){A[i].note=4;continue;}

		//Si la position appartient à une branche où se trouvent deux pions adverses, empechant l'adversaire de faire un moulin s on y place un pion
		if(occupe_par(p,Carac_Position,ab,or-1,1)==1 && occupe_par(p,Carac_Position,ab,or+1,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab,or-1,1)==1 && occupe_par(p,Carac_Position,ab,or-2,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab,or+1,1)==1 && occupe_par(p,Carac_Position,ab,or+2,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,1)==1 && occupe_par(p,Carac_Position,ab+1,or,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,1)==1 && occupe_par(p,Carac_Position,ab-2,or,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab+1,or,1)==1 && occupe_par(p,Carac_Position,ab+2,or,1)==1){A[i].note=3;continue;}

		//Il existe sur la branche un pion du joueur. Y ajouter un pion permet d'en aligner deux et se rapprocher du moulin
		if(occupe_par(p,Carac_Position,ab,or-1,2)==1 || occupe_par(p,Carac_Position,ab,or+1,2)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,ab,or-1,2)==1 || occupe_par(p,Carac_Position,ab,or-2,2)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,ab,or+1,2)==1 || occupe_par(p,Carac_Position,ab,or+2,2)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,2)==1 || occupe_par(p,Carac_Position,ab+1,or,2)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,2)==1 || occupe_par(p,Carac_Position,ab-2,or,2)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,ab+1,or,2)==1 || occupe_par(p,Carac_Position,ab+2,or,2)==1){A[i].note=2;continue;}

		//Il existe sur la branche un pion du joueur adverse. Y placer un pion empêche l'adversaire d'avir un moulin sur cette branche
		if(occupe_par(p,Carac_Position,ab,or-1,1)==1 || occupe_par(p,Carac_Position,ab,or+1,1)==1){A[i].note=1;continue;}
		if(occupe_par(p,Carac_Position,ab,or-1,1)==1 || occupe_par(p,Carac_Position,ab,or-2,1)==1){A[i].note=1;continue;}
		if(occupe_par(p,Carac_Position,ab,or+1,1)==1 || occupe_par(p,Carac_Position,ab,or+2,1)==1){A[i].note=1;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,1)==1 || occupe_par(p,Carac_Position,ab+1,or,1)==1){A[i].note=1;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,1)==1 || occupe_par(p,Carac_Position,ab-2,or,1)==1){A[i].note=1;continue;}
		if(occupe_par(p,Carac_Position,ab+1,or,1)==1 || occupe_par(p,Carac_Position,ab+2,or,1)==1){A[i].note=1;continue;}

		else{A[i].note=0;}
	}


}
int choose(arbre *A,int taille){
	//Choix de la première position la mieux notée dans le tableau A de taille 'taille'
	int i,max=0,indice;
	for(i=0;i<taille;i++){
		if(max<A[i].note){
			max=A[i].note;
			indice=i;
		}
	}
	return indice;
}

int create_arbre_retrait(arbre *A,pion *jeu,position *p,char *Carac_Position){
	//Création d'un tableau contenant l'ensemble des pion de l'adversaire que l'on retirer du jeu
	int i,j=0;
	for(i=0;i<9;i++){
		if(jeu[i].x>0 && jeu[i].Moul==0){
			A[j].ligne=jeu[i].x;
			A[j].colonne=jeu[i].y;
			j++;
		}

	}
	return j;
}

void notation_arbre_retrait(arbre *A,position *p,char *Carac_Position,int taille){
	//Notation des éléments de l'arbre , en tenant des avantages que le joueur aura les retirer du jeu
	int i,ab,or;
	for(i=0;i<taille;i++){
		ab=A[i].ligne;
		or=A[i].colonne;
		//Le pion en question n'est pas seul sur la branche
		if(occupe_par(p,Carac_Position,ab,or-1,1)==1 || occupe_par(p,Carac_Position,ab+1,or,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab,or-1,1)==1 || occupe_par(p,Carac_Position,ab,or-2,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab,or+1,1)==1 || occupe_par(p,Carac_Position,ab,or+2,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,1)==1 || occupe_par(p,Carac_Position,ab+1,or,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab-1,or,1)==1 || occupe_par(p,Carac_Position,ab-2,or,1)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,ab+1,or,1)==1 || occupe_par(p,Carac_Position,ab+2,or,1)==1){A[i].note=3;continue;}
		//Cas quelconque
		else{A[i].note=0;}

	}

}
void retirer_Machine2(pion *jeu,char *Carac_Position,position *p,int i){
	//Fonction permettant à la machine de retirer du jeu le pion le mieux noté de son adversaire
	int ab,or,j,ind,taille;
	int n=0;
	int c=0;
	char o;
	arbre A[18];
	if(i==2){
		printf("Vous pouvez retirer un de ces pions de votre adversaire\n");
		for(j=9;j<18;j++){
			if(jeu[j].Moul==0 && jeu[j].x>0){
				c++;
				printf("(%i,%i)\t",jeu[j].x,jeu[j].y);
			}
		}

		if(c==0){printf("\n*******Il n'y a aucun pion que vous pouvez retirer*****");
		scanf("%c",&o);

		}
		else{
			while(n==0){
				printf("\nEntrez les coordonnées du pion à enlever du jeu:\nLIGNE:");
				scanf("%d",&ab);
				printf("\nCOLONNE:");
				scanf("%d",&or);
				for(j=9;j<18;j++){
					if(jeu[j].x==ab && jeu[j].y==or && jeu[j].Moul==0){n=1;
						jeu[j].x=-1;
						jeu[j].y=-1;
					}
				}

			}
		}
	}
	if(i==1){
			taille=create_arbre_retrait(A,jeu,p,Carac_Position); //Création de l'arbre
			if(taille==0){printf("\n*******Il n'y a aucun pion à retirer pour Machine*****");

					}
			else{
					notation_arbre_retrait(A,p,Carac_Position,taille); //Notation de séléments de l'arbre
					ind=choose(A,taille); //Choix d'un des éléments les mieux notés
					ab=A[ind].ligne;
					or=A[ind].colonne;
					//RETRAIT
					for(j=0;j<9;j++){
						if(jeu[j].x==ab && jeu[j].y==or && jeu[j].Moul==0){n=1;
							jeu[j].x=-1;
							jeu[j].y=-1;
						}
					}
					printf("\nMachine a retiré un pion sur la position (%i,%i)\n",ab,or);
			}
	}

	for(j=0;j<24;j++){
		if((p[j].x==ab) && (p[j].y==or)){
			p[j].etat=0;
			Carac_Position[j]='#';
		}

	}

}
void moulin_Machine2(pion *joueur,position *p,char *Carac_position,int *score,int player){
	//Fonction Moulin, incluant le retrait intélligeant de pion par la machine en cas de moulin
int i,j,k,l,c;
int a,b,d;

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
			if(joueur[a].Moul+joueur[b].Moul+joueur[d].Moul<3){

				joueur[a].Moul++;
				joueur[b].Moul++;
				joueur[d].Moul++;
				if(player==1){
					score[player-1]+=1;
					printf("*****Congratulation!!!!\n*****Vous avez un Moulin\n");
					printf("Vous obtenez un point.\nVotre nouveau score est de %i\n",score[player-1]);
					retirer_Machine2(joueur,Carac_position,p,2);
				}
				if(player==2){
					score[player-1]+=1;
					printf("*****Machine a un Moulin*****\n");
					printf("Machine gagne un point.\nnouveau score pour Machine est de %i\n",score[player-1]);
					retirer_Machine2(joueur,Carac_position,p,1);
				}
				getchar();
			}
		}

		else if((POJ(joueur,j,i,player).stat+POJ(joueur,k,i,player).stat+POJ(joueur,l,i,player).stat)==3){
			a=POJ(joueur,j,i,player).pos;
			b=POJ(joueur,k,i,player).pos;
			d=POJ(joueur,l,i,player).pos;
			if(joueur[a].Moul+joueur[b].Moul+joueur[d].Moul<3){

				joueur[a].Moul++;
				joueur[b].Moul++;
				joueur[d].Moul++;
				if(player==1){
					score[player-1]+=1;
					printf("*****Congratulation!!!!\n*****Vous avez un Moulin\n");
					printf("Vous obtenez un point.\nVotre nouveau score est de %i\n",score[player-1]);
					retirer_Machine2(joueur,Carac_position,p,2);
				}
				if(player==2){
					score[player-1]+=1;
					printf("*****Machine a un Moulin*****\n");
					printf("Machine gagne un point.\nnouveau score pour Machine est de %i\n",score[player-1]);
					retirer_Machine2(joueur,Carac_position,p,1);
				}
				getchar();
			}
		}
	}


}
niveau choix_placement(pion *jeu,position *p,char *Carac_Position){
	//FOnction non utilisée pour le moment
	arbre A[24];
	niveau N;
	int taille,ind;
 	taille=create_arbre_placement(A,jeu,p,Carac_Position);
 	notation_arbre_placement(A,p,Carac_Position,taille);
 	ind=choose(A,taille);
	N.pos=A[ind].ligne;
	N.stat=A[ind].colonne;
	return N;
}
void Placement_Machine2(char *Carac_Position,pion *jeu,position *p,int *score){
	//Procédure de placemt Humain Vs Machine, avec la fonction le choix intelligent de la position où placer par la machine
	int n,i,j,k,ab,or,ind,taille;
	arbre A[24];
    i=0;
	j=9;
	n=0;
	affichage(Carac_Position);
    for(i=0;i<9;i++){
	n=0;
	printf("\n\n****JOUEUR1:*****\n");
	affiche_Pions_Libres(jeu,1);
	affiche_Positions_Libres(p);
	while(n==0){
	printf("\n**Entrez LIGNE:\n\n");
	scanf("%d",&ab);

	printf("**\nEntrez COLONNE:\n\n");
	scanf("%d",&or);

	printf("\nab=%i   or=%i",ab,or);//Placement marche
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

	affichage(Carac_Position);
	moulin(jeu,p,Carac_Position,score,1);
	getchar();


	printf("\n****MACHINE:*****\n");
	 	taille=create_arbre_placement(A,jeu,p,Carac_Position);
	 	notation_arbre_placement(A,p,Carac_Position,taille);
	 	ind=choose(A,taille);
		printf("\nPosition choisie (%i,%i)",A[ind].ligne,A[ind].colonne);
		ab=A[ind].ligne;
		or=A[ind].colonne;
		jeu[j].x=ab;
		jeu[j].y=or;
		for(k=0;k<24;k++){
			if(p[k].x==ab && p[k].y==or){
				p[k].etat=1;
				Carac_Position[k]='X';
			}
		}
	affichage(Carac_Position);
	moulin(jeu,p,Carac_Position,score,2);
	getchar();
	j++;

	}

}

int create_arbre_move(arbre *A,pion *jeu,position *p,char *Carac_Position){
	//Création d'un arbre, regroupant chaque pion déplaçable et toutes les positions possibles où il peut être placé
	int i,j=0,x,y;
	for(i=0;i<24;i++){
		x=p[i].x;
		y=p[i].y;
		if(Carac_Position[i]=='X'){
			//Position de gauche
			if(position_libre(p,x,y-1)==0){
				A[j].ligne=x;
				A[j].colonne=y;
				A[j].Ligne=x;
				A[j].Colonne=y-1;
				j++;
			}
			//Position de droite
			if(position_libre(p,x,y+1)==0){
				A[j].ligne=x;
				A[j].colonne=y;
				A[j].Ligne=x;
				A[j].Colonne=y+1;
				j++;
			}
			//Position de bas
			if(position_libre(p,x-1,y)==0){
				A[j].ligne=x;
				A[j].colonne=y;
				A[j].Ligne=x-1;
				A[j].Colonne=y;
				j++;
			}
			//Position de haut
			if(position_libre(p,x+1,y)==0){
				A[j].ligne=x;
				A[j].colonne=y;
				A[j].Ligne=x+1;
				A[j].Colonne=y;
				j++;
			}
		}


	}



	return j;
}

void notation_arbre_move(arbre *A,position *p,char *Carac_Position,int taille){
	//Notation des couples de l'arbre de déplacement
	int i,x,y;
	for(i=0;i<taille;i++){
		x=A[i].Ligne;
		y=A[i].Colonne;
		//Moulin si le pion est placé à cette position
		if(occupe_par(p,Carac_Position,x,y-1,2)==1 && occupe_par(p,Carac_Position,x,y+1,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x,y-1,2)==1 && occupe_par(p,Carac_Position,x,y-2,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x,y+1,2)==1 && occupe_par(p,Carac_Position,x,y+2,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x-1,y,2)==1 && occupe_par(p,Carac_Position,x+1,y,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x-1,y,2)==1 && occupe_par(p,Carac_Position,x-2,y,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x+1,y,2)==1 && occupe_par(p,Carac_Position,x+2,y,2)==1){A[i].note=3;continue;}
		//Empêche l'adversaire de faire un moulin sur une branche où il a déjà deux pions
		if(occupe_par(p,Carac_Position,x,y-1,1)==1 && occupe_par(p,Carac_Position,x,y+1,1)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,x,y-1,1)==1 && occupe_par(p,Carac_Position,x,y-2,1)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,x,y+1,1)==1 && occupe_par(p,Carac_Position,x,y+2,1)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,x-1,y,1)==1 && occupe_par(p,Carac_Position,x+1,y,1)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,x-1,y,1)==1 && occupe_par(p,Carac_Position,x-2,y,1)==1){A[i].note=2;continue;}
		if(occupe_par(p,Carac_Position,x+1,y,1)==1 && occupe_par(p,Carac_Position,x+2,y,1)==1){A[i].note=2;continue;}
		//Le déplacemnt va créer un alignement de deux pions pour Machine
		if(occupe_par(p,Carac_Position,x,y-1,2)==1 || occupe_par(p,Carac_Position,x,y+1,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x,y-1,2)==1 || occupe_par(p,Carac_Position,x,y-2,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x,y+1,2)==1 || occupe_par(p,Carac_Position,x,y+2,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x-1,y,2)==1 || occupe_par(p,Carac_Position,x+1,y,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x-1,y,2)==1 || occupe_par(p,Carac_Position,x-2,y,2)==1){A[i].note=3;continue;}
		if(occupe_par(p,Carac_Position,x+1,y,2)==1 || occupe_par(p,Carac_Position,x+2,y,2)==1){A[i].note=3;continue;}

		//Cas quelconques
		else{A[i].note=0;}


	}

}


void deplacer_Machine2(pion *jeu,position *p,char *Carac_Position,int *score){
	//Procédure déplacement par la Machine (Déplacment du pion vers la position dont l'ensemble est le mieux noté
	int ind,x,y,w,z,taille,player=2;
	arbre A[36];
	taille=create_arbre_move(A,jeu,p,Carac_Position);//Création de l'arbre
	notation_arbre_move(A,p,Carac_Position,taille);//Notation des couple (pion à déplacer-destination
	ind=choose(A,taille);//Choix d'un des couples les mieux notés
	x=A[ind].ligne;
	y=A[ind].colonne;
	w=A[ind].Ligne;
	z=A[ind].Colonne;
	move(jeu,p,Carac_Position,x,y,w,z);
	affichage(Carac_Position);
	moulin_Machine2(jeu,p,Carac_Position,score,player);
	getchar();

}

void jeu_H_M2(pion *jeu,position *p,char *Carac_Position,int *score){
	//Procédure de jeu Homme Machine Niveau avancé
	int s=0;
		Placement_Machine2(Carac_Position,jeu,p,score);

		while(s==0){

			if(stop(jeu,p)==0){
				affichage(Carac_Position);
			deplacer(jeu,p,Carac_Position,score,1);


			}
			else s=1;
			if(stop(jeu,p)==0){
				affichage(Carac_Position);
			deplacer_Machine2(jeu,p,Carac_Position,score);

			}
			else s=1;
		}
		printf("\n*****Partie Terminée****");
		printf("\nScores:JOUEUR1:%i\tMACHINE:%i\n\n\n",score[0],score[1]);



}



#endif /* IA_H_ */
