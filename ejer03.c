#include "chess.h"
#include "figures.h"

void display(){
	char** espaciooscuro = reverse(whiteSquare);
	char** paroscuroblanco=join(espaciooscuro,whiteSquare);
	char** totaloscuroblanco=repeatH(paroscuroblanco,4);
	char** parblancooscuro=join(whiteSquare,espaciooscuro);
	char** totalblancooscuro=repeatH(parblancooscuro,4);
	char** parcombinacion=up(totaloscuroblanco,totalblancooscuro);
	char** total=repeatV(parcombinacion,2);
	interpreter(total);
}
