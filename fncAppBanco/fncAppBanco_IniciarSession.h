void fncAppBanco_IniciarSession(){
	
	CLEAN;
	printf("%s", TitulosAppBanco[1]);
	char NoTarjeta[MAXCARACTERES];
	int PIN = 0;

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		fncBD_EstablecerConexionBD(false);
		fncBD_ObtenerDatosBanco();
		fncBD_ObtenerDatosUser();
		
		printf("2) Introduzca el PIN: \n");
		scanf("%i", &PIN);
		BUFFERFREE;

		if( PIN == banco.PIN ){
			Session = true;
			Cuenta = banco.EstadoDeCuenta;
		}else{
			printf("Lo siento, PIN incorrecto. \n");
			fncBD_DeshacerConexionDB();
		}
		

	}else
	{
		printf("Lo siento, la cuenta es inexistente. \n");
		fncBD_DeshacerConexionDB();
	}
	
	BUFFERFREE;

}
