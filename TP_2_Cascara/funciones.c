#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



/**\brief Obtiene el primer indice libre del array.
     *
     * @param lista el array se pasa como parametro.
     * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[],int cant,int valor)
{
    int espacioLibre;
    int i;
    for(i=0;i<cant;i++)
    {
        if(lista[i].estado == valor)
        {
            espacioLibre = i;
            printf("\n      Usted dispone de estacio para ingregar datos\n");
            break;
        }
        else{
            espacioLibre = -1;
        }
    }
    return espacioLibre;
}

/**\brief Obtiene el indice que coincide con el dni pasado por parametro.
     *
     * @param lista: el array se pasa como parametro.
     * @param dni: dni a ser buscado en el array.
     * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */


int buscarPorDni(ePersona lista[],int cant, int dni)
{
    int i;
    int valor=-1;
    for(i=0;i<cant;i++)
    {
        if(lista[i].dni==dni)
        {
            valor=i;
            break;
        }
    }
    return valor;
}


/**\brief Reemplazo las funciones printf y scanf, por getString
    *
    * \param Mensaje: es un array de caracteres
    * \param input: es el string escrito por el usuario
    * \return -
*/
void getString(char mensaje[],char input[])
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%[^\n]", input);
}

/**\brief declaro una variable para crear un buffer,
          guardo en ella lo que indique el uusario a traves de otra funcion "GetString",
          valido si esta compuesta solo por letras a traves de otra funcion "esSoloLetras"
    *
    * \param mensaje, lo que se requiera exponer por consola
    * \param input: la variable a llenar con lo que ingrese el usuario
* \return retorna 1 si es correcto el ingreso de letras, retorna 0 si es incorrecto
*/
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
* \brief declaro una variable para crear un buffer, guardo en ella lo que indique el uusario a través de otra funcion GetString,
         Valido si esta compuesta solo por Letras a través de otra funcion esNumerico
    *
    * \param mensaje, lo que se requiera exponer por consola
    * \param input: la variable a llenar con lo que ingrese el usuario
    * \return retorna 1 si es correcto el ingreso de letras, retorna 0 si es incorrecto
*/
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**\brief Valida si lo ingresado a la funcion está compuesto solo por numeros. Recorre un array hasta encontrar '\0'
    *
    * \param str: es el array de caracteres a validar.
    * \return retorna 1 si es correcto el ingreso de numeros, retorna 0 si es incorrecto
*/
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i]<'0' || str[i]>'9')
            return 0;
        i++;
    }
    return 1;
}



/**\brief Valida si lo ingresado a la funcion está compuesto solo por Letras. Recorre un array hasta encontrar '\0' el final del array
    *
    * \param str: es el array de caracteres a validar.
    * \return retorna 1 si es correcto el ingreso de letras, retorna 0 si es incorrecto
*/
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z'))
            return 0;
        i++;
    }
    return 1;
}


/**\brief inicializa un array de personas poniendo un valor entero en el atributo estado de la estructura persona
    *
    * \param ePersona es la estructura, se envia como Array
    * \param cantidadPersonas es la cantidad de veces a recorrer el array
    * \param valor representa al valor a considerarse en el Estado que determina si la posicion esta libre o no
    * \return no retona valores.
*/
void inicializarArray(ePersona vecPersona[],int cantidadPersonas,int valor)
{
    int i;
    for(i = 0;i < cantidadPersonas; i++)
    {
        vecPersona[i].estado = valor;
    }
}



/**\brief inicializa un array de edades poniendo un valor entero en el atributo estado de la estructura persona
    *
    * \param EPersona es la estructura, se envia como Array
    * \param cantidadPersonas es la cantidad de veces a recorrer el array
    * \param valor representa al valor a considerarse en el Estado que determina si la posicion esta libre o no
    * \return no retona valores.
*/
void graficarEdades(ERangos arrayRangos[],int rango,int valor)
{

    int i;
    for(i = 0;i < rango; i++)
    {
        arrayRangos[i].estado=valor;
    }
}
