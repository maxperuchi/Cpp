#include "Util.h"

void LimpaMatriz(char matriz[3][3])
{
    int i;
    int j;

    for (i=0;i < 3; i++)
    {
        for (j=0;j< 3;j++)
        {
            matriz[i][j] = ' ';
        }
    }
}
