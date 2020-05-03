#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Asientos_v 10

 
int asignarAsiento(int [], int, int);
void pasaje(int);
void diagrama(int [], int);
 
main()
{
    srand(time(NULL));
    int asientos[Asientos_v] = {0};
    int i, num, cont = 0;
 
    printf("SISTEMA DE RESERVACION DE AEROLINEAS\n\n");
 
    diagrama(asientos, Asientos_v);
 
    while (cont <= Asientos_v - 1){
 
        printf("\n***********************************************\n");
        printf("Por favor ingrese 1 para clase ejecutivo\n"
               "Por favor ingrese 2 para clase economica\n");
        scanf("%d", &num);
 
        while (num > 2){
            printf("Numero no valido\n\n");
            printf("Por favor ingrese 1 para clase ejecutivo\n"
                   "Por favor ingrese 2 para clase economica\n");
            scanf("%d", &num);
             
        }
 
        if ((asignarAsiento(asientos, Asientos_v, num)) != 0)
            cont++;
 
        diagrama(asientos, Asientos_v);
    }
    printf("\n------------------------------------\n");
    printf("VUELO COMPLETO\n");
	printf("\nEl PROXIMO VUELO SALE EN 3 HORAS\n\n");
    printf("\n------------------------------------\n");
 
    return 0;
}
  
int asignarAsiento(int a[], int size, int n)
{
    char rta[1];
    int i, status = 0;
    static int cont1 = 0, cont2 = 0;
 
    switch(n){
        case 1:                     
            if (cont1 < size / 2){
                while (status == 0){
                    i = rand() % size /2;
                    if(a[i] == 0){
                        a[i] = 1;
                        pasaje(i);
                        cont1++;
                        status = 1;
                    }
                }
            }
            else{
                printf("La clase ejecutiva esta llena. "
                       "Le gustaria q le asignemos un lugar en la clase "
                       "economica? (s/n)");
                scanf("%s", rta);
 
                if(rta[0] == 's' || rta[0] == 'S'){
                    while (status == 0){
                        i = size / 2 + rand() % size / 2;
                        if(a[i] == 0){
                            a[i] = 1;
                            pasaje(i);
                            cont2++;
                            status = 1;
                        }
                    }
                }
 
                else{
                    printf("\nEl PROXIMO VUELO SALE EN 3 HORAS\n\n");
                    return 0;
                }
            }
 
            break;
 
 
        case 2:                   
            if (cont2 < size / 2){
                while (status == 0){
                    i = size / 2 + rand() % size / 2;
                    if (a[i] == 0){
                        a [i] = 1;
                        pasaje(i);
                        cont2++;
                        status = 1;
                    }
                }
            }
 
            else{
                printf("La clase economica esta completa. "
                       "Le gustaria q le asignemos un lugar en la clase "
                       "ejecutiva? (s/n)");
                scanf("%s", rta);
 
                if(rta[0] == 's' || rta[0] == 'S'){
                    while (status == 0){
                        i = rand() % size /2;
                        if(a[i] == 0){
                            a[i] = 1;
                            pasaje(i);
                            cont1++;
                            status = 1;
                        }
                    }
                }
 
                else{
                    printf("\nEL PROXIMO VUELO SALE EN 3 HORAS\n\n");
                    return 0;
                }
            }
 
            break;
    }
 
}

 
void pasaje(int numAsiento)
{
    printf("\n************************\n");
    printf("AEROLINEA\n");
    printf("Pase de abordaje\n");
    if (numAsiento >= 0 && numAsiento <= 4){
        printf("Asiento nº %d\n", numAsiento + 1);
        printf("clase ejecutiva\n");
    }
    else{
        printf("Asiento nº %d\n", numAsiento + 1);
        printf("clase economica\n");
    }
    printf("\n************************\n");
}
 
void diagrama(int a[], int size)
{
    int i;
 
    printf("\n");
    printf("%30s\n\n", "DIAGRAMA AVION");
    printf("%15s %26s\n", "CLASE EJECUTIVA", "CLASE ECONOMICA");
    printf("**********************");
    printf("  ***********************\n");
        for (i = 0; i <= size - 1; i++)
            printf("%-5d", a[i]);
    printf("\n\n");
 
}
