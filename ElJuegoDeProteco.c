#include <stdio.h>
<<<<<<< HEAD
#include <unistd.h>
#include <stdlib.h>
void SinVidaSocialProteco(int tablero[10][10],int filas,int columnas,int celulas);
void ponerEn0s(int tablero[10][10],int filas, int columnas);
void imprimirMatriz(int tablero[10][10],int filas, int columnas);
int Vecinirijillos(int tablero[10][10], int filas, int columnas);
=======

//Hola git :D
>>>>>>> ce78d3e280fad269b13b3259f9eb5fb91b80d45c
void ponerEn0s(int tablero[10][10],int filas, int columnas) {
	int	i, j;
	for (i=0; i<columnas; i++){
		for (j=0; j<filas; j++){
			tablero[i][j] = 0;
		}
	}
}
void regarBendiciones(int tablero[10][10],int filas, int columnas,int celulas) {
	int	i;
	for (i=0; i<celulas;i++){
		tablero[rand() % 10][rand() % 10] = 1;
	}
}
int main(){
	int filas,columnas,celulas;
	printf("Bienvenido al juego de PROTECO.\n");
	printf("Ingrese el tamaño del tablero por filas, columnas y cantidad de celulas vivas: \n");
	printf("Filas: ");
	scanf("%d",&filas);
	printf("Columnas: ");
	scanf("%d",&columnas);
	printf("Cantidad celulas vivas: ");
	scanf("%d",&celulas);
	int tablero[filas][columnas];
	ponerEn0s(tablero,filas,columnas);
	regarBendiciones(tablero,filas,columnas,celulas);
	imprimirMatriz(tablero,filas,columnas);
	printf("\n\n");
	int i;
	for(int i=0;i<10;i++){
		//usleep(100000);
		SinVidaSocialProteco(tablero,filas,columnas,celulas);
		imprimirMatriz(tablero,filas,columnas);
		printf("\n");
		printf("\n");
}
}
int Vecinirijillos(int tablero[10][10], int filas, int columnas) {
	int	k, l, i;
	i = 0;
	for (k=-1; k<=1; k++) 
		for (l=-1; l<=1; l++)
		if (k || l)
			if (tablero[filas+k][columnas+l]==1) 
				i++;
	return i;
}
void SinVidaSocialProteco(int tablero[10][10],int filas,int columnas,int celulas){
	int	i, j, a, nuevaTabla[columnas][filas];
	for (i=0; i<columnas; i++) 
		for (j=0; j<filas; j++) {
			a = Vecinirijillos(tablero,i,j);
			if (a == 2) 
				nuevaTabla[i][j] = tablero[i][j];
			if (a == 3) 
				nuevaTabla[i][j] = 1;
			if (a < 2) 
				nuevaTabla[i][j] = 0;
			if (a > 3) 
				nuevaTabla[i][j] = 0;
	}
	for (i=0; i<filas; i++){ 
		for (j=0; j<columnas;j++) {
			tablero[i][j] = nuevaTabla[i][j];
	}
}
}
void imprimirMatriz(int tablero[10][10],int filas, int columnas){
	int i,j;
	for(i=0;i<columnas;i++){
		for(j=0;j<filas;j++){
			printf("   %d",tablero[i][j]);
	}
<<<<<<< HEAD
	printf("\n");
}
}
=======
}
>>>>>>> ce78d3e280fad269b13b3259f9eb5fb91b80d45c
