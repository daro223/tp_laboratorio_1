#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANT_PERSONAS 7

void inicializarArray(ePersona vecPersona[],int cantidadPersonas,int valor);
void hardcodeArray(ePersona vecPersona[],int tam);
void graficarEdades(ERangos arrayRangos[],int rango,int valor);

int main()
{
    ePersona vecPersona[CANT_PERSONAS];
    ePersona auxEPersona;
    ERangos auxRangos;

    char auxNombre[50];
    char auxEdad[3];
    char auxDni[10];
    int Edad;
    int Dni;
    int estado=0;
    int espacioLibre;
    int resultadoBusqueda=-1;
    int menores=0;
    int adolecentes=0;
    int mayores=0;
    int rango=0;
    ERangos arrayRangos[rango];
    char seguir='s';
    int opcion=0;
    int i;
    int j;


    inicializarArray(vecPersona,CANT_PERSONAS,-1);

    for(i=0;i<CANT_PERSONAS;i++)
    {
        if(vecPersona[i].estado== -1){
            vecPersona[i].edad=-1;
        }
    }

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                espacioLibre = obtenerEspacioLibre(vecPersona,CANT_PERSONAS,-1);
                if(espacioLibre == -1)
                {
                    printf("\n\nNO HAY ESPACIO PARA CARGAR DATOS\n\n");

                printf("\n                         LISTADO DE PERSONAS CARGADAS                        \n");
                printf("_______________________________________________________________________________\n");
                printf("\n|                    NOMBRE                    |EDAD|       |   DNI   |\n");
                for(i=0; i < CANT_PERSONAS-1; i++)
                {
                    if(vecPersona[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < CANT_PERSONAS; j++)
                    {
                        if(vecPersona[j].estado == -1)
                        {
                            continue;
                        }
                        if(strcmp(vecPersona[i].nombre,vecPersona[j].nombre)>0)
                        {
                            auxEPersona=vecPersona[j];
                            vecPersona[j]=vecPersona[i];
                            vecPersona[i]=auxEPersona;
                        }
                    }
                }
                for(i=0; i < CANT_PERSONAS; i++)
                {
                    if(vecPersona[i].estado != -1)
                    {
                        printf("|%40s      | %3d|       |%9d|\n",vecPersona[i].nombre, vecPersona[i].edad, vecPersona[i].dni);
                        printf("|                                              |    |       |         |\n");
                    }
                }
                printf("_______________________________________________________________________________\n");
                break;
                }

                printf("\n\nALTA\n\n");
                while(!getStringNumeros("\nIngresar el DNI: ",auxDni))
                {
                    printf("\n      ***ERROR***\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n\nEl DNI debe ser Numerico\n\n");
                }
                printf("______________________________________________\n\n");

                Dni = atoi(auxDni);
                resultadoBusqueda=buscarPorDni(vecPersona,CANT_PERSONAS,Dni);
                if(resultadoBusqueda!=-1)
                {
                    printf("\n\nEl DNI ingresado pertenece a %s \nNo sera registrado.\n",vecPersona[resultadoBusqueda].nombre);
                    break;
                }
                while(!getStringLetras("Ingresar el nombre: ",auxNombre))
                {
                    printf("\n                ***ERROR***                   \n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
                    printf("\nEl nombre debe estar compuesto solo por letras\n\n");
                }
                printf("______________________________________________\n\n");

                while(!getStringNumeros("Ingresar el Edad: ",auxEdad))
                {
                    printf("\n      ***ERROR***       \n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
                    printf("\nLa Edad debe ser Numerica\n\n");
                }
                Edad = atoi(auxEdad);

                strcpy(vecPersona[espacioLibre].nombre,auxNombre);
                vecPersona[espacioLibre].edad=Edad;
                vecPersona[espacioLibre].dni=Dni;
                vecPersona[espacioLibre].estado=estado;

                system("cls");
                printf("\nSe ingreso\n      Nombre: %s\n      Edad: %d\n      Dni: %d\ncon exito\n",vecPersona[espacioLibre].nombre, vecPersona[espacioLibre].edad, vecPersona[espacioLibre].dni);
                break;

            case 2:
                system("cls");
                printf("\n                         LISTADO DE PERSONAS CARGADAS                        \n");
                printf("_______________________________________________________________________________\n");
                printf("\n|                    NOMBRE                    |EDAD|       |   DNI   |\n");
                for(i=0; i < CANT_PERSONAS-1; i++)
                {
                    if(vecPersona[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < CANT_PERSONAS; j++)
                    {
                        if(vecPersona[j].estado == -1)
                        {
                            continue;
                        }
                        if(strcmp(vecPersona[i].nombre,vecPersona[j].nombre)>0)
                        {
                            auxEPersona=vecPersona[j];
                            vecPersona[j]=vecPersona[i];
                            vecPersona[i]=auxEPersona;
                        }
                    }
                }
                for(i=0; i < CANT_PERSONAS; i++)
                {
                    if(vecPersona[i].estado != -1)
                    {
                        printf("|%40s      | %3d|       |%9d|\n",vecPersona[i].nombre, vecPersona[i].edad, vecPersona[i].dni);
                        printf("|                                              |    |       |         |\n");
                    }
                }
                printf("_______________________________________________________________________________\n");
                printf("\nBORRAR\n");
                if(!getStringNumeros("\nIngrese el DNI de la persona que desea borrar: ",auxDni))
                {
                    printf("\n\nEl DNI debe ser Numerico\n\n");
                    break;
                }
                Dni = atoi(auxDni);
                resultadoBusqueda=buscarPorDni(vecPersona,CANT_PERSONAS,Dni);
                if(resultadoBusqueda!=-1)
                {
                    char borrar;
                    printf("\n\nEl DNI corresponde a %s \n",vecPersona[resultadoBusqueda].nombre);
                    printf("Desea eliminar a esta persona del registro?\n\nIngrese 's' para confirmar.");

                    fflush(stdin);
                    borrar=getchar();

                    switch(borrar)
                    {
                        case 's':
                            strcpy(vecPersona[resultadoBusqueda].nombre," ");
                            vecPersona[resultadoBusqueda].edad=0;
                            vecPersona[resultadoBusqueda].dni=0;
                            vecPersona[resultadoBusqueda].estado=-1;
                            break;
                        default:
                            break;
                    }
                }
                break;

            case 3:
                system("cls");
                printf("\n                         LISTADO DE PERSONAS CARGADAS                        \n");
                printf("_______________________________________________________________________________\n");
                printf("\n|                    NOMBRE                    |EDAD|       |   DNI   |\n");
                for(i=0; i < CANT_PERSONAS-1; i++)
                {
                    if(vecPersona[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < CANT_PERSONAS; j++)
                    {
                        if(vecPersona[j].estado == -1)
                        {
                            continue;
                        }
                        if(strcmp(vecPersona[i].nombre,vecPersona[j].nombre)>0)
                        {
                            auxEPersona=vecPersona[j];
                            vecPersona[j]=vecPersona[i];
                            vecPersona[i]=auxEPersona;
                        }
                    }
                }
                for(i=0; i < CANT_PERSONAS; i++)
                {
                    if(vecPersona[i].estado != -1)
                    {
                        printf("|%40s      | %3d|       |%9d|\n",vecPersona[i].nombre, vecPersona[i].edad, vecPersona[i].dni);
                        printf("|                                              |    |       |         |\n");
                    }
                }
                printf("_______________________________________________________________________________\n");
                break;

            case 4:
                system("cls");


                for(i=0; i < CANT_PERSONAS; i++)
                {

                    if(vecPersona[i].edad > -1 && vecPersona[i].edad < 19 )
                    {
                        menores++;
                    }
                    else if(vecPersona[i].edad >18 && vecPersona[i].edad <36)
                    {
                        adolecentes++;
                    }
                    else if(vecPersona[i].edad >35)
                    {
                        mayores++;
                    }
                }
                if(menores>adolecentes && menores>mayores)
                {
                    rango=menores;
                }
                else if(adolecentes>menores && adolecentes>mayores)
                {
                    rango=adolecentes;
                }
                else if(mayores>menores && mayores>adolecentes)
                {
                    rango=mayores;
                }
                else
                {
                    rango=0;
                }
                for(i=0; i < rango; i++)
                {
                    if( i <menores)
                    {
                        arrayRangos[i].menos18='X';
                    }
                    else
                    {
                        arrayRangos[i].menos18=' ';
                    }

                    if(i < adolecentes)
                    {
                        arrayRangos[i].de19a35='X';
                    }
                    else
                    {
                        arrayRangos[i].de19a35=' ';
                    }
                    if(i < mayores)
                    {
                        arrayRangos[i].mas35='X';
                    }
                    else
                    {
                        arrayRangos[i].mas35=' ';
                    }
                }
                for(i=0; i < rango-1; i++)
                {
                    if(arrayRangos[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i; j < rango; j++)
                    {
                        if(arrayRangos[j].estado == -1)
                        {
                            continue;
                        }
                        if(arrayRangos[i].menos18 < arrayRangos[j].menos18)
                        {
                            auxRangos=arrayRangos[j];
                            arrayRangos[j]=arrayRangos[i];
                            arrayRangos[i]=auxRangos;
                        }
                    }
                }
                printf("          Grafico de edad\n");
                for(i = rango-1; i > -1; i--)
                {
                     printf("   %c             %c            %c\n",arrayRangos[i].menos18, arrayRangos[i].de19a35, arrayRangos[i].mas35);
                }
                printf("De 0 a 18       19 a 35       35 o mas\n");

                menores=0;
                mayores=0;
                adolecentes=0;

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}






