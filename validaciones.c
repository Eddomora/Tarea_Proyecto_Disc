#include "header.h"

int contieneCalleExacta(const char* nombreNodo, const char* nombreCalle){
	const char* pos= strstr(nombreNodo, nombreCalle); //Si encuentra una coincidencia, apunta a la dirección de memoria donde la encontró en el primer string.

	while (pos != NULL){
		int lenCalle= strlen(nombreCalle);

		int checkIzq= (pos == nombreNodo) || (*(pos - 1) == '-');
		int checkDer= (*(pos + lenCalle) == '\0') || (*(pos + lenCalle) == '-');

		if (checkIzq && checkDer){
			return 1;
		}

		pos= strstr(pos + 1, nombreCalle);
	}

	return 0;

}