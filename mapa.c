#include "mapa.h";

void crear_vertices(Calle lista_calles[50], int *cant_calles)
{
     for (int i = 0; i < cant_calles; i++)
     {
          for (int j = i + 1; j < cant_calles; j++)
          {
               if (lista_calles[i].sentido != lista_calles[j].sentido)
               {
                    if (chequeo_interseccion(lista_calles[i], lista_calles[j], &resultado))
                    {

                         int duplicado = 0;
                         for (int chequeo = 0; chequeo < cantidad_vertices; chequeo++)
                         {
                              if (resultado.x == lista_intersecciones[chequeo].x && resultado.y == lista_intersecciones[chequeo].y)
                              {
                                   duplicado = 1;
                              }
                         }
                         if (!duplicado)
                         {
                              lista_intersecciones[cantidad_vertices] = (resultado);
                              cantidad_vertices++;
                         }
                    }
               }
          }
     }
}

int chequeo_interseccion(Calle calle1, Calle calle2, interseccion *resultado)
{
     double denominador = (calle1.x1 - calle1.x2) * (calle2.y1 - calle2.y2) - (calle1.y1 - calle1.y2) * (calle2.x1 - calle2.x2);
     if (denominador == 0)
          return 0;

     double t = ((calle1.x1 - calle2.x1) * (calle2.y1 - calle2.y2) - (calle1.y1 - calle2.y1) * (calle2.x1 - calle2.x2)) / denominador;
     double u = ((calle1.x1 - calle1.x2) * (calle1.y1 - calle2.y1) - (calle1.y1 - calle1.y2) * (calle1.x1 - calle2.x1)) / denominador;
     if (t >= 0 && t <= 1 && u >= 0 && u <= 1)
     {
          resultado->x = calle1.x1 + t * (calle1.x2 - calle1.x1);
          resultado->y = calle1.y1 + t * (calle1.y2 - calle1.y1);
          return 1;
     }
     return 0;
}
