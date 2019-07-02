#include "chess.h"
#include "figures.h"

void display(){
	char** casilleronegroreyna=superImpose(queen,reverse(whiteSquare));
	char** casilleroblancoreyna=superImpose(queen,whiteSquare);
	char** fila12=join(reverse(whiteSquare),whiteSquare);
	char** fila13=join(fila12,reverse(whiteSquare));
	char** fila14=join(fila13,casilleroblancoreyna);
	char** primerafila=join(fila14,repeatH(join(reverse(whiteSquare),whiteSquare),2));

	char** fila26=join(whiteSquare,reverse(whiteSquare));
	char** fila27=join(fila26,casilleroblancoreyna);
	char** fila28=join(fila27,reverse(whiteSquare));
	char** segundafila=join(repeatH(join(whiteSquare,reverse(whiteSquare)),2),fila28);

	char** fila32=join(reverse(whiteSquare),whiteSquare);
	char** fila33=join(fila32,casilleronegroreyna);
	char** fila34=join(fila33,whiteSquare);
	char** tercerafila=join(fila34,repeatH(join(reverse(whiteSquare),whiteSquare),2));

	char** fila46=join(whiteSquare,reverse(whiteSquare));
	char** fila47=join(fila46,whiteSquare);
	char** fila48=join(fila47,casilleronegroreyna);
	char** cuartafila=join(repeatH(join(whiteSquare,reverse(whiteSquare)),2),fila48);

	char** fila52=join(reverse(whiteSquare),casilleroblancoreyna);
	char** fila54=join(fila52,join(reverse(whiteSquare),whiteSquare));
	char** quintafila=join(fila54,repeatH(join(reverse(whiteSquare),whiteSquare),2));

	char** fila66=join(casilleroblancoreyna,reverse(whiteSquare));
	char** fila68=join(fila66,join(whiteSquare,reverse(whiteSquare)));
	char** sextafila=join(repeatH(join(whiteSquare,reverse(whiteSquare)),2),fila68);

	char** fila72=join(casilleronegroreyna,whiteSquare);
	char** septimafila=join(fila72,repeatH(join(reverse(whiteSquare),whiteSquare),3));

	char** fila86=join(whiteSquare,casilleronegroreyna);
	char** fila88=join(fila86,join(whiteSquare,reverse(whiteSquare)));
	char** octavafila=join(repeatH(join(whiteSquare,reverse(whiteSquare)),2),fila88);

	char** columna12=up(primerafila,segundafila);
	char** columna13=up(columna12,tercerafila);
	char** columna14=up(columna13,cuartafila);
	char** columna15=up(columna14,quintafila);
	char** columna16=up(columna15,sextafila);
	char** columna17=up(columna16,septimafila);
	char** columna18=up(columna17,octavafila);
	interpreter(columna18);
}
