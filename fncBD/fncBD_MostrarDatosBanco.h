void fncBD_MostrarDatosBanco(){
    
	fncBD_ObtenerDatosBanco();
	
	printf("Numero de tarjeta: %s\n", banco.NoTarjeta);
	printf("Numero de cuenta: %s\n", banco.NoCuenta);
	printf("Total de operaciones: %i \n", actividades.TotalDeCampos);
	
	if( banco.EstadoDeCuenta == 0 ){
		// Si la cuenta es nueva, muestra el saldo y PIN
		printf("PIN: %i \n", banco.PIN);
		printf("Saldo: %lf \n", banco.Saldo);
	}else if( banco.EstadoDeCuenta == 1 ){
		// Si la cuenta esta activa, oculta el saldo y PIN		
		printf("PIN: ***** \n");
		printf("Saldo: ***** \n");
	}else if( banco.EstadoDeCuenta == 2 ){
		// Si la cuenta esta recuperado, oculta el saldo y muestra PIN		
		printf("PIN: %i \n", banco.PIN);
		printf("Saldo: ***** \n");
	}

	if( banco.EstadoDeCuenta == -1 )
		printf("Estado de cuenta: Bloqueada \n");
	else if( banco.EstadoDeCuenta == 0 )
		printf("Estado de cuenta: Cuenta nueva \n");
	else if( banco.EstadoDeCuenta == 1 )
		printf("Estado de cuenta: Activa \n");
	else if( banco.EstadoDeCuenta == 2 )
		printf("Estado de cuenta: Cuenta recuperado \n");
	
}