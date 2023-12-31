#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

/**
 * @brief Muestra un men� y solicita al usuario que ingrese una opci�n.
 * Esta funci�n muestra un men� en la consola y solicita al usuario que ingrese una opci�n v�lida.
 * @return Opci�n elegida por el usuario.
 */
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
	printf("\n5. Ordenar compras (alfabeticamente).");
	printf("\n6. Guardar compras.");
	printf("\n7. Salir.");

	askForInteger(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 7);
	return opcion;
}

/**
 * @brief Muestra un men� de filtros y solicita al usuario que elija un tipo de filtro.
 * Esta funci�n muestra un men� de filtros en la consola y solicita al usuario que elija un tipo de filtro v�lido.
 * @return Tipo de filtro elegido por el usuario.
 */
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

	askForInteger(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 4);
	return opcion;
}

/**
 * @brief Muestra un men� de ordenamiento y solicita al usuario que elija un tipo de orden.
 * Esta funci�n muestra un men� de ordenamiento en la consola y solicita al usuario que elija un tipo de orden v�lido.
 * @return Tipo de orden elegido por el usuario.
 */
int menuOrdenamiento()
{
	int opcion;

	printf("\n\n-----------------------------------------");
	printf("\n  DE QUE FORMA QUERES ORDENAR LA LISTA   ");
	printf("\n-----------------------------------------");
	printf("\n\n0. Descendente. ");
	printf("\n1. Ascendente.");

	askForInteger(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 0, 1);
	return opcion;
}
