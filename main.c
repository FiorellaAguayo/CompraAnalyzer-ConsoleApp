#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "inputs.h"
#include "controller.h"
#include "LinkedList.h"

int main()
{
    int stop = 0;
    int flag = 0;
    char fileName[30];
    Linkedlist* listaDeCompras = ll_newLinkedList();

    while(stop == 0)
    {
        switch(menu())
        {
            case 1:
                askForCSVFile(fileName, "\nPor favor, ingrese el nombre del archivo con extension .csv: ", "\nEl nombre no es valido.\n");
                if(controller_loadFileFromText(fileName, listaDeCompras))
                {
                    printf("\nEl archivo '%s' se ha cargado correctamente.", fileName);
                    flag = 1;
                }
                else
                {
                    printf("\nHubo un problema al cargar el archivo.");
                }
                break;

            case 2:
                if(flag)
                {
                    if(controller_printList(listaDeCompras))
                    {
                        printf("\nLa lista se imprimio exitosamente.");
                    }
                    else
                    {
                        printf("\nHubo un problema al imprimir el archivo.");
                    }
                }
                else
                {
                    printf("\nTodavia no se cargo el archivo.");
                }
                break;

            case 3:
                if(flag)
                {
                    if(controller_assignTotals(listaDeCompras))
                    {
                        printf("\nTotales asignados con exito!");
                    }
                    else
                    {
                        printf("\nHubo un problema al asignar los totales.");
                    }
                }
                else
                {
                    printf("\nTodavia no se cargo el archivo.");
                }
                break;

            case 4:
                if(flag)
                {
                    switch(menuFiltros())
                    {
                        case 1:
                            if(controller_filter_Jugueteria(listaDeCompras))
                            {
                                printf("\nSe cargo la lista filtrada de jugueteria.");
                            }
                            else
                            {
                                printf("\nHubo un problema al cargar la lista filtrada.");
                            }
                            break;

                        case 2:
                            if(controller_filter_Electronica(listaDeCompras))
                            {
                                printf("\nSe cargo la lista filtrada de electronica.");
                            }
                            else
                            {
                                printf("\nHubo un problema al cargar la lista filtrada.");
                            }
                            break;

                        case 3:
                            if(controller_filter_Indumentaria(listaDeCompras))
                            {
                                printf("\nSe cargo la lista filtrada de indumentaria.");
                            }
                            else
                            {
                                printf("\nHubo un problema al cargar la lista filtrada.");
                            }
                            break;

                        case 4:
                            if(controller_filter_Calzado(listaDeCompras))
                            {
                                printf("\nSe cargo la lista filtrada de calzado.");
                            }
                            else
                            {
                                printf("\nHubo un problema al cargar la lista filtrada.");
                            }
                            break;
                    }
                }
                else
                {
                    printf("\nTodavia no se cargo el archivo.");
                }
                break;

            case 5:
                if(flag)
                {
                    if(controller_sortList(listaDeCompras))
                    {
                        printf("\nSe ordeno la lista exitosamente.");
                    }
                    else
                    {
                        printf("\nHubo un problema al ordenar la lista.");
                    }
                }
                else
                {
                    printf("\nTodavia no se cargo el archivo.");
                }
                break;

            case 6:
                if(flag)
                {
                    askForCSVFile(fileName, "¿Con que nombre desea guardar la lista? (.csv: ", "\nEl nombre no es valido. ");
                    if(controller_saveFileFromText(fileName, listaDeCompras))
                    {
                        printf("\nSe guardo la lista exitosamente!");
                    }
                    else
                    {
                        printf("\nHubo un problema al guardar la lista.");
                    }
                }
                else
                {
                    printf("\nTodavia no se cargo el archivo.");
                }
                break;

            case 7:
                printf("\nGracias por utilizar este programa!");
                stop = 1;
                break;
        }
    }
    return 0;
}
