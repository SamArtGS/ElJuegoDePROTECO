#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void SinVidaSocialProteco(int ** tablero,int filas,int columnas,int celulas);
void ponerEn0s(int ** tablero,int filas, int columnas);
void imprimirMatriz(int ** tablero,int filas, int columnas);
int Vecinirijillos(int ** tablero, int filas, int columnas,int filReal,int colReal);
void ponerEn0s(int ** tablero,int filas, int columnas) {
    int    i, j;
    for (i=0; i<columnas; i++){
        for (j=0; j<filas; j++){
            tablero[i][j] = 0;
        }
    }
}
void regarBendiciones(int ** tablero,int filas, int columnas,int celulas) {
    int    i;
    for (i=0; i<celulas;i++){
        tablero[rand() % filas][rand() % columnas] = 1;
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
    int i;
    int **tablero=NULL;
    tablero = (int **)malloc ((filas)*sizeof(int *));
    for (i=0;i<filas;i++)
        tablero[i] = (int *) malloc ((columnas)*sizeof(int));
    ponerEn0s(tablero,filas,columnas);
    regarBendiciones(tablero,filas,columnas,celulas);
    imprimirMatriz(tablero,filas,columnas);
    usleep(500000);
    system("clear");
    
    for(int i=0;i<100;i++){
        SinVidaSocialProteco(tablero,filas,columnas,celulas);
        imprimirMatriz(tablero,filas,columnas);
        fflush(stdout);
        usleep(500000);
        system("clear");
        
    }
    free(tablero);
}
int Vecinirijillos(int ** tablero, int filas, int columnas,int filReal,int colReal){
    int horiz, vert, i;
    i = 0;
    for (horiz=-1; horiz<=1; horiz++){
        for (vert=-1; vert<=1; vert++){
            if (horiz || vert){
                if(filas+horiz >-1 && (filas+horiz) < (filReal) && (columnas+vert) >-1 && (columnas+vert) < (colReal)){
                    if (tablero[filas+horiz][columnas+vert]==1){
                        i++;
                    }
                }
            }
        }
    }
    return i;
}
void SinVidaSocialProteco(int ** tablero,int filas,int columnas,int celulas){
    int    i, j, vecinosCantidad;
    int **nuevaTabla=NULL;
    nuevaTabla = (int **)malloc ((filas+1)*sizeof(int *));
    for (i=0;i<filas;i++){
        nuevaTabla[i] = (int *) malloc ((columnas+1)*sizeof(int));
    }
    for (i=0; i<columnas; i++){
        for (j=0; j<filas; j++) {
            vecinosCantidad = Vecinirijillos(tablero,i,j,filas,columnas);
            if (vecinosCantidad == 2)
                nuevaTabla[i][j] = tablero[i][j];
            if (vecinosCantidad == 3)
                nuevaTabla[i][j] = 1;
            if (vecinosCantidad < 2)
                nuevaTabla[i][j] = 0;
            if (vecinosCantidad > 3)
                nuevaTabla[i][j] = 0;
        }
    }
    for (i=0; i<filas; i++){
        for (j=0; j<columnas;j++) {
            
            tablero[i][j] = nuevaTabla[i][j];
        }
    }
}
void imprimirMatriz(int ** tablero,int filas, int columnas){
    int i,j;
    for(i=0;i<columnas;i++){
        for(j=0;j<filas;j++){
            if(tablero[i][j]==0){
                printf("   .");
            }else{
                printf("   @");
            }
        }
        printf("\n");
    }
}
