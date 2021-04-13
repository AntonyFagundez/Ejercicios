#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**

Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones. 
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B 
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones


 Antony Fagundez TP 1°G
 */

void ejercicioTres()
{

    int firstNumber;
    int secondNumber;

    int flagFirst=0;
    int flagSecond=0;

    char option;

    char contin = 's';

    do 
    {
        system("cls");
        printf("\t\t***Calculadora***\n");
        
        printf("Opciones:\n");
        if(flagFirst)
        {
            printf("1. Ingresar 1er operando (A=%d)\n", firstNumber);
        }
        else
        {
            printf("1. Ingresar 1er operando (A=x)\n");
        }

        if(flagSecond)
        {
            printf("2. Ingresar 2do operando (B=%d)\n", secondNumber);
        }
        else
        {
            printf("2. Ingresar 2do operando (B=Y)\n");
        }

        printf("3.- Calcular todas las operaciones\n");
        printf("\ta).- Calcular la suma (A+B)\n");
        printf("\tb).- Calcular la resta (A-B)\n");
        printf("\tc).- Calcular la division (A/B)\n");
        printf("\td).- Calcular la multiplicacion (A*B)\n");
        printf("\te).- Calcular el factorial (A!)\n");
        printf("4.- Informar resultados\n");
        printf("5. Salir\n");


        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 'a':
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            break;
        case 'e':
            break;
        case 4:
            break;
        case 5:
            break;
        
        default:
            break;
        }





    } while (contin == 's'); 

}


