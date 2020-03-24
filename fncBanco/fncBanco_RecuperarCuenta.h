void fncBanco_RecuperarCuenta(){
    
    CLEAN;
	printf("%s", TitulosBanco[12]);
	String NoTarjeta;

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO_INPUT(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		
		// Obtener el path de cada base de datos 
		fncBD_EstablecerConexionBD(false);
		// Obtener registros de la base de datos << banco >>
		fncBD_ObtenerDatosBanco();

		// Verificar el estado de cuenta
		if( banco.EstadoDeCuenta == ecCuentaRecuperado){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta ya esta recuperada. \n");
		}else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta nueva, la cuenta deberia estar (bloqueada / desactivada). \n");
		}else if( banco.EstadoDeCuenta == ecCuentaActivada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta activada, la cuenta deberia estar (bloqueada / desactivada). \n");
		}else{ 
			// Cambiar estado de cuenta a :
			// Cuenta recuperado
			banco.PIN = fnc_GenerarPIN();
			banco.EstadoDeCuenta = ecCuentaRecuperado;
			fncBD_ActualizarDBBanco();

			// Registrar operacion
			actividades.TipoDeActividad = taConfiguracionCuenta;
			fncBD_RegistrarActividades("Banco: E&V Bank",
			"Cuenta: Recuperada", "Operacion: Aprobada");

			printf("\nNOTA:\n");
			printf("La cuenta %s \n", banco.NoCuenta);
			printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
			printf("Se recupero exitosamente. \n");

			MOSTRAR_MSGOPERACION("DATOS BANCO");
			fncBD_MostrarDatosBanco();
		}
	}else{ MOSTRAR_MSGO_ERROR("Lo siento, la cuenta es inexistente."); }
	
	fncBD_DeshacerConexionDB();
	// BUFFERFREE;
    
}