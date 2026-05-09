#include "header.h"


int dfs(Nodo* actual, Nodo* destino){

	actual->visitado_dfs= 1;


	if(actual == destino){
		return 1;
	}

	for(int i= 0; i < actual->num_adyacentes; i++){
		Nodo* vecino= actual->adyacentes[i];

		if (vecino->visitado_dfs == 0){
			vecino->predecesor= actual;

			if(dfs(vecino, destino) == 1){
				return 1;
			}

		}
	}

	return 0; //Callejón sin salida
}



void imprimirCamino(Nodo* actual){

	if(actual == NULL){
		return;
	}

	if(actual->predecesor != NULL){
		imprimirCamino(actual->predecesor);
		printf(" -> ");
	}

	printf("[%s]", actual->nombre);

}


void iniciarRecorrido(Grafo* mapa, Nodo** arreglo_puntos, int total_turisticos){

	for(int i= 0; i < total_turisticos; i++){
		arreglo_puntos[i]->visitado_turistico= 0;
	}

	Nodo* origen_actual= arreglo_puntos[0]; //Orden según lo ingresado en el archivo
	origen_actual->visitado_turistico= 1;


	for(int i= 1; i < total_turisticos; i++){ //Ciclo para para cambiar el destino
		Nodo* destino= arreglo_puntos[i];

		if(destino->visitado_turistico == 1){ //Si ya se pasó por este punto, se salta
			continue;
		}

		for(int j= 0; j < mapa->num_nodos; j++){ //Limpiar intersecciones para pasarselas al dfs
			mapa->grafo[j].visitado_dfs= 0;
			mapa->grafo[j].predecesor= NULL;
		}

		if(dfs(origen_actual, destino) == 1){

			Nodo* rastro= destino;
			while(rastro != NULL){
				if(rastro->es_turistico == 1){
					rastro->visitado_turistico= 1;
				}
				rastro= rastro->predecesor;
			}

			printf("Tramo: %s a %s\n", origen_actual->nombre, destino->nombre);
			printf("Camino: ");
			imprimirCamino(destino);
			printf("\n\n");
			origen_actual= destino;
		}
		else{
			printf("Error al encontrar ruta: No existe una ruta entre %s y %s. \n", origen_actual->nombre, destino->nombre);
			return;
		}

	}
}