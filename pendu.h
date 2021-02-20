#ifndef PENDU_H
#define PENDU_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>
	#include "fonctions.c"

#define TAILLE_MAX 15

//Prototypes
char lireCaractere();
int motTrouver(char *, char *, int);
int perdu();
void multipleLettre(char *, int, short int *, char);
int nbLignes(FILE *);

#endif