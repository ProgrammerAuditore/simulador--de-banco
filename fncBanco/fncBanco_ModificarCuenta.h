void fncBanco_ModificarCuenta(){
	
	CLEAN;
	printf("%s", TitulosBanco[2]);
	String NoTarjeta;
	char Datos[NOFILAS_DBUSER][MAXCARACTERES];
	int PIN[2] = {0,0};

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO_INPUT(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		
		// Obtener el path de cada base de datos
		fncBD_EstablecerConexionBD(false);
		// Obtener registros de la base de datos << banco >>
		fncBD_ObtenerDatosBanco();

		if( banco.EstadoDeCuenta == ecCuentaBloqueada ){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta bloqueada, activar cuenta antes de realizar operaciones.\n");
		}else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta nueva, activar cuenta antes de realizar operaciones. \n");
		}else if( banco.EstadoDeCuenta == ecCuentaDesactivada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta desactivada, activar cuenta antes de realizar operaciones. \n");
		}else if( banco.EstadoDeCuenta == ecCuentaRecuperado){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta recuperada, activar cuenta antes de realizar operaciones. \n");
		}else{

			printf("2) Introduzca PIN de la cuenta: \n");
			scanf("%i", &PIN[0]);
			BUFFERFREE;

			printf("3) Confirmar PIN de la cuenta: \n");
			scanf("%i", &PIN[1]);
			BUFFERFREE;

			if( CHECKEO_PIN(PIN[1]) ){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN debe ser de 6 digitos.");
			}else if(PIN[1] != PIN[0]){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN no coinciden.");
			}else if( PIN[1] != banco.PIN ){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN incorrecto.");
			}else{
				
				// Mostrar datos personales actual
				MOSTRAR_MSGOPERACION("DATOS PERSONALES");
				fncBD_MostrarDatosUser();

				// Iniciando a modificar datos
				MOSTRAR_MSGOPERACION("MODIFICANDO DATOS PERSONALES");
				printf("Escribe nuevo nombre(s): \n");
				fgets( Datos[0] , MAXCARACTERES , stdin );
				MODIFICAR_DATO( user.Nombres, MAXCARACTERES , Datos[0] );
				BUFFERFREE;
				
				printf("Escribe nuevo apellido 1: \n");
				fgets( Datos[1] , MAXCARACTERES , stdin );
				MODIFICAR_DATO( user.ApellidoPaterno, MAXCARACTERES , Datos[1] );
				BUFFERFREE;
				
				printf("Escribe nuevo apellido 2: \n");
				fgets( Datos[2] , MAXCARACTERES , stdin );
				MODIFICAR_DATO( user.ApellidoMaterno, MAXCARACTERES , Datos[2] );
				BUFFERFREE;

				// Actualizar la base de datos << banco >>
				// de la cuenta
				fncBD_ActualizarDBUser();

				// Registrar operacion
				actividades.TipoDeActividad = taConfiguracionCuenta;
				fncBD_RegistrarActividades("Banco: E&V Bank",
				"Cuenta: Modificado", "Operacion: Aprobada");

				MOSTRAR_MSGOPERACION("NUEVOS DATOS PERSONALES");
				printf("Nombre (s): %s\n", user.Nombres);
				printf("Apellido Paterno: %s\n", user.ApellidoPaterno);
				printf("ApellidoMaterno: %s\n", user.ApellidoMaterno);
				printf("Fecha de Nacimiento: %s\n", user.FechaNacimiento);

				printf("\nNOTA:\n");
				printf("La cuenta %s \n", banco.NoCuenta);
				printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
				printf("Se modifico exitosamente. \n");
				
			}
		}
		
	} else MOSTRAR_MSGO_ERROR("Lo siento, cuenta inexistente.");

	fncBD_DeshacerConexionDB();
	// BUFFERFREE;
	
}

