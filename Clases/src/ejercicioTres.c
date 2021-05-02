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
	int notaPromedio;

	int cantidadMaterias;
	int contMasc=0;
	int acumMasc=0;
	int contFem=0;
	int acumFem=0;
	int contNoBin=0;
	int acumNoBin=0;
	int edad;
    int edadMayCantMat;
    int legajoMayCantMat;
    int legMasJovLibr;
    int legMejPromFem;
    int mayCantMat;
	int mejorPromFem;
	int menorEdadLibre;

    int primerFem = 1;
    int primMascLibre= 1;
    int primEst = 1;

    float promMasc;
    float promFem;
    float promNoBin;

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
			printf("ERROR. Ingrese un tipo de cursada válido. Opciones: ('L'=libre, 'P'=presencial o 'R'=remota) \n");
			fflush(stdin);
			scanf("%c", &tipoCursada);
		}

		printf("Ingrese cantidad de materias \n");
		scanf("%d", &cantidadMaterias);
		while(cantidadMaterias < 1 || cantidadMaterias > 7)
		{
			printf("ERROR. Ingrese cantidad de materias válido (entre 1 y 7) \n");
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

//		 Se debe informar de existir, o informar que no existe , en el caso que
//		 corresponda.

//		 c) El promedio de nota por sexo.
		switch(sexo)
		{
	        case 'F':
	        	if(mejorPromFem < notaPromedio || primerFem)
	        	{// a) El Legajo del mejor promedio que femenino.
	        		legMejPromFem=legajo;
	        		primerFem=0;
	        		mejorPromFem=notaPromedio;
	        	}
	        	acumFem+=notaPromedio;
	        	contFem++;
	     		break;
	   		case 'M':
	   			if(tipoCursada == 'L' && (menorEdadLibre > edad || primMascLibre))
	   			{//b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
	   				legMasJovLibr=legajo;
	   				primMascLibre=0;
	   				menorEdadLibre=edad;
	   			}
	   			acumMasc+=notaPromedio;
	   			contMasc++;
				break;
	   		case 'O':
	   			acumNoBin+=notaPromedio;
	   		    contNoBin++;
	   			break;
		}
       //d) La edad y legajo del que cursa más materias. (Sin importar su género)
        if(mayCantMat > cantidadMaterias || primEst)
        {
        	mayCantMat = cantidadMaterias;
        	edadMayCantMat = edad;
        	legajoMayCantMat = legajo;
        	primEst = 0;
        }

	} while (respuesta == 's');

//c) El promedio de nota por sexo.
if(contMasc != 0)
{
	//b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
	if(primMascLibre)
	{
		printf("No se ingresaron alumnos masculinos que cursaran libre\n");
	}
	else
	{
		printf("El legajo del más joven de los alumnos masculinos que rinden libre es: %d\n", legMasJovLibr);
	}

	promMasc = (float)acumMasc / contMasc;
	printf("El promedio de nota de los alumnos másculinos es de: %.2f\n", promMasc);
}
else
{
	printf("No se ingresaron alumnos masculinos");
}

if(contFem != 0)
{
	//a) El Legajo del mejor promedio que femenino.
	if(primerFem)
	{
		printf("No se ingresaron alumnas. \n");
	}
	else
	{
		printf("EL legajo de la mejor estudiante es: %d\n", legMejPromFem);
	}
	promFem = (float)acumFem / contFem;
	printf("El promedio de nota de los alumnos femeninos es de: %.2f\n", promFem);

}
else
{
	printf("No se ingresaron alumnos femeninos.\n");
}

if(contNoBin != 0)
{
	promNoBin = (float)acumNoBin / contNoBin;
	printf("El promedio de nota de los alumnos no binarios es de: %.2f\n", promNoBin);
}
else
{
	printf("No se ingresaron no binarios.\n");
}
//d) La edad y legajo del que cursa más materias. (Sin importar su género)
printf("El alumno que cursas más materias es:\n");
printf("Edad: %d \n", edadMayCantMat);
printf("Legajo: %d \n", legajoMayCantMat);

}
