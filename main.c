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
#define ROWS 9
#define COLS 9

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void addBombs(int matrix[ROWS][COLS]);
void impMatrix(int matriz[ROWS][COLS]);

int main() {
    int game[ROWS][COLS];
    char x = 'A';
    int y = 1;

    printf("\n");
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
    addBombs(game);
    impMatrix(game);

}
void impMatrix(int matriz[ROWS][COLS]){
    char x = 'A';
    int y = 1;
    printf("\n");
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
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void addBombs(int matrix[ROWS][COLS]){
    int l,c;
    int i = 0;
    srand(time(NULL));
    while (i < BOMBS) {
        l = rand() % ROWS;
        c = rand() % COLS;
        if (matrix[l][c] == 0){
            matrix[l][c] = -1;
            i++;
        }
    }
}

