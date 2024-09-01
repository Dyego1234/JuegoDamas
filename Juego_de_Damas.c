#include <stdio.h>


#define SIZE 8           // Tamaño del tablero 
#define PIEZA 12        // Numero de piezas X y O
#define TURNOS 10        //Numero de turnos

void boardIn(char *board) {
    // Inicializar el tablero vacío
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(board + i * SIZE + j) = ' ';
            if((i+j) %2 ==0){
                *(board + i * SIZE +j) = '#';
            }
        }
    }

    // Llenar las filas 0 a la 3 con fichas "X"
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                *(board + i * SIZE + j) = 'X';
            }
        }
    }

    // Llenar las filas 5 a la 7 con fichas "0"
    for (int i = 5; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                *(board + i * SIZE + j) = '0';
            }
        }
    }
}

void boardPrint(char *tablero) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|%c", *(tablero + i * SIZE + j));
        }
        printf("|\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    boardIn((char *)board);
    boardPrint((char *)board);

    return 0;
}