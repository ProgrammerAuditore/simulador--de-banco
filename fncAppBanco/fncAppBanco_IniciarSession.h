void fncAppBanco_IniciarSession(){
	
	CLEAN;
	printf("%s", TitulosAppBanco[1]);
	String NoTarjeta;
	int PIN = 0;

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO_INPUT(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		// Obtener el path de cada base de datos
		fncBD_EstablecerConexionBD(false);
		// Obtener registros de la base de datos << banco >>
		fncBD_ObtenerDatosBanco();
		// Obtener registros de la base de datos << usuario / datos personales >>
		fncBD_ObtenerDatosUser();

		// Verificar el estado de cuenta
		if( banco.EstadoDeCuenta == ecCuentaBloqueada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta bloqueada, acude al banco para desbloquearlo. \n");
			SessionIntentos = 0;
		}else if( banco.EstadoDeCuenta == ecCuentaDesactivada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta desactivada, acude al banco para desactivarlo. \n");
			SessionIntentos = 0;
		}else{

			printf("2) Introduzca el PIN: \n");
			scanf("%i", &PIN);
			BUFFERFREE;
			
			if( PIN == banco.PIN ){

			// Activar session
			Session = true;

			// Verificar el estado de cuenta
			if( banco.EstadoDeCuenta == ecCuentaCreadaONueva || 
				banco.EstadoDeCuenta == ecCuentaRecuperado )
				Cuenta = false;
			else
				Cuenta = true;

			// Reiniciar contador de intentos fallidos
			SessionIntentos = 0;
			printf("Inicio session, correctamente \n");


			}else{		
				// Contar los intetos fallidos
				// printf("1>[%s] --- 2>[%s] \n", GuardaCuenta, NoTarjeta);
				if( fnc_CompararString(GuardaCuenta, NoTarjeta) ){
					SessionIntentos++;
				}else{ SessionIntentos = 1; }
					// Si el usuario falla 3 intentos al momento de introducir el PIN
					// la cuenta se bloquea.
					if( SessionIntentos == 3){
						banco.EstadoDeCuenta = ecCuentaBloqueada;
						fncBD_ActualizarDBBanco();
						printf("\nNOTA:\n");
						printf("Lo siento, la cuenta esta bloqueada. \n");
						printf("Intentos fallidos %i. \n", SessionIntentos);
						printf("Cuenta bloqueada, acude al banco para desbloquearlo. \n");
					}else{
					// Si el usuario al momento de introducir el PIN
					// mostramos una advertencia.
						printf("\nNOTA:\n");
						printf("Lo siento, PIN incorrecto. \n");
						printf("Intentos disponible %i. \n", 3 - SessionIntentos);
						strcpy(GuardaCuenta, banco.NoTarjeta);
					}	

					fncBD_DeshacerConexionDB();
			}
		}
	}
	else{ MOSTRAR_MSGO_ERROR("Lo siento, la cuenta es inexistente."); }
	
	BUFFERFREE;

}
