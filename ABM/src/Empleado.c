/*
 * Empleado.c
 *
 *  Created on: 23 abr. 2021
 *      Author: Antony
 */
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarEmpleado(eEmpleado *empleado)
{
	printf("Ingrese legajo: ");
	scanf("%d", &empleado->legajo);

	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(empleado->nombre);

	printf("Ingrese edad: ");
	scanf("%d", &empleado->edad);

	printf("Ingrese sexo: ");
	fflush(stdin);
	scanf("%c", &empleado->sexo);

	printf("Ingrese sueldo: ");
	scanf("%f", &empleado->sueldo);

	printf("Ingrese fecha de Ingreso (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &empleado->fechaIngreso.dia, &empleado->fechaIngreso.mes,
			&empleado->fechaIngreso.anio);
}

void mostrarEmpleados(eEmpleado lista[], int tam)
{

	int invalidEmployees = 1;

	printf("    *** Empleados ***\n");
	printf(
			"Indice Legajo      Nombre     Edad   Sexo    Sueldo    Fecha de Ingreso\n");

	for (int i = 0; i < tam; i++)
	{
		if (!lista[i].isEmpty)
		{
			printf("  %d   ", i);
			mostrarEmpleado(lista[i]);
			invalidEmployees = 0;
		}
	}

	if (invalidEmployees)
	{
		printf("\n\t\tNo hay empleados en la lista");
	}

	printf("\n\n");
}

void mostrarEmpleado(eEmpleado empleado)
{
	printf("%6d    %10s     %2d    %c    %10.2f    %02d/%02d/%d\n",
			empleado.legajo, empleado.nombre, empleado.edad, empleado.sexo,
			empleado.sueldo, empleado.fechaIngreso.dia,
			empleado.fechaIngreso.mes, empleado.fechaIngreso.anio);
}

void ordenarEmpleados(eEmpleado lista[], int tam)
{

	eEmpleado aux;

	for (int i = 0; i < tam - 1; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			//ordernar por sexos descendente y por legajo ascendente
			if (lista[i].sexo < lista[j].sexo
					|| (lista[i].sexo < lista[j].sexo
							&& lista[i].legajo > lista[j].legajo))
//			if(lista[i].edad < lista[j].edad)
//			if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
			{
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}

}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		lista[i].isEmpty = 1;
	}
}

eEmpleado crearEmpleado()
{
	eEmpleado empleado;

	//printf("Ingrese legajo: ");
	//scanf("%d", &empleado.legajo);

	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(empleado.nombre);

	printf("Ingrese edad: ");
	scanf("%d", &empleado.edad);

	printf("Ingrese sexo: ");
	fflush(stdin);
	scanf("%c", &empleado.sexo);

	printf("Ingrese sueldo: ");
	scanf("%f", &empleado.sueldo);

	printf("Ingrese fecha de Ingreso (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &empleado.fechaIngreso.dia, &empleado.fechaIngreso.mes,
			&empleado.fechaIngreso.anio);

	empleado.isEmpty = 0;

	return empleado;
}

int buscarLegajo(eEmpleado lista[], int tam, int legajo)
{
	int index = -1;

	if (lista != NULL && tam > 0 && legajo > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (lista[i].legajo == legajo)
			{
				index = i;
				break;
			}
		}
	}

	return index;

}

int bajaEmpleado(eEmpleado lista[], int tam)
{
	int success = 0;
	int legajo;
	int indice;
	char confirm;

	system("cls");
	printf("      Baja empleado\n\n");
	mostrarEmpleados(lista, tam);

	printf("Ingrese legajo: ");
	scanf("%d", &legajo);

	indice = buscarEmpleado(lista, tam, legajo);

	if (indice == -1)
	{
		printf("ERROR. No se consiguio el empleado con el legajo: %d\n",
				legajo);
	}
	else
	{
		mostrarEmpleado(lista[indice]);

		printf("Confirma baja: ");
		fflush(stdin);
		scanf("%c", &confirm);
		if (confirm == 's')
		{
			lista[indice].isEmpty = 1;
			success = 1;
		}
		else
		{
			printf("Baja cancelada por el usuario\n");
		}
	}

	return success;

}

int buscarIndice(eEmpleado lista[], int tam)
{
	int index = -1;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
	int index = -1;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (!lista[i].isEmpty && lista[i].legajo == legajo)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int altaEmpleado(eEmpleado lista[], int tam, int *pId)
{
	int success = 0;
	int indice;
	eEmpleado nuevoEmpleado;
	system("cls");
	printf("     Alta Empleado\n\n");
	printf("Legajo: %d\n", *pId);

	if (lista != NULL && tam > 0 && pId != NULL)
	{
		indice = buscarIndice(lista, tam);

		if (indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			nuevoEmpleado = crearEmpleado();
			nuevoEmpleado.legajo = *pId;
			nuevoEmpleado.isEmpty = 0;

			lista[indice] = nuevoEmpleado;
			*pId = (*pId) + 1;
			success = 1;
		}

	}

	return success;
}

int modificarEmpleado(eEmpleado lista[], int tam)
{
	int success = 0;
	int legajo;
	int indice;
	int option;
	char cont = 's';
	int successSecondMenu = 0;

	system("cls");
	printf("      Modificar empleado\n\n");
	mostrarEmpleados(lista, tam);

	printf("Ingrese legajo: ");
	scanf("%d", &legajo);

	indice = buscarEmpleado(lista, tam, legajo);

	if (indice == -1)
	{
		printf("ERROR. No se consiguio el empleado con el legajo: %d\n",
				legajo);
	}
	else
	{
		mostrarEmpleado(lista[indice]);
		printf("Propiedades Modificables: \n");

		printf("1.- nombre\n");
		printf("2.- sexo\n");
		printf("3.- sueldo\n");
		printf("0 SALIR\n");

		do
		{
			printf("Ingrese campo a editar: ");
			fflush(stdin);

			scanf("%d", &option);

			switch (option)
			{
			case 1:
				printf("Nombre actual: %s\n", lista[indice].nombre);
				printf("Ingrese nuevo nombre: ");
				fflush(stdin);
				gets(lista[indice].nombre);
				break;
			case 2:
				printf("Sexo actual: %c\n", lista[indice].sexo);
				printf("Ingrese nuevo sexo: ");
				fflush(stdin);
				scanf("%c", &lista[indice].sexo);
				break;
			case 3:
				printf("Sueldo actual: %.2f\n", lista[indice].sueldo);
				printf("Ingrese nuevo sueldo: ");
				scanf("%f", &lista[indice].sueldo);
				break;
			case 0:
				printf("Operacion cancelada por el usuario");
				cont = 'n';
				break;
			default:
				break;
			}
		} while (cont == 's');
		success = 1;
		successSecondMenu = 1;
	}

	if (successSecondMenu)
	{
		return success;
	}

	return success;
}
