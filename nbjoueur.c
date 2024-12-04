#include <graph.h>


/*
 * Fonction qui permet de déssiner le bouton du Joueur contre Joueur
 */



void nbjoueur(){
	int x = 100, xx = 250, y = 150, l = 30, h = 30, angle1 = 20, angle2 = 30;
	ChoisirCouleurDessin(CouleurParNom("Black"));
	DessinerSegment(x, y, xx, y);
	DessinerSegment(x - 2, y + 50, xx, y + 50);
	EcrireTexte(x + 10, y + 35, "2 Joueurs", 2);
	DessinerArc(xx - 23, y - 3, l, h, angle1, angle2);
	DessinerArc(x - 9, y - 2, l, h, angle1 + 100, angle2 + 10);
	DessinerArc(xx - 23, y + 23, l, h, angle1 + 290, angle2);
	DessinerArc(x - 9, y + 23, l, h, angle1 + 180, angle2);
	DessinerSegment(x - 8, y + 9, x - 8, y + 43);
	DessinerSegment(xx + 6, y + 8, xx + 6, y + 43);
}



/*
 * Fonction qui permet de déssiner le bouton du joueur contre IA
 */

void nbjoueur2(){
        int x = 400, xx = 550, y = 150, l = 30, h = 30, angle1 = 20, angle2 = 30;
        ChoisirCouleurDessin(CouleurParNom("Black"));
        DessinerSegment(x, y, xx, y);
        DessinerSegment(x - 2, y + 50, xx, y + 50);
        EcrireTexte(x + 10, y + 35, "J1 VS IA", 2);
        DessinerArc(xx - 23, y - 3, l, h, angle1, angle2);
        DessinerArc(x - 9, y - 2, l, h, angle1 + 100, angle2 + 10);
        DessinerArc(xx - 23, y + 23, l, h, angle1 + 290, angle2);
        DessinerArc(x - 9, y + 23, l, h, angle1 + 180, angle2);
        DessinerSegment(x - 8, y + 9, x - 8, y + 43);
        DessinerSegment(xx + 6, y + 8, xx + 6, y + 43);
}

