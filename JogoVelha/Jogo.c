#include "Jogo.h"
#include <stdio.h>

void LerJogada(char matriz[3][3])
{
    int linha;
    int coluna;
    char jogador;

    printf("Entre com o jogador (x ou o): ");
    scanf("%c", &jogador);
    fflush(stdin);

    if (jogador == 'X')
    {
        jogador = 'x';
    }
    else if (jogador == 'O')
    {
        jogador = 'o';
    }

    if (jogador != 'o' && jogador != 'x')
    {
        printf("\n\n!!! Jogador invalido! Utilize somente 'x' ou 'o' !!!\n\n");
        system("pause");
        return;
    }

    printf("\n\nEntre com a linha: ");
    scanf("%d", &linha);
    fflush(stdin);

    if (linha < 1 || linha > 3)
    {
        printf("\n\n!!! Linha inexistente, utilize apenas de 1 a 3 !!!\n\n");
        system("pause");
        return;
    }

    printf("\n\nEntre com a coluna: ");
    scanf("%d", &coluna);
    fflush(stdin);

    if (coluna < 1 || coluna > 3)
    {
        printf("\n\n!!! Coluna inexistente, utilize apenas de 1 a 3 !!!\n\n");
        system("pause");
        return;
    }

    coluna = coluna -1;
    linha = linha -1;

    if (matriz[linha][coluna] != ' ')
    {
        printf("\n\n!!! Nao e possivel jogar nesta posicao pois alguem ja esta utilizando !!!\n\n");
        system("pause");
        return;
    }

    matriz[linha][coluna] = jogador;
    return;
}

char ValidarVitoria(char matriz[3][3])
{
    int i;
    int j;
    int contador;
    char jogador;

    //Valida jogos na horizontal
    for(i = 0; i < 3; i++)
    {
        contador = 0;
        for (j = 1; j < 3; j++)
        {
            if (matriz[i][0] == matriz[i][j] && matriz[i][j] != ' ')
            {
                jogador = matriz[i][0];
                contador = contador + 1;
            }
            if (contador == 2)
            {
                return jogador;
            }
        }
    }

    //Valida jogos na vertical
    for(i = 0; i < 3; i++)
    {
        contador = 0;
        for (j = 1; j < 3; j++)
        {
            if (matriz[0][i] == matriz[j][i] && matriz[j][i] != ' ')
            {
                jogador = matriz[0][i];
                contador = contador + 1;
            }
            if (contador == 2)
            {
                return jogador;
            }
        }
    }

    //Valida jogos na diagonal de cima pra baixo
    contador = 0;
    for (i = 1; i < 3; i++)
    {
        if (matriz[0][0] == matriz[i][i] && matriz[i][i] != ' ')
        {
            jogador = matriz[0][0];
            contador = contador + 1;
        }
    }
    if (contador == 2)
    {
        return jogador;
    }

    //Valida jogos na diagonal de cima pra baixo
    contador = 0;
    if (matriz[2][0] == matriz[1][1] && matriz[2][0] != ' ')
    {
        jogador = matriz[2][0];
        contador = contador + 1;
    }
    if (matriz[2][0] == matriz[0][2] && matriz[2][0] != ' ')
    {
        jogador = matriz[2][0];
        contador = contador + 1;
    }

    if (contador == 2)
    {
        return jogador;;
    }

    //Valida se acabou com empate
    contador = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matriz[i][j] != ' ')
            {
                contador = contador + 1;
            }
        }
    }
    if (contador == 9)
    {
        return 'E';
    }

    return 'N';
}
