#include <stdio.h>
#include <stdlib.h>
#define TAM 10

float calcularPromedio(int num1, int num2);

void mostrarPromedios(int n1[], int n2[], float prom[], int legajos[], char sexo[], int tam);

void ordenarAlumnos(int n1[], int n2[], float prom[], int legajos[], char sexo[], int tam);

int ejercicioClase2()
{
    int legajos[TAM] = {123, 243, 356, 475, 534, 345, 234, 156, 264, 284};
    char sexo[TAM] = {'m', 'f', 'm', 'f', 'm', 'f', 'f', 'm', 'f', 'm'};
    int notas1[TAM] = {1, 2, 3, 4, 5, 1, 7, 7, 8, 10};
    int notas2[TAM] = {1, 2, 3, 4, 5, 10, 3, 4, 6, 8};
    float promedios[TAM];

    for (int i = 0; i < TAM; i++)
    {
        // printf("Ingrese nota 1 parcial: ");
        // scanf("%d", &notas1[i]);

        // printf("Ingrese nota segundo parcial: ");
        // scanf("%d", &notas2[i]);

        // printf("Ingrese legajo: ");
        // scanf("%d", &legajos[i]);

        // fflush(stdin);
        // printf("Ingrese sexo: ");
        // scanf("%c", &sexo[i]);

        promedios[i] = calcularPromedio(notas1[i], notas2[i]);
    }

    mostrarPromedios(notas1, notas2, promedios, legajos, sexo, TAM);

    ordenarAlumnos(notas1, notas2, promedios, legajos, sexo, TAM);

    mostrarPromedios(notas1, notas2, promedios, legajos, sexo, TAM);
    system("pause");

    return 0;
}

float calcularPromedio(int num1, int num2)
{
    return (float)(num1 + num2) / 2;
}

void mostrarPromedios(int n1[], int n2[], float prom[], int legajos[], char sexo[], int tam)
{
    //system("cls");
    printf("*** Listado Alumnos ***\n");
    printf("Legajo sexo  Nota 1 parcial  Nota 2parcial  Promedio\n");
    for (int i = 0; i < tam; i++)
    {
        printf("  %2d     %2c    %2d               %2d             %5.2f\n", legajos[i], sexo[i], n1[i], n2[i], prom[i]);
    }

    printf("\n\n");
}

void ordenarAlumnos(int n1[], int n2[], float prom[], int legajos[], char sexo[], int tam)
{
    int auxInt;
    float auxFloat;
    char auxChar;

    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (prom[i] < prom[j])
            { //Criterio de ordenamiento
                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;

                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;

                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;
            }
        }
    }
}
