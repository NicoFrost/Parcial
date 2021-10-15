/*
 * Funciones.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Javier
 */

#include "Clientes.h"
#ifndef PEDIDOS_H_
#define PEDIDOS_H_

typedef struct {

	int id;
	char nombreEmpresa[51];
	char cuit[51];
	char direccion[51];
	char localidad[51];
	int PedidosActivos;
	int isEmpty;

}eCliente;

typedef struct {
	int PedidoClienteID;
	int PedidoID ;
	int PedidoKg;
	int PedidoEstado;
	int PlaKgHDPE;
	int PlaKgLDPE;
	int PlaKgPP;
	int isEmpty;
}ePedidos;


int buscarEspacioLibreP(ePedidos listaE[],int tamE);



/// \brief muestra un pedido, es complementaria de MostrarListadoPedidos pero se puede usar sola
/// \param struct pedidos, struct cliente, ubicacion del pedido, estado del pedido(iniciado/pendiente/completo), cantidad total (CAP)
/// \no retorna nada solo muestra resultados

void MostrarUnPedido(ePedidos Pedido[],eCliente Cliente[],int ubicacion,int estado,int cant);

/// \brief Adicionalmente a mostrar la lista de los pedidos muestra un pequeño
///        menu arriba aunque se desincroniza con facilidad
///
//// \param struct pedidos, struct cliente, ubicacion del pedido, estado del pedido
///        (iniciado/pendiente/completo),aqui se pone 1 o 2 (dependiendo si se quiere
///        imprimir al tocar en el submenu de imprimir la opcion 2 o 3

void MostrarListaPedidos(ePedidos Pedidos[],eCliente Cliente[],int cant, int impresion);

/// \brief la funcion sirve para iniciar la creacion de un pedido de recoleccion.
/// \param estructura cliente,estructura pedido, cantidad total(CAP), ID traida con putero desde el main

void PedidoRecoleccion(eCliente Cliente[],ePedidos Pedido[],int cant, int* idP);

/// \brief esta funcion hace
///

void ProcesarPedidos(ePedidos PedidosCreados[],eCliente Cliente[], int cant);

void PedidosLocalidad(eCliente Cliente[],ePedidos Pedido[],int cant);
float ReciclajePromedioPP(ePedidos PedidoProm[],int cant);
//void BajaPedidos(int bajaID, ePedidos Pedido[],int cant);

#endif /* PEDIDOS_H_ */
