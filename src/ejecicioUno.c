#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 *  * Ejercicio 1:
 Ingresar námeros enteros, hasta que el usuario lo decida. Calcular y mostrar:
 a) El promedio de los námeros positivos.
 b) El promedio de los námeros negativos.

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

		printf("Ingrese un número: \n");
		converted = scanf("%d", &num); //Si no consigue ningun elemento que concida con la mascara retorna cero

		if (!converted)
		{
			fflush(stdin); // si no es un número debo limpiear el bufer
			printf("ERROR. Ingrese un número válido: \n");
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
					"ERROR. Ingrese una opción válida. Desea continuar: (s/n) \n");
			fflush(stdin);
			scanf("%c", &respuesta);
		}

	} while (respuesta == 's');

	if (contPos > 0)
	{
		promPos = acumPos / contPos;
		printf("El promedio de los números positivos es: %.2f\n", promPos);
	}
	else
	{
		printf("No se ingresaron números positivos.\n");
	}

	if (contNeg > 0)
	{
		promNeg = acumNeg / contNeg;
		printf("El promedio de los números negativos es: %.2f\n", promNeg);
	}
	else
	{
		printf("No se ingresaron números negativos.\n");
	}

}
