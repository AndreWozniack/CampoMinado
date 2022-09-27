/*
 * REQUISITOS
 * Criar matriz com bombas (back-end)
 * Criar matriz de jogo (front-end)
 * Sortear bombas na matriz back
 * Inserir numero de bombas ao redor de cada casa
 * Revelar casas por jogada
 * Finalizar caso o usuario selecione uma bomba
 * Dar opcao de marcar casa com bandeira
 *
 * FACIL : 9X9, 10B
 * MEDIO: 16X16, 40B
 * DIFICIL: 16X30, 99B
 */
#define BOMBAS 10
#define LINHAS 10
#define COLS 10

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int game[LINHAS][COLS];
    char x = 'A';
    int y = 1;
    printf("%4s", " ");
    for (int k = 0; k < COLS; k++) {
        printf("%2c ", x);
        x++;
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
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

void impMatrix(int matriz[LINHAS][COLS]){
    char x = 'A';
    int y = 1;
    printf("\n");
    printf("%4s", " ");
    for (int k = 0; k < COLS; k++) {
        printf("%2c ", x);
        x++;
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d |", y);
        y++;
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void addBombs(int matrix[LINHAS][COLS]){
    int l,c;
    int i = 0;
    srand(time(NULL));
    while (i < BOMBAS) {
        l = rand() % LINHAS;
        c = rand() % COLS;
        if (matrix[l][c] == 0){
            matrix[l][c] = -1;
            i++;
        }
    }
}

int isBomb(int *ptr) {
    if (*ptr == 1) {
        return 0;
    } else {
        return 1;
    }
}

void getDicas(int matriz[LINHAS][COLS]) {
    int *ptr;
    int numBombas = 0;

    // percorre todas as linhas
    for (int i = 0; i < LINHAS; i++) {
        // percorre todas as colunas
        for (int j = 0; j < COLS; j++) {
            for (int k = i - 1; k < i + 2; k++) {
                ptr = &matriz[k][j - 1];
                while (ptr <= &matriz[k][j + 1]) {
                    if (ptr == &matriz[i][j]) {
                        ptr++;
                        continue;
                    } else {
                        if (*ptr == -1) numBombas++;
                        ptr++;
                    }
                }
            }
        }
    }
}



