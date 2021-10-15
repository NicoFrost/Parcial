#include "Pedidos.h"
#include "libreria.h"
#include "Clientes.h"
#define CAP 100



int buscarEspacioLibreP(ePedidos listaE[],int tamE)
{
	int ubicacionLibre = -1;

	if(listaE != NULL && tamE > 0){
		for(int i = 0; i < tamE; i++){
			if(listaE[i].PedidoEstado == 0)
			{
				ubicacionLibre = i;
				break;
			}
		}
	}

	return ubicacionLibre;
}

void MostrarUnPedido(ePedidos Pedido[],eCliente Cliente[],int ubicacion,int estado,int cant){

	int clienteIDAux;
	int ubicacionCliente;

	int dato1 = Pedido[ubicacion].PedidoID;
	int dato2 = Pedido[ubicacion].PedidoKg;

	char dato3[51];

	char dato4[51];


	char estadoAUX[20];
			switch(estado){
			case 1:
			strcpy(estadoAUX,"Pendiente");
			break;
			case 2:
			strcpy(estadoAUX,"Completado");
			break;
			}
	//copia el id de cliente de pedido
	clienteIDAux = Pedido[ubicacion].PedidoClienteID;
	//busca la id de cliente en el array de estructura
	for(int u = 0; u < cant;u++){
		//verifica la id con cada uno de los id del array
		if(clienteIDAux == Cliente[u].id && Cliente[u].isEmpty == 1){
			ubicacionCliente = u;
			break;
		}
	}
	strcpy(dato3,Cliente[ubicacionCliente].cuit);
	strcpy(dato4,Cliente[ubicacionCliente].direccion);
	printf("%04d \t| %04d | %s | %s | %s ", dato1, dato2,Cliente[ubicacionCliente].cuit,dato4, estadoAUX);
	printf("| %d/%d/%d\n",Pedido[ubicacion].PlaKgHDPE,Pedido[ubicacion].PlaKgLDPE,Pedido[ubicacion].PlaKgPP);
}

void MostrarListaPedidos(ePedidos Pedidos[],eCliente Cliente[],int cant, int impresion){
	int flag = 0;
	int i = 0;
	printf("---------------PEDIDOS---------------");
	printf("\nID PEDIDO | KG | CUIT | DIRECCION | ESTADO ");
	for(i = 0; i < cant; i++){
		if(impresion == 1 && Pedidos[i].PedidoEstado == 1){
			printf("\n");
			MostrarUnPedido(Pedidos,Cliente, i,impresion,cant);
		} else {
		if(impresion == 2 && flag == 0){
			printf("| KG (HDPE/LDPE/PP) |\n");
			flag = 1;
		}
		if(impresion == 2 && Pedidos[i].PedidoEstado == 2){
			MostrarUnPedido(Pedidos,Cliente, i,impresion, cant);
		}
		}

	}
	printf("\n-----------------------------------------\n");
}

void PedidoRecoleccion(eCliente Cliente[],ePedidos Pedido[],int cant, int* idP){


	int ClienteID;
	// inicializado 0
	// pendiente 1
	// hecho 2
	char repetir;
	int ubicacion;

	MostrarListaCliente(Cliente, cant);
	do{
		ClienteID = IngresarEntero("Ingrese ID del cliente: ");
		//Verificacion
		while(ClienteID <= 0){
			printf("Numeros negativos y cero NO VALIDOS ingresar nuevamente\n");
			ClienteID = IngresarEntero("Ingrese ID del cliente: ");
		}
		// Recorrer los 1000 espacios buscando uno libre comparando el ID CLIENTE
			ubicacion = buscarEspacioLibreP(Pedido, 1000);
			for(int i = 0; i < cant;i++){
				if(ClienteID == Cliente[i].id && Cliente[i].isEmpty == 1){
					Pedido[ubicacion].PedidoClienteID = Cliente[i].id;
					Pedido[ubicacion].PedidoKg = IngresarEntero("ID encontrado. ¿cuantos kilos totales se recogeran?: ");
					Pedido[ubicacion].PedidoEstado = 1;
					Cliente[i].PedidosActivos = Cliente[i].PedidosActivos + 1;
					Pedido[ubicacion].PedidoID = *idP;
					*idP = *idP + 1;
					repetir = 'n';
				}
			}
			if(ubicacion == -1){
			printf("ID no encontrado desea intentar de nuevo? (s/n): ");
			fflush(stdin);
			scanf("%c",&repetir);
			while(!(repetir == 's' || repetir == 'n')){
				printf("respuesta no valida ingrese de nuevo: ");
				setbuf(stdin, NULL);
				scanf("%c",&repetir);
			}
		}
	}while(repetir != 'n');
}

