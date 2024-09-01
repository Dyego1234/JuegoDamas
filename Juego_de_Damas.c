#include <stdio.h>


#define SIZE 8           // Tamaño del tablero 
#define PIEZA 12        // Numero de piezas X y O
#define TURNOS 10        //Numero de turnos
#define X_PIEZA 'X'
#define O_PIEZA 'O'


typedef struct {
    int row;  // Fila de la posición
    int col;  // Columna de la posición
} Posicion;

void boardin(int *board) {
    int i;
    for (i = 0; i < PIEZA; i++) {
        
    }
}

void printBoard(int *board) {
    int i, j;
    printf("\nTablero:\n");
    
    
    for (i = 0; i < SIZE; i++) {      //for para recorrer renglones y columnas
        for (j = 0; j < SIZE; j++) {
           
            char c = (*(board + i * SIZE + j) == X_PIEZA) ? 'X' : (*(board + i * SIZE + j) == O_PIEZA) ? 'O' : '.';
            printf("%c ", c);  
        }
        printf("\n");
    }
}


int main() {
    int board[SIZE * SIZE] = { 0 };   //todas las fichas se inicializan en 0
    char turno_pieza;

    int turn;

       for (turn = 0; turn < TURNOS * 2; turn++) {
        // Determina si es el turno de X o de O
        turno_pieza = (turn % 2 == 0) ? X_PIEZA : O_PIEZA;   //operador ternario usa el modulo para saber si es par o impar
        
        // Espera la entrada del usuario para proceder con el siguiente movimiento
        printf("Turno de la ficha %c. Presione <Enter> para continuar...", turno_pieza == X_PIEZA ? 'X' : 'O');
        getchar();

       }




}