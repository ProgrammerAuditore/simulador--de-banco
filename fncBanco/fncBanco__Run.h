// Archivo - Banco
char TitulosBanco[20][250] = {
"################## BANCO ###################\n", // 0	
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
};

// Archivos de cabecera - Banco
#include "fncBanco_MensajesMenu.h"
#include "fncBanco_CrearCuenta.h"
#include "fncBanco_BuscarCuenta.h"
#include "fncBanco_Depositar.h"
#include "fncBanco_ModificarCuenta.h"
#include "fncBanco_Retirar.h"
#include "fncBanco_Transferir.h"
#include "./fncBanco_EliminarCuenta.h"
#include "./fncBanco_ActivarCuenta.h"
#include "./fncBanco_BloquearCuenta.h"
#include "./fncBanco_ConfigurarCuenta.h"