// Archivos de Cabecera C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#ifdef __WIN32
    #include <io.h>
#elif __linux__
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

// Archivos de Cabecera  - SRC
#include "enviroment.h"
#include "macros.h"
#include "fnc_CompararString.h"
#include "fnc_FechaCorrecto.h"

// Archivos de cabecera - BD
#include "fncBD_DeshacerConexionDB.h"
#include "fncBD_VerificarCuenta.h"
#include "fncBD_ObtenerRegistroDB.h"
#include "fncBD_MostrarConexionDB.h"
#include "fncBD_EstablecerConexionBD.h"
#include "fncBD_ObtenerDatosUser.h"
#include "fncBD_ObtenerDatosBanco.h"
#include "fncBD_MostrarDatosBanco.h"
#include "fncBD_MostrarDatosUser.h"
#include "fncBD_ActualizarDBBanco.h"
#include "fncBD_ActualizarDBUser.h"
#include "fncBD_RegistrarActividad.h"
#include "fncBD_MostrarActividades.h"
#include "fncBD_CrearBDActividades.h"
#include "fncBD_CrearBDBanco.h"
#include "fncBD_CrearBDUsuario.h"
#include "fncBD_RegistrarUsuarioBD.h"

// Archivos de cabecera - Banco
#include "fncBanco_CrearCuenta.h"
#include "fncBanco_MensajesMenu.h"
#include "fncBanco_BuscarCuenta.h"
#include "fncBanco_Depositar.h"
#include "fncBanco_ModificarCuenta.h"
#include "fncBanco_Retirar.h"
#include "fncBanco_Transferir.h"
