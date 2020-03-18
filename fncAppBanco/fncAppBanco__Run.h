// Archivo - AppBanco
char TitulosAppBanco[10][250] = {
"################## APP BANCO ###################\n", // 0	
"################## INICIAR SESSION ###################\n", // 1	
"################## CERRAR SESSION ###################\n", // 2
"################## DATOS PERSONALES ###################\n", // 3
"################## DATOS DE BANCO ###################\n", // 4
"################## MOSTRAR ACTIVIDADES  ###################\n", // 5
"################## MOSTRAR DEPOSITOS ###################\n", // 6
"################## MOSTRAR RETIROS ###################\n", // 7
"################## MOSTRAR TRANSFERENCIAS ###################\n" // 8
};

// Controlar la session
bool Session = false; 


// Controlar la cuenta
bool Cuenta = false;

#include "./fncAppBanco_MensajesMenu.h"
#include "./fncAppBanco_IniciarSession.h"
#include "./fncAppBanco_CerrarSession.h"
#include "./fncAppBanco_DatosPersonales.h"
#include "./fncAppBanco_DatosBanco.h"
#include "./fncAppBanco_MostrarActividades.h"
#include "./fncAppBanco_CambiarPIN.h"