/*
 ============================================================================
 Name        : Parcial 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#include "Clientes.h"
#include "Pedidos.h"

#define SUBMENU 1
#define MENU 0
#define CAP 100
#define PED_CAP 1000

int main(void) {
	setbuf(stdout, NULL);
	int respuesta;
	int terminar;
	int id = 1;
	int *pid = &id;
	int idp = 1;
	int *idpP = &idp;
	float promedio;

	eCliente Cliente[CAP];
	ePedidos Pedido[PED_CAP];

	do{
		respuesta = MenuGeneral("1.Alta\n", "2.Modificar datos de cliente\n", "3.Baja de cliente\n", "4.Crear pedido de recoleccion\n", "5.Procesar residuos\n", "6.Imprimir\n","7.Buscar Pedidos por Locacion\n","8.Promedio de reciclaje PP\n",MENU);
		switch (respuesta){
		case 1:
			AltaCliente(Cliente,pid, CAP);
			break;
		case 2:
			ModCliente(Cliente,CAP);
			break;
		case 3:
			BajaCliente(Cliente,Pedido,CAP);
			break;
		case 4:
			PedidoRecoleccion(Cliente,Pedido,CAP,idpP);
			break;
		case 5:
			ProcesarPedidos(Pedido,Cliente,PED_CAP);
			break;
		case 6:
			do{
				terminar = MenuGeneral("1.Imprimir Cliente\n", "2.Imprimir Pedidos pendientes\n", "3.Imprimir Pedidos procesados\n", "", "", "","","",SUBMENU);
				switch (terminar){
				case 1:
					MostrarListaCliente(Cliente, CAP);
					break;
				case 2:
					MostrarListaPedidos(Pedido,Cliente,CAP,1);
					break;
				case 3:
					MostrarListaPedidos(Pedido,Cliente,CAP,2);
					break;
				}
			}while(terminar != 0);
			break;
		case 7:
			PedidosLocalidad(Cliente,Pedido,CAP);
			break;
		case 8:
			promedio = ReciclajePromedioPP(Pedido,CAP);
			printf("el promedio de reciclaje de los PP es de: %.2f", promedio);
			break;
		}
	}while(respuesta != 0);

	return 0;
}
