/*
 * Cliente.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Javier
 */
#include "Clientes.h"
#include "libreria.h"
#include "Pedidos.h"

int buscarEspacioLibre(eCliente listaE[],int tamE)
{
	int ubicacionLibre = -1;

	if(listaE != NULL && tamE > 0){
		for(int i = 0; i < tamE; i++){
			if(listaE[i].isEmpty == 0)
			{
				ubicacionLibre = i;
				break;
			}
		}
	}

	return ubicacionLibre;
}

void IngresarNombre(char cadenaNueva[],int cant)
{
	char cadenaF[cant];
	printf("Ingrese nombre de Empresa: ");
	fflush(stdin);
	gets(cadenaF);
		while(SoloLetras(cadenaF) == 0)
		{
			printf("ERROR. Ingrese nombre de Empresa valido (sin numeros): ");
			gets(cadenaF);
		}
	strcpy(cadenaNueva,cadenaF);
}

int VerifCUIT(char cadenaAAnalizar[]) {

	int retorno = 0;
	for(int i=0; cadenaAAnalizar[i] != '\0';i++){
		if(isdigit(cadenaAAnalizar[i]) == 1){
			retorno = 1;
		}
	}

	return retorno;
}

void IngresarCUIT(char cadenaNueva[],int cant)
{
	char cadenaF[cant];
	getString(cadenaF, "Ingrese CUIT: ", cant);
		while(!(esTelefono(cadenaF) == 1 && strlen(cadenaF) == 13))
		{
			printf("%d",strlen(cadenaF));
			getString(cadenaF, "ERROR, Ingrese un CUIT valido (11 NUMEROS y 2 GUIONES): ", cant);
		}
	strcpy(cadenaNueva,cadenaF);
}

void IngresarDir(char cadenaNueva[], int cant)
{
	char cadenaF[cant];
	printf("Ingrese direccion: ");
	fflush(stdin);
	gets(cadenaF);
	while(dirVerif(cadenaF) == 0){
		printf("ERROR,Ingrese direccion valida: ");
		gets(cadenaF);
	}
	strcpy(cadenaNueva,cadenaF);
}

void IngresarLoc(char cadenaNueva[], int cant)
{
	char cadenaF[cant];
	printf("Ingrese Localidad: ");
	fflush(stdin);
	gets(cadenaF);
	while(SoloLetras(cadenaF) == 0){
		printf("ERROR. Ingrese localidad Valida");
		gets(cadenaF);
	}
	strcpy(cadenaNueva,cadenaF);
}

int Verifllenado(int ubicacion,eCliente Cliente[]){
	//devuelve 0 si el llenado de la cadena no esta
	int retorno = 0;
	if (!(strcmp(Cliente[ubicacion].nombreEmpresa, "") == 0 &&
		strcmp(Cliente[ubicacion].cuit, "") == 0 &&
		strcmp(Cliente[ubicacion].direccion, "") == 0 &&
		strcmp(Cliente[ubicacion].localidad, "") == 0))
	{
		retorno = 1;
	}

	return retorno;
}

void AltaCliente(eCliente Cliente[],int* id,int capacidad)
{
	int ubicacion;
	char nuevoCUIT[51];
	char nuevoNombre[51];
	char nuevaDireccion[51];
	char nuevaLocalidad[51];
	eCliente ClienteAUX[capacidad];
	ubicacion = buscarEspacioLibre(ClienteAUX, capacidad);


	IngresarNombre(nuevoNombre, 51);
	strcpy(ClienteAUX[ubicacion].nombreEmpresa,nuevoNombre);

	IngresarCUIT(nuevoCUIT,51);
    strcpy(ClienteAUX[ubicacion].cuit,nuevoCUIT);

	IngresarDir(nuevaDireccion, 51);
	strcpy(ClienteAUX[ubicacion].direccion,nuevaDireccion);

	IngresarLoc(nuevaLocalidad, 51);
	strcpy(ClienteAUX[ubicacion].localidad,nuevaLocalidad);

	ClienteAUX[ubicacion].id = *id;
	*id = *id + 1;

	ClienteAUX[ubicacion].isEmpty = 1;


	Cliente[ubicacion] = ClienteAUX[ubicacion];
}

void MostrarUnCliente(eCliente Cliente[], int ubicacion){

	printf("\n| %04d |  %s\t | \t%s\t | \t%s\t\t |\t %s\t\t | %d",Cliente[ubicacion].id,Cliente[ubicacion].nombreEmpresa,Cliente[ubicacion].cuit,Cliente[ubicacion].direccion,Cliente[ubicacion].localidad, Cliente[ubicacion].PedidosActivos);

}

void MostrarListaCliente(eCliente Cliente[],int cant){

	printf("----------------------------------------------------------------------------------------------------\n");
	printf("|  ID  |  NOMBRE  \t |\tCUIT\t\t | \tDIRECCION\t\t |\t LOCALIDAD\t\t |  PEDIDOS");
	for(int i = 0;i < cant;i++){
		if(Cliente[i].isEmpty == 1){
			MostrarUnCliente(Cliente, i);
		}
	}
	printf("\n----------------------------------------------------------------------------------------------------\n");
}
void ModCliente(eCliente Cliente[], int cant){

	int modID;
	char nuevaDir[51];
	char nuevaLoc[51];

	MostrarListaCliente(Cliente, cant);
	printf("\nQue Clinte desea modificar?, 0 para cancelar\n");
	scanf("%d", &modID);

	if(modID > 0){
		for(int i = 0; i < cant; i++){
			if(Cliente[i].id == modID){
				IngresarDir(nuevaDir, 51);
				strcpy(Cliente[i].direccion,nuevaDir);

				IngresarLoc(nuevaLoc, 51);
				strcpy(Cliente[i].localidad,nuevaLoc);
				printf("Modificacion realizada");
				break;
			}
		}
	}
}

void BajaCliente(eCliente Cliente[],ePedidos Pedido[], int cant){

	int bajaID;
	char respuesta;

	MostrarListaCliente(Cliente, cant);
	printf("\nQue Clinte desea dar de Baja?, 0 para cancelar\n");
	scanf("%d", &bajaID);

	if(bajaID != 0){
		for(int i = 0; i < cant; i++){
			if(Cliente[i].id == bajaID){
				printf("Esta seguro de dar de baja al cliente %s ? (S/N)", Cliente[i].nombreEmpresa);
				fflush(stdin);
				scanf("%c",&respuesta);
				respuesta = tolower(respuesta);
				while(!(respuesta == 's' || respuesta == 'n')){
					printf("ERROR. Respuesta invalida");
					printf("Esta seguro de dar de baja al cliente %s ? (S/N)", Cliente[i].nombreEmpresa);
					scanf("%c", &respuesta);
					respuesta = tolower(respuesta);
				}
				if(respuesta == 's'){
					printf("Cliente %s dado de baja", Cliente[i].nombreEmpresa);

//					BajaPedidos(Cliente[i].id,Pedido, cant);
					Cliente[i].isEmpty = 0;
					break;
				} else {
					printf("bye bye");
					break;
				}
			}
		}
	}
}
