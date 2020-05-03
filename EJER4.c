#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANTIDAD_DADOS_LANZADOS 36000



int main()
{
    srand(time(NULL));
    int r, sumaDados, i, j;
    // 2 = 0,
    // 3 = 1,
    // 4 = 2,
    // 5 = 3,
    // 6 = 4,
    // 7 = 5,
    // 8 = 6,
    // 9 = 7,
    // 10 = 8,
    // 11 = 9,
    // 12 = 10,
    int cantidadSumasDados[11] = {0};

    for (i = 0; i < CANTIDAD_DADOS_LANZADOS; i++)
    {
      
        sumaDados = 0;

       
        for (j = 0; j < 2; j++)
        {
            r = rand() % 6 + 1;
            sumaDados += r;
        }

        switch (sumaDados)
        {
        case 2:
            cantidadSumasDados[0]++;
            break;
        case 3:
            cantidadSumasDados[1]++;
            break;
        case 4:
            cantidadSumasDados[2]++;
            break;
        case 5:
            cantidadSumasDados[3]++;
            break;
        case 6:
            cantidadSumasDados[4]++;
            break;
        case 7:
            cantidadSumasDados[5]++;
            break;
        case 8:
            cantidadSumasDados[6]++;
            break;
        case 9:
            cantidadSumasDados[7]++;
            break;
        case 10:
            cantidadSumasDados[8]++;
            break;
        case 11:
            cantidadSumasDados[9]++;
            break;
        case 12:
            cantidadSumasDados[10]++;
            break;
        }
    }

    // Mostrando los valores
    printf("Resultado de la sumatoria de los dados lanzados\n\n");
    printf("[2]\t[3]\t[4]\t[5]\t[6]\t[7]\t[8]\t[9]\t[10]\t[11]\t[12]\t\n");
    printf("%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t", cantidadSumasDados[0], cantidadSumasDados[1], cantidadSumasDados[2], cantidadSumasDados[3], cantidadSumasDados[4], cantidadSumasDados[5], cantidadSumasDados[6], cantidadSumasDados[7], cantidadSumasDados[8], cantidadSumasDados[9], cantidadSumasDados[10]);

    return 0;
}
