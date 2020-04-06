#include <conio.h>
#include <stdio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;	
}nodo;

nodo* primero = NULL;


void insertarNodo();
void desplegarPila();
void modificarNodo();
void eliminarNodo();
void buscarNodo();

int main(){ 
	int opcionMenu = 0;
	do{
		printf("\n|---------------------------------|");
		printf("\n|      * CONCEPTO DE PILA*        |");
		printf("\n|----------------|----------------|");
		printf("\n|  1. Insertar   |  4. Eliminar   |");
		printf("\n|  2. Buscar     |  5. Desplegar  |");
		printf("\n|  3. Modificar  |  6. Salir      |");
		printf("\n|----------------|----------------|");
		printf("\n\n Escoja una opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTAR NODO EN LA PILA \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n BUSCAR UN NODO EN LA PILA \n\n");
				buscarNodo();
				break;
			case 3:
				printf("\n\n MODIFICAR UN NODO DE LA PILA \n\n");
				modificarNodo();
				break;
			case 4:
				printf("\n\n ELIMINAR UN NODO DE LA PILA \n\n");
				eliminarNodo();
				break;	
			case 5:
				printf("\n\n DESPLEGAR PILA DE NODOS \n\n");
				desplegarPila();
				break;
			case 6:
				printf("\n\n Programa finalizando...");
				break;
			default:
				printf("\n\n Opcion No valida \n\n");	
							
		}
		
	}while(opcionMenu != 6);	
	return 0;
}

//13, 16, 18, 20
//primero = 18
//13 -> 16, 18 -> 20 -> null 

void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf("Ingresar el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	nuevo->siguiente = primero;
	primero = nuevo;	
}

void buscarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	if(primero != NULL){ 
	printf(" Ingrese el dato del Nodo a buscar: ");
	scanf("%d", &nodoBuscado);
		while(actual != NULL){
		
		if(actual->dato == nodoBuscado){
			printf("\n El nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
			encontrado = 1;
		}
		
		actual = actual -> siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo  no encontrado\n\n");
		}
	
	}else{
		printf("\n La pila se encuentra vacia\n\n");
	}
	
}

void modificarNodo(){
		nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	if(primero != NULL){ 
	printf(" Ingrese el dato del Nodo a buscar para modificar: ");
	scanf("%d", &nodoBuscado);
		while(actual != NULL){
		
		if(actual->dato == nodoBuscado){
			printf("\n El nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
			printf("\n Ingrese el nuevo dato para el nodo: ");
			scanf("%d", &actual->dato);
			printf(" Nodo modificado\n\n");
			encontrado = 1;
		}
		
		actual = actual -> siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo  no encontrado\n\n");
		}
	
	}else{
		printf("\n La pila se encuentra vacia\n\n");
	}
}

void eliminarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del Nodo a buscar para eliminar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){ 
		while(actual != NULL && encontrado != 1){
		
		if(actual->dato == nodoBuscado){
		
			if(actual == primero){
				primero = primero -> siguiente;	
				}else{
				anterior -> siguiente = actual -> siguiente;
				}
			printf("\n El nodo ha sido eliminado con exito");
			encontrado = 1;
		}
		anterior = actual;
		actual = actual -> siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo  no encontrado\n\n");
		}else{
			free(anterior);
		}
	
	}else{
		printf("\n La pila se encuentra vacia\n\n");
	
	}
}



void desplegarPila(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero != NULL){ 
		while(actual != NULL){
		printf("\n %d", actual -> dato);
		actual = actual -> siguiente;
		}
	
	}else{
		printf("\n La pila se encuentra vacia\n\n");
	}	
}

