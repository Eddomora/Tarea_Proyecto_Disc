#include "header.h"

int nodoIntersecciones(Calle* calles, int num_calles, Nodo* arreglo_nodosIntersecciones){
	int contador_intersecciones= 0;


	for(int i= 0; i < num_calles; i++){
		for(int j= i+1; j < num_calles; j++){

			
		double x1= calles[i].x1;
		double y1= calles[i].y1;
		double x2= calles[i].x2;
		double y2= calles[i].y2;

		double x3= calles[j].x1;
		double y3= calles[j].y1;
		double x4= calles[j].x2;
		double y4= calles[j].y2;

		double denominador= (x1 - x2) * (y3 - y4) - (y1 -y2) * (x3 - x4);

		if(denominador != 0){
			double t= ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominador;
			double u= ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / denominador;

			if(t >= 0.0 && t <= 1.0 && u >= 0.0 && u <= 1.0){
				double x_cruce=  x1 + t * (x2-x1);
				double y_cruce= y1 + t * (y2 - y1);

				int existe_duplicado = 0;
                for (int k = 0; k < contador_intersecciones; k++) {
                    if (fabs(arreglo_nodosIntersecciones[k].x - x_cruce) < 0.001 &&
                        fabs(arreglo_nodosIntersecciones[k].y - y_cruce) < 0.001) {
                        
                        existe_duplicado = 1;

                        if (contieneCalleExacta(arreglo_nodosIntersecciones[k].nombre, calles[i].nombre) == 0) {
                            strcat(arreglo_nodosIntersecciones[k].nombre, "-");
                            strcat(arreglo_nodosIntersecciones[k].nombre, calles[i].nombre);
                        }

                        else if (contieneCalleExacta(arreglo_nodosIntersecciones[k].nombre, calles[j].nombre) == 0) {
	                             strcat(arreglo_nodosIntersecciones[k].nombre, "-");
	                             strcat(arreglo_nodosIntersecciones[k].nombre, calles[j].nombre);
                        }
                        
                        break;
                    }
                }
            	if(existe_duplicado == 0){

					arreglo_nodosIntersecciones[contador_intersecciones].x= x_cruce;
					arreglo_nodosIntersecciones[contador_intersecciones].y= y_cruce;

					arreglo_nodosIntersecciones[contador_intersecciones].es_turistico= 0;
					arreglo_nodosIntersecciones[contador_intersecciones].num_adyacentes= 0;

					snprintf(arreglo_nodosIntersecciones[contador_intersecciones].nombre, 100, "%s-%s", calles[i].nombre, calles[j].nombre);
					contador_intersecciones++;
				}

			}
		}
		}
	}
	return contador_intersecciones;
}