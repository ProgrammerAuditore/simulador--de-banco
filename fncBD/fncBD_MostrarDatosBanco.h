void fncBD_MostrarDatosBanco(){
    
	fncBD_ObtenerDatosBanco();
	
	printf("Numero de tarjeta: %s\n", banco.NoTarjeta);
	printf("Numero de cuenta: %s\n", banco.NoCuenta);
	printf("Total de operaciones: %i \n", actividades.TotalDeCampos);
	
	// 
	if( banco.EstadoDeCuenta == 0 ){
		printf("PIN: %i \n", banco.PIN);
		printf("Saldo: %lf \n", banco.Saldo);
	}if( banco.EstadoDeCuenta == 1 ){		
		printf("PIN: ***** \n");
		printf("Saldo: ***** \n");
	}

	if( banco.EstadoDeCuenta == -1 )
		printf("Estado de cuenta: Bloqueada \n");
	else if( banco.EstadoDeCuenta == 0 )
		printf("Estado de cuenta: Cuenta nueva \n");
	else if( banco.EstadoDeCuenta == 1 )
		printf("Estado de cuenta: Activa \n");
	
}