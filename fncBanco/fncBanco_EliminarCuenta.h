void fncBanco_EliminarCuenta(){

    CLEAN;
	printf("%s", TitulosBanco[11]);
	char NoTarjeta[MAXCARACTERES];
	int PIN[2] = {0,0};

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		
		// Obtener el path de cada base de datos
		fncBD_EstablecerConexionBD(false);
		// Obtener registros de la base de datos << banco >>
		fncBD_ObtenerDatosBanco();

				// Verificar el saldo de cuenta
		if( banco.Saldo > 0  ){
				printf("\n*** ");
				printf("Lo siento, la cuenta tiene fondos. \n");	
				// Verificar el estado de cuenta
		}else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta nueva, activar y (bloquear / desactivar) antes de eliminar la cuenta. \n");
		}else if( banco.EstadoDeCuenta == ecCuentaActivada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta activadad, (bloquear / desactivar) antes de eliminar la cuenta. \n");
		}else{

			printf("2) Introduzca PIN de la cuenta: \n");
			scanf("%i", &PIN[0]);
			BUFFERFREE;

			printf("3) Confirmar PIN de la cuenta: \n");
			scanf("%i", &PIN[1]);
			BUFFERFREE;

			// Verificar el PIN introducido
			if( NUEVO_PIN(PIN[1]) ){
				printf("\n*** ");
				printf("Lo siento, PIN debe ser de 6 digitos. \n");
			}else if(PIN[1] != PIN[0]){
				printf("\n*** ");
				printf("Lo siento, PIN no coinciden. \n");
			}else if( PIN[1] != banco.PIN ){
				printf("Lo siento, PIN incorrecto. \n");
			}else{	
				// Eliminar todos los archvios/base de datos
				// de la cuenta
				remove(bdusuarios.PATHActividades);
				remove(bdusuarios.PATHBanco);
				remove(bdusuarios.PATHUsuario);
				
				// Eliminar el directorio
				#ifdef __WIN32
					ELIMINAR_DIR("rmdir /S /Q" , banco.NoCuenta);
				#elif __linux__
					ELIMINAR_DIR("rm -R -f" , banco.NoCuenta);
				#endif

				// Actualizar la base de datos general
				// del banco
				fncBD_ActualizarUsuariosBD();

				printf("\nNOTA:\n");
				printf("La cuenta %s \n", banco.NoCuenta);
				printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
				printf("Se elimino exitosamente. \n");
			}
		}

	}else printf("Lo siento, la cuenta es inexistente. \n");

	fncBD_DeshacerConexionDB();
	//BUFFERFREE;

}