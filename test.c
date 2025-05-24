#include <stdio.h>

#define LINHA 5
#define COLUNA 5
int main()
{

    int lista[LINHA][COLUNA];
    int soma = 1;

    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            soma++;
            lista[i][j] = soma;
            printf("%d ",lista[i][j]);
        }
        printf("\n");
    }
    return 0;
}