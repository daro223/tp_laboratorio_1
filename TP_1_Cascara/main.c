#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numUno=0;
    float numDos=0;
    float total;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",numUno);
        printf("2- Ingresar 2do operando (B=%.2f)\n",numDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");
        printf("Ingrese numero de opcion: ");

        scanf("%d",&opcion);

        printf("_____________________\n\n");
        switch(opcion)
        {
            case 1:
                numUno=getFloat("ingrese 1er operando: ");
                printf("_____________________\n\n");
                break;
            case 2:
                numDos=getFloat("ingrese 2do operando: ");
                printf("_____________________\n\n");
                break;
            case 3:
                total=sumaNumero(numUno,numDos);
                printf("La suma de %.2f y %.2f es %.2f\n\n",numUno,numDos,total);
                printf("_____________________\n\n");
                break;
            case 4:
                total=restaNumero(numUno,numDos);
                printf("La resta de %.2f y %.2f es %.2f\n\n",numUno,numDos,total);
                printf("_____________________\n\n");
                break;
            case 5:
                while(numDos==0){
                    printf("ERROR no se puede divir por 0(CERO)\n\n");
                    numDos=getInt("ingrese 2do operando: ");
                    printf("_____________________\n\n");
                }
                total=division(numUno,numDos);
                printf("La division entre %.2f y %.2f es %.2f\n\n",numUno,numDos,total);
                printf("_____________________\n\n");
                break;
            case 6:
                total=multiplicacion(numUno,numDos);
                printf("La multiplicacion entre %.2f y %.2f es %.2f\n\n",numUno,numDos,total);
                printf("_____________________\n\n");
                break;
            case 7:
                if(numUno>0 && numUno<35){
                  printf("El factorial de %.2f es %.2f\n",numUno,factorial(numUno));
                printf("_____________________\n\n");
                }
                else if(numUno<1){
                    printf("El factorial de %.2f no se puede calcular\n\n",numUno);
                }
                else{
                    printf("El factorial es demasiado grande para ser mostrado\n\n");
                }
                break;
            case 8:
                while(numUno==0){
                    printf("ERROR para realizar esta operacion el 1er operando no puede ser 0(CERO)\n\n");
                    numUno=getInt("ingrese 1er operando: ");
                    printf("_____________________\n\n");
                }
                while(numDos==0){
                    printf("ERROR para realizar esta operacion el 2do operando no puede ser 0(CERO)\n\n");
                    numDos=getInt("ingrese 2do operando: ");
                    printf("_____________________\n\n");
                }
                total=sumaNumero(numUno,numDos);
                printf("La suma de %.2f y %.2f es %.2f\n\n",numUno,numDos,total);
                printf("_____________________\n\n");

                total=restaNumero(numUno,numDos);
                printf("La resta de %.2f y %.2f es %.2f\n\n",numUno,numDos,total);
                printf("_____________________\n\n");


                total=division(numUno,numDos);
                printf("La division entre %.2f y %.2f es %.2f\n\n",numUno,numDos,total);
                printf("_____________________\n\n");

                total=multiplicacion(numUno,numDos);
                printf("La multiplicacion entre %.2f y %.2f es %.2f\n\n",numUno,numDos,total);
                printf("_____________________\n\n");

                if(numUno>0 && numUno<35){
                  printf("El factorial de %.2f es %.2f\n",numUno,factorial(numUno));
                printf("_____________________\n\n");
                }
                else if(numUno<1){
                    printf("El factorial de %.2f no se puede calcular\n\n",numUno);
                }
                else{
                    printf("El factorial es demasiado grande para ser mostrado\n\n");
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }


    }


    return 0;
}
