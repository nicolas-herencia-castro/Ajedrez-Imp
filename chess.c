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
char** superImpose(char** f1, char** f2){

  int filas = tamFila(f1);
  int columnas = tamCol(f1);
  int i,j,k;
  char* vacio= {" "};  

  char** superI = (char**)malloc(sizeof(char*)*(filas));
  for(i=0;i<filas;i++){
    superI[i]=(char*)malloc(sizeof(char)*(columnas));
    for(j=0;j<columnas;j++)
      superI[i][j]=f2[i][j];
    superI[i][j]=0;
    for(k=0;k<columnas;k++){
      if(f1[i][k]!=vacio[0])
        superI[i][k]=f1[i][k];
    }
    superI[i][j]=0;
  }
  superI[filas]=0;
  return superI;
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

char** flipV(char** f){

  int filas = tamFila(f);
  int columnas = tamCol(f);
  int i,j,j1; 

  char** fv = (char**)malloc(sizeof(char*)*(filas));
  for(i=0;i<filas;i++){
    fv[i]=(char*)malloc(sizeof(char)*(columnas));
    j1=0;
    for(j=columnas-1;j>=0;j--){
      fv[i][j1]=f[i][j];   
      j1++; 
    }
    fv[i][j1]=0;
  }
  fv[filas]=0;
  return fv;
}

char** flipH(char** f){

  int filas = tamFila(f);
  int columnas = tamCol(f);
  int i,j;
  int i1=0;

  char** fh = (char**)malloc(sizeof(char*)*(filas));
  for(i=filas-1;i>=0;i--){
    fh[i1]=(char*)malloc(sizeof(char)*(columnas));
    for(j=0;j<columnas-1;j++)
      fh[i1][j]=f[i][j];
    fh[i1][j]=0;
    i1++;
  }
  fh[filas]=0;
  return fh;
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

char** repeatH(char** fig,int n){

  int filas = tamFila(fig);
  int columnas = tamCol(fig);
  int i,j,k,l=0;

  char** unir = (char**)malloc(sizeof(char*)*(filas));
  for(i=0;i<filas;i++){
    unir[i]=(char*)malloc(sizeof(filas)*(columnas*n));
    l=0;
    for(k=0;k<n;k++){
      for(j=0;j<columnas;j++){
        unir[i][l]=fig[i][j];
        l++;
      }
    } 
    unir[i][l]=0;
  }
  unir[filas]=0;
  return unir;
}



char** up(char**a,char**b){

  int filas=tamFila(a)+tamFila(b);
  int columnas=tamCol(a);
  int m=tamFila(a);
  int n=tamFila(b);
  int i,j,k;
  int cont=0;
  char** upp=(char**)malloc(sizeof(char*)*(filas));
  for(i=0;i<filas;i++){
    upp[i]=(char*)malloc(sizeof(char)*(columnas));
  }

  for(j=0;j<m;j++){
    strcpy(upp[j],a[j]);
    cont++;
    for(k=0;k<n;k++){
    strcpy(upp[cont+k],b[k]);
    }
  }
  upp[filas]=0;
  return upp;



}

char** repeatV(char** fig,int n){

  int filas = tamFila(fig);
  int columnas = tamCol(fig);
  int i,j,k,l=0;

  char** unir = (char**)malloc(sizeof(char*)*(filas*n));
  for(k=0;k<n;k++){
    for(i=0;i<filas;i++){
      unir[l]=(char*)malloc(sizeof(filas)*(columnas));
        for(j=0;j<columnas;j++)
          unir[l][j]=fig[i][j];
        unir[l][j]=0;
        l++;
    }

  }
  unir[l]=0;
  return unir;
}
