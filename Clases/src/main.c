#include <stdio.h>
#include <stdlib.h>
#include "../fagundez/fagundez.h"
#define TAM 5
#define ASC 1
#define DESC 0

void ejercicioUno(void);
void ejercicioDos(void);
void ejercicioTres(void);
void ejercicioClase(void);
void ejercicioClase2(void);
void ejercicioTP(void);

void mostrarVectorEnteros(int vec[], int tam);

void mostrarVectorCaracteres(char vec[], int tam);

/**
 * @brief Ordenar vector de enteros
 * @param int[] array de enteros
 * @param tam tamaño de vector
 * @param criterio Criterio de ordenamiento 1 es ascendente y 0 descendente
 * @return ocurrio correctamente
  */
int ordenarVectorEnteros(int vec[], int tam, int criterio);

/**
 * @brief Ordenar vector de caracteres
 * @param char[] array de enteros
 * @param tam tamaño de vector
 * @param criterio Criterio de ordenamiento 1 es AScendente y 0 descendente
 * @return ocurrio correctamente
  */
int ordenarVectorCaracteres(char vec[], int tam, int criterio);

/**
 * @brief Ordenar vector de caracteres
 * @param char[] array de enteros
 * @param tam tamaño de vector
 * @param caracter Caracter a buscar
 * @param reemplazo reemplazo de caracter
 * @return ocurrio correctamente
  */
int remplazarCaracter(char vec[], int tam, char caracterABuscar, char reemplazo);

int main()
{
	int option;
	int success;

	int numc = 3;

	int vector[TAM];

	char caracteres[TAM] = {'a', 'm', 'a', 'p', 'o'};

	// for (int i = 0; i < TAM; i++)
	// {
	// 	printf("Ingrese un numero de la posicion: %d\n", i);
	// 	scanf("%d", &vector[i]);
	// };
	// printf("\n\n");

	// mostrarVectorEnteros(vector, TAM);

	// mostrarVectorCaracteres(caracteres, TAM);
	// ordenarVectorCaracteres(caracteres, TAM, 1);
	// mostrarVectorCaracteres(caracteres, TAM);

	// int cant = remplazarCaracter(caracteres, TAM, 'a', 'x');

	// printf("Cantidad %d\n", cant);
	// printf("Caracteres: ");
	// mostrarVectorCaracteres(caracteres, TAM);

	setbuf(stdout, NULL);
	printf(
		"Ingrese el ejercicio que quiere ver: (1,2, 3, 4, 5 o 0 para cancelar) \n");
	success = scanf("%d", &option);

	while (!success || option < 0 || option > 5)
	{
		fflush(stdin);
		printf("ERROR. Ingrese un ejercicio válido que quiere ver: (1,2 o 3, 4 o 0  para cancelar)");
		success = scanf("%d", &option);
	}

	switch (option)
	{
	case 1:
		ejercicioUno();
		break;
	case 2:
		ejercicioDos();
		break;
	case 3:
		ejercicioTres();
		break;
	case 4:
		ejercicioClase();
		break;
	case 5:
		ejercicioClase2();
		break;
	case 0:
		printf("Programa finalizado por el usuario");
	}

	return EXIT_SUCCESS;
}

void mostrarVectorEnteros(int vec[], int tam)
{
	for (int i = tam - 1; i > -1; i--)
	{
		printf("%d, ", vec[i]);
	};
	printf("\n\n");
}

void mostrarVectorCaracteres(char vec[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		printf("%c", vec[i]);
	};
	printf("\n-------------------------------------\n");
}

int ordenarVectorCaracteres(char vec[], int tam, int asc)
{
	int success = 0;
	if (vec != NULL && tam > 0 && (asc == 0 || asc == 1))
	{
		char aux;
		for (int i = 0; i < tam; i++)
		{
			for (int j = i + 1; j < tam; j++)
			{
				if ((asc && vec[i] > vec[j]) || (!asc && vec[i] < vec[j]))
				{
					aux = vec[i];
					vec[i] = vec[j];
					vec[j] = aux;
				}
			}
		}
		success = 1;
	}

	return success;
}

int ordenarVectorEnteros(int vec[], int tam, int asc)
{
	int success = 0;
	if (vec != NULL && tam > 0 && (asc == 0 || asc == 1))
	{
		int aux;
		for (int i = 0; i < tam; i++)
		{
			for (int j = i + 1; j < tam; j++)
			{
				if ((asc && vec[i] > vec[j]) || (!asc && vec[i] < vec[j]))
				{
					aux = vec[i];
					vec[i] = vec[j];
					vec[j] = aux;
				}
			}
		}
		success = 1;
	}

	return success;
}

int remplazarCaracter(char vec[], int tam, char caracterABuscar, char reemplazo)
{
	int contador = 0;
	if (vec != NULL && tam > 0)
	{

		for (int i = 0; i < tam; i++)
		{
			if (vec[i] == caracterABuscar)
			{
				vec[i] = reemplazo;
				contador++;
			}
		}
	}

	return contador;
}