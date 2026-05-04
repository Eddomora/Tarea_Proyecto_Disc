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

typedef struct{
	char nombre[50];
	double x, y;
	int es_turistico;

	int adyacentes[10];
	int num_adyacentes;

}Nodo;