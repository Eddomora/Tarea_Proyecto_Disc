#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[50];
    double x1, y1, x2, y2;
    char sentido;
} Calle;

typedef struct{
    char nombre_punto[50];
    char nombre_calle[50];
    double x, y;
}PuntosInteres;

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

        Calle lista_calles[100]; //Lista de structs para guardar calles
        PuntosInteres lista_puntos[100]; //Lista de structs para guardar puntos de interés

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

        for(int i= 0; i < num_puntos; i++){ //ciclo que guarda cada dato de la linea en la lista de structs de puntos
            if(fgets(buffer, 256, file)){
                sscanf(buffer, "%s %s %lf %lf", lista_puntos[i].nombre_punto, lista_puntos[i].nombre_calle, &lista_puntos[i].x, &lista_puntos[i].y);
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