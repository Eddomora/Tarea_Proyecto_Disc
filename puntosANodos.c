#include "header.h"

void puntosANodo(Grafo* mapa){

	for(int i= 0; i < mapa->num_puntos; i++){
		int indice= mapa->num_nodos;

		mapa->grafo[indice].x= mapa->puntos[i].x;
		mapa->grafo[indice].y= mapa->puntos[i].y;

		strcpy(mapa->grafo[indice].nombre, mapa->puntos[i].nombre_punto);

		mapa->grafo[indice].es_turistico= 1;
		mapa->grafo[indice].num_adyacentes= 0;

		mapa->num_nodos++;
	}
}