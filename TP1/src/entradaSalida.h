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
 * @param numeroActualIngresado, es el numero actual que se encuentra ingresado en el sistema
 * @return retorna el numero ingresado ya validado.
 */
double pedirDecimal(char cadenaTexto[], char cadenaError[], float numeroActualIngresado);

/**
 * @brief imprime en pantalla la instruccion, guarda el dato ingresado por el usuario,
 * lo valida y en caso que este bien lo retornar, de lo contrario pide de nuevo al usuario ingresar el dato
 *
 * @param cadenaTexto, es la instruccion que se le pide al usuario realizar
 * @param cadenaError, es el mensaje de error, por si el ususario se equivoca al ingresar
 * @return retorna el numero ingresado ya validado.
 */
int pedirEntero(char cadenaTexto[], char cadenaError[]);

/**
 * @brief imprime en pantalla la instruccion, guarda el dato ingresado por el usuario,
 * lo valida y en caso que este bien lo retornar, de lo contrario pide de nuevo al usuario ingresar el dato
 *
 * @param cadenaTexto, es la instruccion que se le pide al usuario realizar
 * @param cadenaError, es el mensaje de error, por si el ususario se equivoca al ingresar
 * @return retorna el caracter ingresado ya validado
 */
char pedirCaracter(char cadenaTexto[], char cadenaError[]);

/**
 * @brief realiza la suma de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero sumando
 * @param segundoValor, segundo numero sumando
 * @return retorna el resultado de la suma
 */
double sumar(double primerValor, double segundoValor);

/**
 * @brief realiza la resta de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero es el minuendo
 * @param segundoValor, segundo numero es el substraendo
 * @return retorna la diferencia de la resta
 */
double restar(double primerValor, double segundoValor);

/**
 * @brief realiza la multiplicacion de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero es el multiplicando
 * @param segundoValor, segundo numero es el multiplicador
 * @return retorna el producto de la multiplicacion
 */
double multiplicar(double primerValor, double segundoValor);

/**
 * @brief realiza la division de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero es el dividiendo
 * @param segundoValor, segundo numero es el divisor
 * @return retorna el cociente de la division
 */
double dividir(double primerValor, double segundoValor);

/**
 * @brief realiza el factorial del numero ingresado como parametro
 *
 * @param Valor, es el numero al cual se le realiza el factorial
 * @return retorna el factorial
 */
double factorial(double Valor);

#endif /* ENTRADASALIDA_H_ */

