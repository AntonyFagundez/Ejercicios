#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 *  Ejercicio 3:
 Realizar el algoritmo que permita ingresar los datos de los alumnos de una
 división de la UTN FRA, los datos solicitados son:
 Legajo X
 Tipo cursada(L: 'libre', P: 'presencial' o R: 'remota')
 Cantidad de materias( mas de cero y menos de 8)
 Sexo (F: 'femenino' , M: 'masculino' , O: 'no binario')
 Nota promedio (entre 0 y 10)
 Edad (validar)
 Se debe informar de existir, o informar que no existe , en el caso que
 corresponda.
 a) El Legajo del mejor promedio que femenino.
 b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
 c) El promedio de nota por sexo.
 d) La edad y legajo del que cursa más materias. (Sin importar su género)

 Antony Fagundez
 */

void ejercicioTres()
{
	int legajo;
	char tipoCursada;
	char sexo;
	int cantidadMaterias;
	int notaPromedio;
	int edad;

	char respuesta = 's';
	do
	{

		printf("Ingrese Legajo\n");
		scanf("%d",&legajo);

		printf("Ingrese tipo de cursada. Opciones: ('L'=libre, 'P'=presencial o 'R'=remota): \n");
		fflush(stdin);
		scanf("%c", &tipoCursada);
		tipoCursada = toupper(tipoCursada);
		while (tipoCursada != 'L' && tipoCursada != 'P' && tipoCursada != 'R')
		{
			printf("ERROR. Ingrese un tipo de cursada v�lido. Opciones: ('L'=libre, 'P'=presencial o 'R'=remota) \n");
			fflush(stdin);
			scanf("%c", &tipoCursada);
		}

		printf("Ingrese cantidad de materias \n");
		scanf("%d", &cantidadMaterias);
		while(cantidadMaterias < 1 || cantidadMaterias > 7)
		{
			printf("ERROR. Ingrese cantidad de materias v�lido (entre 1 y 7) \n");
			scanf("%d", &cantidadMaterias);
		}

		printf("Ingrese sexo. Opciones: ('F'=femenino, 'M'=masculino o 'O'=no binario): \n");
		fflush(stdin);
		scanf("%c", &sexo);
		sexo = toupper(sexo);
		while (sexo != 'F' && sexo != 'M' && sexo != 'O')
		{
			printf("ERROR. Ingrese un sexo válido. Opciones: ('F'=femenino, 'M'=masculino o 'O'=no binario) \n");
			fflush(stdin);
			scanf("%c", &tipoCursada);
		}

		printf("Ingrese Nota promedio \n");
		scanf("%d", &notaPromedio);
		while(notaPromedio < 0 || notaPromedio > 10)
		{
			printf("ERROR. Ingrese Nota promedio válido (entre 0 y 10) \n");
			scanf("%d", &cantidadMaterias);
		}

		printf("Ingrese Edad \n");
		scanf("%d", &edad);
		while(edad < 18)
		{
			printf("ERROR. Ingrese Edad válida (mayor a 17) \n");
			scanf("%d", &edad);
		}


		printf("Desea continuar (s/n): \n");
		fflush(stdin);
		scanf("%c", &respuesta);
		while (respuesta != 's' && respuesta != 'n')
		{
			printf("ERROR. Ingrese una opción válida. Desea continuar: (s/n) \n");
			fflush(stdin);
			scanf("%c", &respuesta);
		}

	} while (respuesta == 's');

}
