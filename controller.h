#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"

int controller_cargarArchivoDesdeTexto(char* path, Linkedlist* arrayListaCompras);
int controller_imprimirLista(Linkedlist* arrayListaCompras);
int controller_asignarTotales(Linkedlist* arrayListaCompras);
int controller_guardarArchivoDesdeTexto(char* path, Linkedlist* arrayListaCompras);
int controller_Filtro_Jugueteria(Linkedlist* arrayListaCompras);
int controller_Filtro_Electronica(Linkedlist* arrayListaCompras);
int controller_Filtro_Indumentaria(Linkedlist* arrayListaCompras);
int controller_Filtro_Calzado(Linkedlist* arrayListaCompras);
int controller_ordenarLista(Linkedlist* arrayListaCompras);

#endif // CONTROLLER_H_INCLUDED

