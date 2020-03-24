// Archivo - AppBanco
char TitulosAppBanco[15][250] = {
"################## APP E&V BANK ###################\n", // 0	
"################## INICIAR SESSION ###################\n", // 1	
"################## CERRAR SESSION ###################\n", // 2
"################## DATOS PERSONALES ###################\n", // 3
"################## DATOS DE BANCO ###################\n", // 4
"################## MOSTRAR ACTIVIDADES  ###################\n", // 5
"################## MOSTRAR DEPOSITOS ###################\n", // 6
"################## MOSTRAR RETIROS ###################\n", // 7
"################## MOSTRAR TRANSFERENCIAS ###################\n", // 8
"################## MOSTRAR SALDO ###################\n" // 9
};

// Controlar la session
bool Session = false; 
int SessionIntentos = 0;
String GuardaCuenta;

// Controlar la cuenta
bool Cuenta = false;

#include "./fncAppBanco_MensajesMenu.h"
#include "./fncAppBanco_IniciarSession.h"
#include "./fncAppBanco_CerrarSession.h"
#include "./fncAppBanco_DatosPersonales.h"
#include "./fncAppBanco_DatosBanco.h"
#include "./fncAppBanco_MostrarActividades.h"
#include "./fncAppBanco_CambiarPIN.h"
#include "./fncAppBanco_ConsultarSaldo.h"