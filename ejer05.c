#include "chess.h"
#include "figures.h"

void display(){
	char** casillero1=superImpose(reverse(rook),reverse(whiteSquare));
	char** casillero2=superImpose(reverse(knight),whiteSquare);
	char** casillero3=superImpose(reverse(bishop),reverse(whiteSquare));
	char** casillero4=superImpose(reverse(queen),whiteSquare);
	char** casillero5=superImpose(reverse(king),reverse(whiteSquare));
	char** casillero6=superImpose(reverse(bishop),whiteSquare);
	char** casillero7=superImpose(reverse(knight),reverse(whiteSquare));
	char** casillero8=superImpose(reverse(rook),whiteSquare);
	char** primermitad=join(join(casillero1,casillero2),join(casillero3,casillero4));
	char** segundamitad=join(join(casillero5,casillero6),join(casillero7,casillero8));
	char** primerafila=join(primermitad,segundamitad);
	interpreter(primerafila);
}
