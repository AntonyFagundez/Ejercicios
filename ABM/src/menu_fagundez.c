/*
 * menu_fagundez.c
 *
 *  Created on: 26 abr. 2021
 *      Author: Antony
 */
#include <stdio.h>


int menu()
{
	int option;

	printf("Menu:\n");
	printf("1.- Alta empleado\n");
	printf("2.- Modificar Empleado\n");
	printf("3.- Baja Empleado\n");
	printf("4.- Listar empleados\n");
	printf("5.- Ordenar empleados\n");
	printf("6.- Informes\n");
	printf("7.- Salir\n");

	printf("Ingrese opcion: ");
	scanf("%d", &option);
	while (option < 0 || option > 7)
	{
		printf("ERROR. Ingrese opcion valida (entre 0 y 7): ");
		fflush(stdin);
		scanf("%d", &option);
	}

	return option;
}
