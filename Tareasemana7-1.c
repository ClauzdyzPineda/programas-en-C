#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definir la estructura a utilizar
typedef struct{
	int codigo;
	char nombreCliente[100];
	char direccion[100];
	char fechaNacimiento[10];
	struct Nodo *sgte;
}Nodo;

//Crear punteros para el primero y ultimo elemento de la lista
Nodo *primero = NULL;
Nodo *ultimo = NULL;

void Menu(void){
     
     system("cls");
     
     printf("|==========================================|\n");
     printf("|              Menu principal              |\n");
     printf("|==========================================|\n");
     printf("|  [1] Agregar datos a la lista            |\n");
     printf("|  [2] Salir                               |\n");
     printf("|==========================================|\n");
     
}

void SubMenu(char *nameSubMenu){
     
     system("cls");
     // 43 espacios
     //      0123456789012345678901234567890123456789012
     printf("============================================\n");
     printf("*        Menu secundario                  *\n");
     printf("* %s", nameSubMenu);
     int i;
     for(i=strlen(nameSubMenu);i<=39;i++)
     {
      printf(" ");
     }
     printf("   *\n");
     printf("|============================================|\n");
     printf("|  [1] Insertar                              |\n");
     printf("|  [2] Buscar                                |\n");
     printf("|  [3] Modificar                             |\n");
     printf("|  [4] Eliminar                              |\n");
     printf("|  [5] Salir                                 |\n");
     printf("|============================================|\n");
     
}

int main(int argc, char *argv[])
{
    
    int sistemExit = 0;
    
    while(sistemExit == 0){
    	
    	int opMenu, opSubMenu;
    
	    Menu();
	    scanf("%d",&opMenu);
	    switch(opMenu){
	       	case 1:
	            SubMenu("     MENU DE REGISTRO DE CLIENTES");
	            scanf("%d",&opSubMenu);
	            switch(opSubMenu){
	            	case 1:
	            		system("cls");
	            		printf("\nAgregar  Cliente\n");
	            		agregarNodo();
	            		system("pause");
	            		break;
	            	case 2:
	            		printf("\nBuscar Cliente\n");
	            		buscarNodo();
	            		system("pause");
	            		break;
	            	case 3:
	            		printf("\nModificar Cliente\n");
	            	    modificarNodo();
	            		system("pause");
	            		break;
	            	case 4:
	            		system("cls");
	            		printf("\nEliminar Clientes\n");
	            		eliminarNodo();
	            		system("pause");
	            		break;
	            	default:
	            		system("cls");
	            		break;
				}
	    	break;
	    case 2:
	        	sistemExit = 1;
	        	break;
	        default:
	        	printf("Opcion incorrecta");
	        	system("pause");
	        	break;
	    }
    	
	}
  
  return 0;
}


