#ifndef MAPA_H
#define MAPA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

typedef struct
{
     double x, y;
} interseccion;

interseccion lista_intersecciones[1000];
interseccion resultado;
int cantidad_vertices = 0;

#endif