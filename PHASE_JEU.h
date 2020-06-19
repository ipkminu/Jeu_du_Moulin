/*
 * PHASE_JEU.h
 *
 *  Created on: 16 déc. 2019
 *      Author: razing
 */
/*Ensemble de fonctions permettant le déplacement des pions sur a grille entre deux joueurs humains
 * Attribution de scores
 * Gestion de moulins
 * Arrêt automatique du jeu, si les conditions d'arrêt sont vérifiées.
 */
#ifndef PHASE_JEU_H_
#define PHASE_JEU_H_

int position_libre(position *p,int ab,int or){
	//Retourne 1 si la position dont les coordonnées sont entrées en paramètre est libre
	int i;
	for(i=0;i<24;i++){
		if(p[i].x==ab && p[i].y==or){
			if(p[i].etat==0){
				return 1;
			}
			else {
				return 0;

			}
		}
	}
	return 0;
}
void Demouliner(pion *joueur,position *p,int x,int y,int player){
	/*Destruction d'un moulin en cas de déplacement d'un de ses éléments
	 * en décrémentant la variable moul des pions constituant le mouli
	 */
int i,j,k,l,c;
int a,b,d;

    printf("\nDemoulinage test start!!!!!!!!!!!!\n");
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
	if(x==i && (y==j || y==k || y==l)){

		if((POJ(joueur,i,j,player).stat+POJ(joueur,i,k,player).stat+POJ(joueur,i,l,player).stat)>=3){
			a=POJ(joueur,i,j,player).pos;
			b=POJ(joueur,i,k,player).pos;
			d=POJ(joueur,i,l,player).pos;
			if(joueur[a].Moul>0 && joueur[b].Moul>0 && joueur[d].Moul>0){

				joueur[a].Moul--;
				joueur[b].Moul--;
				joueur[d].Moul--;
			}
		}
	}
	if(y==i && (x==j || x==k || x==l)){

		if((POJ(joueur,j,i,player).stat+POJ(joueur,k,i,player).stat+POJ(joueur,l,i,player).stat)>=3){
			a=POJ(joueur,j,i,player).pos;
			b=POJ(joueur,k,i,player).pos;
			d=POJ(joueur,l,i,player).pos;
			if(joueur[a].Moul>0 && joueur[b].Moul>0 && joueur[d].Moul>0){

				joueur[a].Moul--;
				joueur[b].Moul--;
				joueur[d].Moul--;
			}
		}
	}



	}
}
/*void essai(position *p){
	//Fonction de test ayant servi à imprimer les positions libres sur un fichier afin de suivre les changements
	int x,y,i,j;
	FILE *f=fopen("essai","w");
	if(f!=NULL){
		for(i=1;i<8;i++){
				 for(j=1;j<8;j++){
					 x=i;y=j;
				     if(Position_est_Libre(p,x,y)==1){
				    	 fprintf(f,"\n(%i,%i) LIBRE",x,y);
				     }
				     else {fprintf(f,"\n\t\t\t\t\t\t(%i,%i)PasLIBRE",x,y);}
				 }
			 }
	}
	fclose(f);
}
*/
void move(pion *jeu,position *p,char *Carac_Position,int a,int b,int x,int y){
	/*Deplacemnt d'un pion de coordonnées (a,b), vers une position de coordonnées (x,y)*/
	int i,j;
	int player;
	int indpos1,indpos2,indpi;
	for(i=0;i<24;i++){
		if(p[i].x==a && p[i].y==b){indpos1=i;}
	}
	for(i=0;i<24;i++){
			if(p[i].x==x && p[i].y==y){indpos2=i;}
	}

	for(j=0;j<18;j++){
			if(jeu[j].x==a && jeu[j].y==b){indpi=j;}
	}
	if(jeu[indpi].type=='@')player=1;
	else player=2;
	Demouliner(jeu,p,a,b,player);

p[indpos1].etat=0;
p[indpos2].etat=1;

jeu[indpi].Moul=0;
jeu[indpi].x=x;
jeu[indpi].y=y;
Carac_Position[indpos2]=Carac_Position[indpos1];
Carac_Position[indpos1]='#';
}
void deplacer(pion *jeu,position *p,char *Carac_Position,int *score,int player){
	/*Procédure de déplacement d'un pion
	 * affichage des pions pouvant être déplacés
	 * Choix du pion à déplacer
	 * Validation de déplacement
	 */
	int i,x,y,state;
	int a,b,e,d;
	char c;
	printf("\n*****Joueur %i, vous pouvez déplacer les pions suivants:\n",player);
	if(player==1){
		for(i=0;i<9;i++){
			if(jeu[i].x>0){
				a=position_libre(p,jeu[i].x,(jeu[i].y+1));
				b=position_libre(p,jeu[i].x,(jeu[i].y-1));
				e=position_libre(p,(jeu[i].x+1),jeu[i].y);
				d=position_libre(p,(jeu[i].x-1),jeu[i].y);
				state=a+b+e+d;

				if(state>0){
					printf("(%d,%d)\t",jeu[i].x,jeu[i].y);
					if(i==3 || i==6){
					printf("\n");

					}
				}
			}
		}
	}
	else {
		for(i=9;i<18;i++){
					if(jeu[i].x>0){
						a=position_libre(p,jeu[i].x,(jeu[i].y)+1);
						b=position_libre(p,jeu[i].x,(jeu[i].y)-1);
						e=position_libre(p,(jeu[i].x)+1,jeu[i].y);
						d=position_libre(p,(jeu[i].x)-1,jeu[i].y);
						state=a+b+e+d;

						if(state>0){
							printf("(%d,%d)\t",jeu[i].x,jeu[i].y);
							if(i==3 || i==6){
							printf("\n");

							}
						}
					}
				}

	}
	int t=0;
while(t==0){
	printf("\n*****Entrez les coordonnées du pion à déplacer:");
	printf("\nLIGNE:");
	scanf("%i",&x);
	printf("\nCOLONNEE:");
	scanf("%i",&y);
	a=position_libre(p,x+1,y);
	b=position_libre(p,x-1,y);
	e=position_libre(p,x,y-1);
	d=position_libre(p,x,y+1);
	if(a==1)printf("entrez h pour deplacer vers le bas \n");
	if(b==1)printf("entrez b pour deplacer vers le haut\n");
	if(e==1)printf("entrez g pour deplacer vers la gauche  \n");
	if(d==1)printf("entrez d pour deplacer vers la droite \n");
	getchar();
	scanf("%c",&c);
	if(c=='g'){
		if(position_libre(p,x,y-1)==1){t=1;
		move(jeu,p,Carac_Position,x,y,x,y-1);
		}
		else {printf("\nVous ne pouvez pas deplacer sur cette position");}
	}
	else if(c=='d'){
		if(position_libre(p,x,y+1)==1){t=1;
			move(jeu,p,Carac_Position,x,y,x,y+1);
		}
		else {printf("\nVous ne pouvez pas deplacer sur cette position");}
	}
	else if(c=='b'){
		if(position_libre(p,x-1,y)==1){t=1;
			move(jeu,p,Carac_Position,x,y,x-1,y);
		}
		else {printf("\nVous ne pouvez pas deplacer sur cette position");}
	}
	else if(c=='h'){
		if(position_libre(p,x+1,y)==1){t=1;
			move(jeu,p,Carac_Position,x,y,x+1,y);
		}
		else {printf("\nVous ne pouvez pas deplacer sur cette position");}
	}
	else{
		printf("\n***Veuillez choisir une position valide***");
	}
	affichage(Carac_Position);
	moulin(jeu,p,Carac_Position,score,player);
}

}
int stop(pion *jeu,position *p){
	/*Fonction retournant 1 s'il faut arrêter le jeur en vérifiant les deux principales conditions d'arrêt
	 *
	 */
	int i=0,j=9;
	int c1=0,c2=0;
	int d1=0,d2=0;
	for(i=0;i<9;i++){

		if(jeu[i].x>0){c1++;}
		if(jeu[j].x>0){c2++;}
		j++;
	}
	if(c1<=2 || c2<=2){return 1;}
	for(i=0;i<9;i++){
				if(jeu[i].x>0){
					if(position_libre(p,jeu[i].x,jeu[i].y+1)==1 || position_libre(p,jeu[i].x,jeu[i].y-1)==1
						  ||position_libre(p,jeu[i].x+1,jeu[i].y)==1
							||position_libre(p,jeu[i].x-1,jeu[i].y)==1){
						d1=1;

						}
					}
				}
	for(i=9;i<18;i++){
						if(jeu[i].x>0){
							if(position_libre(p,jeu[i].x,jeu[i].y+1)==1 || position_libre(p,jeu[i].x,jeu[i].y-1)==1
								  || position_libre(p,jeu[i].x+1,jeu[i].y)==1
									|| position_libre(p,jeu[i].x-1,jeu[i].y)==1){
								d2=1;
							}
						}
					}
	if(d1==0 || d2==0){return 1; }
	return 0;
}

void JEU_H_H(pion *jeu,position *p,char *Carac_Position,int *score){
	/*Procédure complète de jeu entre deux joueurs humains
	 * Phase de placemnt
	 * Déplacements à tour de rôle
	 * Attribution de scores
	 * retraits de piions en cas de moulin
	 * arrêt du jeu, si conditions d'arrêt vérifiées
	 */
	int s=0;
	Placement(Carac_Position,jeu,p,score);

	while(s==0){
		if(stop(jeu,p)==0){
			affichage(Carac_Position);

		deplacer(jeu,p,Carac_Position,score,1);
		}
		else s=1;
		if(stop(jeu,p)==0){
			affichage(Carac_Position);

		deplacer(jeu,p,Carac_Position,score,2);
		}
		else s=1;
	}
	printf("\n*****Partie Terminée****");
	printf("\nScores:JOUEUR1:%i\tJOUEUR2:%i\n\n\n",score[0],score[1]);

}

#endif /* PHASE_JEU_H_ */
