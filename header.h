#ifndef HEADER_H
#define HEADER_H 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nombre[50];
    double x1, y1, x2, y2;
    char sentido;
} Calle;

typedef struct{
    char nombre_punto[50];
    char nombre_calle[50];
    double x, y;
}PuntosInteres;

//grafo
typedef struct Nodo{
	char nombre[100];
	double x, y;
	int es_turistico;

	struct Nodo* adyacentes[15];
	int num_adyacentes;
}Nodo;

typedef struct{
	Calle calles[50];
	int num_calles;
	PuntosInteres puntos[50];
	int num_puntos;
	Nodo grafo[100];
	int num_nodos;
} Grafo;


int leerArchivo(char* nombreArchivo, Grafo* mapaTuristico);
int contieneCalleExacta(const char* nombreNodo, const char* nombreCalle)
void crearGrafo(Grafo* mapa);
void puntosANodo(Grafo* mapa);
int nodoIntersecciones(Calle *calles, int num_calles, Nodo *arreglo_nodosIntersecciones);

#endif