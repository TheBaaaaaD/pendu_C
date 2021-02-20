#include "pendu.h"

int main(){

	short int ligneNB = 0;
	char cara;
	short int a = 0;
	int tempo;
	char motSecret[] = "MARRON";
	char lettreTrouve[6] = "";
	char lettre;
	short int test = 0;
	short int tenta = 10; short int *ptr_tenta = &tenta;
	char *tabTrouver = NULL;
	int nbLettres = 0;
	short int jouer = 0;
	short int continuer = 0;
	int ligneTot = 0;
	short int ligneChoisi = 0;

//activation du générateur de nombre "aléatoire"
	srand(time(NULL));

//ouverture fichier pour le mot	
		FILE* fichier = NULL;
		fichier =  fopen("dico.txt","r");//on ouvre le fichier dico en lecture simple

		if(fichier == NULL){//verifier ouverture fichier
			return(0);
		}
//choix du mot "aléatoire"
		ligneTot = nbLignes(fichier);//recupere le nb de ligne du fichier
		ligneChoisi = rand()%ligneTot;
		rewind(fichier);//on remontre au début du fichier

//mise en place du mot mystère
		do{
			cara = fgetc(fichier);
			if(cara == *"\n"){
				ligneNB++;
			}
		}while(ligneNB != ligneChoisi);
		while(fgetc(fichier)!= *"\n"){
			cara = fgetc(fichier);
			//fgets(motSecret,TAILLE_MAX,fichier); ERREUR A VOIR PK
		}
		printf("%s", motSecret);

//allocation du tableau de lettre trouver
		nbLettres = strlen(motSecret);
		tabTrouver = malloc(nbLettres * sizeof(char));

//fermeture du fichier
		fclose(fichier);

//programme pendu		
		if(tabTrouver == NULL){
			return(0);
		}
		else{
			for (int i = 0; i < nbLettres; ++i)
			{
				tabTrouver[i] = *"*";//préparation du tableau
				//printf("%c",tabTrouver[i]);
			}
			do{
				tenta = 10;//pour avoir 10 tentas quand on relances
				test = 0;//on reset la réussite !
				do{
					if(tenta == 0){//on teste si plus de tenta
						printf("Dommage vous avez perdu !\nVoullez vous rejouer ?\n1_Oui\n2_Non\n");
						scanf("%d",&jouer);
						if(jouer == 1){
							tenta = 10;//c'est repartie
						}
						if(jouer == 2){
							printf("A bientot !\n");
							free(tabTrouver);
							return (0);//arret du jeu
						}
						else if(jouer != 1 && jouer != 2){
							printf("T'es un enfant ! Au revoir !");
							free(tabTrouver);
							return(0);
						}
					}
					printf("Il vous reste %d tentatives !\n",tenta);
					lettre = lireCaractere();//demande la lettre
					for (int i = 0; i < nbLettres; ++i)
					{
						if(lettre == motSecret[i]){//on test si la lettre vaut une lettre du mot
							tabTrouver[i] = motSecret[i];//on stock le positionnement de la lettre
							multipleLettre(tabTrouver, nbLettres, ptr_tenta, lettre);
							tenta++;//si la lettre existe j'ajoute un pour ne pas perdre de coup avec le -1 en bas
						}
					}
					for (int i = 0; i < nbLettres; ++i)//affichage du mot global
					{
						printf("%c",tabTrouver[i]);
					}
					tenta--;
					printf("\n");
					test = motTrouver(motSecret, tabTrouver, nbLettres);
				}while(test != 1);//tant que les mots sont différents
				printf("Bravo vous avez terminer avec %d coups d'avance !\n",tenta);
				printf("Voullez vous continuer de jouer ? \n1_Oui\n2_Non\n");
				scanf("%d",&continuer);
			}while(continuer != 2);
			free(tabTrouver);
		}
}