/*
 * HEU_H_M1.h
 *
 *  Created on: 1 janv. 2020
 *      Author: razing
 */
/*Librairie de jeu entre un joueur humain et la machine
 * Niveau facile (choix aléatoires)
 */

#ifndef HEU_H_M1_H_
#define HEU_H_M1_H_

void affiche_Pions_Libres_Machine(pion *jeu,int s){
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

		printf("\n****MACHINE: Encore %i Pions à placer\n",count);
}
int affiche_Positions_Libres_Machine(position *p,int *tab){
	int i;
	int count=0;
	for(i=0;i<24;i++){
		if(p[i].etat==0){
			tab[count]=i;
			count++;
		}
	}
	printf("\n***POSITIONS LIBRES:%i ****\n",count);
	return count;
}
int choose_pos(int *tab,int count){
    int c;

    c=rand()%count+0;
	return tab[c];
}
void retirer_Machine(pion *jeu,char *Carac_position,position *p,int i){
	int ab,or,j,ind;
	int tab[9];
	int n=0;
	int c=0;
	char o;
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
			for(j=0;j<9;j++){
				if(jeu[j].Moul==0 && jeu[j].x>0){
					tab[c]=j;
					c++;
				}
			}
			if(c==0){printf("\n*******Il n'y a aucun pion à retirer pour Machine*****");

					}
			else{

					ind=rand()%c+0;
					ab=jeu[tab[ind]].x;
					or=jeu[tab[ind]].y;

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
			Carac_position[j]='#';
		}

	}

}
void moulin_Machine(pion *joueur,position *p,char *Carac_position,int *score,int player){
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
			if(joueur[a].Moul+joueur[b].Moul+joueur[d].Moul<3){
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
			if(joueur[a].Moul+joueur[b].Moul+joueur[d].Moul<3){
				moul.stat=i;
				joueur[a].Moul++;
				joueur[b].Moul++;
				joueur[d].Moul++;
			}
		}
	}
		if(moul.stat!=0){

			if(player==1){
				score[player-1]+=1;
				printf("*****Congratulation!!!!\n*****Vous avez un Moulin\n");
				printf("Vous obtenez un point.\nVotre nouveau score est de %i\n",score[player-1]);
				retirer_Machine(joueur,Carac_position,p,2);
			}
			if(player==2){
				score[player-1]+=1;
				printf("*****Machine a un Moulin*****\n");
				printf("Machine gagne un point.\nnouveau score pour Machine est de %i\n",score[player-1]);
				retirer_Machine(joueur,Carac_position,p,1);}
			}


}

void Placement_Machine(char *Carac_Position,pion *jeu,position *p,int *score){
	int n,i,j,k,ab,or,ind,count=0;
	int *tab;
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
	getchar();
	affichage(Carac_Position);

	printf("\n****JOUEUR2:*****\n");
		tab=malloc(24*sizeof(int));
		affiche_Pions_Libres_Machine(jeu,2);
		count=affiche_Positions_Libres_Machine(p,tab);

		ind=choose_pos(tab,count);
		printf("\nPosition choisie (%i,%i)",p[ind].x,p[ind].y);
		ab=p[ind].x;
		or=p[ind].y;
		jeu[j].x=ab;
		jeu[j].y=or;
		for(k=0;k<24;k++){
			if(p[k].x==ab && p[k].y==or){
				p[k].etat=1;
				Carac_Position[k]='X';
			}
		}

	moulin_Machine(jeu,p,Carac_Position,score,2);
	getchar();
	j++;

	}

}

void deplacer_Machine(pion *jeu,position *p,char *Carac_Position,int *score,int player){
	int ind,i,x,y,count=0,tab[9],count2=0;
	int a,b,e,d;
	char tab2[4];
	char c;
	printf("\n*****Joueur %i, vous pouvez déplacer les pions suivants:\n",player);
	if(player==1){
		for(i=0;i<9;i++){
			if(jeu[i].x>0){
				a=position_libre(p,jeu[i].x,(jeu[i].y)+1);
				b=position_libre(p,jeu[i].x,(jeu[i].y)-1);
				e=position_libre(p,(jeu[i].x)+1,jeu[i].y);
				d=position_libre(p,(jeu[i].x)-1,jeu[i].y);
				if((a+b+e+d)>0){
					printf("(%i,%i)\t",jeu[i].x,jeu[i].y);
					if(i==3 || i==6){
					printf("\n");

					}
				}
			}
		}
	}

	else if(player==2){
		for(i=9;i<18;i++){
					if(jeu[i].x>0){
						a=position_libre(p,jeu[i].x,(jeu[i].y)+1);
						b=position_libre(p,jeu[i].x,(jeu[i].y)-1);
						e=position_libre(p,(jeu[i].x)+1,jeu[i].y);
						d=position_libre(p,(jeu[i].x)-1,jeu[i].y);
						if((a+b+e+d)>0){
							tab[count]=i;
							count++;

						}
					}
				}

	}
	int t=0;
while(t==0){

	ind=rand()%count+0;
	x=jeu[tab[ind]].x;
	y=jeu[tab[ind]].y;
	a=position_libre(p,x+1,y);
	b=position_libre(p,x-1,y);
	e=position_libre(p,x,y-1);
	d=position_libre(p,x,y+1);
	if(a==1){tab2[count2]='b'; count2++;}
	if(b==1){tab2[count2]='h'; count2++;}
	if(e==1){tab2[count2]='g'; count2++;}
	if(d==1){tab2[count2]='d'; count2++;}

	ind=rand()%count+0;
	c=tab2[ind];
	if(c=='g'){
		t=1;
		move(jeu,p,Carac_Position,x,y,x,y-1);
		printf("\nMachine a deplacé un pion de (%i,%i) vers (%i,%i)!\n",x,y,x,y-1);

	}
	else if(c=='d'){
			t=1;
			move(jeu,p,Carac_Position,x,y,x,y+1);
			printf("\nMachine a deplacé un pion de (%i,%i) vers (%i,%i)!\n",x,y,x,y+1);
	}
	else if(c=='b'){
			t=1;
			move(jeu,p,Carac_Position,x,y,x+1,y);
			printf("\nMachine a deplacé un pion de (%i,%i) vers (%i,%i)!\n",x,y,x+1,y);
	}
	else if(c=='h'){
			t=1;
			move(jeu,p,Carac_Position,x,y,x-1,y);
			printf("\nMachine a deplacé un pion de (%i,%i) vers (%i,%i)!\n",x,y,x-1,y);
	}


}
affichage(Carac_Position);
	moulin_Machine(jeu,p,Carac_Position,score,player);
	getchar();

}
void JEU_H_M(pion *jeu,position *p,char *Carac_Position,int *score){
	int s=0;
	Placement_Machine(Carac_Position,jeu,p,score);

	while(s==0){
		if(stop(jeu,p)==0){
			affichage(Carac_Position);
		deplacer(jeu,p,Carac_Position,score,1);


		}
		else s=1;
		if(stop(jeu,p)==0){
			affichage(Carac_Position);
		deplacer_Machine(jeu,p,Carac_Position,score,2);


		}
		else s=1;
	}
	printf("\n*****Partie Terminée****");
	printf("\nScores:JOUEUR1:%i\tMACHINE:%i\n\n\n",score[0],score[1]);

}

#endif /* HEU_H_M1_H_ */
