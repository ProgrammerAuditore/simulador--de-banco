void fncBanco_Depositar(){
	CLEAN;
	printf("%s", TitulosBanco[4]);
	String NoTarjeta;
	String Descripcion;	
	int Depositar=0;

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
			
			printf("1) Introduzca la cantidad a depositar \n");
			scanf("%i", &Depositar);
			BUFFERFREE;
			
			if(Depositar < 0 || Depositar%100 != 0 || Depositar == 0){
				printf("Lo siento, operacion rechazado. \n");
				printf("Debe ser multiplos de 100.\n");
			}else{
				
				printf("Operacion aceptado \n\n");
				banco.Saldo += Depositar;
				// Actualizar la base de datos << banco >>
				// de la cuenta
				fncBD_ActualizarDBBanco();
				
				// Registrar operacion
				sprintf(Descripcion,"Monto: (+) $%i" , Depositar);
				actividades.TipoDeActividad = taDeposito;
				fncBD_RegistrarActividades("Banco: E&V Bank",
				"Deposito: Operacion aceptado",
				Descripcion);

				MOSTRAR_MSGOPERACION("OPERACION REALIZADO");
				fncBD_MostrarDatosBanco();
		
			}
		}
		
	}else{ MOSTRAR_MSGO_ERROR("Lo siento, la cuenta es inexistente."); }

	fncBD_DeshacerConexionDB();
	BUFFERFREE;
	
}

