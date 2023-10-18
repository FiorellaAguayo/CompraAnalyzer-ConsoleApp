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

eCompras* entity_new();
eCompras* entity_newParameters(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalBultoStr);
void entity_deleteEntity(eCompras* unaCompra);
int entity_setId(eCompras* unaCompra, int idArticulo);
int entity_getId(eCompras* unaCompra, int* idArticulo);
int entity_setDescripcion(eCompras* unaCompra, char* descripcion);
int entity_getDescripcion(eCompras* unaCompra, char* descripcion);
int entity_setTipo(eCompras* unaCompra, int tipo);
int entity_getTipo(eCompras* unaCompra, int* tipo);
int entity_setPrecioUnitario(eCompras* unaCompra, float precioUnitario);
int entity_getPrecioUnitario(eCompras* unaCompra, float* precioUnitario);
int entity_setCantidad(eCompras* unaCompra, int cantidad);
int entity_getCantidad(eCompras* unaCompra, int* cantidad);
int entity_setTotalCompras(eCompras* unaCompra, float totalCompras);
int entity_getTotalCompras(eCompras* unaCompra, float* totalCompras);
void entity_showHeader();
int entity_showOneEntity(eCompras* unaCompra);
void* entity_map(void* elemento);
int entity_filterByJugueteria(void* elemento);
int entity_filterByElectronica(void* elemento);
int entity_filterByIndumentaria(void* elemento);
int entity_filterByCalzado(void* elemento);
int entity_sortByDescripcion(void* item1, void* item2);
