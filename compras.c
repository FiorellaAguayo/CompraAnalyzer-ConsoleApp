#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compras.h"

eCompras* newCompra()
{
    eCompras* unaCompra;
    unaCompra = (eCompras*)malloc(sizeof(eCompras));
    if(unaCompra != NULL)
    {
        unaCompra->id_articulo = 0;
        strcpy(unaCompra->descripcion, " ");
        unaCompra->tipo = 0;
        unaCompra->precioUnitario = 0.00;
        unaCompra->cantidad = 0;
        unaCompra->totalBulto = 0.00;
    }
    return unaCompra;
}

eCompras* compras_newParametros(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalBultoStr)
{
    eCompras* unaCompra;
    unaCompra = newCompra();

    if(unaCompra != NULL)
    {
        if( compras_setId(unaCompra, atoi(idStr)) == -1 ||
            compras_setDescripcion(unaCompra, descripcionStr) == -1 ||
            compras_setTipo(unaCompra, atoi(tipoStr)) == -1 ||
            compras_setPrecioUnitario(unaCompra, atof(precioUnitarioStr)) == -1 ||
            compras_setCantidad(unaCompra, atoi(cantidadStr)) == -1 ||
            compras_setTotalCompras(unaCompra, atof(totalBultoStr)) == -1 )
        {
            unaCompra = NULL;
            compras_deleteCompras(unaCompra);
        }
    }
    return unaCompra;
}

void compras_deleteCompras(eCompras* unaCompra)
{
    if(unaCompra != NULL)
    {
        free(unaCompra);
    }
}

int compras_setId(eCompras* unaCompra, int idArticulo)
{
    int todoOk = -1;

    if(unaCompra != NULL && idArticulo > 0)
    {
        unaCompra->id_articulo = idArticulo;
        todoOk = 0;
    }
    return todoOk;
}

int compras_getId(eCompras* unaCompra, int* idArticulo)
{
    int todoOk = -1;
    if(unaCompra != NULL && idArticulo != NULL)
    {
        *idArticulo = unaCompra->id_articulo;
        todoOk = 0;
    }
    return todoOk;
}

int compras_setDescripcion(eCompras* unaCompra, char* descripcion)
{
	int todoOk = -1;
	if(unaCompra != NULL)
	{
		strcpy(unaCompra->descripcion, descripcion);
        todoOk = 0;
	}
    return todoOk;
}

int compras_getDescripcion(eCompras* unaCompra, char* descripcion)
{
	int todoOk = -1;
	if(unaCompra != NULL && descripcion != NULL)
	{
		strcpy(descripcion, unaCompra->descripcion);
		todoOk = 0;
	}
	return todoOk;
}

int compras_setTipo(eCompras* unaCompra, int tipo)
{
    int todoOk = -1;
    if(unaCompra != NULL && tipo > 0)
    {
        unaCompra->tipo = tipo;
        todoOk = 0;
    }
    return todoOk;
}

int compras_getTipo(eCompras* unaCompra, int* tipo)
{
    int todoOk = -1;
    if(unaCompra != NULL && tipo != NULL)
    {
        *tipo = unaCompra->tipo;
        todoOk = 0;
    }
    return todoOk;
}

int compras_setPrecioUnitario(eCompras* unaCompra, float precioUnitario)
{
    int todoOk = -1;
    if(unaCompra != NULL && precioUnitario > 0)
    {
        unaCompra->precioUnitario = precioUnitario;
        todoOk = 0;
    }
    return todoOk;
}

int compras_getPrecioUnitario(eCompras* unaCompra, float* precioUnitario)
{
    int todoOk = -1;
    if(unaCompra != NULL && precioUnitario != NULL)
    {
        *precioUnitario = unaCompra->precioUnitario;
        todoOk = 0;
    }
    return todoOk;
}

int compras_setCantidad(eCompras* unaCompra, int cantidad)
{
    int todoOk = -1;
    if(unaCompra != NULL)
    {
        unaCompra->cantidad = cantidad;
        todoOk = 0;
    }
    return todoOk;
}

