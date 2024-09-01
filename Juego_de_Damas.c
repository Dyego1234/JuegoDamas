#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Biblioteca para usar la función sleep
#define SIZE 8          // Tamaño del tablero
#define TURNOS 10       // Numero de turnos

// Estructura para manejar las posiciones
typedef struct {
    int row;
    int col;
} Position;

// Función para inicializar el tablero
void boardIn(char *board) {
    int i = 0, j = 0;

    // Inicializar el tablero vacio
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            *(board + i * SIZE + j) = ' ';
            j++;
        }
        i++;
    }

    // Llenar las filas 0 a la 3 con fichas "X"
    i = 0;
    while (i < 3) {
        j = 0;
        while (j < SIZE) {
            if ((i + j) % 2 != 0) {
                *(board + i * SIZE + j) = 'X';
            }
            j++;
        }
        i++;
    }

    // Llenar las filas 5 a la 7 con fichas "O"
    i = 5;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            if ((i + j) % 2 != 0) {
                *(board + i * SIZE + j) = 'O';
            }
            j++;
        }
        i++;
    }
}

// Función para imprimir el tablero, resaltando la última pieza movida
void boardPrint(char *board, int lastRow, int lastCol) {
    int i = 0, j = 0;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            if (i == lastRow && j == lastCol) { //Si ya hay un movimiento cambia de color la ficha
                
                // La instruccion /033 se usa para hablar con el sistema y asi poder cambiar el color
                // Resalta la pieza movida con un color (el ascii de rojo es 31m)
                // Y deja en blanco (ascii 0m) el pasado
                printf("|\033[1;31m%c\033[0m", *(board + i * SIZE + j));
            } else {
                printf("|%c", *(board + i * SIZE + j));
            }
            j++;
        }
        printf("|\n");
        i++;
    }
}

// Funcion para verificar si un movimiento es valido
int isValidMove(char *board, int fromRow, int fromCol, int toRow, int toCol, char piece) {
    // Verifica que la posicion destino esté dentro del tablero
    if (toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE) {  
        return 0;
    }

    // Verifica que la casilla destino este vacia
    if (*(board + toRow * SIZE + toCol) != ' ') { 
        return 0;
    }

    // Verifica que el movimiento sea diagonal 
    int rowDiff = toRow - fromRow;     
    int colDiff = toCol - fromCol;     

    if (piece == 'X' && (rowDiff == 1 || rowDiff == -1) && (colDiff == 1 || colDiff == -1)) {
        return 1; // Verifica para X (diagonal) ambos forzosamente
    }
    if (piece == 'O' && (rowDiff == 1 || rowDiff == -1) && (colDiff == 1 || colDiff == -1)) {
        return 1; // Verifica para O (diagonal) ambos forzosamente
    }

    return 0; // Si no movimiento invalido
}

// Funcion para mover pieza aleatoriamente y mostrar el movimiento
void movePiece(char *board, char piece, int *lastRow, int *lastCol) {
    Position pos, newPos;        
    int moveFound = 0;           
    int direction = (piece == 'X') ? 1 : -1;

    // Busca una pieza aleatoria que pueda moverse
    while (!moveFound) {         
        pos.row = rand() % SIZE;  
        pos.col = rand() % SIZE;  

        if (*(board + pos.row * SIZE + pos.col) == piece) {    

            // Intenta mover la pieza en una direccion valida
            newPos.row = pos.row + direction;   
            newPos.col = pos.col + (rand() % 2 == 0 ? -1 : 1); 

            if (isValidMove(board, pos.row, pos.col, newPos.row, newPos.col, piece)) {
                moveFound = 1;             
                // Imprime la posición inicial y final
                printf("El jugador %c movio de (%d, %d) a (%d, %d)\n", piece, pos.row, pos.col, newPos.row, newPos.col);
                // Realiza el movimiento
                *(board + newPos.row * SIZE + newPos.col) = piece;    
                *(board + pos.row * SIZE + pos.col) = ' ';        
                
                // Actualiza las últimas posiciones
                *lastRow = newPos.row;
                *lastCol = newPos.col;
            }
        }
    }
}

int main() {
    char board[SIZE][SIZE];  
    int turn = 0; // 0 para el jugador 1 (X), 1 para el jugador 2 (O)
    int lastRow = -1, lastCol = -1; // Inicializa la última posición movida

    boardIn((char *)board);      
    boardPrint((char *)board, lastRow, lastCol);    

    for (int i = 0; i < TURNOS*2; i++) {    
        
        printf("Presione <Enter> para el turno de %c...\n", turn == 0 ? 'X' : 'O');
        getchar();
        printf("\nJugador %c moviendo...\n",turn == 0 ? 'X' : 'O');

        int delayThinking= rand() % 3 + 1; //Calcula un valor entre 1 y 3 de forma aleatoria para el sleep
        sleep(delayThinking);  //Funcion de sleep (espera)

        movePiece((char *)board, turn == 0 ? 'X' : 'O', &lastRow, &lastCol);     
        boardPrint((char *)board, lastRow, lastCol);                           
        turn = turn == 0 ? 1 : 0; // Cambia el turno
        
    }

    printf("Juego terminado.\n");

    return 0;
}
