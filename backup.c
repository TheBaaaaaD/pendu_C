			do{
				printf("Il vous reste %d tentatives !\n",tenta);
				lettre = lireCaractere();//demande la lettre
				for (int i = 0; i < nbLettres; ++i)
				{
					if(lettre == motSecret[i]){//on test si la lettre vaut une lettre du mot
						tabTrouver[i] = motSecret[i];//on stock le positionnement de la lettre
						tenta++;//si la lettre existe j'ajoute un pour ne pas perdre de coup avec le -1 en bas
						printf("%c",tabTrouver[i]);
					}
					else{
						printf("*");
					}
				}
				tenta--;
				printf("\n");
				test = motTrouver(motSecret, tabTrouver, nbLettres);
			}while(test != 1);//tant que les mots sont différents