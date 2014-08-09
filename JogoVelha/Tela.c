#include "Tela.h"
#include <stdio.h>

void LimpaTela()
{
    system("cls");
}

void ImprimirJogo(char matriz[3][3])
{
    ImprimirBoasVindas();
    int i;
    int j;

    printf("   1 2 3\n\n");

    for (i = 0; i < 3; i++)
    {
        printf("%d ",i+1);
        for (j = 0; j < 3; j++)
        {
            printf("|%c",matriz[i][j]);
        }

        printf("|\n");

        if (i < 2)
        {
            printf("  -------\n");
        }
    }

    printf("\n");
}

void ImprimirBoasVindas()
{
    printf("=======================================");
    printf("\nJogo da Velha com MATRIZ by Max Peruchi\n");
    printf("=======================================\n\n");
}
