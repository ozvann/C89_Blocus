int initialisationX(int SourisX, int maxX, int taille){
	int casejoueur = 0, x = 0, y = 50, verou = 0;
	for(x = 0; x <= taille; x++){
		if(SourisX >= 50 && SourisX <= maxX){
			if(SourisX <= y && verou == 0){
				casejoueur = x;
				verou++;
			}		/* code qui retourne l'index X de la case du joueur */
			y += 50;
		}
	}
	return casejoueur;
}

int initialisationY(int SourisY, int maxY, int taille){
	int casejoueur = 0, x = 0, y = 100, verou = 0;
	for(x = 0; x <= taille; x++){
		if(SourisY >= 100 && SourisY <= maxY){
			if(SourisY <= y && verou == 0){
				casejoueur = x;
				verou++;
			}		/* code qui retourne l'index Y de la case du joueur */
			y += 50;
		}
	}
	return casejoueur;
}



int initialisationXbox(int SourisX, int maxX, int taille){
	int caseblock = 0, x = 0, y = 50, verou = 0;
	for(x = 0; x <= taille; x++){
		if(SourisX >= 50 && SourisX <= maxX){
			if(SourisX <= y && verou == 0){
				caseblock = x;
				verou++;	/* code qui retourne l'index X de la case du block */
			}
			y += 50;
		}
	}
	return caseblock;
}


int initialisationYbox(int SourisY, int maxY, int taille){
	int caseblock = 0, x = 0, y = 100, verou = 0;
	for(x = 0; x <= taille; x++){
		if(SourisY >= 100 && SourisY <= maxY){
			if(SourisY <= y && verou == 0){
				caseblock = x;
				verou++;	/* code qui retourne l'index Y de la case du block */
			}
			y += 50;
		}
	}
	return caseblock;
}
