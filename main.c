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
#define LINHAS 9
#define COLS 9

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void showMatrizCampo(int matriz[LINHAS][COLS]);
void addBombas(int matriz[LINHAS][COLS]);
int isBomba(int valor);
void setDicas(int matriz[LINHAS][COLS]);
void showMatrizTela(char matriz[LINHAS][COLS]);
void abrirCasas(int l, int c, int campo[LINHAS][COLS], char tela[LINHAS][COLS]);

int main() {
    int campo[LINHAS][COLS];
    char tela[LINHAS][COLS];
    char casa[2];
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLS; j++) {
            campo[i][j] = 0;
            tela[i][j] = '-';
        }
    }
    addBombas(campo);
    setDicas(campo);
    abrirCasas(2, 2, campo, tela);
    showMatrizTela(tela);
    showMatrizCampo(campo);
/*
    printf("\nEscolha uma casa:");
    gets(casa);
    printf("%s",casa);
    for (int i = 0; i < sizeof(casa); ++i) {
        printf("%c ",casa[i]);
    }
*/
    return 0;

}
void showMatrizCampo(int matriz[LINHAS][COLS]){
    char y = 'A';
    int x = 1;
    printf("\n");
    printf("%4s", " ");
    for (int k = 0; k < COLS; k++) {
        printf("%2d ", x);
        x++;
    }
    printf("\n");
    printf("%4s", " ");
    for (int i = 0; i < COLS; ++i) {
        printf(" _ ");
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%2c |", y);
        y++;
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void showMatrizTela(char matriz[LINHAS][COLS]){
    char y = 'A';
    int x = 1;
    printf("\n");
    printf("%4s", " ");
    for (int k = 0; k < COLS; k++) {
        printf("%2d ", x);
        x++;
    }
    printf("\n");
    printf("%4s", " ");
    for (int i = 0; i < COLS; ++i) {
        printf(" _ ");
    }

    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%2c |", y);
        y++;
        for (int j = 0; j < COLS; j++) {
            printf("%2c ", matriz[i][j]);
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
int isBomba(int valor) {
    if (valor == -1) {
        return 0;
    } else {
        return 1;
    }
}
void setDicas(int matriz[LINHAS][COLS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLS; j++) {
            int numBombas = 0;
            for (int a = i - 1; a < i + 2; a++) {
                for (int b = j - 1; b < j + 2; b++) {
                    if (a >= 0 && a < LINHAS) {
                        if (b >= 0 && b < COLS) {
                            if (a == i && b == j) continue;
                            else if (isBomba(matriz[a][b]) == 0) {
                                numBombas++;
                            }
                        }
                    }
                }
            }
            if (matriz[i][j] != -1) matriz[i][j] = numBombas;
        }
    }
}

void abrirCasas(int l, int c, int campo[LINHAS][COLS], char tela[LINHAS][COLS]){
    if(campo[l][c] > 0) {
        tela[l][c] = ((char) campo[l][c]) + 48;
    }
    if(campo[l][c] == 0){
        tela[l][c] = 'O';
        for (int i = l-1; i < l+2 ; i++) {
            for (int j = c-1; j < c+2; j++) {
                if(campo[i][j] > 0){
                    tela[i][j] = ((char) campo[i][j]) + 48;
                }
                if(i >= 0 && i < LINHAS && j >= 0 && j < COLS){
                    if(campo[i][j] == 0 && tela[i][j] != 'O'){
                        abrirCasas(i,j,campo,tela);
                    }

                }
            }
        }
    }
}



