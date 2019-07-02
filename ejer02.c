#include "chess.h"
#include "figures.h"

void display(){
	char** espaciooscuro = reverse(whiteSquare);
	char** parespacios=join(espaciooscuro,whiteSquare);
	char** total=repeatH(parespacios,4);
	interpreter(total);
}
