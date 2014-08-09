#include <stdio.h>
#include <stdlib.h>
#include "Tela.h"
#include "Util.h"
#include "Jogo.h"

int main()
{
    //Setup

    char matrizJogo[3][3];

    LimpaMatriz(matrizJogo);

    ImprimirJogo(matrizJogo);

    //Main loop

    while(1)
    {
        LerJogada(matrizJogo);

        LimpaTela();
        ImprimirJogo(matrizJogo);

        char retorno = ValidarVitoria(matrizJogo);
        if (retorno != 'E' && retorno != 'N')
        {
            printf("\n!!! Fim de jogo! O jogador '%c' venceu !!!\n\n", retorno);
            system("pause");
            return 0;
        }
        else if (retorno == 'E')
        {
            printf("\n!!! Fim de jogo! Empate !!!\n\n");
            system("pause");
            return 0;
        }
    }

    return 0;
}
