

/*
 * 3 : x = 200 y = 250
 * 4 : x = 250 y = 300
 * 5 : x = 300 y = 350
 * 6 : x = 350 y = 400
 * 7 : x = 400 y = 450
 * 8 : x = 450 y = 500
 * 9 : x = 500 y = 550
 *
 * Les deux codes permettent de définir la taille maximale en pixel
 */

int DefMaxX(int taille){
	int maxX = 0, x = 0, max = 200;
	if(taille == 3){
		maxX = 200;
	}
	for(x = 3; x < 10; x++){
		if(taille == x){
			maxX = max;
		}
		max += 50;
	}
	return maxX;
}

int DefMaxY(int taille){
	int maxY = 0, x = 0, max = 250;
	for(x = 3; x < 10; x++){
		if(taille == x){
			maxY = max;
		}
		max += 50;
	}
	return maxY;
}
