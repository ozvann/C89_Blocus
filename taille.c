#include <graph.h>


/* Fonction qui affiche le cadre des bouttons et affiche une image représentant la taille du tableau disponible */
void AfficherSelectionBoutton(){
	DessinerSegment(100, 100, 150, 100);
	DessinerSegment(100, 200, 150, 200);
	DessinerSegment(100, 100, 100, 200);
	DessinerSegment(150, 100, 150, 200);
	ChargerSprite("./image/3.png");
	AfficherSprite(1, 100, 100);

	DessinerSegment(200, 100, 250, 100);
	DessinerSegment(200, 200, 250, 200);
	DessinerSegment(200, 200, 200, 100);
	DessinerSegment(250, 200, 250, 100);
	ChargerSprite("./image/4.png");
	AfficherSprite(2, 200, 100);

	DessinerSegment(300, 100, 350, 100);
	DessinerSegment(300, 200, 350, 200);
	DessinerSegment(300, 100, 300, 200);
	DessinerSegment(350, 100, 350, 200);
	ChargerSprite("./image/5.png");
	AfficherSprite(3, 300, 100);
	
	DessinerSegment(400, 100, 450, 100);
	DessinerSegment(400, 200, 450, 200);
	DessinerSegment(400, 100, 400, 200);
	DessinerSegment(450, 100, 450, 200);
	ChargerSprite("./image/6.png");
	AfficherSprite(4, 400, 100);
	
	DessinerSegment(500, 100, 550, 100);
	DessinerSegment(500, 200, 550, 200);
	DessinerSegment(500, 100, 500, 200);
	DessinerSegment(550, 100, 550, 200);
	ChargerSprite("./image/7.png");
	AfficherSprite(5, 500, 100);
	
	DessinerSegment(100, 250, 150, 250);
	DessinerSegment(100, 350, 150, 350);
	DessinerSegment(100, 250, 100, 350);
	DessinerSegment(150, 250, 150, 350);
	ChargerSprite("./image/8.png");
	AfficherSprite(6, 100, 250);
	
	DessinerSegment(200, 250, 250, 250);
	DessinerSegment(200, 350, 250, 350);
	DessinerSegment(200, 250, 200, 350);
	DessinerSegment(250, 250, 250, 350);
	ChargerSprite("./image/9.png");
	AfficherSprite(7, 200, 250);
}



/* Code permettant de choisir la taille de la grille en fonction du chiffre que l'utilisateur a entrer qui est compris entre 3 et 9 */

int GererChoixTaille(){
	int taille = 0, SourisX = 0, SourisY = 0;
	while(taille == 0){
		AfficherSelectionBoutton();
		if(SourisCliquee()){
			SourisX = _X;		/* Met les coordonés de la souris si le joueur a cliquer dans SourisX et SourisY */
			SourisY = _Y;
		}
		/* Vérifi si le joueur a cliquer dans la zone d'un des choix de taille de grille */
		if(SourisX >= 100 && SourisX <= 150 && SourisY >= 100 && SourisY <= 200){
			taille = 3;
		}else if(SourisX >= 200 && SourisX <= 250 && SourisY >= 100 && SourisY <= 200){
			taille = 4;
		}else if(SourisX >= 300 && SourisX <= 350 && SourisY >= 100 && SourisY <= 200){
			taille = 5;
		}else if(SourisX >= 400 && SourisX <= 450 && SourisY >= 100 && SourisY <= 200){
			taille = 6;
		}else if(SourisX >= 500 && SourisX <= 550 && SourisY >= 100 && SourisY <= 200){
			taille = 7;
		}else if(SourisX >= 100 && SourisX <= 150 && SourisY >= 250 && SourisY <= 350){
			taille = 8;
		}else if(SourisX >= 200 && SourisX <= 250 && SourisY >= 250 && SourisY <= 350){
			taille = 9;
		}
	}
	return taille;
}
