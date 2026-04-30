#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000

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
    while (1)
    {

        while (1)
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

        char buffer[MAX];
        char *token;
        char *lineas[256];

        int n_linea = 0;
        // Mientras queden líneas por leer, avanzamos
        while (feof(file) != 1)
        {
            // Leemos la línea actual y la dejamos copiada en buffer
            if (fgets(buffer, MAX, file))
            {
                printf("Línea %d: %s", n_linea + 1, buffer);
                lineas[n_linea] = buffer;
                n_linea++;
            }
        }

        /*
                char *palabras[256];
                char *token = strtok(texto_entrada, " ");
                int i = 0;
                while (token != NULL)
                {
                    palabras[i] = token;
                    token = strtok(NULL, " ");
                    i++;
                    if (i >= 256)
                        break;
                }

                if (strcasecmp(palabras[0], "exit") == 0)
                {
                    break;
                }

                if (strlen(*palabras) != 4)
                {
                    printf("Error, intrucción mal escrita\n");
                    continue;
                    ;
                }
        */
        printf("\n");
        return 0;
    }
}