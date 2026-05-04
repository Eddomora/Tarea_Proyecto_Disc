#include "header.h"

int main(int argc, char const *argv[])
{

    // char nombreArchivo = scanf();

    // while (1)
    //{

    // e = fgetc(file);
    // if (isdigit(e))
    // {
    //     (*c)++;
    // }
    // else if (e == '\n' || e == EOF)
    // {
    //     return;
    // }
    //}

    char texto_entrada[256];
    FILE *file;
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

        Calle lista_calles[50]; //Lista de structs para guardar calles
        PuntosInteres lista_puntos[50]; //Lista de structs para guardar puntos de interés

        int num_calles= 0, num_puntos= 0; //Variables para guardar la cantidad de lineas que vienen después
        if(fgets(buffer, 256, file))
        {
            sscanf(buffer, "%d", &num_calles);  //guardar numero de lineas de las calles
        }

        for(int i= 0; i < num_calles; i++){ //ciclo que guarda cada dato de la linea en la lista de structs de calles
            if(fgets(buffer, 256, file)){
                sscanf(buffer, "%s %lf %lf %lf %lf %c", lista_calles[i].nombre, &lista_calles[i].x1, &lista_calles[i].y1, &lista_calles[i].x2, &lista_calles[i].y2, &lista_calles[i].sentido);    
            }
        }

        if(fgets(buffer, 256, file))
        {
            sscanf(buffer, "%d", &num_puntos); //guardar numero de lineas de puntos
        }
        for (int i= 0; i < num_puntos; i++)
            if(fgets(buffer, 256, file)){
                double pos_leida;

                sscanf(buffer, "%s %s %lf", lista_puntos[i].nombre_punto, lista_puntos[i].nombre_calle, &pos_leida);

                for(int j= 0; j < num_calles; j++){
                    if (strcmp(lista_puntos[i].nombre_calle, lista_calles[j].nombre) == 0)

                        if (lista_calles[j].sentido == 'X') // Si el sentido X, la coordenada x será la posición dada por el archivo
                        {
                            lista_puntos[i].x = pos_leida;
                        }
                            if (lista_calles[j].y1 == lista_calles[j].y2){ //Si es horizontal, y será constante (la de la calle)
                                lista_puntos[i].y = lista_calles[j].y1;

                            } else{ // Si es diagonal, se calcula la pendiente para usar la formula punto-pendiente

                                double m= (lista_calles[j].y2 - lista_calles[j].y1)/(lista_calles[j].x2 - lista_calles[j].x1);
                                lista_puntos[i].y= lista_calles[j].y1 + m *(pos_leida - lista_calles[j].x1);
                            }


                        if (lista_calles[j].sentido == 'Y') // Si el sentido Y, la coordenada y será la posición dada por el archivo
                        {
                            lista_puntos[i].x = pos_leida;
                        }
                            if (lista_calles[j].x1 == lista_calles[j].x2){ //Si es horizontal, x será constante (la de la calle)
                                lista_puntos[i].x = lista_calles[j].x1;

                            } else{ // Si es diagonal, se calcula la pendiente para usar la formula punto-pendiente

                                double m= (lista_calles[j].y2 - lista_calles[j].y1)/(lista_calles[j].x2 - lista_calles[j].x1);
                                lista_puntos[i].x= lista_calles[j].x1 + m *(pos_leida - lista_calles[j].y1);
                            }
                }
            }

        fclose(file);
        printf("Mapa cargado!\n");

        /* Prueba para ver si imprime bien
        for (int i = 0; i < num_calles; i++) {
            printf("%s | Inicio: %.2f, %.2f | Fin: %.2f, %.2f | Sentido: %c\n", 

            lista_calles[i].nombre, 
            lista_calles[i].x1, lista_calles[i].y1, 
            lista_calles[i].x2, lista_calles[i].y2, 
            lista_calles[i].sentido);
        }

        for (int i = 0; i < num_puntos; i++) {
            printf("%s | %s | Coordenadas: %.2f, %.2f\n",  
            lista_puntos[i].nombre_punto, 
            lista_puntos[i].nombre_calle, 
            lista_puntos[i].x, 
            lista_puntos[i].y);
        }
        */
        return 0;
    }
}