#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ALTURA 15
#define LARGURA 20

int pontuacao = 0;
int pacmanX, pacmanY;
int fantasmaX[5], fantasmaY[5];
char mapa[ALTURA][LARGURA];

void inicializarMapa() {
    int i, j;
    for (i = 0; i < ALTURA; i++) {
        for (j = 0; j < LARGURA; j++) {
            if (i == 0 || i == ALTURA - 1 || j == 0 || j == LARGURA - 1)
                mapa[i][j] = '#'; // Parede
            else
                mapa[i][j] = ' '; // Espaço vazio
        }
    }
}

void desenharMapa() {
    int i, j;
    system("cls");
    for (i = 0; i < ALTURA; i++) {
        for (j = 0; j < LARGURA; j++) {
            if (i == pacmanY && j == pacmanX)
                printf("C"); // Pac-Man
            else {
                int eFantasma = 0;
                for (int k = 0; k < 5; k++) {
                    if (i == fantasmaY[k] && j == fantasmaX[k]) {
                        printf("F"); // Fantasma
                        eFantasma = 1;
                        break;
                    }
                }
                if (!eFantasma)
                    printf("%c", mapa[i][j]);
            }
        }
        printf("\n");
    }
    printf("Pontuacao: %d\n", pontuacao);
}

void moverPacman(char direcao) {
    int novoX = pacmanX;
    int novoY = pacmanY;

    switch (direcao) {
        case 'w': novoY--; break;
        case 's': novoY++; break;
        case 'a': novoX--; break;
        case 'd': novoX++; break;
    }

    if (mapa[novoY][novoX] != '#') {
        pacmanX = novoX;
        pacmanY = novoY;

        if (mapa[pacmanY][pacmanX] == 'o') {
            pontuacao++;
            mapa[pacmanY][pacmanX] = ' ';
        }
    }
}

void moverFantasma(int index) {
    int novoX, novoY;

    if (fantasmaX[index] < pacmanX) {
        novoX = fantasmaX[index] + 1;
        novoY = fantasmaY[index];
    } else if (fantasmaX[index] > pacmanX) {
        novoX = fantasmaX[index] - 1;
        novoY = fantasmaY[index];
    } else if (fantasmaY[index] < pacmanY) {
        novoX = fantasmaX[index];
        novoY = fantasmaY[index] + 1;
    } else {
        novoX = fantasmaX[index];
        novoY = fantasmaY[index] - 1;
    }

    if (mapa[novoY][novoX] != '#') {
        fantasmaX[index] = novoX;
        fantasmaY[index] = novoY;
    }
}

int main() {
    char tecla;
    inicializarMapa();
    pacmanX = 1;
    pacmanY = 1;

    // Posições iniciais dos fantasmas
    fantasmaX[0] = LARGURA - 2;
    fantasmaY[0] = ALTURA - 2;
    fantasmaX[1] = LARGURA - 2;
    fantasmaY[1] = 1;
    fantasmaX[2] = 1;
    fantasmaY[2] = ALTURA - 2;
    fantasmaX[3] = LARGURA / 2;
    fantasmaY[3] = ALTURA / 2;
    fantasmaX[4] = LARGURA / 2;
    fantasmaY[4] = ALTURA / 2;

    while (1) {
        if (kbhit()) {
            tecla = getch();
            if (tecla == 'q')
                break;
            moverPacman(tecla);
        }

        for (int i = 0; i < 5; i++)
            moverFantasma(i);

        desenharMapa();

        // Verificar colisão com fantasmas
        for (int i = 0; i < 5; i++) {
            if (pacmanX == fantasmaX[i] && pacmanY == fantasmaY[i]) {
                printf("Voce perdeu!\n");
                return 0;
            }
        }
    }

    return 0;
}
