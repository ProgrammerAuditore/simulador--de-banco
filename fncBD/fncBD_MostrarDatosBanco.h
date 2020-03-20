void fncBD_MostrarDatosBanco(){
    
	fncBD_ObtenerDatosBanco();

	printf("Numero de tarjeta: %s\n", banco.NoTarjeta);
	printf("Numero de cuenta: %s\n", banco.NoCuenta);
	printf("Total de operaciones: %i \n", actividades.TotalDeCampos);
	
	if( banco.EstadoDeCuenta == ecCuentaCreadaONueva ){
		// Si la cuenta es nueva, muestra el saldo y PIN
		printf("PIN: %i \n", banco.PIN);
		printf("Saldo: %lf \n", banco.Saldo);
	}else if( banco.EstadoDeCuenta == ecCuentaActivada ){
		// Si la cuenta esta activa, oculta el saldo y PIN		
		printf("PIN: ***** \n");
		printf("Saldo: ***** \n");
	}else if( banco.EstadoDeCuenta == ecCuentaRecuperado ){
		// Si la cuenta esta recuperado, oculta el saldo y muestra PIN		
		printf("PIN: %i \n", banco.PIN);
		printf("Saldo: ***** \n");
	}

	if( banco.EstadoDeCuenta == ecCuentaBloqueada )
		printf("Estado de cuenta: Bloqueada \n");
	else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva )
		printf("Estado de cuenta: Cuenta nueva \n");
	else if( banco.EstadoDeCuenta == ecCuentaActivada )
		printf("Estado de cuenta: Activa \n");
	else if( banco.EstadoDeCuenta == ecCuentaRecuperado )
		printf("Estado de cuenta: Cuenta recuperado \n");
	
}