void fncBanco_Retirar(){
	CLEAN;
	printf("%s", TitulosBanco[5]);
	char NoTarjeta[MAXCARACTERES];
	char Descripcion[MAXCARACTERES];
	int Retirar=0;

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
			printf("Cuenta bloqueda.\n");
		}else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta nueva, activar cuenta antes de realizar operaciones. \n");
			fncBD_ObtenerDatosBanco();
		}else if( banco.EstadoDeCuenta == ecCuentaDesactivada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta desactivada, activar cuenta antes de realizar operaciones. \n");
			fncBD_ObtenerDatosBanco();
		}else if( banco.EstadoDeCuenta == ecCuentaRecuperado){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta recuperada, activar cuenta antes de realizar operaciones. \n");
		}else{

			printf("1) Introduzca la cantidad a retirar \n");
			scanf("%i", &Retirar);
			BUFFERFREE;
			
			if(Retirar < 0 || Retirar%100 != 0 || Retirar == 0){
				printf("Lo siento, operacion rechazado. \n");
				printf("Debe ser multiplos de 100.\n");
			}else if(Retirar > banco.Saldo ){
				printf("Lo siento, operacion rechazado. \n");
				printf("Fondo insuficiente.\n");
			}else{
				// Descontamos la cantidad 
				printf("Operacion aceptado \n\n");
				banco.Saldo -= Retirar;
				// Actualizar la base de datos << banco >>
				// de la cuenta
				fncBD_ActualizarDBBanco();
				
				// Registrar operacion
				sprintf(Descripcion,"Monto: (-) $%i" , Retirar);
				actividades.TipoDeActividad = 400;
				fncBD_RegistrarActividad("Banco: CASTIyO",
				"Retiro: Operacion aceptado",
				Descripcion);

				printf("------------[ OPERACION REALIZADO ]\n");
				fncBD_MostrarDatosBanco();
			}
		}

	}else {	printf("Lo siento, la cuenta es inexistente. \n"); }
	
	fncBD_DeshacerConexionDB();
	BUFFERFREE;

}

