#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 *  * Ejercicio 1:
 Ingresar n�meros enteros, hasta que el usuario lo decida. Calcular y mostrar:
 a) El promedio de los n�meros positivos.
 b) El promedio de los n�meros negativos.

 Fagundez Antony 1 G
 * */
void ejercicioUno()
{
	int acumPos;
	int acumNeg;
	int contPos;
	int contNeg;
	float promPos;
	float promNeg;

	int num;

	char respuesta;

	acumPos = 0;
	acumNeg = 0;
	contPos = 0;
	contNeg = 0;

	respuesta = 's';
	int converted;

	setbuf(stdout, NULL);
	do
	{

		printf("Ingrese un n�mero: \n");
		converted = scanf("%d", &num); //Si no consigue ningun elemento que concida con la mascara retorna cero

		if (!converted)
		{
			fflush(stdin); // si no es un n�mero debo limpiear el bufer
			printf("ERROR. Ingrese un n�mero v�lido: \n");
			converted = scanf("%d", &num);
		}

		if (num > -1)
		{
			acumPos += num;
			contPos++;
		}
		else
		{
			acumNeg += num;
			contNeg++;
		}

		printf("Desea continuar (s/n): \n");
		fflush(stdin);
		scanf("%c", &respuesta);
		while (respuesta != 's' && respuesta != 'n')
		{
			printf(
					"ERROR. Ingrese una opci�n v�lida. Desea continuar: (s/n) \n");
			fflush(stdin);
			scanf("%c", &respuesta);
		}

	} while (respuesta == 's');

	if (contPos > 0)
	{
		promPos = acumPos / contPos;
		printf("El promedio de los n�meros positivos es: %.2f\n", promPos);
	}
	else
	{
		printf("No se ingresaron n�meros positivos.\n");
	}

	if (contNeg > 0)
	{
		promNeg = acumNeg / contNeg;
		printf("El promedio de los n�meros negativos es: %.2f\n", promNeg);
	}
	else
	{
		printf("No se ingresaron n�meros negativos.\n");
	}

}
