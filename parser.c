#include <stdio.h>
#include <stdlib.h>
#include "compras.h"
#include "parser.h"
#include "LinkedList.h"

int parser_ComprasDesdeTexto(FILE* file, Linkedlist* arrayListaCompras)
{
	int todoOk = -1;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	eCompras* unaCompra;
	char header[256];

    fscanf(file, "%[^\n]\n", header);
	while(!feof(file))
	{
		fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,], %[^\n]", var1, var2, var3, var4, var5, var6);
		unaCompra = compras_newParametros(var1, var2, var3, var4, var5, var6);
		if(unaCompra != NULL)
		{
			ll_add(arrayListaCompras, unaCompra);
			todoOk = 1;
		}
	}
	return todoOk;
}
