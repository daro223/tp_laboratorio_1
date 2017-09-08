#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Solicita un numero de tipo flotante al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return el numero ingresado por el usuario
 *
 */

float getFloat(char mensaje []){
     float auxiliar;
     printf("%s",mensaje);
     scanf("%f",&auxiliar);
     return auxiliar;
}

 /**
 * \brief Solicita un numero de tipo entero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return el numero ingresado por el usuario
 *
 */

int getInt(char mensaje []){
     int auxiliar;
     printf("%s",mensaje);
     scanf("%d",&auxiliar);
     return auxiliar;
}

 /**
 * \brief toma dos numeros flotantes y los suma
 * \param numero1 es el primer numero, numero2 es el segundo numero
 * \return el resultado de la suma de ambos numeros
 *
 */
float sumaNumero(float numero1, float numero2){
    float x=numero1;
    float y=numero2;
    float suma=x+y;

    return suma;
}

 /**
 * \brief toma dos numeros flotantes y los resta.
 * \param numero1 es el primer numero, numero2 es el segundo numero
 * \return el resultado de la resta de ambos numeros
 *
 */
float restaNumero(float numero1, float numero2){
    float x=numero1;
    float y=numero2;
    float resta=x-y;

    return resta;
}

 /**
 * \brief toma dos numeros flotantes y los multiplica.
 * \param numero1 es el primer numero, numero2 es el segundo numero
 * \return el resultado de la multiplicacion de ambos numeros
 *
 */
float multiplicacion(float numero1, float numero2){
    float x=numero1;
    float y=numero2;
    float multiplicacion=x*y;

    return multiplicacion;
}

 /**
 * \brief toma dos numero flotantes y los divide.
 * \param numero1 es el primer numero, numero2 es el segundo nunero
 * \return el resultado de la division de ambos numeros
 *
 */
float division(float numero1, float numero2){
    float x=numero1;
    float y=numero2;
    float division;
    division=x/y;

    return division;
}


 /**
 * \brief toma un numero y devuelve el factorial
 * \param numero es el numero a tomar
 * \return el factorial de un numero
 *
 */


float factorial(float n){
    float resp;
    if(n==1){
        return 1;
    }
    else{
        resp=n * factorial(n-1);
    }
    return (resp);
}

