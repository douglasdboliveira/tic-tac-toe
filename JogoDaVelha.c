#include <stdio.h>
#include <stdlib.h>

int main() {
    int jogo[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0},
        notValid[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0},
        i,
        j,
        posicao,
        jogador,
        winner = 0,
        velha = 1;

    // 1 para O
    // 2 para X

    do {
        printf("Qual jogador voce gostaria de ser?\n\n1 - O\n2 - X\n\nR.: ");
        scanf("%d", &jogador);

        if(jogador < 1 || jogador > 2) {
            printf("\nRESPOSTA INVALIDA\n\n");
        }
    } while(jogador < 1 || jogador > 2);

    while(1) {
        system("CLS");

        if(jogador == 1) {
            printf("\n-> VEZ DO JOGADOR O: \n\n");
        }
        else {
            printf("\n-> VEZ DO JOGADOR X: \n\n");
        }
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                if(!jogo[i][j]) {
                    printf("     ");
                }
                else if(jogo[i][j] == 1) {
                    printf("  O  ");
                }
                else {
                    printf("  X  ");
                }

                if(j < 2) {
                    printf("|");
                }
            }
            if(i < 2) {
                printf("\n_________________\n\n");
            }
        }

        if(winner) {
            if(jogador == 1) {
                printf("\n\n\n\n * X IS THE WINNER *\n");
                system("pause");
            }
            else if(jogador == 2) {
                printf("\n\n\n\n * O IS THE WINNER *\n");
                system("pause");
            }
            break;
        }

        // Velha
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                if(!jogo[i][j]) {
                    velha = 0;
                }
            }
        }
        if(velha) {
            printf("\n\n\n\n* RAPAZ! DEU VELHA *\n");
            system("pause");
            break;
        }
        else {
            velha = 1;
        }

        do {
            printf("\n\nEm qual posicao voce gostaria de jogar?\nR.: ");
            scanf("%d", &posicao);

            if(posicao < 1 || posicao > 9 || notValid[posicao-1]) {
                printf("\nRESPOSTA INVALIDA\n");
            }
        } while(posicao < 1 || posicao > 9 || notValid[posicao-1]);

        notValid[posicao-1] = 1;

        switch(posicao) {
            case 1:
                if(jogador == 1) {
                    jogo[2][0] = 1;
                }
                else {
                    jogo[2][0] = 2;
                }
                break;
            case 2:
                if(jogador == 1) {
                    jogo[2][1] = 1;
                }
                else {
                    jogo[2][1] = 2;
                }
                break;
            case 3:
                if(jogador == 1) {
                    jogo[2][2] = 1;
                }
                else {
                    jogo[2][2] = 2;
                }
                break;
            case 4:
                if(jogador == 1) {
                    jogo[1][0] = 1;
                }
                else {
                    jogo[1][0] = 2;
                }
                break;
            case 5:
                if(jogador == 1) {
                    jogo[1][1] = 1;
                }
                else {
                    jogo[1][1] = 2;
                }
                break;
            case 6:
                if(jogador == 1) {
                    jogo[1][2] = 1;
                }
                else {
                    jogo[1][2] = 2;
                }
                break;
            case 7:
                if(jogador == 1) {
                    jogo[0][0] = 1;
                }
                else {
                    jogo[0][0] = 2;
                }
                break;
            case 8:
                if(jogador == 1) {
                    jogo[0][1] = 1;
                }
                else {
                    jogo[0][1] = 2;
                }
                break;
            case 9:
                if(jogador == 1) {
                    jogo[0][2] = 1;
                }
                else {
                    jogo[0][2] = 2;
                }
                break;
        }

        if(jogador == 1) {
            jogador = 2;
        }
        else {
            jogador = 1;
        }

        // Verticais
        for(i = 0; i < 3; i++) {
            if(jogo[i][0] > 0 && jogo[i][1] > 0 && jogo[i][2] > 0) {
                if(jogo[i][0] == jogo[i][1] && jogo[i][0] == jogo[i][2]) {
                    winner = 1;
                    break;
                }
            }
        }

        // Horizontais
        for(i = 0; i < 3; i++) {
            if(jogo[0][i] > 0 && jogo[1][i] > 0 && jogo[2][i] > 0) {
                if(jogo[0][i] == jogo[1][i] && jogo[0][i] == jogo[2][i]) {
                    winner = 1;
                    break;
                }
            }
        }

        // Diagonais
        if(jogo[0][0] > 0 && jogo[1][1] > 0 && jogo[2][2] > 0) {
            if(jogo[0][0] == jogo[1][1] && jogo[0][0] == jogo[2][2]) {
                winner = 1;
            }
        }

        if(jogo[0][2] > 0 && jogo[1][1] > 0 && jogo[2][0] > 0) {
            if(jogo[0][2] == jogo[1][1] && jogo[0][2] == jogo[2][0]) {
                winner = 1;
            }
        }
    }

    return 0;
}
