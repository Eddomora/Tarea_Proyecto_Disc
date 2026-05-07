#ifndef MAPA_H
#define MAPA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"

typedef struct
{
     double x, y;
} interseccion;

interseccion lista_intersecciones[1000];
interseccion resultado;
int cantidad_vertices = 0;

#endif