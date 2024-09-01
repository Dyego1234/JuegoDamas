#include <stdio.h>


#define SIZE 8           // Tamaño del tablero 
#define PIEZA 12        // Numero de piezas X y O
#define TURNOS 10        //Numero de turnos

typedef struct{
    char *piece;
    int numberOfPiece;
}playerPiece;

playerPiece *p1;
playerPiece *p2;

//Funcion para inicializar tablero
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

//Funcion para imprimir el tablero
void boardPrint(char *board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|%c", *(board + i * SIZE + j));
        }
        printf("|\n");
    }
}

//Funcion para verificar turno
int turn(int turn){
    if(turn = 0){
        
    }

    return turn;
}

//Funcion para mover pieza
void movePiece(){
    
}

//Funcion para validar el movimiento
void isValid(char *board, char piece){
    if
}

int main() {
    char board[SIZE][SIZE];
    boardIn((char *)board);
    boardPrint((char *)board);

    return 0;
}