#include <stdio.h>
#include <stdlib.h>

/**
 *  Ejercicio 3:
 Realizar el algoritmo que permita ingresar los datos de los alumnos de una
 divisi�n de la UTN FRA, los datos solicitados son:
 Legajo
 Tipo cursada(L: &quot;libre&quot; - P: &quot;presencial&quot; � R: &quot;remota&quot;)
 Cantidad de materias( mas de cero y menos de 8)
 Sexo (F: �femenino� � M: �masculino� , O: �no binario�)
 Nota promedio (entre 0 y 10)
 Edad (validar)
 Se debe informar de existir, o informar que no existe , en el caso que
 corresponda.
 a) El Legajo del mejor promedio que femenino.
 b) El legajo del m�s joven de los alumnos masculinos entre los que dan libre.
 c) El promedio de nota por sexo.
 d) La edad y legajo del que cursa m�s materias. (Sin importar su g�nero)

 Antony Fagundez
 */

void ejercicioTres()
{
	char respuesta = 's';
	do
	{

		printf("Ingrese legajo");

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

}
