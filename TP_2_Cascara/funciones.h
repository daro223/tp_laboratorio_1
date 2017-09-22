#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;
}ePersona;

typedef struct
{
    char menos18;
    char de19a35;
    char mas35;
    int estado;
}ERangos;

/**\brief Obtiene el primer indice libre del array.
     *
     * @param lista: el array se pasa como parametro.
     * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[],int cantidad, int valor);


/**\brief Obtiene el indice que coincide con el dni pasado por parametro.
     *
     * @param lista: el array se pasa como parametro.
     * @param dni: dni a ser buscado en el array.
     * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[],int cantidad, int dni);

/**\brief Las funciones printf y scanf son reemplazadas por getString
    *
    * \param Mensaje: es un array de caracteres
    * \param input: es el string escrito por el usuario
    * \return -
*/
void getString(char mensaje[],char input[]);

/**\brief declaro una variable para crear un buffer,
          guardo en ella lo que indique el usario a traves de la funcion "GetString",
          valida si esta compuesta solo por letras a traves de otra funcion "esSoloLetras"
    *
    * \param mensaje: lo que se requiera exponer por consola
    * \param input: la variable a llenar con lo que ingrese el usuario
    * \return retorna 1 si es correcto el ingreso de letras, retorna 0 si es incorrecto
*/
int getStringLetras(char mensaje[],char input[]);

/**\brief declaro una variable para crear un buffer,
          guardo en ella lo que indique el usario a traves de la funcion "GetString",
          valida si esta compuesta solo por letras a traves de la funcion "esNumerico"
    *
    * \param mensaje: lo que se requiera exponer por consola
    * \param input: la variable a llenar con lo que ingrese el usuario
    * \return retorna 1 si es correcto el ingreso de letras, retorna 0 si es incorrecto
*/
int getStringNumeros (char mensaje[],char input[]);

/**\brief Valida solo numeros. Recorre un array hasta encontrar "\0"
    *
    * \param str: es el array de caracteres a validar.
    * \return retorna 1 si es correcto el ingreso de numeros, retorna 0 si es incorrecto
*/
int esNumerico(char str[]);

/**\brief Valida solo letras. Recorre un array hasta encontrar "\0" el final del array
    *
    * \param str: es el array de caracteres a validar.
    * \return retorna 1 si es correcto el ingreso de letras, retorna 0 si es incorrecto
*/
int esSoloLetras(char str[]);


#endif // FUNCIONES_H_INCLUDED
