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

	imprimirCamino(actual->predecesor);

	printf("%s", actual->nombre);

	if(actual->visitado_dfs == 1){
		printf(" -> ");
	}

}


void iniciarRecorrido(Grafo* mapa, Nodo** arreglo_puntos, int total_turisticos){

	for(int i= 0; i < total_turisticos; i++){
		arreglo_puntos[i]->visitado_turistico= 0;
	}

	Nodo* origen_actual= arreglo_puntos[0];
	origen_actual->visitado_turistico= 1;


	for(int i= 1; i < total_turisticos; i++){
		Nodo* destino= arreglo_puntos[i];

		if(destino->visitado_turistico == 1){
			continue;
		}

		for(int j= 0; j < mapa->num_nodos; j++){
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

			imprimirCamino(destino);
			origen_actual= destino;
		}
		else{
			printf("Error al encontrar ruta: No existe una ruta entre %s y %s. \n", origen_actual->nombre, destino->nombre);
			return;
		}

	}
}