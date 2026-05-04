#include "header.h"

int nodoIntersecciones(Calle *calles, int num_calles, Nodo *arreglo_nodosIntersecciones){
	int contador_intersecciones= 0;


	for(int i= 0; i < num_calles; i++){

		int es_iH= (calles[i].y1 == calles[i].y2);
		int es_iV= (calles[i].x1 == calles[i].x2);
		int es_iD= (!es_iH && !es_iV);

		for(int j= i+1; j < num_calles; j++){

			int es_jH= (calles[j].y1 == calles[j].y2);
			int es_jV= (calles[j].x1 == calles[j].x2);
			int es_jD= (!es_jH && !es_jV);

			double x_cruce= 0;
			double y_cruce= 0;

			int cruceFlag= 0;



			if((es_iH && es_jV) || (es_jH && es_iV)){ //Si una es vertical y la otra horizontal:

				Calle h= es_iH ? calles[i] : calles[j];
				Calle v= es_iV ? calles[i] : calles[j];

				x_cruce= v.x1;
				y_cruce= h.y1;
				cruceFlag= 1;

			}

			else if((es_iH && es_jD) || (es_jH && es_iD)){ //Si una es horizontal y la otra diagonal:

				Calle h= es_iH ? calles[i] : calles[j];
				Calle d= es_iD ? calles[i] : calles[j];

				double m= (d.y2 - d.y1)/(d.x2 - d.x1);
				y_cruce= h.y1;
				x_cruce= ((y_cruce - d.y1) / m) + d.x1; //Punto-pendiente
				cruceFlag= 1;
			}

			else if((es_iV && es_jD) || (es_jV && es_iD)){ //Si una es vertical y la otra diagonal:

				Calle v= es_iV ? calles[i] : calles[j];
				Calle d= es_iD ? calles[i] : calles[j];

				double m= (d.y2 - d.y1) / (d.x2 - d.x1);
				x_cruce= v.x1;
				y_cruce= m * (x_cruce - d.x1) + d.y1;
				cruceFlag= 1;
			}

			else if(es_iD && es_jD){ //Si ambas son diagonales
				double m1= (calles[i].y2 - calles[i].y1) / (calles[i].x2 - calles[i].x1);
				double m2= (calles[j].y2 - calles[j].y1) / (calles[j].x2 - calles[j].x1);

				if(m1 != m2){ //Si las pendientes son distintas, no son paralelas
					x_cruce= (calles[j].y1 - calles[i].y1 + m1 * calles[i].x1 - m2 * calles[j].x1) / (m1 - m2); //Igualamos las ecuaciones punto-pendiente para encontrar x
					y_cruce = m1 * (x_cruce - calles[i].x1) + calles[i].y1; //Punto-pendiente
					cruceFlag= 1;
				}

			}

			if(cruceFlag){ //Verifica si las coordenadas obtenidas están dentro del rango de las calles y lo añade al arreglo
				if(	   x_cruce >= calles[i].x1 
					&& x_cruce <= calles[i].x2

					&& y_cruce >= calles[i].y1
					&& y_cruce <= calles[i].y2

					&& x_cruce >= calles[j].x1
					&& x_cruce <= calles[j].x2

					&& y_cruce >= calles[j].y1
					&& y_cruce <= calles[j].y2){


					arreglo_nodosIntersecciones[contador_intersecciones].x= x_cruce;
					arreglo_nodosIntersecciones[contador_intersecciones].y= y_cruce;

					arreglo_nodosIntersecciones[contador_intersecciones].es_turistico= 0;
					arreglo_nodosIntersecciones[contador_intersecciones].num_adyacentes= 0;

					sprintf(arreglo_nodosIntersecciones[contador_intersecciones].nombre, "%s-%s", calles[i].nombre, calles[j].nombre);

					contador_intersecciones++;				


				}

			}


		}

	}
	return contador_intersecciones;
}