//Funcion para agregar elementos a la lista
void agregarNodo(void){
	//Reservar en memoria el nuevo nodo
	Nodo *nodo = malloc(sizeof(Nodo));
	//Limpiar pantalla
	system("cls");
	//Solicitar los valores del nodo
	printf("\n====================================\n");
	printf("REGISTRO DE DATOS DEL CLIENTE");
	printf("\n====================================\n");
	printf("Ingrese codigo: ");		
	scanf("%d", &nodo->codigo);
	printf("Ingrese el nombre: ");	
	scanf(" %[^\n]",nodo->nombreCliente);
	printf("Ingrese la direccion: "); 			
	scanf(" %[^\n]",nodo->direccion);
	printf("Ingrese fecha de nacimiento: ");	
	scanf(" %s",nodo->fechaNacimiento);
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


//Funcion para buscar
void buscarNodo(void){
	//Limpiar pantalla
	system("cls");
	//Crear puntero centinela para el recorrido de la lista
	Nodo *i = primero;
	//Variable local
	char nombreCliente[100];
	int encontrado = 0;//Indicar si el nodo fue encontrado
	
	//Preguntar si la lista esta vacia
	if(i != NULL){
		printf("\n\n=====================================\n");
		printf("BUSQUEDA DE CLIENTES");
		printf("\n\n=====================================\n");
		
		//PEDIR el valor a buscar en la lista
		printf("\nIngrese el nombre del cliente a buscar: ");
		scanf(" %[^\n]",&nombreCliente);
		
		//RECORRIENDO LA LISTA
		while(i != NULL){
			//Preguntar si son iguales los valores del nodo con el digitado
			if(strcmp(i->nombreCliente,nombreCliente)==0){//Si es valor caracter
			//if(i->codigo == descripcion){//Solo si es para valor numerico
				printf("\nCodigo: %d",i->codigo);
				printf("\nNombre: %s",i->nombreCliente);
				printf("\nDireccion: %s",i->direccion);
				printf("\nFecha de nacimiento: %s",i->fechaNacimiento);
				encontrado = 1;//Indicar que el nodo fue encontrado
				break;	
			}//Fin de if
			
			//Mover el valor de i al siguiente nodo
			i = i->sgte;
		}//Fin de while
		
		//Preguntar si nunca entro por el while
		if(encontrado==0)
			printf("\n***REGISTRO DE INVENTARIO NO ENCONTRADO***\n");
	}else{
		printf("\n\n***NO HAY ELEMENTOS PARA BUSCAR***\n");
	}
	system("pause");
}//Fin de buscarNodo

//Funcion para modificar
void modificarNodo(void){
	Nodo *actual = (Nodo*) malloc(sizeof(Nodo));
	actual = primero;
	char clienteBuscado[100];
	int encontrado = 0;
	if(primero != NULL){ 
	printf(" Ingrese el nombre de cliente para modificar: ");
	scanf(" %[^\n]", &clienteBuscado);
		while(actual != NULL){
		
		if(strcmp(actual->nombreCliente,clienteBuscado)==0){
			printf("\n El nombre con el dato ( %s ) Encontrado\n\n", clienteBuscado);
			printf("\n Ingrese el nuevo dato para el nodo: ");
			scanf(" %[^\n]", actual->nombreCliente);
			printf(" Cliente modificado\n\n");
			encontrado = 1;
		}
		
		actual = actual -> sgte;
		}
		if(encontrado == 0){
			printf("\n Cliente  no encontrado\n\n");
		}
	
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
	system("pause");
}


//Funcion eliminar
void eliminarNodo(void){
	//limpiar pantalla
	system("cls");
	//Variable local
	char nombreCliente[100];
	Nodo *lista = primero;//Puntero auxiliar 
	//Preguntar si la lista esta vacia
	if(lista != NULL){
		printf("\n\n=====================================\n");
		printf("ELIMINACION DE REGISTROS DE CLINETES");
	    printf("\n\n=====================================\n");
		printf("\nDigite el nombre del cliente: ");
		scanf(" %[^\n]",&nombreCliente);
		
		//Puntero axuliar
		Nodo *aux_borrar;
		aux_borrar = lista;
		Nodo *anterior = NULL;
		//Recorrer la lista
		while(aux_borrar !=NULL &&(strcmp(aux_borrar->nombreCliente,nombreCliente)!=0)){
			anterior 	= aux_borrar;
			aux_borrar 	= aux_borrar->sgte;
		}//Fin de while
		//Preguntar si fue encontrado el nodo a eliminar
		if(aux_borrar == NULL){
			printf("\n<<NOMBRE  DE CLIENTE NO ENCONTRADA>>\n");
		}else if(anterior == NULL){
			lista = lista->sgte;
			free(aux_borrar);//Eliminar nodo
			printf("\n\n***ELEMENTO ELIMINADO DEL REGISTRO DE CLIENTES 2***\n");
		}else{
			anterior->sgte = aux_borrar->sgte;
			free(aux_borrar);
			printf("\n\n***ELEMENTO ELIMINADO DEL REGISTRO DE CLIENTES 3***\n");
		}
	}else
		printf("\n\n***NO HAY ELEMENTOS PARA ELIMINAR***\n");
	system("pause");	
}//Fin de eliminar


