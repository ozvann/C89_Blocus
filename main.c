#include <graph.h>
#include <stdlib.h>


#include "menu.h"
#include "comportementJCJ.h"
#include "comportementJCIA.h"

int main (void){
	int victoire = 0, choix = 0, SourisX = 0, SourisY = 0;
	InitialiserGraphique();
	CreerFenetre(50, 50, 700, 500);		/* Initialise la fenetre puis lance le programme jeu.c qui lancera d'autre programme */
	while(1){				/* Boucle infinie pour le jeu la seul façons d'arreter le jeu hors de la croix de la fenetre est de cliquer sur quitter une fois une partie fini */
		choix = 0;
		SourisX = 0;
		SourisY = 0;
		EffacerEcran(CouleurParNom("white"));
		victoire = Jeu();		/* Lance le jeu pour la première fois */
		FermerGraphique();
		InitialiserGraphique();
		CreerFenetre(50, 50, 700, 500);
		while(choix == 0){
			ChoisirCouleurDessin(CouleurParNom("black"));
			DessinerRectangle(100, 100, 200, 50);
			EcrireTexte(120, 135, "Rejouer ?", 2);		/* Affiche les bouttons pour rejouer ou alors quitter */
			DessinerRectangle(400, 100, 200, 50);
			EcrireTexte(420, 135, "Quitter ?", 2);
			if(SourisCliquee()){
				SourisX = _X;
				SourisY = _Y;
			}
			if(SourisX <= 300 && SourisX >= 100 && SourisY <= 150 && SourisY >= 100){
				choix++;	/* Fonction qui dit juste que le joueur veux rejouer donc change la variable de la boucle while */
			}else if(SourisX <= 600 && SourisX >= 400 && SourisY <= 150 && SourisY >= 100){
				choix = 5;
			}
			if(victoire == 1){
				EcrireTexte(200, 235, "Joueur 1 a gagner !", 2);
			}else if (victoire == 2){
				EcrireTexte(200, 235, "Joueur 2 a gagner !", 2);		/* Affiche le gagnant */
			}else if (victoire == 3){
				EcrireTexte(200, 235, "L'IA a gagner !", 2);
			}
			if(choix == 5){
				FermerGraphique();
				return EXIT_SUCCESS;						/* Ferme le programme */
			}
		}
	}
}


int Jeu(){
	int choix[2], taille = 0, victoire = 0;
	Menu(choix);
	taille = choix[1];
	if(choix[0] == 1){
		victoire = compJCJ(taille);
	}else if (choix[0] == 2){
		victoire = compJCIA(taille);
	}
	return victoire;
}
