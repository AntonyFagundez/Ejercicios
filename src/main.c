#include <stdio.h>
#include <stdlib.h>

void ejercicioUno(void);
void ejercicioDos(void);
void ejercicioTres(void);
/*
 *
 *
 * */

int main()
{
	int option;
	int success;

	setbuf(stdout, NULL);
	printf(
			"Ingrese el ejercicio que quiere ver: (1,2, 3 o 0 para cancelar) \n");
	success = scanf("%d", &option);

	while (!success || option < 0 || option > 3)
	{
		fflush(stdin);
		printf(
				"ERROR. Ingrese un ejercicio válido que quiere ver: (1,2 o 3 o 0  para cancelar)");
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
	case 0:
		printf("Programa finalizado por el usuario");
		return EXIT_SUCCESS;

	}

	return EXIT_SUCCESS;
}
