#include <graph.h>


#include "definirMaxXY.h"
#include "initialisation.h"
#include "coordoner.h"


int compJCJ(int taille){
	int fin = 0, tabx = 0, taby = 0, tour = 0, initi = 0, SourisX = 0, SourisY = 0, initialiser = 0;
	int maxX = 0, maxY = 0, joueurx1 = 0, joueury1 = 0, joueurx2 = 0, joueury2 = 0, placer = 1;
        int emplacementcooX1 = 0, emplacementcooX2 = 0, emplacementcooY1 = 0, emplacementcooY2 = 0;
	int grille[taille+2][taille+2];
	int empblock[4] = {0, 0, 0, 0}, empperso[4] = {0, 0, 0, 0};
	maxX = DefMaxX(taille);			/* Defini les maximum de X et Y */
	maxY = DefMaxY(taille);
	for(tabx = 0; tabx < taille + 2; tabx++){
		for(taby = 0; taby < taille + 2; taby++){
			grille[tabx][taby] = 0;		/* Defini la grille */
			if(taby == 0 || taby == taille + 1 || tabx == 0 || tabx == taille + 1){
				grille[tabx][taby] = 9;
			}
		}
	}
	EcrireTexte(30, 40, "Joueur 1 choisissez l'emplacement de base du pion 1", 1);
	while(initi == 0){		/* Initialise la position des deux joueurs */
		if(SourisCliquee()){	/* Recupère les coordonées de la souris */
			SourisX = _X;
			SourisY = _Y;
		}
		if(initialiser == 0){
			if(SourisX >= 50 && SourisX <= maxX && SourisY >= 100 && SourisY <= maxY){
				ChargerSprite("./image/pion1.png");	/* Charge l'image, trouve l'index par la position de la souris ainsi que les coordonées */
				joueurx1 = initialisationX(SourisX, maxX, taille);
				joueury1 = initialisationY(SourisY, maxY, taille);
				emplacementcooX1 = coordonerX(SourisX);
				emplacementcooY1 = coordonerY(SourisY);
				AfficherSprite(1, emplacementcooX1, emplacementcooY1);	/* Affiche le sprite */
				grille[joueury1][joueurx1] = 1;
				initialiser++;
				SourisX = 0;
				SourisY = 0;
				Efface();
				EcrireTexte(30, 40, "Joueur 2 choisissez l'emplacement de base du pion 2", 1);
			}
		}else if (initialiser == 1){
			if(SourisX >= 50 && SourisX <= maxX && SourisY >= 100 && SourisY <= maxY){
				ChargerSprite("./image/pion2.png");
				joueurx2 = initialisationX(SourisX, maxX, taille);
				joueury2 = initialisationY(SourisY, maxY, taille);
				if(grille[joueury2][joueurx2] != 1){		/* Si l'emplacement n'est pas déjà pris par l'user 1 */
					emplacementcooX2 = coordonerX(SourisX);
					emplacementcooY2 = coordonerY(SourisY);
					AfficherSprite(2, emplacementcooX2, emplacementcooY2);
					grille[joueury2][joueurx2] = 2;
					initialiser++;
					initi++;
				}
				SourisX = 0;
				SourisY = 0;
			}
		}
	}					/* Charge les sprites */
	ChargerSprite("./image/croix1.png");
	ChargerSprite("./image/croix2.png");
	while(fin == 0){
		if(tour == 0){		/* Tour du joueur 1 */
			Efface();
			EcrireTexte(30, 40, "Tour du joueur 1", 2);
			SourisX = 0;
			SourisY = 0;
			while(placer == 1){
				if(SourisCliquee()){
					SourisX = _X;	/* Recupere les coordonnées de la souris X et Y */
					SourisY = _Y;
				}
				VerifBlock1(SourisX, SourisY, maxX, maxY, taille, empperso);
				if(grille[joueury1+1][joueurx1-1] != 0 && grille[joueury1+1][joueurx1] != 0 && grille[joueury1+1][joueurx1+1] != 0 && grille[joueury1][joueurx1-1] != 0 && grille[joueury1][joueurx1+1] != 0 && grille[joueury1-1][joueurx1-1] != 0 && grille[joueury1-1][joueurx1] != 0 && grille[joueury1-1][joueurx1+1] != 0){
					LibererSprite(1);
					LibererSprite(2);		/* condition de victoire */
					LibererSprite(3);
					LibererSprite(4);
					return 2;
				}
				if(empperso[0] != 0){
					if(grille[empperso[1]][empperso[0]] == 0 && (empperso[1] <= joueury1+1 && empperso[1] >= joueury1-1) && (empperso[0] <= joueurx1+1 && empperso[0] >= joueurx1-1)){
						grille[joueury1][joueurx1] = 0;
						ChoisirCouleurDessin(CouleurParNom("white"));
						RemplirRectangle(emplacementcooX1, emplacementcooY1, 40, 40);	/* Suprime l'ancient perso pour le remplacer par un nouveau */
						ChoisirCouleurDessin(CouleurParNom("black"));
						joueurx1 = empperso[0];				/* Recupere les index du tableau par rapport au clique effectuer*/
						joueury1 = empperso[1];
						empperso[2] = coordonerX(SourisX);
						empperso[3] = coordonerY(SourisY);		/* Recupere les coordoner pour les sprites */
						grille[empperso[1]][empperso[0]] = 1;
						AfficherSprite(1, empperso[2], empperso[3]);
						emplacementcooX1 = empperso[2];			/* Sauvegarde les anciennes coordoner pour supressions de sprite */
						emplacementcooY1 = empperso[3];
						placer = 0;
					}
				}
			}
			empperso[0] = 0;
			placer = 1;
			tour++;
		}else if(tour == 1){		/* Fonction qui place les blocs du joueur 1 */
			Efface();
			EcrireTexte(30, 40, "Joueur 1 place le bloc", 2);
			SourisX = 0;
			SourisY = 0;
			while(placer == 1){
				if(SourisCliquee()){
					SourisX = _X;		/* Recupere les coordonnées de la souris */
					SourisY = _Y;
				}
				VerifBlock1(SourisX, SourisY, maxX, maxY, taille, empblock);
				if(empblock[0] != 0){
					if(grille[empblock[1]][empblock[0]] == 0){
						empblock[2] = coordonerX(SourisX);
						empblock[3] = coordonerY(SourisY);		/* Récupere les coordonnées et index pour le placement de bloc */
						grille[empblock[1]][empblock[0]] = 3;
						AfficherSprite(3, empblock[2], empblock[3]);
						placer = 0;
					}
				}
			}
			empblock[0] = 0;
			placer = 1;
			tour++;
		}else if(tour == 2){		/* Tour du joueur 2 le code est le même que pour le joueur 1 mais avec des variables du joueur 2 */
			Efface();
                        EcrireTexte(30, 40, "Tour du joueur 2", 2);
                        SourisX = 0;
                        SourisY = 0;
                        while(placer == 1){
                                if(SourisCliquee()){
                                        SourisX = _X;
                                        SourisY = _Y;
                                }
                                VerifBlock1(SourisX, SourisY, maxX, maxY, taille, empperso);
				if(grille[joueury2+1][joueurx2-1] != 0 && grille[joueury2+1][joueurx2] != 0 && grille[joueury2+1][joueurx2+1] != 0 && grille[joueury2][joueurx2-1] != 0 && grille[joueury2][joueurx2+1] != 0 && grille[joueury2-1][joueurx2-1] != 0 && grille[joueury2-1][joueurx2] != 0 && grille[joueury2-1][joueurx2+1]){
					LibererSprite(1);
					LibererSprite(2);
					LibererSprite(3);
					LibererSprite(4);
					return 1;
				}
                                if(empperso[0] != 0){
                                        if(grille[empperso[1]][empperso[0]] == 0 && (empperso[1] <= joueury2+1 && empperso[1] >= joueury2-1) && (empperso[0] <= joueurx2+1 && empperso[0] >= joueurx2-1)){
                                                grille[joueury2][joueurx2] = 0;
                                                ChoisirCouleurDessin(CouleurParNom("white"));
                                                RemplirRectangle(emplacementcooX2, emplacementcooY2, 40, 40);
                                                ChoisirCouleurDessin(CouleurParNom("black"));
                                                joueurx2 = empperso[0];
                                                joueury2 = empperso[1];
                                                empperso[2] = coordonerX(SourisX);
                                                empperso[3] = coordonerY(SourisY);
                                                grille[empperso[1]][empperso[0]] = 2;
                                                AfficherSprite(2, empperso[2], empperso[3]);
                                                emplacementcooX2 = empperso[2];
                                                emplacementcooY2 = empperso[3];
                                                placer = 0;
                                        }
                                }
                        }
                        empperso[0] = 0;
                        placer = 1;
                        tour++;

		}else if(tour == 3){	/* Place les blocs comme pour les blocs du joueur 2 */
			Efface();
			EcrireTexte(30, 40, "Joueur 2 place le bloc", 2);
			SourisX = 0;
			SourisY = 0;
			while(placer == 1){
				if(SourisCliquee()){
					SourisX = _X;
					SourisY = _Y;
				}
				VerifBlock1(SourisX, SourisY, maxX, maxY, taille, empblock);
				if(empblock[0] != 0){
					if(grille[empblock[1]][empblock[0]] == 0){
						empblock[2] = coordonerX(SourisX);
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
	return 0;
}

void Efface(){						/* Efface l'affichage du haut */
	ChoisirCouleurDessin(CouleurParNom("white"));
	RemplirRectangle(0, 0, 650, 50);
	ChoisirCouleurDessin(CouleurParNom("black"));
}
