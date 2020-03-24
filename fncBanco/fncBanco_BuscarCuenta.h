void fncBanco_BuscarCuenta(){
	
	CLEAN;
	printf("%s", TitulosBanco[3]);
	String NoTarjeta;

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO_INPUT(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		fncBD_EstablecerConexionBD(false);

		MOSTRAR_MSGOPERACION("DATOS BANCO");
		fncBD_MostrarDatosBanco();
		
		MOSTRAR_MSGOPERACION("DATOS PERSONALES");
		fncBD_MostrarDatosUser();
	}else{ MOSTRAR_MSGO_ERROR("Lo siento, la cuenta es inexistente."); }
	
	fncBD_DeshacerConexionDB();
	//BUFFERFREE;
	
}

