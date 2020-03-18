// Archivos de cabecera  << ./src >>
#include "Run.h"
// Archivos de cabecera  << ./BD >>
#include "./fncBD/fncBD__Run.h"
// Archivos de cabecera << ./Banco >>
#include "./fncBanco/fncBanco__Run.h"


// Compilar
// gcc -c Banco.c -I"./src" -std=c99 && gcc -o Banco Banco.o
// Compatible con Windows y Linux-Mint

int main(){

	CLEAN;
	char Opcion;

	do{
		CLEAN;
		fncBanco_MensajesMenu();
		Opcion = '\0';
		printf("Selecciona una opcion: ");
		Opcion = getchar();
		BUFFERFREE;
		
		if( Opcion != '\n'){
			switch (Opcion){
				case '0': break; break;
				case '1': OPTION(fncBanco_CrearCuenta); break;
				case '2': OPTION(fncBanco_ModificarCuenta); break;
				case '3': OPTION(fncBanco_BuscarCuenta); break;
				case '4': OPTION(fncBanco_Depositar); break;
				case '5': OPTION(fncBanco_Retirar); break;
				case '6': OPTION(fncBanco_Transferir); break;
				default: OPTIONERROR;
			}
		}
		
	}while(Opcion != '0');

	printf("THE END ");
	BUFFERFREE;

return 0;	
}