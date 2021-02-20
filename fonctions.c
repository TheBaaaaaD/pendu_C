#include "pendu.h"

//Fonctions

char lireCaractere() //permet de lire un catactère sans avoir de problèmes avec scanf
{ 
    char caractere = 0;
 	
    printf("Veuillez saisir un caractere : ");

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}


int motTrouver(char tabMystere[], char tabTrouver[], int nbLettres){//permet de tester si les 2 mots sont identiques
	int sommeMystere = 0, sommeTrouver = 0;
	for (int i = 0; i < nbLettres; ++i)
	{
		sommeMystere = sommeMystere + tabMystere[i];//valeur total tableau mystère
		sommeTrouver = sommeTrouver + tabTrouver[i];//valeur total tableau trouver
	}
	if(sommeTrouver == sommeMystere){//si les 2 mots sont identiques alors 1
		return(1);
	}
	else{//sinon 0
		return(0);
	}
}

int perdu(){
		
}

void multipleLettre(char tabTrouver[],int nbLettres, short int *ptr_tenta, char lettre){//test s'il y a plusiers fois la lettre dans le mot
	int nbfois = 0;//nombre de fois ou on trouve la lettre
	for (int i = 0; i < nbLettres; ++i)
	{
		if(tabTrouver[i] == lettre){
			nbfois++;
		}
	}
	if(nbfois > 1){//si on à plusieurs fois la même lettre on retire une tenta pour pas qu'ils donne +2 a tenta mais juste +1
		*ptr_tenta = *ptr_tenta - (nbfois - 1);//tenta perd autant de points qu'il y a dans le mot -1 (pour qu'il ne perde pas de tenta mais qu'il n'en gagne pas non plus)
	}
}

int nbLignes(FILE * fichier){//compte le nombre de lignes d'un fichier
int nbLignes = 0;
char cara;
		do{
			cara = fgetc(fichier);
			if(cara == *"\n"){
				nbLignes++;
			}
		}while(cara != EOF);
	return nbLignes;
}