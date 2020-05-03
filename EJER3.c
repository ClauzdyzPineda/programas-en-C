#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int dado[6], i, cont=0;
	srand(time(NULL));
	for(i=0; i<2; i++){
		dado[i]=1+rand()%6;
		printf("La %d vez que se lanzo el dado, callo en: %d \n",(i+1), dado[i]);
		cont+=dado[i];
	}
	printf("\nLa sumatoria de lanzar dos veces el dado es: %d", cont);
	return 0;
}
