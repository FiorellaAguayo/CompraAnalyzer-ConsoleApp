#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"
#include "compras.h"
#include "menus.h"

int controller_cargarArchivoDesdeTexto(char* path, Linkedlist* arrayListaCompras)
{
    int todoOk = 0;
    FILE* file;
    if(path != NULL && arrayListaCompras != NULL)
    {
        file = fopen(path, "r");
        if(file != NULL)
        {
            parser_ComprasDesdeTexto(file, arrayListaCompras);
            todoOk = 1;
        }
        fclose(file);
    }
    return todoOk;
}

int controller_guardarArchivoDesdeTexto(char* path, Linkedlist* arrayListaCompras)
{
	int todoOk = 0;
	FILE* file;
	eCompras* unaCompra;
	int id;
	char descripcion[30];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalBulto;

	if(path != NULL && arrayListaCompras != NULL)
	{
		file = fopen(path, "w");
		if(file != NULL)
		{
			unaCompra = newCompra();
			fprintf(file,"id,descripcion,tipo,precioUnitario,cantidad,totalBulto");

			int tam = ll_len(arrayListaCompras);
			for(int i = 0; i < tam; i++)
			{
				unaCompra = (eCompras*)ll_get(arrayListaCompras, i);

				if(unaCompra != NULL)
				{
					compras_getId(unaCompra, &id);
					compras_getDescripcion(unaCompra, descripcion);
					compras_getTipo(unaCompra, &tipo);
					compras_getCantidad(unaCompra, &cantidad);
					compras_getPrecioUnitario(unaCompra, &precioUnitario);
					compras_getTotalCompras(unaCompra, &totalBulto);

					fprintf(file, "\n%d,%s,%d,%f,%d,%f", id, descripcion, tipo, precioUnitario, cantidad, totalBulto);
					todoOk = 1;
				}
				else
				{
					break;
				}
			}
			fclose(file);
		}
	}
    return todoOk;
}

int controller_imprimirLista(Linkedlist* arrayListaCompras)
{
    int todoOk = 0;
    eCompras* unaCompra;
    if(arrayListaCompras != NULL)
    {
        int tam = ll_len(arrayListaCompras);
        if(tam > 0)
        {
            compras_mostrarEncabezado();
            for(int i = 0; i < tam; i++)
            {
                unaCompra = (eCompras*) ll_get(arrayListaCompras, i);
                if(unaCompra != NULL)
                {
                    compras_mostrarUnaCompra(unaCompra);
                }
            }
            todoOk = 1;
        }
        else
        {
            compras_deleteCompras(unaCompra);
        }
    }
    return todoOk;
}

int controller_asignarTotales(Linkedlist* arrayListaCompras)
{
    int todoOk = 0;
    if(arrayListaCompras != NULL)
    {
        ll_map(arrayListaCompras, compras_map);
        todoOk = 1;
    }
    return todoOk;
}

int controller_Filtro_Jugueteria(Linkedlist* arrayListaCompras)
{
    int todoOk = 0;
    Linkedlist* listaJugueteria;
    if(arrayListaCompras != NULL)
    {
        listaJugueteria = ll_filter(arrayListaCompras, compras_filtrarPorJugueteria);
        controller_guardarArchivoDesdeTexto("FiltroJugueteia.csv", listaJugueteria);
        todoOk = 1;
    }
    return todoOk;
}

int controller_Filtro_Electronica(Linkedlist* arrayListaCompras)
{
    int todoOk = 0;
    Linkedlist* listaElectronica;
    if(arrayListaCompras != NULL)
    {
        listaElectronica = ll_filter(arrayListaCompras, compras_filtrarPorElectronica);
        controller_guardarArchivoDesdeTexto("FiltroElectronica.csv", listaElectronica);
        todoOk = 1;
    }
    return todoOk;
}

int controller_Filtro_Indumentaria(Linkedlist* arrayListaCompras)
{
    int todoOk = 0;
    Linkedlist* listaIndumentaria;
    if(arrayListaCompras != NULL)
    {
        listaIndumentaria = ll_filter(arrayListaCompras, compras_filtrarPorIndumentaria);
        controller_guardarArchivoDesdeTexto("FiltroIndumentaria.csv", listaIndumentaria);
        todoOk = 1;
    }
    return todoOk;
}

int controller_Filtro_Calzado(Linkedlist* arrayListaCompras)
{
    int todoOk = 0;
    Linkedlist* listaCalzado;
    if(arrayListaCompras != NULL)
    {
        listaCalzado = ll_filter(arrayListaCompras, compras_filtrarPorCalzado);
        controller_guardarArchivoDesdeTexto("FiltroCalzado.csv", listaCalzado);
        todoOk = 1;
    }
    return todoOk;
}

int controller_ordenarLista(Linkedlist* arrayListaCompras)
{
    int todoOk = 0;
    if(arrayListaCompras != NULL)
    {
        int criterio = menuOrdenamiento();
        if(ll_isEmpty(arrayListaCompras) == 0)
        {
            ll_sort(arrayListaCompras, compras_ordenarPorDescripcion, criterio);
            controller_imprimirLista(arrayListaCompras);
            todoOk = 1;
        }
        else
        {
            printf("\nAtencion. La lista esta vacia!");
        }
    }
    return todoOk;
}
