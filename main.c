/*
 * REQUISITOS
 * Criar matriz com bombas (back-end)
 * Criar matriz de jogo (front-end)
 * Sortear bombas na matriz back
 * Inserir numero de bombas ao redor de cada casa
 * Revelar casas por jogada
 * Finalizar caso o usuario selecione uma bomba
 * Dar opcao de marcar casa com bandeira
 */
#define BOMBS 10
#define ROWS 10
#define COLS 10

#include "stdio.h"

int main() {
    int game[ROWS][COLS];
    char x = 'A';
    int y = 1;
    printf("%4s", " ");
    for (int k = 0; k < COLS; k++) {
        printf("%2c ", x);
        x++;
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%2d |", y);
        y++;
        for (int j = 0; j < COLS; j++) {
            game[i][j] = 0;
            printf("%2d ", game[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void addBombs(){

}
