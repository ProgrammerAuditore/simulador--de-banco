void fncBanco_Transferir(){
	
	CLEAN;
	printf("%s", TitulosBanco[6]);
	
	char NoTarjeta1[MAXCARACTERES];
	char NoTarjeta2[MAXCARACTERES];
	char _Descripcion[MAXCARACTERES];
	char _Asunto[MAXCARACTERES];
	int iTransferir = 0;
	
	printf("1) Introduzca el No. de tarjeta (remitente): \n");
	fgets(NoTarjeta1, MAXCARACTERES, stdin);
	strtok(NoTarjeta1,"\n");
	CHECKEO(NoTarjeta1);
	BUFFERFREE;
	
	printf("2) Introduzca el No. de tarjeta (a transferir): \n");
	fgets(NoTarjeta2, MAXCARACTERES, stdin);
	strtok(NoTarjeta2,"\n");
	CHECKEO(NoTarjeta2);
	BUFFERFREE;
	
	if( !fncBD_VerificarCuenta(NoTarjeta2) ){
		printf("Lo siento, la cuenta a transferir es inexistente. \n");
	}else if( !fncBD_VerificarCuenta(NoTarjeta1) ){
		printf("Lo siento, la cuenta remitente es inexistente. \n");
	}else if( fnc_CompararString(NoTarjeta1, NoTarjeta2) ){
		printf("*** Error cuenta duplicadas. \n");
	}else if( banco.EstadoDeCuenta == ecCuentaBloqueada ){
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
	}else{

		fncBD_EstablecerConexionBD(false);
		fncBD_ObtenerDatosBanco();
		
		printf("3) Ingrese el monto a transferir: \n");
		scanf("%i", &iTransferir);
		BUFFERFREE;
		
		if(	(iTransferir < 0) || (iTransferir%100 != 0))
			printf("*** Error en el monto de transferencia. \n");
		else if ( (iTransferir > banco.Saldo) )
			printf("*** Fondo insuficientes \n");
		else{
			
			// Cuenta 1
			banco.Saldo -= iTransferir;
			fncBD_ActualizarDBBanco();
		
			// Registrar actividad - 301 - Transferencia enviado
			actividades.TipoDeActividad = 301;
			sprintf(_Asunto, "Transferencia enviado: %s", NoTarjeta2);
			sprintf(_Descripcion, "Monto: (-) $%i", iTransferir);
			fncBD_RegistrarActividad("Banco: E&V", _Asunto, _Descripcion);
			
			// Cuenta 2			
			fncBD_VerificarCuenta(NoTarjeta2);
			fncBD_EstablecerConexionBD(false);
			fncBD_ObtenerDatosBanco();
			
			banco.Saldo += iTransferir;
			fncBD_ActualizarDBBanco();
			
			// Registrar actividad - 302 - Transferencia recibido
			actividades.TipoDeActividad = 302;
			sprintf(_Asunto, "Transferencia recibido: %s", NoTarjeta1);
			sprintf(_Descripcion, "Monto: (+) $%i", iTransferir);
			fncBD_RegistrarActividad("Banco: E&V", _Asunto, _Descripcion);
		
			
			printf("------------[ OPERACION REALIZADA ]\n");
			
		}
	}

	fncBD_DeshacerConexionDB();
	BUFFERFREE;
	
}

