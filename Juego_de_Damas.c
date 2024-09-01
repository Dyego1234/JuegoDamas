#include <stdio.h>


#define SIZE 8           // Tamaño del tablero 
#define PIEZA 12        // Numero de piezas X y O
#define TURNOS 10        //Numero de turnos

void boardIn(int *board) {
    int i,j;
    for (i=0 ; i < SIZE; i++){
        for (j=0; j< SIZE; j++){
            *(board + i * 8 +j) = ' ';
            if((i+j) %2 ==0){
                *(board + i * 8 +j) = '█';
            }
        }
    }

    i,j =0;
    //Llenamos las X
    for(i; i < 3; i++)
        for(j; j<8; j++)
            if((i+j) % 2 !=0){
                *(board + i * 8 +j) = 'X';
            }

    //Llenamos las O
    i = 5;
    j = 0;
    for(i; i < 8; i++)
        for(j; j<8; j++)
            if((i+j) % 2 !=0){
                *(board + i * 8 +j) = 'O';
            }
}

void printBoard(int *board) {
    int i, j;
    printf("\nTablero:\n");
    for (i = 0; i < SIZE; i++) {      //for para recorrer renglones y columnas
        for (j = 0; j < SIZE; j++) {
            printf("|%c", *(board + i * 8 + j));
        }
        printf("|\n");
    }
}



int main() {
    char board[SIZE * SIZE];
    /*
    char turno_pieza;

    int turn;

       for (turn = 0; turn < TURNOS * 2; turn++) {
        // Determina si es el turno de X o de O
        turno_pieza = (turn % 2 == 0) ? X_PIEZA : O_PIEZA;   //operador ternario usa el modulo para saber si es par o impar
        
        // Espera la entrada del usuario para proceder con el siguiente movimiento
        printf("Turno de la ficha %c. Presione <Enter> para continuar...", turno_pieza == X_PIEZA ? 'X' : 'O');
        getchar();

       }
       */

      boardIn((char*)board);
      printBoard((char*)board);


}