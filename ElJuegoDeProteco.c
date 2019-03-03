#include <stdio.h>

//Hola git :D
void ponerEn0s(int tablero[10][10],int filas, int columnas) {
	int	i, j;
	for (i=0; i<columnas; i++){
		for (j=0; j<filas; j++){
			tablero[i][j] = 0;
		}
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
	SinVidaSocialProteco(tablero[filas][columnas],filas,columnas,celulas);
}
int anadirY(int i, int ontoy,int filas) {
	i += ontoy;
	while (i < 0) 
		i += filas;
	while (i >= filas) 
		i -= filas;
	return i;
}
int anadirX(int i, int ontoy,int columnas) {
	i += ontoy;
	while (i < 0) 
		i += columnas;
	while (i >= columnas) 
		i -= columnas;
	return i;
}
void SinVidaSocialProteco(int tablero[10][10],int filas,int columnas,int celulas){
	int	i, j, a, nuevaTabla[columnas][filas];
	for (i=0; i<columnas; i++) 
		for (j=0; j<filas; j++) {
			//a = adjacent_to (tablero, i, j);
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
			if(tablero[i][j]==1){
				printf("   O");
			}else{
				printf("   X");
			}
		}
		printf("\n");
	}
}
