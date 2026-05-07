#include "header.h"

int main(int argc, char const *argv[])
{

    char texto_entrada[256];
    Grafo mapaTuristico;

    while(1){
        mapaTuristico.num_calles= 0;
        mapaTuristico.num_puntos= 0;
        mapaTuristico.num_nodos= 0;

        printf("Ingrese nombre del archivo o 'exit' para cerrar: ");

        if (fgets(texto_entrada, 256, stdin) == NULL) break;
        texto_entrada[strcspn(texto_entrada, "\n")]= 0; //Limpiar enter

        if (strcasecmp(texto_entrada, "exit") == 0){
            printf("SALIENDO...");
            break;
        }

        if(leerArchivo(texto_entrada, &mapaTuristico) == 1){
            printf("Archivo cargado");

            crearGrafo(&mapaTuristico);
            printf("Grafo generado");
        }
    }
    
    return 0;
}