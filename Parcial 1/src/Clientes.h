/*
 * Clientes.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Javier
 */


#ifndef CLIENTES_H_
#define CLIENTES_H_
#include "Pedidos.h"



int buscarEspacioLibre(eCliente listaE[],int tamE);

int VerifCUIT(char cadenaAAnalizar[]);
int Verifllenado(int ubicacion,eCliente Cliente[]);

void IngresarNombre(char cadenaNueva[],int cant);
void IngresarDir(char cadena[], int cant);
void IngresarCUIT(char cadena[],int cant);
void IngresarLoc(char cadena[], int cant);

void AltaCliente(eCliente Cliente[],int* id,int capacidad);
void ModCliente(eCliente Cliente[], int cant);
void BajaCliente(eCliente Cliente[],ePedidos Pedido[], int cant);

void MostrarUnCliente(eCliente Cliente[], int capacidad);
void MostrarListaCliente(eCliente Cliente[],int cant);

#endif /* CLIENTES_H_ */
