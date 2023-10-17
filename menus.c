#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

int menu()
{
	int opcion;

	printf("\n\n-------------------------");
	printf("\n         MENU            ");
	printf("\n-------------------------");
	printf("\n\n1. Cargar archivo.");
	printf("\n2. Imprimir lista. ");
	printf("\n3. Asignar totales.");
	printf("\n4. Filtrar por tipo.");
	printf("\n5. Mostrar compras.");
	printf("\n6. Guardar compras.");
	printf("\n7. Salir.");

	pedirEntero(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 7);
	return opcion;
}

int menuFiltros()
{
	int opcion;

	printf("\n\n-------------------------------------------");
	printf("\n  ELEGI EL TIPO POR EL QUE QUERES FILTRAR  ");
	printf("\n-------------------------------------------");
	printf("\n\n1. Jugueteria.");
	printf("\n2. Electronica. ");
	printf("\n3. Indumentaria.");
	printf("\n4. Calzado.");

	pedirEntero(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 4);
	return opcion;
}

int menuOrdenamiento()
{
	int opcion;

	printf("\n\n-----------------------------------------");
	printf("\n  DE QUE FORMA QUERES ORDENAR LA LISTA   ");
	printf("\n-----------------------------------------");
	printf("\n\n0. Descendente. ");
	printf("\n1. Ascendente.");

	pedirEntero(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 0, 1);
	return opcion;
}
