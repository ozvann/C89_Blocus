#include "initialisation.h"

int coordonerX(int SourisX){
	int x = 0, z = 0;
	for(z = 50; z <= 500; z += 50){
		if(SourisX > z){		/* Récupère les coordonnées par rapport a l'emplacement du sprite */
			x = z + 5;
		}
	}
	return x;
}


int coordonerY(int SourisY){
	int x = 0, z = 0;
	for(z = 100; z <= 550; z += 50){
		if(SourisY > z){		/* de même que le code mis en haut */
			x = z + 5;
		}
	}
	return x;
}


void VerifBlock1(int SourisX, int SourisY, int maxX, int maxY, int taille, int* coordoner){
        int placementX = 0, placementY = 0;
        if(SourisX >= 50 && SourisX <= maxX && SourisY >= 100 && SourisY <= maxY){
                placementX = initialisationXbox(SourisX, maxX, taille);			/* récupère l'index de la case selectionner par le joueur */
                placementY = initialisationYbox(SourisY, maxY, taille);
        }
        coordoner[0] = placementX;
        coordoner[1] = placementY;
}

