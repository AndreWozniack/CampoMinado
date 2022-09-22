//
// Created by gusta on 22/09/2022.
//
#define BOMBS 10
#define ROWS 12
#define COLS 12

#include "stdio.h"

int main() {
    int game[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            game[i][j] = 0;
            printf("%d ", game[i][j]);
        }
        printf("\n");
    }
}
