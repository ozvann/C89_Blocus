#include <graph.h>

#include "taille.h"
#include "nbjoueur.h"


void Menu(int *retour) {
	int x = 50, y = 50, taille = -5, choix = 0, echotaille = 0, verrou = 0; 	/* initialisation des variable */
	couleur c = CouleurParNom("white");
	while(choix == 0){		/* Condition pour que le menu s'arrête quand le joueur aura selectionner le nombre de joueur */
		ChoisirCouleurDessin(CouleurParNom("black"));
		EcrireTexte(x, y, "Taille de grille entre 3 et 9 :", 2);
		taille = GererChoixTaille();		/* Récupération de la taille de la grille */
		/* Demande a taille sa valeur pour la comparé pour savoir si menu peu passer a la selection de joueur */
		if(taille > 2 && taille < 10){
			EffacerEcran(c);
			if(verrou == 0){
				echotaille = taille;
				verrou++;
			}
			taille = 10;
		}
		if(taille == 10){
	/* Code permettant de selectionner le nombre de joueur */
			nbjoueur();
			nbjoueur2();
			if(choix == 0){
				choix = boutonJVJ();
			}
		}
	}
        FermerGraphique();
        InitialiserGraphique();
	CreerFenetre(50, 50, 650, 650);
	Grille(echotaille);		/* Lancement du code qui affiche la grille */
	retour[0] = choix;
	retour[1] = echotaille;
}



void Grille(int taille){
        int bord = 0, x = 100, xx = 50, y = 100, yy = 100;
        ChoisirCouleurDessin(CouleurParNom("Black"));
        for(bord = 0; bord < taille; bord++){
                DessinerSegment(50, 100, x, 100);       /* Dessine le bord du haut de la grille */
                x += 50;
        }
        x -= 50;                			/* Enlève le surplus de la fonction for */
        for(bord = 0; bord <= taille; bord++){
                DessinerSegment(50, 100, 50 , y);       /* Dessine les barre latérale en fonction de la taille choisie */
                DessinerSegment(x, 100, x, y);
                y += 50;
        }
        y -= 50;					/* Enlève le surplus de la fonction for */
        DessinerSegment(50, y, x, y);
        for(bord = 0; bord <= taille; bord++){
                DessinerSegment(50, yy, x, yy);         /* Dessine les barre horizontale de l'intérieur de la grille */
                yy += 50;
        }
        for(bord = 0; bord <= taille; bord++){
                DessinerSegment(xx, 100, xx, y);        /* Dessine les barre verticale de l'intérieur de la grille */
                xx += 50;
        }
}



/* Fonction qui permet de délimiter le clique de la souris pour le bouton de Joueur contre Joueur */

int boutonJVJ(){
        int choix = 0, SourisX = 0, SourisY = 0;
        while(choix == 0){                              /* Boucle effectif tant que le joueur n'a pas fais de choix */
                if (SourisCliquee()){   /* Détecte quand le joueur clique et met les coordonées du clique de SourisX et Souris Y */
                        SourisX = _X;
                        SourisY = _Y;
                }
                if(SourisX > 100 && SourisX < 250 && SourisY > 150 && SourisY < 200){
                        choix = 1;              /* Quand le joueur clique dans l'emplacement de Joueur contre Joueur choix = 1 */
                }else if(SourisX > 400 && SourisX < 550 && SourisY > 150 && SourisY < 200){
                        choix = 2;              /* Quand le joueur cliqye dans l'emplacement de Joueur contre IA choix = 2 */
                }
        }
        return choix;   /* On retourne choix pour que le menu puisse le retourner a jeu.c pour faire la selection de l'ennemie */
}

