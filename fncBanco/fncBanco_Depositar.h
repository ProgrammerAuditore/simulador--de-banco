void fncBanco_Depositar(){
	CLEAN;
	printf("%s", TitulosBanco[4]);
	char NoTarjeta[MAXCARACTERES];
	char Descripcion[MAXCARACTERES];	
	int Depositar=0;

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjeta);
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
				actividades.TipoDeActividad = 200;
				fncBD_RegistrarActividad("Banco: CASTIyO",
				"Deposito: Operacion aceptado",
				Descripcion);

				printf("------------[ OPERACION REALIZADO ]\n");
				fncBD_MostrarDatosBanco();
		
			}
		}
		
	}else printf("Lo siento, la cuenta es inexistente. \n");
	
	fncBD_DeshacerConexionDB();
	BUFFERFREE;
	
}

