/*
 * entradaSalida.h
 *
 *  Created on: 27 mar. 2021
 *      Author: Yesid
 */
#include <stdio.h>
#include <ctype.h>
#ifndef ENTRADASALIDA_H_
#define ENTRADASALIDA_H_

/**
 * @brief imprime en pantalla la instruccion, guarda el dato ingresado por el usuario,
 * lo valida y en caso que este bien lo retornar, de lo contrario pide de nuevo al usuario ingresar el dato
 *
 * @param cadenaTexto, es la instruccion que se le pide al usuario realizar
 * @param cadenaError, es el mensaje de error, por si el ususario se equivoca
 * @param minimo, es el valor minimo que el usuario puede ingresar.
 * @param maximo, es el valor maximo que el usuario puede ingresar.
 * @return retorna el numero ingresado ya validado en tipo de dato double
 */
double pedirDecimalValidar(char cadenaTexto[], char cadenaError[], double minimo, double maximo);

/**
 * @brief imprime en pantalla la instruccion, guarda el dato ingresado por el usuario,
 * lo valida y en caso que este bien lo retornar, de lo contrario pide de nuevo al usuario ingresar el dato
 *
 * @param cadenaTexto, es la instruccion que se le pide al usuario realizar
 * @param cadenaError, es el mensaje de error, por si el ususario se equivoca al ingresar
 * @param minimo, es el valor minimo que el usuario puede ingresar.
 * @param maximo, es el valor maximo que el usuario puede ingresar.
 * @return retorna el numero ingresado ya validado en tipo de dato int
 */
int pedirEnteroValidar(char cadenaTexto[], char cadenaError[], int minimo, int maximo);

/**
 * @brief realiza la suma de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero sumando
 * @param segundoValor, segundo numero sumando
 * @return retorna el resultado de la suma en tipo de dato double
 */
double sumar(double primerValor, double segundoValor);

/**
 * @brief realiza la resta de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero es el minuendo
 * @param segundoValor, segundo numero es el substraendo
 * @return retorna la diferencia de la resta en tipo de dato double
 */
double restar(double primerValor, double segundoValor);

/**
 * @brief realiza la multiplicacion de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero es el multiplicando
 * @param segundoValor, segundo numero es el multiplicador
 * @return retorna el producto de la multiplicacion en tipo de dato double
 */
double multiplicar(double primerValor, double segundoValor);

/**
 * @brief realiza la division de dos numeros decimales o enteros pasados como parametros solo si es posible
 *
 * @param primerValor, primer numero es el dividiendo
 * @param segundoValor, segundo numero es el divisor
 * @return retorna el cociente de la division en tipo de dato double solo si se puede dividir,
 * de lo contrario retorna un -1.
 */
double dividir(double primerValor, double segundoValor);

/**
 * @brief valida y realiza el factorial del numero ingresado solo si se cumple la condicion
 *
 * @param valor, es el numero al cual se le realiza el factorial
 * @param minimo, es el valor minimo a calcular
 * @param maximo, es el valor maximo a calcular
 * @return retorna el factorial en tipo de dato double si cumple la condicion,
 * retorna -1 si no cumple la condicion o retorna 1 si el valor numerico ingresado es 0
 */
double factorialValidar(double valor, double minimo, double maximo);

/**
 * @brief valida un numero Decimal o Entero y retorna un 0 o un 1 dependiendo si cumple la condicion
 *
 * @param primerValor, es el numero a validar el rango
 * @param minimo, es el valor minimo a calcular
 * @param maximo, es el valor maximo a calcular
 * @return retorna 0 si el valor cumple con la condicion, de lo contrario retorna -1
 */
int validacionRangoEnteroDecimal(double primerValor, double minimo, double maximo);

/**
 * @brief Pide un numero entero valida que sea entero y lo retorna en caso que se cumpla, de lo contrario
 * retorna -1
 *
 * @param cadenaTexto, es la instruccion que se le pide al usuario realizar
 * @return retorna el numero solo si es de tipo entero, si no retorna -1.
 */
int pedirEntero(char cadenaTexto[]);

/**
 * @brief Pide un numero decimal valida que sea decimal y lo retorna en caso que se cumpla, de lo contrario
 * retorna -1
 *
 * @param cadenaTexto, es la instruccion que se le pide al usuario realizar
 * @return retorna el numero solo si es de tipo decimal, si no retorna -1.
 */
double pedirDecimal(char cadenaTexto[]);

#endif /* ENTRADASALIDA_H_ */
























