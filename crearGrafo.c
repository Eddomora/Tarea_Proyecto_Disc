#include "header.h"


//funciones para qsort, ordenan segun distancia
int compararX(const void* a, const void* b){
	Nodo* nodoA= *(Nodo** )a; //Casteo para guardar un puntero simple
	Nodo* nodoB= *(Nodo** )b;

	if(nodoA->x < nodoB->x) return -1;
	if(nodoA->x > nodoB->x) return 1;
	return 0;
}

int compararY(const void* a, const void* b) {
    Nodo* nodoA = *(Nodo** )a; //Casteo para guardar un puntero simple
    Nodo* nodoB = *(Nodo** )b;
    
    if (nodoA->y < nodoB->y) return -1;
    if (nodoA->y > nodoB->y) return 1;
    return 0;
}

void crearGrafo(Grafo *mapa){

	mapa->num_nodos= nodoIntersecciones(mapa->calles, mapa->num_calles, mapa->grafo);
	puntosANodo(mapa);


	for(int i= 0; i < mapa->num_calles; i++){ //Recorremos las calles
		Nodo* nodos_calle[100];
		int count= 0;


		for(int j= 0; j < mapa->num_nodos; j++){ //Recorremos los nodos
			int en_calle= 0;

			if(mapa->grafo[j].es_turistico == 0){ // Si no es turistico se busca el nombre de la calle actual en el del nodo.
				if (strstr(mapa->grafo[j].nombre, mapa->calles[i].nombre) != NULL){
					en_calle= 1;
				}

			}
			else{
				for (int k= 0; k < mapa->num_puntos; k++){ //Si es turistico se recorre el arreglo con los puntos para verificar si la calle es igual
					if(strcmp(mapa->grafo[j].nombre, mapa->puntos[k].nombre_punto) == 0 &&
						strcmp(mapa->puntos[k].nombre_calle, mapa->calles[i].nombre) == 0){
						en_calle= 1;
						break;
					}
				}
			}

			if (en_calle == 1){
				nodos_calle[count]= &mapa->grafo[j]; //Puntero al arreglo en el struct
				count++;
			}

		}

		if (count > 1){

			if(mapa->calles[i].sentido == 'X'){ //Si el sentido es X se ordenarán según la coordenada en el eje X, los más cercanos se conectarán
				qsort(nodos_calle, count, sizeof(Nodo*), compararX);
			}

			else if (mapa->calles[i].sentido == 'Y') { //Si el sentido es Y se ordenarán según la coordenada en el eje Y, los más cercanos se conectarán
                qsort(nodos_calle, count, sizeof(Nodo*), compararY); 
            }
		}

		for (int y = 0; y < count - 1; y++) {

                nodos_calle[y]->adyacentes[nodos_calle[y]->num_adyacentes] = nodos_calle[y+1]; //Conec
                nodos_calle[y]->num_adyacentes++;

                nodos_calle[y+1]->adyacentes[nodos_calle[y+1]->num_adyacentes] = nodos_calle[y];
                nodos_calle[y+1]->num_adyacentes++;
        }
	}
}