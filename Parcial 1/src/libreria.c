/*
 * libreria.c
 *
 *  Created on: 9 set. 2021
 *      Author: Javier
 */

#include "libreria.h"

#define LIBRE 0
#define OCUPADO 1


int MenuGeneral(char mensaje1[], char mensaje2[], char mensaje3[], char mensaje4[], char mensaje5[], char mensaje6[], char mensaje7[], char mensaje8[],int submenu){

	int respuesta;

	printf("\ningrese una opcion (en numeros)...\n");
	printf("%s", mensaje1);
	printf("%s", mensaje2);
	printf("%s", mensaje3);
	printf("%s", mensaje4);
	printf("%s", mensaje5);
	printf("%s", mensaje6);
	printf("%s", mensaje7);
	printf("%s", mensaje8);

	if(submenu == 0){
		printf("o ingrese 0 para salir\n");
	} else {
		printf("o ingrese 0 para regresar\n");
	}
	setbuf(stdin, NULL);
	scanf("%d", &respuesta);
	while(isspace(respuesta) || isalpha(respuesta))
	{
		printf("ERROR, ingresar unicamente numeros indicados");
		scanf("%d", &respuesta);
	}
	return respuesta;
}


//FUNCIONES PARA INGRESOS

float IngresarFlotante(char mensaje[])
{
    float numero;

    printf("%s",mensaje);
	scanf("%f",&numero );

	return numero;
}

void getString(char cadena[],char mensaje[],int tam)
{
    char auxiliar[tam];
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", auxiliar);
    strcpy(cadena, auxiliar);
}

int IngresarEntero(char mensaje[])
{
    int numero;

    printf("%s",mensaje);
    fflush(stdin);
	scanf("%d",&numero );


	return numero;
}

//FUNCIONES DE ORDENAMIENTO

void OrdenamientoBurbujaAscendente(int numero[],int cant,int *puntero){

	int aux,i,j;

	for(i = 0; i < cant-1;i++){
		for(j = i+1; j < cant;j++){
			if(numero[i] < numero[j]){
				aux = numero[j];
				numero[j] = numero[i];
				numero[i] = aux;
			}
		}
	}

}

void OrdenamientoBurbujaDscendente(int numero[],int cant,int *puntero){

	int aux,i,j;

	for(i = 0; i < cant-1;i++){
		for(j = i+1; j < cant;j++){
			if(numero[i] > numero[j]){
				aux = numero[j];
				numero[j] = numero[i];
				numero[i] = aux;
			}
		}
	}
	puntero = numero;
}

//FUNCIONES DE VERIFICACION

int SoloLetras(char cadenaAAnalizar[]){
	int retorno = 0;
	for(int i= 0; cadenaAAnalizar[i] != '\0';i++){
		if((isspace(cadenaAAnalizar[i]) || isalpha(cadenaAAnalizar[i])))
		{
			retorno = 1;
		}
	}
	return retorno;
}

int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==2) // debe tener dos guiones
        return 1;

    return 0;
}


int dirVerif(char cadenaAAnalizar[]){
	//devuelve 1 en caso de ser una direccion con letras y 4 numeros o menos
	int espacio = 0;
	int numero = 0;
	int letras = 0;
	int retorno = 0;
	int i;

	for(i = 0;i < 4;i++){
		if(isdigit(cadenaAAnalizar[i])){
			numero++;
		}
	}

	i++;
	espacio = espacio - numero;
	while(cadenaAAnalizar[i] != '\n'){

		if(isalpha(cadenaAAnalizar[i])){
			letras++;
		}
		i++;
	}

	if(numero <= 4 && letras > 1){
		retorno = 1;
	}

	return retorno;
}

int EsFloatOInteger(float numero)
{
//en caso de devolver 1 es flotante
//en caso de devolver 0 es entero
	int ent;
	int retorno;

	ent = numero;


	if(numero - ent){
		retorno = 1;
	}else {
		retorno = 0;
	}

	return retorno;
}

//FUNCIONES MISCELANEAS

void NombresInicioMayus(char* sustantivo[],int tam){
	for(int x = 0; x < tam;x++){
		*sustantivo[x] = tolower(*sustantivo[x]);
	}
	*sustantivo[1] = toupper(*sustantivo[1]);
}


/*
int buscarEspacioLibre(eEmployee listaE[],int tamE)
{
	int ubicacionLibre = -1;

	if(listaE != NULL && tamE > 0){
		for(int i = 0; i < tamE; i++){
			if(listaE[i].isEmpty == 0)
			{
				ubicacionLibre = i;
			}
		}
	}

	return ubicacionLibre;
}

*/