void ProcesarPedidos(ePedidos PedidosCreados[],eCliente Cliente[], int cant){

	int PedidoID;
	int SumaKgPla;
	int repetir;
	int restoBasura;
	int hdpeAux;
	int ldpeAux;
	int ppAux;
	char respuesta;

	MostrarListaPedidos(PedidosCreados,Cliente, cant,1);
	PedidoID = IngresarEntero("Ingrese ID a procesar");
	for(int i = 0; i < cant; i++){
		if(PedidoID-1 == i && PedidosCreados[i].PedidoEstado == 1){
			do{
				Cliente[i].PedidosActivos = Cliente[i].PedidosActivos - 1;
				repetir = 0;
				hdpeAux = IngresarEntero("Ingrese kg de Plastico HDPE(Polietileno de alta densidad)");
				ldpeAux = IngresarEntero("Ingrese kg de Plastico LDPE(Polietileno de baja densidad)");
			    ppAux = IngresarEntero("Ingrese kg de Plastico PP(Polipropileno)");


				PedidosCreados[i].PlaKgHDPE = hdpeAux;
				PedidosCreados[i].PlaKgLDPE = ldpeAux;
				PedidosCreados[i].PlaKgPP = ppAux;
				PedidosCreados[i].PedidoEstado = 2;
				SumaKgPla = PedidosCreados[i].PlaKgHDPE + PedidosCreados[i].PlaKgLDPE + PedidosCreados[i].PlaKgPP;
				if(PedidosCreados[i].PedidoKg != SumaKgPla){
					restoBasura = SumaKgPla - PedidosCreados[i].PedidoKg;
					printf("se descarto los %d de basura restante? (s/n)\n", restoBasura);
					fflush(stdin);
					scanf("%c", &respuesta);
					respuesta = tolower(respuesta);
					if(respuesta == 's'){
						break;
						break;
					} else {
						printf("ERROR: Pedido no ingresado correctamente vuelva a ingresar, recuerde que el\ntotal de los kg de plastico por separado no puede superar el total ingresado anteriormente\n");
						repetir = 1;
					}

				}
			}while(repetir);
		}
	}
}

void PedidosLocalidad(eCliente Cliente[],ePedidos Pedido[],int cant)
{
	char localidadBusc[51];

	gets(localidadBusc);


	for(int i = 0;i < cant;i++){
		if(Cliente[i].localidad == localidadBusc  && Cliente[i].isEmpty == 1)
		{
			MostrarUnPedido(Pedido, Cliente, i, 1, cant);
		}
	}

}

float ReciclajePromedioPP(ePedidos PedidoProm[],int cant)
{
	int sumaPP = 0;
	int pedidosPP = 0;
	float promedio;

	for(int i = 0;i < cant;i++){
		if(PedidoProm[i].PlaKgPP > 0 && PedidoProm[i].PedidoEstado == 1){
			sumaPP = sumaPP + PedidoProm[i].PlaKgPP;
			pedidosPP++;
			printf("paso!");
		}
	}
	promedio =  sumaPP / pedidosPP;

	return promedio;
}

//void BajaPedidos(int bajaID, ePedidos Pedido[],int cant){
//
//	for(int i = 0;i < cant; i++){
//		if(bajaID == Pedido[i].PedidoClienteID){
//
//			int cero = 0;
//
//			Pedido[i].PedidoClienteID = cero;
//			Pedido[i].PedidoEstado = cero;
//			Pedido[i].PedidoID = cero-1;
//			Pedido[i].PedidoKg = cero;
//			Pedido[i].PlaKgHDPE = cero;
//			Pedido[i].PlaKgLDPE = cero;
//			Pedido[i].PlaKgPP = cero;
//			Pedido[i].isEmpty = cero;
//		}
//	}
//}
