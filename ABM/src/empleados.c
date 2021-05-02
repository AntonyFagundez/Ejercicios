/*
 ============================================================================
 Name        : empleados.c
 Author      : Antony Fagundez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#define TAM 2

#include <stdio.h>
#include <stdlib.h>
#include "menu_fagundez.h"
#include "Empleado.h"



int main(void)
{

	eEmpleado nomina[TAM]; // ={{1234, "antony", 26, 'm', 135000, {8,6,1994}}, {546, "maria", 28, 'f', 200000, {5,12,2014}}, {846, "juan", 21, 'm', 60000, {8,6,2020}}};
	//eEmpleado emp;
	int nextId = 2000;
	char continuar = 's';

	inicializarEmpleados(nomina, TAM);
	system("cls");

	do
	{
		switch (menu())
		{
		case 1:
			if (altaEmpleado(nomina, TAM, &nextId))
			{
				printf("Empleado ingreado correctamente\n");
			}else
			{
				printf("Hubo un problema al dar de alta\n");
			}
			break;
		case 2:
			modificarEmpleado(nomina, TAM);
			break;
		case 3:
			if(bajaEmpleado(nomina, TAM))
			{
				printf("Empleado dado de baja correctamente\n");
			}
			else
			{
				printf("Hubo un problema al dar de baja\n");
			}
			break;
		case 4:
			mostrarEmpleados(nomina, TAM);
			break;

		case 7:
			continuar = 'n';
            break;

		}

		system("pause");
	} while (continuar == 's');

	return EXIT_SUCCESS;
}




