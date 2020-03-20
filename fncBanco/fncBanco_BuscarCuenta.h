void fncBanco_BuscarCuenta(){
	
	CLEAN;
	printf("%s", TitulosBanco[3]);
	char NoTarjeta[MAXCARACTERES];

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		fncBD_EstablecerConexionBD(false);

		printf("------------[ DATOS BANCO ]\n");
		fncBD_MostrarDatosBanco();
		
		printf("------------[ DATOS PERSONALES ]\n");
		fncBD_MostrarDatosUser();
	}else
	{
		printf("Lo siento, la cuenta es inexistente. \n");
	}
	
	fncBD_DeshacerConexionDB();
	//BUFFERFREE;
	
}

