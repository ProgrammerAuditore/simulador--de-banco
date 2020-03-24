// Archivo - Banco
char TitulosBanco[20][250] = {
"################## E&V BANK  ###################\n", // 0	
"################## CREAR CUENTA ###################\n", // 1	
"################## MODIFICAR DATOS PERSONALES ###################\n", // 2	
"################## BUSCAR CUENTA ###################\n", // 3
"################## DEPOSITAR ###################\n", // 4
"################## RETIRAR ###################\n", // 5
"################## TRANSFERIR ###################\n", // 6
"################## CONFIGURAR CUENTA ###################\n", // 7
"################## ACTIVAR CUENTA ###################\n", // 8
"################## DESACTIVAR CUENTA ###################\n", // 9
"################## BLOQUEAR CUENTA ###################\n", // 10
"################## ELIMINAR CUENTA ###################\n", // 11
"################## RECUPERAR CUENTA ###################\n", // 12
"################## CONFIGURAR CUENTA ###################\n", // 13
"################## OPCIONES DE CUENTA ###################\n", // 14
"################## DESACTIVAR CUENTA ###################\n" // 15
};

// Funciones globales para el programa Banco
int fnc_NumRandom(){
	time_t t;
	srand((unsigned) time(&t));
	return 100 + rand() % 899;
}

int fnc_GenerarPIN(){
	time_t t;
	srand((unsigned) time(&t));
	return ( 111111 + rand() % 888888 );
}

// Archivos de cabecera - Banco
#include "./fncBanco_MensajesMenu.h"
#include "./fncBanco_CrearCuenta.h"
#include "./fncBanco_BuscarCuenta.h"
#include "./fncBanco_Depositar.h"
#include "./fncBanco_ModificarCuenta.h"
#include "./fncBanco_Retirar.h"
#include "./fncBanco_Transferir.h"
#include "./fncBanco_EliminarCuenta.h"
#include "./fncBanco_ActivarCuenta.h"
#include "./fncBanco_DesactivarCuenta.h"
#include "./fncBanco_BloquearCuenta.h"
#include "./fncBanco_ConfigurarCuenta.h"
#include "./fncBanco_RecuperarCuenta.h"
#include "./fncBanco_OpcionesDeCuenta.h"