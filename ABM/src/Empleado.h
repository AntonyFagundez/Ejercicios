/*
 * Empleado.h
 *
 *  Created on: 23 abr. 2021
 *      Author: Antony
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct {
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct {
	int legajo;
	char nombre[20];
	int edad;
	char sexo;
	float sueldo;
	eFecha fechaIngreso;
	int isEmpty;
}eEmpleado;

/**
 * @brief funcion para cargar empleado en espacio en memora
 *
 * @param empleado referencia de empleado
 */
void cargarEmpleado(eEmpleado *empleado);

/**
 * @brief funcion para crearEmpleado
 *
 * @returns Empleado
 */
eEmpleado crearEmpleado();

/**
 * @brief mostrar la lista de empleados
 *
 * @param lista - lista de empleados a mostrar
 * @param tam - tamaño de empleados
 */
void mostrarEmpleados(eEmpleado lista[], int tam);

/**
 * @brief funcion para mostrar el empleado
 *
 * @param empleado - empleado a mostrar
 */
void mostrarEmpleado(eEmpleado empleado);


/**
 * @brief funcion para ordenar empleados por edad descendente
 *
 * @param lista - lista de empleados
 * @param tam - tamaño de lista de empleados
 */
void ordenarEmpleados(eEmpleado lista[], int tam);


/**
 * @brief funcion para inicializar empleados
 *
 * @param lista - lista de empleados
 * @param tam - tamaño de lista
 */
void inicializarEmpleados(eEmpleado lista[], int tam);


/**
 * @brief funcion para retornar el indice del empleado con el legajo indicado
 *
 * @param legajo
 * @return indice o -1 en caso de fallar
 */
int buscarLegajo(eEmpleado lista[], int tam, int legajo);

/**
 * @brief Elimina empleado con el indice indicado
 *
 * @param lista lista de emplados
 * @param tam tamanio  de la lista
 * @param indice indice donde se encuentra el empleado
 * @return 1 si es correcto o cero si no puede eliminarlo;
 */
int bajaEmpleado(eEmpleado lista[], int tam);


/**
 * @brief buscar empleado con legajo
 *
 * @param lista
 * @param tam
 * @param legajo
 * @return
 */
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
/**
 * @brief busca el primero libre
 *
 * @param lista
 * @param tam
 * @return
 */
int buscarIndice(eEmpleado lista[], int tam);

/**
 * @brief insertar empleado en la lista
 *
 * @param lista - lista de empleados
 * @param tam - tamanio de la lista de empleados
 * @param pId - proxLegajo;
 * @return success
 */
int altaEmpleado(eEmpleado lista[], int tam, int *pId);

/**
 * @brief modificar empleado
 *
 * @param lista
 * @param tam
 */
int modificarEmpleado(eEmpleado lista[], int tam);


#endif /* EMPLEADO_H_ */