int compras_getCantidad(eCompras* unaCompra, int* cantidad)
{
    int todoOk = -1;
    if(unaCompra != NULL && cantidad != NULL)
    {
        *cantidad = unaCompra->cantidad;

        todoOk = 0;
    }
    return todoOk;
}

int compras_setTotalCompras(eCompras* unaCompra, float totalBulto)
{
    int todoOk = -1;
    if(unaCompra != NULL && totalBulto >= 0)
    {
        unaCompra->totalBulto = totalBulto;
        todoOk = 0;
    }
    return todoOk;
}

int compras_getTotalCompras(eCompras* unaCompra, float* totalBulto)
{
    int todoOk = -1;
    if(unaCompra != NULL && totalBulto != NULL)
    {
        *totalBulto = unaCompra->totalBulto;
        todoOk = 0;
    }
    return todoOk;
}

void compras_mostrarEncabezado()
{
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("| ID  |  DESCRIPCION               | TIPO            | PRECIO UNITARIO      | CANTIDAD   | TOTAL SERVICIO |\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
}

int compras_mostrarUnaCompra(eCompras* unaCompra)
{
    int todoOk = 0;
    eCompras auxCompra;
    if(unaCompra != NULL)
    {
        compras_getId(unaCompra, &auxCompra.id_articulo);
        compras_getDescripcion(unaCompra, auxCompra.descripcion);
        compras_getTipo(unaCompra, &auxCompra.tipo);
        compras_getPrecioUnitario(unaCompra, &auxCompra.precioUnitario);
        compras_getCantidad(unaCompra, &auxCompra.cantidad);
        compras_getTotalCompras(unaCompra, &auxCompra.totalBulto);

        printf("| %-3d | %-26s | %-15d | %-20.2f | %-10d | %-15.2f|\n", auxCompra.id_articulo, auxCompra.descripcion, auxCompra.tipo, auxCompra.precioUnitario, auxCompra.cantidad, auxCompra.totalBulto);
        printf("-----------------------------------------------------------------------------------------------------------\n");
        todoOk = 1;
    }
    return todoOk;
}

void* compras_map(void* elemento)
{
    eCompras* unaCompra;
    int cantidad;
    float precioUnitario;
    float totalBulto;

    unaCompra = (eCompras*) elemento;
    compras_getCantidad(unaCompra, &cantidad);
    compras_getPrecioUnitario(unaCompra, &precioUnitario);

    if(unaCompra != NULL)
    {
        totalBulto = (float)cantidad * precioUnitario;
        compras_setTotalCompras(unaCompra, totalBulto);
    }
    return unaCompra;
}

int compras_filtrarPorJugueteria(void* elemento)
{
    int todoOk = 0;
    eCompras* unaCompra = (eCompras*) elemento;
    if(unaCompra != NULL)
    {
        if(unaCompra->tipo == 1)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int compras_filtrarPorElectronica(void* elemento)
{
    int todoOk = 0;
    eCompras* unaCompra = (eCompras*) elemento;
    if(unaCompra != NULL)
    {
        if(unaCompra->tipo == 2)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int compras_filtrarPorIndumentaria(void* elemento)
{
    int todoOk = 0;
    eCompras* unaCompra = (eCompras*) elemento;
    if(unaCompra != NULL)
    {
        if(unaCompra->tipo == 3)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int compras_filtrarPorCalzado(void* elemento)
{
    int todoOk = 0;
    eCompras* unaCompra = (eCompras*) elemento;
    if(unaCompra != NULL)
    {
        if(unaCompra->tipo == 4)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int compras_ordenarPorDescripcion(void* item1, void* item2)
{
    int todoOk = 0;
    eCompras* compra1 = (eCompras*) item1;
    eCompras* compra2 = (eCompras*) item2;
    char descripcion1[50];
    char descripcion2[50];

    if(compra1 != NULL && compra2 != NULL)
    {
        if(compras_getDescripcion(compra1, descripcion1) == 0 && compras_getDescripcion(compra2, descripcion2) == 0)
        {
            if(strcmp(descripcion1, descripcion2) > 0)
            {
                todoOk = 1;
            }
            else if(strcmp(descripcion1, descripcion2) < 0)
            {
                todoOk = -1;
            }
        }
    }

    return todoOk;
}
