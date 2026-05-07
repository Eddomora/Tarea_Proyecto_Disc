#ifndef CAMINOS_H
#define CAMINOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"

void dijkstra(int Grafo[MAX][MAX], int n, int nodo_inicio, int nodo_final);
void orientacion1(int g_adyacencia[MAX][MAX], struct grafo graf);
void orientacion2(int g_adyacencia[MAX][MAX], struct grafo graf);
void orientacion3(int g_adyacencia[MAX][MAX], struct grafo graf);
void orientacion4(int g_adyacencia[MAX][MAX], struct grafo graf);

#endif