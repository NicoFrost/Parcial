#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUT_H_
#define INPUT_H_

int MenuGeneral(char mensaje1[], char mensaje2[], char mensaje3[], char mensaje4[], char mensaje5[], char mensaje6[], char mensaje7[], char mensaje8[],int submenu);

/// \fn int MenuGeneral("","","","","","");
/// \brief Ejecuta un menu general y devuelve la respuesta
/// \param ninguno
/// \return respuesta de 1-6 para iniciar una accion detallada en el menu

int IngresarEntero(char mensaje[]);

/// \fn int IngresarEntero(char mensaje[]);
/// \brief Para ingresar un numero y ademas verificar
///	\param mensaje de ingreso
/// \return devuelve el numero

float IngresarFlotante(char mensaje[]);

void getString(char cadena[],char mensaje[],int tam);

void OrdenamientoBurbujaAscendente(int numero[],int cant,int *puntero);

void OrdenamientoBurbujaDescendente(int numero[],int cant,int *puntero);

int SoloLetras(char cadenaAAnalizar[]);

int dirVerif(char cadenaAAnalizar[]);

int EsFloatOInteger(float numero);

int esTelefono(char *str);

void NombresInicioMayus(char *sustantivo[],int tam);


#endif
