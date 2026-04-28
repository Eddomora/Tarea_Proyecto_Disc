#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Ha olvidado el archivo de texto.\n");
        exit(1);
    }

    char nombreArchivo = argv[1];

    FILE *file = fopen(nombreArchivo, "r");

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

    char comando_entrada[256];
    while (1)
    {
        fgets(comando_entrada, 256, stdin);

        comando_entrada[strcspn(comando_entrada, "\n")] = 0;

        char *palabras[256];
        char *token = strtok(comando_entrada, " ");
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
            printf("Error, comando mal escrito\n");
            continue;
            ;
        }

        return 0;
    }
}