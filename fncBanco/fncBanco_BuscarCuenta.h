void fncBanco_BuscarCuenta(){
	
	CLEAN;
	printf("%s", TitulosBanco[3]);
	char NoTarjetaCuenta[MAXCARACTERES];

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjetaCuenta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjetaCuenta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjetaCuenta)){
		fncBD_EstablecerConexionBD(false);
		fncBD_MostrarDatosBanco();
		fncBD_MostrarDatosUser();
		fncBD_DeshacerConexionDB();
	}else
	{
		printf("Lo siento, la cuenta es inexistente. \n");
	}
	
	EnabledOpction = true;
	BUFFERFREE;

}

