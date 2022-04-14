#include <stdio.h>
#include <stdlib.h>6

#include "funciones.h"


int menu(void) {
	setbuf(stdout, NULL);

	 float kilometros;
	 int flagK;
	 flagK = 0;
	 float precioAerolineas;
	 float precioLatam;
	 int flagPrecioAerolineas;
	 flagPrecioAerolineas = 0;
	 int flagPrecioLatam;
	 flagPrecioLatam = 0;
	 float debitoLatam;
	 float creditoLatam;
	 float bitcoinLatam;
	 float unitarioLatam;
	 float debitoAerolineas;
	 float creditoAerolineas;
	 float bitcoinAerolineas;
	 float unitarioAerolineas;
	 float diferencia;
	 int flagCalculos;
	 flagCalculos = 0;
	 int opcion;
	 int flagDatos;
	 flagDatos = 0;

	 do {

	       if (flagK != 0) {
	         printf("\n1: Ingresar Kilometros: (Km = %.0f km)\n", kilometros);
	       } else {
	         printf("\n1: Ingresar Kilometros: (Km = x)\n");
	       }
	       if (flagPrecioLatam != 0 && flagPrecioAerolineas != 0) {
	         printf("2: Ingresar precio de Vuelos: (Aerolíneas = %.2f, Latam = %.2f)\n", precioAerolineas, precioLatam);
	       } else {
	         printf("2: Ingresar precio de Vuelos: (Aerolíneas = Y, Latam = Z)\n");
	       }

	       printf("3: Calcular todos los costos:\n");
	       printf("4: Informar Resultados: \n");
	       printf("5: Carga forzada de datos \n");
	       printf("6: Salir \n");
	       printf("Ingrese la opcion: \n");
	       scanf("%d", & opcion);
	       fflush(stdin);
	       ValidarOpcion(opcion);

	       switch (opcion) {
	       case 1:

	         kilometros = PedirEntero("Ingresar Kilometros: \n");
	         fflush(stdin);
	         flagK = 1;
	         break;

	       case 2:

	     	precioLatam = PedirEntero("Precio vuelo Latam: \n");
	         fflush(stdin);
	         flagPrecioLatam = 1;
	         precioAerolineas = PedirEntero("Precio vuelo Aerolíneas: \n");
	         fflush(stdin);
	         flagPrecioAerolineas = 1;
	         break;

	       case 3:

	         if (flagK != 0 && flagPrecioLatam != 0 && flagPrecioAerolineas != 0) {
	           debitoLatam = Debito(precioLatam);
	           debitoAerolineas = Debito(precioAerolineas);
	           creditoLatam = Credito(precioLatam);
	           creditoAerolineas = Credito(precioAerolineas);
	           bitcoinLatam = Bitcoin(precioLatam);
	 		  bitcoinAerolineas = Bitcoin(precioAerolineas);
	           unitarioLatam = Unitario(precioLatam, kilometros);
	           unitarioAerolineas = Unitario(precioAerolineas, kilometros);
	           diferencia = CalcularDiferencia(precioLatam, precioAerolineas);

	           printf("\n----Numeros calculados----\n");
	           flagCalculos = 1;
	         } else {
	           printf("\n----ERROR: Debe ingresar datos----\n");
	         }
	         break;

	       case 4:

	         if (flagK != 0 && flagPrecioLatam != 0 && flagCalculos != 0) {
	           printf("Kilometros Ingresados: %.0f km\n", kilometros);
	           printf("\nLatam: \n");
	           printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoLatam);
	           printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoLatam);
	           printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitcoinLatam);
	           printf("d) Precio unitario: $ %.2f\n", unitarioLatam);
	           printf("\nAerolineas: \n");
	           printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoAerolineas);
	           printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoAerolineas);
	           printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitcoinAerolineas);
	           printf("d) Precio unitario: $ %.2f\n", unitarioAerolineas);
	           printf("\nLa diferencia de precios es: $ %.2f\n",diferencia);

	           break;
	         } else {
	           printf("\n----ERROR: Debe ingresar todos los datos----\n");
	         }
	         break;
	       case 5:

	     	  kilometros = 7090;
	 		  precioAerolineas = 162965;
	 		  precioLatam = 159339;

	 		  debitoLatam = Debito(precioLatam);
	 		  debitoAerolineas = Debito(precioAerolineas);
	 		  creditoLatam = Credito(precioLatam);
	 		  creditoAerolineas = Credito(precioAerolineas);
	 		  bitcoinLatam = Bitcoin(precioLatam);
	 		  bitcoinAerolineas = Bitcoin(precioAerolineas);
	 		  unitarioLatam = Unitario(precioLatam, kilometros);
	 		  unitarioAerolineas = Unitario(precioAerolineas, kilometros);
	 		  diferencia = CalcularDiferencia(precioLatam, precioAerolineas);
	 		  flagDatos = 1;

	 		  if(flagDatos != 0)
	 		  {
	 			  printf("\nKMs Ingresados: %.2f km\n", kilometros);
	 			  printf("\nLatam: $ %.2f\n",precioLatam);
	 			  printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoLatam);
	 			  printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoLatam);
	 			  printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitcoinLatam);
	 			  printf("d) Precio unitario: $ %.2f\n", unitarioLatam);
	 			  printf("\nAerolineas: $ %.2f\n",precioAerolineas);
	 			  printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoAerolineas);
	 			  printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoAerolineas);
	 			  printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitcoinAerolineas);
	 			  printf("d) Precio unitario: $ %.2f\n", unitarioAerolineas);
	 			  printf("\nLa diferencia de precios es: $ %.2f\n",diferencia);

	 		  }

	     	break;
	       case 6:
	         printf("Buen viaje!\n");
	         break;
	       }

	     } while (opcion != 6);

	     return 0;

}

