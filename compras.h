#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED

typedef struct
{
    int id_articulo;
    char descripcion[30];
    int tipo;
    float precioUnitario;
    int cantidad;
    float totalBulto;
}eCompras;

#endif // COMPRAS_H_INCLUDED

eCompras* newCompra();
eCompras* compras_newParametros(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalBultoStr);
void compras_deleteCompras(eCompras* unaCompra);
int compras_setId(eCompras* unaCompra, int idArticulo);
int compras_getId(eCompras* unaCompra, int* idArticulo);
int compras_setDescripcion(eCompras* unaCompra, char* descripcion);
int compras_getDescripcion(eCompras* unaCompra, char* descripcion);
int compras_setTipo(eCompras* unaCompra, int tipo);
int compras_getTipo(eCompras* unaCompra, int* tipo);
int compras_setPrecioUnitario(eCompras* unaCompra, float precioUnitario);
int compras_getPrecioUnitario(eCompras* unaCompra, float* precioUnitario);
int compras_setCantidad(eCompras* unaCompra, int cantidad);
int compras_getCantidad(eCompras* unaCompra, int* cantidad);
int compras_setTotalCompras(eCompras* unaCompra, float totalCompras);
int compras_getTotalCompras(eCompras* unaCompra, float* totalCompras);
void compras_mostrarEncabezado();
int compras_mostrarUnaCompra(eCompras* unaCompra);
void* compras_map(void* elemento);
int compras_filtrarPorJugueteria(void* elemento);
int compras_filtrarPorElectronica(void* elemento);
int compras_filtrarPorIndumentaria(void* elemento);
int compras_filtrarPorCalzado(void* elemento);
int compras_ordenarPorDescripcion(void* item1, void* item2);
