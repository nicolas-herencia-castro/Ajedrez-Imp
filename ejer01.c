#include "chess.h"
#include "figures.h"

void display(){
	char** total=repeatH(join(whiteSquare,reverse(whiteSquare)),4);
	interpreter(total);
}
