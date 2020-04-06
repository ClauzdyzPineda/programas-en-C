/*
Se requiere crear un programa utilizando LISTAS para registrar y controlar un inventario de equipo informatico.
Para cada elemento de inventario tenemos:
	Codigo int
	Descripcion char(100)
	Modelo char(100)
	FechaIngreso char(10)
Crear las funciones requeridas de menú, agregar, mostrar, buscar, eliminar y salir del programa.*/

#include <stdio.h>
#include <stdlib.h>

//Definir la estructura a utilizar
typedef struct{
	int codigo;
	char descripcion[100];
	char modelo[100];
	char fechaingreso[10];
	struct Nodo *sgte;
}Nodo;

//Crear punteros para el primero y ultimo elemento de la lista
Nodo *primero = NULL;
Nodo *ultimo = NULL;

//Crear las funciones para el manejo de los nodos
//Funcion para menu principal
int menu(void){
	//Variable local
	int opcion = 0;
	//Limpiar pantalla
	system("cls");
	//Crear el menu
	printf("\n\n=================================\n"
			"\t\tMENU PRINCIPAL\n"
			"=================================\n"
			"[1] Agregar inventario\n"
			"[2] Buscar inventario\n"
			"[3] Mostrar inventario\n"
			"[4] Eliminar registro de inventario\n"
			"[5] Salir\n\n"
			"Digite su opcion: ");
	scanf("%d",&opcion);
	return opcion;
}//Fin de menu

//Funcion para agregar elementos a la lista
void agregarNodo(void){
	//Reservar en memoria el nuevo nodo
	Nodo *nodo = malloc(sizeof(Nodo));
	//Limpiar pantalla
	system("cls");
	//Solicitar los valores del nodo
	printf("\n====================================\n"
	"\tREGISTRO DE DATOS DEL INVENTARIO\n"
	"====================================\n");
	printf("Digite codigo: ");		
	scanf("%d",&nodo->codigo);
	printf("Digite descripcion: ");	
	scanf(" %[^\n]",nodo->descripcion);
	printf("Digite modelo: "); 			
	scanf(" %[^\n]",nodo->modelo);
	printf("Digite fecha ingreso: ");	
	scanf(" %s",nodo->fechaingreso);
	//Apuntar a NULL el siguiente elemento de la lista
	nodo->sgte = NULL;
	//Preguntar si la lista esta vacia
	if(primero == NULL){
		primero = nodo; 		
		ultimo = nodo;
	}else{
		ultimo->sgte = nodo; 
		ultimo = nodo;
	}
}//Fin de agregarNodo

//Funcion para mostrar nodos
void mostrarNodo(void){
	//Limpiar pantalla
	system("cls");
	//Crear puntero centinela para el recorrido de la lista
	Nodo *i = primero;
	//Preguntar si la lista esta vacia
	if(i != NULL){
		printf("\n\n=====================================\n"
		"\tELEMENTOS DEL INVENTARIO\n"
		"=====================================\n");
		
		//RECORRIENDO LA LISTA
		while(i != NULL){
			printf("\nCodigo: %d",i->codigo);
			printf("\nDescripcion: %s",i->descripcion);
			printf("\nModelo: %s",i->modelo);
			printf("\nFecha ingreso: %s",i->fechaingreso);
			printf("\n-------------------------------------\n");
			
			//Mover el valor de i al siguiente nodo
			i = i->sgte;
		}//Fin de while
	}else{
		printf("\n\n<<NO HAY ELEMENTOS PARA MOSTRAR>>\n");
	}
	system("pause");
}//Fin de mostrarNodo

//Funcion para buscar
void buscarNodo(void){
	//Limpiar pantalla
	system("cls");
	//Crear puntero centinela para el recorrido de la lista
	Nodo *i = primero;
	//Variable local
	char descripcion[100];
	int encontrado = 0;//Indicar si el nodo fue encontrado
	
	//Preguntar si la lista esta vacia
	if(i != NULL){
		printf("\n\n=====================================\n"
		"\tBUSQUEDA DE INVENTARIO\n"
		"=====================================\n");
		
		//PEDIR el valor a buscar en la lista
		printf("\nDigite descripcion del inventario a buscar: ");
		scanf(" %[^\n]",&descripcion);
		
		//RECORRIENDO LA LISTA
		while(i != NULL){
			//Preguntar si son iguales los valores del nodo con el digitado
			if(strcmp(i->descripcion,descripcion)==0){//Si es valor caracter
			//if(i->codigo == descripcion){//Solo si es para valor numerico
				printf("\nCodigo: %d",i->codigo);
				printf("\nDescripcion: %s",i->descripcion);
				printf("\nModelo: %s",i->modelo);
				printf("\nFecha ingreso: %s",i->fechaingreso);
				encontrado = 1;//Indicar que el nodo fue encontrado
				break;	
			}//Fin de if
			
			//Mover el valor de i al siguiente nodo
			i = i->sgte;
		}//Fin de while
		
		//Preguntar si nunca entro por el while
		if(encontrado==0)
			printf("\n<<REGISTRO DE INVENTARIO NO ENCONTRADO>>\n");
	}else{
		printf("\n\n<<NO HAY ELEMENTOS PARA BUSCAR>>\n");
	}
	system("pause");
}//Fin de buscarNodo

//Funcion eliminar
void eliminarNodo(void){
	//limpiar pantalla
	system("cls");
	//Variable local
	char descripcion[100];
	Nodo *lista = primero;//Puntero auxiliar 
	//Preguntar si la lista esta vacia
	if(lista != NULL){
		printf("\n\n=====================================\n"
				"\tELIMINACION DE REGISTROS DE INVENTARIO\n"
				"=====================================\n");
		printf("\nDigite valor de descripcion: ");
		scanf(" %[^\n]",&descripcion);
		
		//Puntero axuliar
		Nodo *aux_borrar;
		aux_borrar = lista;
		Nodo *anterior = NULL;
		//Recorrer la lista
		while(aux_borrar !=NULL &&(strcmp(aux_borrar->descripcion,descripcion)!=0)){
			anterior 	= aux_borrar;
			aux_borrar 	= aux_borrar->sgte;
		}//Fin de while
		//Preguntar si fue encontrado el nodo a eliminar
		if(aux_borrar == NULL){
			printf("\n<<DESCRIPCION DE INVENTARIO NO ENCONTRADA>>\n");
		}else if(anterior == NULL){
			lista = lista->sgte;
			free(aux_borrar);//Eliminar nodo
			printf("\n\n<<ELEMENTO ELIMINADO DEL INVENTARIO 2>>\n");
		}else{
			anterior->sgte = aux_borrar->sgte;
			free(aux_borrar);
			printf("\n\n<<ELEMENTO ELIMINADO DEL INVENTARIO 3>>\n");
		}
	}else
		printf("\n\n<<NO HAY ELEMENTOS PARA ELIMINAR>>\n");
	system("pause");	
}//Fin de eliminar

int main(void){
	//Declarar variables locales
	int salir = 0;
	while(salir==0){
		switch(menu()){
			case 1:
				agregarNodo();
				break;
			case 2:
				buscarNodo();
				break;
			case 3:
				mostrarNodo();
				break;
			case 4:
				eliminarNodo();
				break;
			case 5:
				salir=1;//Salir del programa
				break;
			default:
				printf("\n\n<<OPCION INCORRECTA\n");
				system("pause");
		}//Fin de switch
	}//Fin de while
	return 0;
}//Fin de main
