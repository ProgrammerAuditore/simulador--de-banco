void fncBanco_EliminarCuenta(){

    CLEAN;
	printf("%s", TitulosBanco[11]);
	String NoTarjeta;
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

				// Verificar el saldo de cuenta
		if( banco.Saldo > 0  ){
				MOSTRAR_MSGO_ERROR("Lo siento, la cuenta tiene fondos.");	
				// Verificar el estado de cuenta
		}else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta nueva, activar y (bloquear / desactivar) antes de eliminar la cuenta. \n");
		}else if( banco.EstadoDeCuenta == ecCuentaActivada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta activada, (bloquear / desactivar) antes de eliminar la cuenta. \n");
		}else if( banco.EstadoDeCuenta == ecCuentaRecuperado){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta recuperada, (bloquear / desactivar) antes de eliminar la cuenta. \n");
		}else{

			printf("2) Introduzca PIN de la cuenta: \n");
			scanf("%i", &PIN[0]);
			BUFFERFREE;

			printf("3) Confirmar PIN de la cuenta: \n");
			scanf("%i", &PIN[1]);
			BUFFERFREE;

			// Verificar el PIN introducido
			if( CHECKEO_PIN(PIN[1]) ){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN debe ser de 6 digitos.");
			}else if(PIN[1] != PIN[0]){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN no coinciden.");
			}else if( PIN[1] != banco.PIN ){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN incorrecto.");
			}else{	
				printf("\n");

				// Eliminar todos los archvios/base de datos
				// de la cuenta
				if(remove(bdusuarios.PATHActividades) == 0)
					printf("Base de datos << actividades >> eliminado exitosamente. \n");
				if(remove(bdusuarios.PATHUser) == 0)
					printf("Base de datos << user >> eliminado exitosamente. \n");
				if(remove(bdusuarios.PATHBanco) == 0)
					printf("Base de datos << banco >> eliminado exitosamente. \n");
				
				// Eliminar el directorio
				#ifdef __WIN32
					ELIMINAR_DIR("rmdir /S /Q" , banco.NoCuenta);
					printf("Base de datos eliminado exitosamente. \n");
				#elif __linux__
					ELIMINAR_DIR("rm -R -f" , banco.NoCuenta);
					printf("Base de datos eliminado exitosamente. \n");
				#endif

				// Actualizar la base de datos general
				// del banco
				fncBD_ActualizarBDUsuariosRegistrados();

				printf("\nNOTA:\n");
				printf("La cuenta %s \n", banco.NoCuenta);
				printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
				printf("Se elimino exitosamente. \n");
			}
		}

	}else{ MOSTRAR_MSGO_ERROR("Lo siento, la cuenta es inexistente."); }

	fncBD_DeshacerConexionDB();
	//BUFFERFREE;

}