#include "header.h"

int main(int argc, char const *argv[])
{

    char texto_entrada[256];
    FILE *file;

    Grafo mapaTuristico;
    mapaTuristico.num_calles= 0;
    mapaTuristico.num_puntos= 0;
    mapaTuristico.num_nodos= 0;    




    while (1) //Bucle principal
    {
        while (1) //Pedir archivo hasta que sea valido
        {
            printf("Ingrese el nombre del archivo de texto (Ej: mapa_turistico.txt): ");
            fgets(texto_entrada, 256, stdin);
            texto_entrada[strcspn(texto_entrada, "\n")] = 0;

            if (strcasecmp(texto_entrada, "exit") == 0) // modificar para que salga con un mensaje especifico
            {
                return 0;
            }

            file = fopen(texto_entrada, "r");
            if (!file)
            {
                printf("Error al abrir el archivo\n");
            }

            else
            {
                break;
            }
        }


        char buffer[256];


        if(fgets(buffer, 256, file))
        {
            sscanf(buffer, "%d", &mapaTuristico.num_calles);  //guardar numero de lineas de las calles
        }

        for(int i= 0; i < mapaTuristico.num_calles; i++){ //ciclo que guarda cada dato de la linea en la lista de structs de calles
            if(fgets(buffer, 256, file)){
                sscanf(buffer, "%s %lf %lf %lf %lf %c", mapaTuristico.calles[i].nombre, &mapaTuristico.calles[i].x1, &mapaTuristico.calles[i].y1, &mapaTuristico.calles[i].x2, &mapaTuristico.calles[i].y2, &mapaTuristico.calles[i].sentido);    
            }
        }

        if(fgets(buffer, 256, file))
        {
            sscanf(buffer, "%d", &mapaTuristico.num_puntos); //guardar numero de lineas de puntos
        }

        for (int i= 0; i < mapaTuristico.num_puntos; i++){
            if(fgets(buffer, 256, file)){
                double pos_leida;

                sscanf(buffer, "%s %s %lf", mapaTuristico.puntos[i].nombre_punto, mapaTuristico.puntos[i].nombre_calle, &pos_leida);

                for(int j= 0; j < mapaTuristico.num_calles; j++){
                    if (strcmp(mapaTuristico.puntos[i].nombre_calle, mapaTuristico.calles[j].nombre) == 0){

                        Calle c= mapaTuristico.calles[j];
                        double t= 0.0;


                        if (c.sentido == 'X') // Si el sentido X, la coordenada x será la posición dada por el archivo
                        {
                            mapaTuristico.puntos[i].x = pos_leida;
                            t= (pos_leida - c.x1) / (c.x2 - c.x1);
                            mapaTuristico.puntos[i].y= c.y1 + t * (c.y2 - c.y1);

                        }

                        else if (c.sentido == 'Y')
                        {
                            mapaTuristico.puntos[i].y= pos_leida;
                            t= (pos_leida - c.y1) / (c.y2 - c.y1);
                            mapaTuristico.puntos[i].x= c.x1 + t * (c.x2 - c.x1);
                        }
                        break;
                    }
                }
            }
        }

        fclose(file);
        printf("Mapa cargado!\n");

        crearGrafo(&mapaTuristico);






        return 0;
    }
}