
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    
    #include <stdio.h>
    #include <stdlib.h> // Para usar abs()

    // cadastrando as variaveis.

int main() {
    int matriz[10][10];
    char colunas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int i, j;

    // cadastrando a matriz.

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            matriz[i][j] = 0;
        }
    }

    // posições dos navios.

    // Navio na horizontal (linha 5, colunas D, E, F)
    matriz[4][3] = 3;
    matriz[4][4] = 3;
    matriz[4][5] = 3;

    // Navio na vertical (coluna C, linhas 7, 8, 9)
    matriz[6][2] = 3;
    matriz[7][2] = 3;
    matriz[8][2] = 3;

    // Navio na diagonal principal (posição: (0,0), (1,1), (2,2))
    matriz[0][0] = 3;
    matriz[1][1] = 3;
    matriz[2][2] = 3;

    // Navio na diagonal secundária (posição: (0,9), (1,8), (2,7))
    matriz[0][9] = 3;
    matriz[1][8] = 3;
    matriz[2][7] = 3;

    // resultado do tabulheiro.

    printf("    ");
    for (i = 0; i < 10; i++) {
        printf("%c ", colunas[i]);
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%2d  ", i + 1);
        for (j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // abilidades especiais.

    int habilidade[5][5];

    // Cone:

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= (2 - i) && j <= (2 + i)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }

    printf("\nHabilidade: Cone\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }

    // Cruz:

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }

    printf("\nHabilidade: Cruz\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }

    // Octaedro:

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }

    printf("\nHabilidade: Octaedro\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }

    return 0;
}