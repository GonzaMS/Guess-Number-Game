/*
    Piensa un numero del 0 al 1.000.000

    Es 500.000 ?
    No, un numero mayor

    Es tu numero 700.00?
    No, es un numero menor

    Es tu numero 800.000?
    No, es un numero menor

    Es tu numero 600.000?
    Si, es mi numero

    Como funciona

    logBase2(1.000.000) = 20.000

    (1.000.000 + 0 - 0)/ 2 == 500.000? Rango 0 al 1.000.000 (1.000.000)

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{

    // Declaracion de variables

    int rangoBajo = 0;                                              // Rango mas bajo a adivinar
    int rangoAlto = 1000000;                                        // Rango mas alto a adivinar
    int adivinacionesPosible = rangoAlto + rangoBajo - 1;           // Rango maximo de numeros a adivinar
    int intentosMaximos = ceil(log(adivinacionesPosible) / log(2)); // Intentos posibles redondeados que llevara adivinar
    int adivinacion;                                                // El numero que la computadora adivina
    int jugador;                                                    //(1)Sí, es mi numero (2)No, es un numero menor (3)No, es un numero mayor
    int intentos = 1;                                               // Contador de turnos

    printf("Piensa en un numero del %d al %d, Puedo adivinar el numero en %d turnos\n", rangoBajo, rangoAlto, intentosMaximos);

    do
    {
        // Generar numero aleatorio
        adivinacionesPosible = rangoAlto + rangoBajo - 1;
        adivinacion = (int)ceil(adivinacionesPosible / 2);
        printf("Es tu numero %d?\n", adivinacion);
        printf("(1)Si, es mi numero\n");
        printf("(2)No, es un numero menor\n");
        printf("(3)No, es un numero mayor\n");
        scanf("%d", &jugador); // Recibe el numero que el jugador ingreso

        if (jugador == 3)
        {
            rangoBajo = adivinacion + 1;
        }
        else if (jugador == 2)
        {
            rangoAlto = adivinacion - 1;
        }
        else if (jugador == 1)
        {
            printf("Felicidades, adivinaste en %d intentos\n", intentos);
        }
        else
        {
            printf("Ingrese un numero valido\n");
        }

        intentos++;

    } while (jugador != 1 && intentos <= intentosMaximos);
}
