void fncBanco_RecuperarCuenta(){
    
    CLEAN;
	printf("%s", TitulosBanco[12]);
	char NoTarjeta[MAXCARACTERES];

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		fncBD_EstablecerConexionBD(false);
		fncBD_ObtenerDatosBanco();
		 
		// Cuenta recuperado
		banco.PIN = fnc_GenerarPIN();
		banco.EstadoDeCuenta = 2;
		fncBD_ActualizarDBBanco();

		printf("\nNOTA:\n");
        printf("La cuenta %s \n", banco.NoCuenta);
        printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
        printf("Se recupero exitosamente. \n");

		printf("\n------------[ DATOS BANCO ]\n");
		fncBD_MostrarDatosBanco();
		
	}else
	{
		printf("Lo siento, la cuenta es inexistente. \n");
	}
	
	fncBD_DeshacerConexionDB();
	// BUFFERFREE;
    
}