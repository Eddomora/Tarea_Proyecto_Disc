#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VERT 50
#define MAX_ARISTAS 100
#define TAM_ARISTA 2
#define MAX 26
#define INFINITO 9999999

typedef struct
{
     char nombre[50];
     double x1, y1, x2, y2;
     char sentido;
} Calle;

typedef struct
{
     char nombre_punto[50];
     char nombre_calle[50];
     double x, y;
} PuntosInteres;

struct grafo
{
     char vertices[MAX_VERT];
     char aristas[MAX_ARISTAS][TAM_ARISTA];
};

int char_a_index(char c);
char index_a_char(int i);
void creacion_grafico(int g_adyacencia[MAX][MAX], struct grafo graf);
int verificar(char letra, struct grafo G);
int distancia();

#endif