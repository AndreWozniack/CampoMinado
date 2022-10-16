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

// definir variaveis globais de tamanho da matriz
int G_BOMBAS;
int G_LINHAS;
int G_COLS;

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <xlocinfo.h>

void showMatrizCampo(int matriz[G_LINHAS][G_COLS]);
void addBombas(int matriz[G_LINHAS][G_COLS], int x, int y);
int isBomba(int valor);
void setDicas(int matriz[G_LINHAS][G_COLS]);
void showMatrizTela(char matriz[G_LINHAS][G_COLS]);
void abrirCasas(int l, int c, int campo[G_LINHAS][G_COLS], char tela[G_LINHAS][G_COLS]);
int convertLetra(char x);
int getLinha();
int getColuna();
void getCasa(int casa[2]);
int editarFlag(int numFlags, int l, int c, char tela[G_LINHAS][G_COLS]);
int verificarVitoria(int numFlags, int campo[G_LINHAS][G_COLS], char tela[G_LINHAS][G_COLS]);


int main() {
    int casa[2];
    int numFlags = 0;
    int jogo;

    printf("-----BEM VINDO AO CAMPO MINADO IMPERATIVO-----");

    do {
        printf("Em qual dificuldade deseja jogar?\n");
        printf("[1] Principiante\n[2] Intermediario\n[3] Especialista\n[4] Customizado\n");
        printf("Insira a opcao desejada: ");
        scanf("%d", &jogo);
        printf("\n");
    } while (jogo != 1 && jogo != 2 && jogo != 3 && jogo != 4);

    switch (jogo) {
        case 1:
            G_LINHAS = 9;
            G_COLS = 9;
            G_BOMBAS = 10;
            break;
        case 2:
            G_LINHAS = 16;
            G_COLS = 16;
            G_BOMBAS = 40;
            break;
        case 3:
            G_LINHAS = 16;
            G_COLS = 30;
            G_BOMBAS = 99;
            break;
        case 4:
            do {
            printf("Insira a quantidade de linhas (MAX: 26): ");
            scanf("%d", &G_LINHAS);
            printf("\nInsira a quantidade de colunas (MAX: 39): ");
            scanf("%d", &G_COLS);
            printf("\nInsira a quantidade de bombas: (MAX: 216) ");
            scanf("%d", &G_BOMBAS);
            } while (G_LINHAS > 26 || G_COLS > 39 || G_BOMBAS > 216);
            break;
    }

    int campo[G_LINHAS][G_COLS];
    char tela[G_LINHAS][G_COLS];

    for (int i = 0; i < G_LINHAS; i++) {
        for (int j = 0; j < G_COLS; j++) {
            campo[i][j] = 0;
            tela[i][j] = '-';
        }
    }

    showMatrizTela(tela);
    getCasa(casa);
    addBombas(campo, casa[0], casa[1]);
    setDicas(campo);
    abrirCasas(casa[0], casa[1], campo, tela);

    do {
        showMatrizTela(tela);
        int jogada;
        printf("NUMERO DE FLAGS RESTANTE: %d", G_BOMBAS - numFlags);
        printf("\nAbrir casa ou posicionar flag?\n");
        printf("[1] Abrir casa\n[2] Colocar/remover flag\n");
        printf("Insira a opcao: ");
        scanf("%d", &jogada);

        if (jogada == 1) {
            getCasa(casa);
            if (campo[casa[0]][casa[1]] == -1) {
                printf("\nVOCE PERDEU");
                showMatrizCampo(campo);
                break;
            } else abrirCasas(casa[0], casa[1], campo, tela);
        } else if (jogada == 2) {
            getCasa(casa);
            numFlags = editarFlag(numFlags,casa[0],casa[1], tela);
        } else {
            printf("Jogada invalida.");
        }

    } while (!verificarVitoria(numFlags, campo, tela));

    if (verificarVitoria(numFlags, campo, tela)) {
        showMatrizCampo(campo);
        printf("VOCE VENCEU");
    }
    return 0;

}
void showMatrizCampo(int matriz[G_LINHAS][G_COLS]){
    char y = 'A';
    int x = 1;
    printf("\n");
    printf("%4s", " ");
    for (int k = 0; k < G_COLS; k++) {
        printf("%2d ", x);
        x++;
    }
    printf("\n");
    printf("%4s", " ");
    for (int i = 0; i < G_COLS; ++i) {
        printf(" _ ");
    }
    printf("\n");
    for (int i = 0; i < G_LINHAS; i++) {
        printf("%2c |", y);
        y++;
        for (int j = 0; j < G_COLS; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void showMatrizTela(char matriz[G_LINHAS][G_COLS]){
    char y = 'A';
    int x = 1;
    printf("\n");
    printf("%4s", " ");
    for (int k = 0; k < G_COLS; k++) {
        printf("%2d ", x);
        x++;
    }
    printf("\n");
    printf("%4s", " ");
    for (int i = 0; i < G_COLS; ++i) {
        printf(" _ ");
    }

    printf("\n");
    for (int i = 0; i < G_LINHAS; i++) {
        printf("%2c |", y);
        y++;
        for (int j = 0; j < G_COLS; j++) {
            printf("%2c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void addBombas(int matriz[G_LINHAS][G_COLS], int x, int y){
    int l,c;
    int i = 0;
    srand(time(NULL));
    while (i < G_BOMBAS) {
        l = rand() % G_LINHAS;
        c = rand() % G_COLS;
        if (matriz[l][c] == 0){
            if (l != x && c != y) {
                matriz[l][c] = -1;
                i++;
            }
        }
    }
}

int isBomba(int valor) {
    if (valor == -1) {
        return 1;
    } else {
        return 0;
    }
}


void setDicas(int matriz[G_LINHAS][G_COLS]) {
    for (int i = 0; i < G_LINHAS; i++) {
        for (int j = 0; j < G_COLS; j++) {
            int numBombas = 0;
            for (int a = i - 1; a < i + 2; a++) {
                for (int b = j - 1; b < j + 2; b++) {
                    if (a >= 0 && a < G_LINHAS) {
                        if (b >= 0 && b < G_COLS) {
                            if (a == i && b == j) continue;
                            else if (isBomba(matriz[a][b]) == 1) {
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

void abrirCasas(int l, int c, int campo[G_LINHAS][G_COLS], char tela[G_LINHAS][G_COLS]){
    if(campo[l][c] > 0) {
        tela[l][c] = ((char) campo[l][c]) + 48;
    }
    if(campo[l][c] == 0){
        tela[l][c] = 'O';
        for (int i = l-1; i < l+2 ; ++i) {
            for (int j = c-1; j < c+2; ++j) {
                if(i >= 0 && i < G_LINHAS && j >= 0 && j < G_COLS){
                    if(campo[i][j] > 0) {
                        tela[i][j] = ((char) campo[i][j])+48;
                    }
                    if(campo[i][j] == 0 && tela[i][j] != 'O'){
                        abrirCasas(i,j,campo,tela);
                    }

                }
            }
        }
    }
}

int convertLetra(char x){
    int numero;
    if (islower(x)){
        x = toupper(x);
    }
    for (int i = 65; i < 91; i++) {
        if (x == i){
            numero = i - 65;
        }
    }
    return numero;
}

int getLinha() {
    char linha;
    int linhaN;
    printf("\nEscolha uma linha \n(Ex. A, B, c): ");
    scanf(" %c", &linha);
    linhaN = convertLetra(linha);
    if (linhaN < G_LINHAS) {
        return linhaN;
    } else {
        return -1;
    }
}

int getColuna() {
    int coluna;
    printf("\nDigite a Coluna\n(Ex. 1,2,3): ");
    scanf("%d", &coluna);
    if(coluna <= G_COLS){
        return coluna - 1;
    } else {
        return -1;
    }
}

void getCasa(int casa[2]) {
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            casa[i] = getLinha();
        } else {
            casa[i] = getColuna();
        }
    }
}

int editarFlag(int numFlags, int l, int c, char tela[G_LINHAS][G_COLS]) {
    if (tela[l][c] == 'P') {
        tela[l][c] = '-';
        numFlags--;
    } else if (tela[l][c] == '-') {
        tela[l][c] = 'P';
        numFlags++;
    }
    return numFlags;
}

int verificarVitoria(int numFlags, int campo[G_LINHAS][G_COLS], char tela[G_LINHAS][G_COLS]) {
    int bombasCorretas = 0;

    for (int i = 0; i < G_LINHAS; i++) {
        for (int j = 0; j < G_COLS; j++) {
            if (tela[i][j] == 'P') {
                if (campo[i][j] == -1) {
                    bombasCorretas++;
                }
            }
        }
    }
    if (bombasCorretas == G_BOMBAS && numFlags == G_BOMBAS) return 1;
    else return 0;
}