// Archivos de cabecera  << ./src >>
#include "Run.h"
// Archivos de cabecera  << ./BD >>
#include "./fncBD/fncBD__Run.h"
// Archivos de cabecera << ./AppBanco >>
#include "./fncAppBanco/fncAppBanco__Run.h"

int main(){

	CLEAN;
	char Opcion;

	do{
		CLEAN;
		fncAppBanco_MensajesMenu();
		Opcion = '\0';
		printf("Selecciona una opcion: ");
		Opcion = getchar();
		BUFFERFREE;
		
		if( Opcion != '\n' ){
			switch (Opcion){
				// Controlar programa
				case '0': 
				if(!Session){
					break;
				}else{
					Opcion = '\0';
					printf("Lo siento, opcion incorrecta. \n"); 
					BUFFERFREE;
				}
				break;

				// Controlar session
				case '1':
				if(!Session)
					fncAppBanco_IniciarSession(); 
				else
					fncAppBanco_CerrarSession(); 
				break;
				
				// Opciones del AppBanco
				case '2': OPTION(Session && Cuenta, fncAppBanco_DatosPersonales); break;
				case '3': OPTION(Session && Cuenta, fncAppBanco_DatosBanco); break;
				case '4': OPTION(Session && Cuenta, fncAppBanco_MostrarActividades); break;
				case '5': OPTION(Session && Cuenta, fncAppBanco_ConsultarSaldo); break;
				case 'x': OPTION(Session && !Cuenta, fncAppBanco_CambiarPIN); break;
				default: OPTIONERROR;
			}
		}
		
	}while(Opcion != '0' );

	printf("THE END ");
	BUFFERFREE;

return 0;	
}
