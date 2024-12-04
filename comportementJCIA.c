#include <graph.h>
#include <time.h>


#include "definirMaxXY.h"
#include "initialisation.h"
#include "coordoner.h"


int compJCIA(int taille){
	int fin = 0, tabx = 0, taby = 0, tour = 0, initi = 0, SourisX = 0, SourisY = 0, initialiser = 0;
	int maxX = 0, maxY = 0, joueurx1 = 0, joueury1 = 0, joueurx2 = 0, joueury2 = 0, placer = 1;
        int emplacementcooX1 = 0, emplacementcooX2 = 0, emplacementcooY1 = 0, emplacementcooY2 = 0;
	int grille[taille+2][taille+2];
	int empblock[4] = {0, 0, 0, 0}, empperso[4] = {0, 0, 0, 0};
	srand(time(NULL));
	maxX = DefMaxX(taille);		/* Définie les positions maximum de la grille */
	maxY = DefMaxY(taille);
	for(tabx = 0; tabx < taille + 2; tabx++){
		for(taby = 0; taby < taille + 2; taby++){
			grille[tabx][taby] = 0;					/* Initialise le tableau a double dimension */
			if(taby == 0 || taby == taille + 1 || tabx == 0 || tabx == taille + 1){
				grille[tabx][taby] = 9;
			}
		}
	}
	EcrireTexte(30, 40, "Joueur 1 choisissez l'emplacement de base du pion 1", 1);
	while(initi == 0){				/* Initialise l'emplacement du joueur 1 */
		if(SourisCliquee()){
			SourisX = _X;
			SourisY = _Y;
		}
		if(initialiser == 0){
			if(SourisX >= 50 && SourisX <= maxX && SourisY >= 100 && SourisY <= maxY){
				/* Change a l'index du tableau une valeur pour colision et affiche le sprote sur la case correspondante */
				ChargerSprite("./image/pion1.png");
				joueurx1 = initialisationX(SourisX, maxX, taille);	/* renvoie l'index de la case cliquee */
				joueury1 = initialisationY(SourisY, maxY, taille);
				emplacementcooX1 = coordonerX(SourisX);		/* renvoie les coordoner qui a été cliquee dans la grille */
				emplacementcooY1 = coordonerY(SourisY);
				AfficherSprite(1, emplacementcooX1, emplacementcooY1);
				grille[joueury1][joueurx1] = 1;		/* Permet de changer a l'index cliquee la valeur pour la detection de colision */
				initialiser++;
				SourisX = 0;
				SourisY = 0;
				EffaceIA();		/* Clear l'affichage du haut */
				EcrireTexte(30, 40, "Joueur 2 choisissez l'emplacement de base du pion 2", 1);
			}
		}else if (initialiser == 1){
			/* Change a l'index du tableau une valeur pour colision et affiche le sprite sur la case correspondante */
			SourisX = rand() % maxX;
			SourisY = rand() % maxY;	/* Voici l'IA */
			if(SourisX >= 50 && SourisX <= maxX && SourisY >= 100 && SourisY <= maxY){
				ChargerSprite("./image/pion2.png");
				joueurx2 = initialisationX(SourisX, maxX, taille);	/* renvoi l'index de la case de la grille choisie pa l'IA */
				joueury2 = initialisationY(SourisY, maxY, taille);
				if(grille[joueury2][joueurx2] != 1){
					emplacementcooX2 = coordonerX(SourisX);		/* renvoie les coordonées de l'emplacement choisie par l'IA */
					emplacementcooY2 = coordonerY(SourisY);
					AfficherSprite(2, emplacementcooX2, emplacementcooY2);
					grille[joueury2][joueurx2] = 2;			/* change a l'index la valeur pour la colision */
					initialiser++;
					initi++;
				}
				SourisX = 0;
				SourisY = 0;
			}
		}
	}
	ChargerSprite("./image/croix1.png");	/* charge les images des blocks */
	ChargerSprite("./image/croix2.png");
	while(fin == 0){
		if(tour == 0){
			EffaceIA();	/* efface l'affichage des tours */
			EcrireTexte(30, 40, "Tour du joueur 1", 2);
			SourisX = 0;
			SourisY = 0;
			while(placer == 1){
				if(SourisCliquee()){
					SourisX = _X;
					SourisY = _Y;
				}
				VerifBlock1(SourisX, SourisY, maxX, maxY, taille, empperso);
				if(grille[joueury1+1][joueurx1-1] != 0 && grille[joueury1+1][joueurx1] != 0 && grille[joueury1+1][joueurx1+1] && grille[joueury1][joueurx1-1] != 0 && grille[joueury1][joueurx1+1] != 0 && grille[joueury1-1][joueurx1-1] != 0 && grille[joueury1-1][joueurx1] != 0 && grille[joueury1-1][joueurx1+1] != 0){
					LibererSprite(1);
					LibererSprite(2);	/* verification des conditions de victoire */
					LibererSprite(3);
					LibererSprite(4);
					return 3;		/* arrete le programme et indique qui a gagner (le 3 car c'est contre l'IA) */
				}
				if(empperso[0] != 0){
					if(grille[empperso[1]][empperso[0]] == 0 && (empperso[1] <= joueury1+1 && empperso[1] >= joueury1-1) && (empperso[0] <= joueurx1+1 && empperso[0] >= joueurx1-1)){
						grille[joueury1][joueurx1] = 0;		/* Change l'emplacement précedent pour le rendre disponible */
						ChoisirCouleurDessin(CouleurParNom("white"));
						RemplirRectangle(emplacementcooX1, emplacementcooY1, 40, 40);	/* Efface le spite a l'ancien emplacement */
						ChoisirCouleurDessin(CouleurParNom("black"));
						joueurx1 = empperso[0];		/* donne l'index de la grille par rapport au clique effectuer */
						joueury1 = empperso[1];
						empperso[2] = coordonerX(SourisX);	/* donne les coordonnés du clique sur la grille */
						empperso[3] = coordonerY(SourisY);
						grille[empperso[1]][empperso[0]] = 1;	/* change la valeur pour la colision */
						AfficherSprite(1, empperso[2], empperso[3]);	/* Affiche le sprite a l'emplacement demander */
						emplacementcooX1 = empperso[2];
						emplacementcooY1 = empperso[3];		/* Recupère l'ancient index pour le supprimer plus tard */
						placer = 0;
					}
				}
			}
			empperso[0] = 0;	/* change empperso[0] a 0 pour la confirmation que le joueur a bien changer une variable */
			placer = 1;
			tour++;
		}else if(tour == 1){
			EffaceIA();		/* Efface l'ancient emplacement du haut de l'affichage */
			EcrireTexte(30, 40, "Joueur 1 place le bloc", 2);
			SourisX = 0;		/* Réinitialise les variables des souris pour refaire une SourisCliquee() */
			SourisY = 0;
			while(placer == 1){
				if(SourisCliquee()){
					SourisX = _X;
					SourisY = _Y;
				}		/* Prend les coordoner de la souris cliquee */
				VerifBlock1(SourisX, SourisY, maxX, maxY, taille, empblock);
				if(empblock[0] != 0){
					if(grille[empblock[1]][empblock[0]] == 0){
						empblock[2] = coordonerX(SourisX);	/* Fait en sorte d'avoir les coordonnées par rapport a la grille */
						empblock[3] = coordonerY(SourisY);
						grille[empblock[1]][empblock[0]] = 3;	/* change l'index de colision */
						AfficherSprite(3, empblock[2], empblock[3]);	/* Affiche le sprite */
						placer = 0;
					}
				}
			}
			empblock[0] = 0;	/* change empperso[0] a 0 pour la confirmation que le joueur a bien changer une variable */
			placer = 1;
			tour++;
		}else if(tour == 2){
			EffaceIA();		/* Efface l'affichage du haut de l'écran */
                        EcrireTexte(30, 40, "Tour du joueur 2", 2);
                        SourisX = 0;		/* remet a zero les variable Souris */
                        SourisY = 0;
                        while(placer == 1){
                                SourisX = rand() % maxX;	/* Le code de l'IA pour l'IA */
                                SourisY = rand() % maxY;
                                VerifBlock1(SourisX, SourisY, maxX, maxY, taille, empperso);
				if(grille[joueury2+1][joueurx2-1] != 0 && grille[joueury2+1][joueurx2] != 0 && grille[joueury2+1][joueurx2+1] != 0 && grille[joueury2][joueurx2-1] != 0 && grille[joueury2][joueurx2+1] != 0 && grille[joueury2-1][joueurx2-1] != 0 && grille[joueury2-1][joueurx2] != 0 && grille[joueury2-1][joueurx2+1] != 0){
					LibererSprite(1);
					LibererSprite(2);
					LibererSprite(3);	/* condition de perte pour l'IA */
					LibererSprite(4);
					return 1;		/* retourne 1 pour dire que le joueur 1 a gagner */
				}
                                if(empperso[0] != 0){
                                        if(grille[empperso[1]][empperso[0]] == 0 && (empperso[1] <= joueury2+1 && empperso[1] >= joueury2-1) && (empperso[0] <= joueurx2+1 && empperso[0] >= joueurx2-1)){
                                                grille[joueury2][joueurx2] = 0;		/* met a l'index précedent a zero */
                                                ChoisirCouleurDessin(CouleurParNom("white"));
                                                RemplirRectangle(emplacementcooX2, emplacementcooY2, 40, 40);	/* supprime le sprite de l'emplacement précedant */
                                                ChoisirCouleurDessin(CouleurParNom("black"));
                                                joueurx2 = empperso[0];			/* Change les anciennes donner par les nouvelles donner */
                                                joueury2 = empperso[1];
                                                empperso[2] = coordonerX(SourisX);	/* Donne les coordoner par rapport au coordoner donner par la souris et la grille */
                                                empperso[3] = coordonerY(SourisY);
                                                grille[empperso[1]][empperso[0]] = 2;	/* Change l'emplacement de la grille pour la colision */
                                                AfficherSprite(2, empperso[2], empperso[3]);
                                                emplacementcooX2 = empperso[2];		/* met le nouvelle emplacement dans l'ancien */
                                                emplacementcooY2 = empperso[3];
                                                placer = 0;
                                        }
                                }
                        }
                        empperso[0] = 0;
                        placer = 1;
                        tour++;

		}else if(tour == 3){
			EffaceIA();
			EcrireTexte(30, 40, "Joueur 2 place le bloc", 2);
			SourisX = 0;
			SourisY = 0;
			while(placer == 1){
				SourisX = rand() % maxX;		/* code de l'IA */
				SourisY = rand() % maxY;
				VerifBlock1(SourisX, SourisY, maxX, maxY, taille, empblock);
				if(empblock[0] != 0){
					if(grille[empblock[1]][empblock[0]] == 0){
						empblock[2] = coordonerX(SourisX);	/* même chose que précedemment */
						empblock[3] = coordonerY(SourisY);
						grille[empblock[1]][empblock[0]] = 4;
						AfficherSprite(4, empblock[2], empblock[3]);
						placer = 0;
					}
				}
			}
			empblock[0] = 0;
			placer = 1;
			tour = 0;
		}
	}
}


void EffaceIA(){
	ChoisirCouleurDessin(CouleurParNom("white"));
	RemplirRectangle(0, 0, 650, 50);			/* Fonction qui supprime l'affichage des tours */
	ChoisirCouleurDessin(CouleurParNom("black"));
}
