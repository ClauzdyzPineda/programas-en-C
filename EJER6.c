#include <stdio.h>

int vendedor[4][5][30];

void limpiar_pantalla(){
    system("@cls||clear");
}

void print(char txt[]){
	printf("%s\n", txt);
}

void imprimir_delimitador(){
	printf("============================================================================================\n");
}

int sumar_ventas(int array[]){
	int i = 0;
	int suma = 0;
	for(i=0;i<30;i++){
		suma+=array[i];
	}
	return suma;
}

void imprimir_resumen(){
	limpiar_pantalla();
	print("VENDEDOR");
	print("PRODUCTO 1");
	print("tPRODUCTO 2");
	print("tPRODUCTO 3");
	print("tPRODUCTO 4");
	print("tTOTAL VENDIDO");
	
	int i = 0;
	for(i = 0; i<4;i++){
		int suma1 = sumar_ventas(vendedor[i][0]);
		int suma2 = sumar_ventas(vendedor[i][1]);
		int suma3 = sumar_ventas(vendedor[i][2]);
		int suma4 = sumar_ventas(vendedor[i][3]);
		int total = suma1 + suma2 + suma3 + suma4;
		printf("*******************************************************************************\n");
		printf("Vendedor %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i+1,suma1,suma2,suma3,suma4,total);
		print("");
		printf("*******************************************************************************\n");
	}
}

int main(){
	int i = 0;
	int j = 0;
	int k = 0;
	srand(time(NULL));
	for(i = 0; i<4;i++){
		imprimir_delimitador();
		printf("Detalle de ventas para: VENDEDOR %d\n",(i+1));
		for(j=0;j<5;j++){
			printf("Producto %d\n", (j+1));
			for(k=0;k<30;k++){
				
				int r = rand() %101;
				printf("%d,",r);
				vendedor[i][j][k] = r; 
			}
			print("");
		}
		imprimir_delimitador();
	}
	print("");
	print("");
	print("Presione una tecla para continuar y visualizar el resumen\n");
	getch();
	imprimir_resumen();
	return 0;
}
