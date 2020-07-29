void fncBanco_Transferir(){
	
	CLEAN;
	printf("%s", TitulosBanco[6]);
	
	String NoTarjeta1;
	String NoTarjeta2;
	String _Descripcion;
	String _Asunto;
	int iTransferir = 0;
	
	printf("1) Introduzca el No. de tarjeta (remitente): \n");
	fgets(NoTarjeta1, MAXCARACTERES, stdin);
	strtok(NoTarjeta1,"\n");
	CHECKEO_INPUT(NoTarjeta1);
	BUFFERFREE;
	
	printf("2) Introduzca el No. de tarjeta (a transferir): \n");
	fgets(NoTarjeta2, MAXCARACTERES, stdin);
	strtok(NoTarjeta2,"\n");
	CHECKEO_INPUT(NoTarjeta2);
	BUFFERFREE;
	
	if( !fncBD_VerificarCuenta(NoTarjeta2) ){
		MOSTRAR_MSGO_ERROR("Lo siento, la cuenta a transferir es inexistente.");
	}else if( !fncBD_VerificarCuenta(NoTarjeta1) ){
		MOSTRAR_MSGO_ERROR("Lo siento, la cuenta remitente es inexistente.");
	}else if( fnc_CompararString(NoTarjeta1, NoTarjeta2) ){
		MOSTRAR_MSGO_ERROR("Error cuenta duplicadas.");
	}else if( banco.EstadoDeCuenta == ecCuentaBloqueada ){
		MOSTRAR_MSGO_ERROR("Lo siento, operacion rechazado.\nCuenta bloqueda.");
	}else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva){
		MOSTRAR_MSGO_ERROR("Lo siento, operacion rechazado.");
		printf("La cuenta remitente es nueva, activar cuenta antes de realizar operaciones. \n");
		//fncBD_ObtenerDatosBanco();
	}else if( banco.EstadoDeCuenta == ecCuentaDesactivada){
		MOSTRAR_MSGO_ERROR("Lo siento, operacion rechazado.");
		printf("La cuenta remitente esta desactivada, activar cuenta antes de realizar operaciones. \n");
		//fncBD_ObtenerDatosBanco();
	}else{

		fncBD_EstablecerConexionBD(false);
		fncBD_ObtenerDatosBanco();
		
		printf("3) Ingrese el monto a transferir: \n");
		scanf("%i", &iTransferir);
		BUFFERFREE;
		
		if(	(iTransferir < 0) || (iTransferir%100 != 0)){
			MOSTRAR_MSGO_ERROR("Error en el monto de transferencia.");
		}else if ( (iTransferir > banco.Saldo) ){
			MOSTRAR_MSGO_ERROR("Fondo insuficientes.");
		}else{
			
			// Cuenta 1
			banco.Saldo -= iTransferir;
			fncBD_ActualizarDBBanco();
		
			// Registrar actividad - 301 - Transferencia enviado
			actividades.TipoDeActividad = taTransferenciaEnviado;
			snprintf(_Asunto, MAXCARACTERES * 2 , "Transferencia enviado: %s", NoTarjeta2);
			sprintf(_Descripcion, "Monto: (-) $%i", iTransferir);
			fncBD_RegistrarActividades("Banco: E&V Bank", _Asunto, _Descripcion);
			
			// Cuenta 2			
			fncBD_VerificarCuenta(NoTarjeta2);
			fncBD_EstablecerConexionBD(false);
			fncBD_ObtenerDatosBanco();
			
			banco.Saldo += iTransferir;
			fncBD_ActualizarDBBanco();
			
			// Registrar actividad - 302 - Transferencia recibido
			actividades.TipoDeActividad = taTransferenciaRecibido;
			snprintf(_Asunto, MAXCARACTERES * 2 , "Transferencia recibido: %s", NoTarjeta1);
			sprintf(_Descripcion, "Monto: (+) $%i", iTransferir);
			fncBD_RegistrarActividades("Banco: E&V Bank", _Asunto, _Descripcion);
		
			
			MOSTRAR_MSGOPERACION("OPERACION REALIZADA");
			
		}
	}

	fncBD_DeshacerConexionDB();
	BUFFERFREE;
	
}

