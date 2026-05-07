#include "header.h"


int leerArchivo(char* nombreArchivo, Grafo* mapaTuristico){

	FILE *file = fopen(nombreArchivo, "r");
    if (!file) {
        printf("Error: No se pudo abrir el archivo %s\n", nombreArchivo);
        return 0;
    }


    char buffer[256];
    if(fgets(buffer, 256, file))
    {
        sscanf(buffer, "%d", &mapaTuristico->num_calles);  //guardar numero de lineas de las calles
    }

    for(int i= 0; i < mapaTuristico->num_calles; i++){ //ciclo que guarda cada dato de la linea en la lista de structs de calles
        if(fgets(buffer, 256, file)){
            sscanf(buffer, "%s %lf %lf %lf %lf %c", mapaTuristico->calles[i].nombre, &mapaTuristico->calles[i].x1, &mapaTuristico->calles[i].y1, &mapaTuristico->calles[i].x2, &mapaTuristico->calles[i].y2, &mapaTuristico->calles[i].sentido);    
        }
    }

    if(fgets(buffer, 256, file))
    {
        sscanf(buffer, "%d", &mapaTuristico->num_puntos); //guardar numero de lineas de puntos
    }

    for (int i= 0; i < mapaTuristico->num_puntos; i++){
        if(fgets(buffer, 256, file)){
            double pos_leida;

            sscanf(buffer, "%s %s %lf", mapaTuristico->puntos[i].nombre_punto, mapaTuristico->puntos[i].nombre_calle, &pos_leida);

            for(int j= 0; j < mapaTuristico->num_calles; j++){
                if (strcmp(mapaTuristico->puntos[i].nombre_calle, mapaTuristico->calles[j].nombre) == 0){

                    Calle c= mapaTuristico->calles[j];
                    double t= 0.0;


                    if (c.sentido == 'X') // Si el sentido X, la coordenada x será la posición dada por el archivo
                    {
                        mapaTuristico->puntos[i].x = pos_leida;
                        t= (pos_leida - c.x1) / (c.x2 - c.x1);
                        mapaTuristico->puntos[i].y= c.y1 + t * (c.y2 - c.y1);

                    }

                    else if (c.sentido == 'Y')
                    {
                        mapaTuristico->puntos[i].y= pos_leida;
                        t= (pos_leida - c.y1) / (c.y2 - c.y1);
                        mapaTuristico->puntos[i].x= c.x1 + t * (c.x2 - c.x1);
                    }
                    break;
                }
            }
        }
    }

    fclose(file);
    return 1;
}