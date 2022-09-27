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

void showMatriz(int matriz[LINHAS][COLS]);
void addBombas(int matriz[LINHAS][COLS]);
int isBomba(const int *ptr);
int getDicas(int matriz[LINHAS][COLS]);

int main() {
    int campo[LINHAS][COLS];
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLS; j++) {
            campo[i][j] = 0;
        }
    }

    showMatriz(campo);
    addBombas(campo);
    showMatriz(campo);

    return 0;
}

void showMatriz(int matriz[LINHAS][COLS]){
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

void addBombas(int matriz[LINHAS][COLS]){
    int l,c;
    int i = 0;
    srand(time(NULL));
    while (i < BOMBAS) {
        l = rand() % LINHAS;
        c = rand() % COLS;
        if (matriz[l][c] == 0){
            matriz[l][c] = -1;
            i++;
        }
    }
}

int isBomba(const int *ptr) {
    if (*ptr == 1) {
        return 0;
    } else {
        return 1;
    }
}

int getDicas(int matriz[LINHAS][COLS]) {
    int *ptr;
    int numBombas = 0;

    // percorre todas as linhas
    for (int i = 0; i < LINHAS; i++) {
        // percorre todas as colunas
        for (int j = 0; j < COLS; j++) {
            for (int k = i - 1; k < i + 2; k++) {
                if (k > 0 && k < LINHAS) {
                    if (j - 1 > 0 && j + 1 < COLS) {
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
    }
    return numBombas;
}

void verificVizinhos(){

}



