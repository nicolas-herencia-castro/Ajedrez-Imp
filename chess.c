#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chess.h"

char invColor(char c){
  switch( c ){
    case '_': return '=';
    case '=': return '_';
    case '.': return '@';
    case '@': return '.';
    case ' ': return ' ';
  }

  return '#';
}

int tamFila(char** a){
  int i=0;
  while(a[i]){
    i++;
  }
  return i;
}

int tamCol(char** a){
  int i=0;
  while(a[0][i]){
    i++;
  }
  return i;
}

char** join(char**a,char**b){

  int filas = tamFila(a);
  int columnas = tamCol(a) + tamCol(b);
  int i,j;

  char** unir = (char**)malloc(sizeof(char*)*(filas));
  unir[filas]=0;
  for(i=0;i<filas;i++){
    unir[i]=(char*)malloc(sizeof(filas)*(columnas));
  }
    for(j=0;j<filas;j++){
      strcpy(unir[j],a[j]);
      strcat(unir[j],b[j]);
    }	
  
  return unir;
}

char** reverse(char**a){
  int filas=tamFila(a);
  int columnas=tamCol(a);
  int i,j;
  char** reves=(char**)malloc(sizeof(char*)*(filas));
  for(i=0;i<filas;i++){
    reves[i]=(char*)malloc(sizeof(char)*(columnas));
    for(j=0;j<columnas;j++){
      reves[i][j]=invColor(a[i][j]);
    }
    reves[i][j]=0;
  }
  reves[filas]=0;
  return reves;
}

char** rotateR(char** a){

	int filas=tamCol(a);
	int columnas=tamFila(a);
	int i,j,k;
	char** rr=(char**)malloc(sizeof(char*)*(filas));

	for(i=0;i<filas;i++){
		rr[i]=(char*)malloc(sizeof(char)*(columnas));
	}

	for(i=0;i<filas;i++){
    k=0;
		for(j=columnas-1;j>=0;j--){
			rr[i][k] = a[j][i];
      k++;
		}
		rr[i][k]=0;
	}
	rr[filas]=0;
  return rr;
}

char** rotateL(char**a){

	
	int filas = tamFila(a);
	int columnas = tamCol(a);
	
	int i,j,k;
	char** rotar=(char**)malloc(sizeof(char*)*(columnas));
	
	for(i=0;i<columnas;i++){
		rotar[i]=(char*)malloc(sizeof(char)*(filas));
	}
	k=0;
	for(i=columnas-1;i>=0;i--){
		for(j=0;j<filas;j++){
			rotar[k][j] = a[j][i];
		}
		rotar[k][j]=0;
	       k++;	
	}
	rotar[columnas]=0;
	return rotar;
}


