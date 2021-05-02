#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 5
/*
 Ejercicio 2:
 Ingresar 5 n�meros. Determinar cu�l es el m�ximo y el m�nimo e
 indicar en qu� orden fue ingresado.
 Fagundez Antony 1 G
 * */
void ejercicioDos()
{
	int cont;
	int minValue;
	int maxValue;
	int number;
	int converted;
	int numbers[5];
	int sizeOfArray;

	for (cont = 0; cont < MAX; ++cont) {

		printf("Ingrese el número de la posición %d\n", cont);
		converted = scanf("%d", &number);

		while(!converted)
		{
			fflush(stdin);
			printf("ERROR. Ingrese un número válido para la posición %d\n", cont);
			converted = scanf("%d", &number);
		}

		if(number < minValue || cont == 0)
		{
			minValue = number;
		}

		if(number > maxValue || cont == 0)
		{
	        maxValue = number;
		}

		numbers[cont] = number;
	}


	printf("El mayor número es: %d\n", maxValue);
	printf("El menor número es: %d\n", minValue);

	sizeOfArray = sizeof(numbers)/sizeof(int);
	for (int index = 0; index < sizeOfArray; ++index) {
		printf("El número %d fue ingresado en la posici�n %d\n", numbers[index], index);
	}


}
