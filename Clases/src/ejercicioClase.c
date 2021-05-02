#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define RED 1
#define YELLOW 2
#define PURPLE 3
#define BLUE 4
#define GREEN 5
#define CYAN 6
#define YELLOWWARNING 7
#define RESET 0


void setColor(int color)
{
    switch (color)
    {
    case RED:
        printf("\033[1;31m");
        break;
    case YELLOW:
        printf("\033[0;33m");
        break;
    case PURPLE:
        printf("\033[0;35m");
        break;   
    case BLUE:
        printf("\033[0;34m");
        break;   
    case GREEN:
        printf("\033[0;32m");
        break;
    case RESET: 
        printf("\033[0m");
        break;
    case CYAN:
        printf("\033[0;36m");
        break;
    case YELLOWWARNING:
        printf("\x1B[33m");
        break;
    default:
        printf("\033[0m");
        break;
    }
}


/*
 *  * Ejercicio 1:

 Fagundez Antony 1 G
 * */
void ejercicioClase()
{
	int acumPos;
    char respuesta;
    char opcion;
    int flagCerrar = 1;
    char confirm;
    WORD Attributes = 0;

	respuesta = 's';
	setbuf(stdout, NULL);
	do
	{
        system("cls");
        setColor(PURPLE);
        printf("*** Menu de Opciones ***\n");
        setColor(GREEN);
        printf("a- Saludar\n");
        setColor(BLUE);
        printf("b- Brindar\n");
        setColor(CYAN);
        printf("c- Despedir\n");
        setColor(RED);
        printf("d- Salir\n");

        setColor(RESET);
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);


		switch (opcion)
        {
        case 'a':
            printf("Hola que tal\n");
            system("pause");
            break;
        case 'b':
            printf("chin chin\n");
            system("pause");
            break;
        case 'c':
            printf("Chau\n");
            system("pause");
            break;
        case 'd':
            if(flagCerrar)
            {
                setColor(YELLOWWARNING);
                printf("Desea salir realmente (s/n)?");
                setColor(RESET);
                fflush(stdin);
                confirm = getchar();
                if(confirm == 's')
                {
                    respuesta = 'n';
                }
                else
                {
                    printf("El programa continua habitualmente\n");
                    Sleep(1000);
                }

            }
            break;       
        default:
            break;
        }

	} while (respuesta == 's');


}
