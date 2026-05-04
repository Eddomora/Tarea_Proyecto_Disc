#include "header.h"

void puntosANodo(PuntosInteres *puntos, int num_puntos, Nodo *arreglo_nodosPuntos){
	for(int i= 0; i < num_puntos; i++){
		arreglo_nodosPuntos[i].x= puntos[i].x;
		arreglo_nodosPuntos[i].y= puntos[i].y;
		strcpy(arreglo_nodosPuntos[i].nombre, puntos[i].nombre_punto);

		arreglo_nodosPuntos[i].es_turistico= 1;
		arreglo_nodosPuntos[i].num_adyacentes;
	}
} 