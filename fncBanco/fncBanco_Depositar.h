void fncBanco_Depositar(){
	CLEAN;
	printf("%s", TitulosBanco[4]);
	char NoTarjetaCuenta[MAXCARACTERES];
	char Descripcion[MAXCARACTERES];	
	int Depositar=0;

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjetaCuenta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjetaCuenta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjetaCuenta)){
		
		printf("1) Introduzca la cantidad a depositar \n");
		scanf("%i", &Depositar);
		BUFFERFREE;
		
		fncBD_EstablecerConexionBD(false);
		fncBD_ObtenerDatosBanco();
		
		if( banco.EstadoDeCuenta == 0){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta bloqueda.\n");
		}else if(Depositar < 0 || Depositar%100 != 0 || Depositar == 0){
			printf("Lo siento, operacion rechazado. \n");
			printf("Debe ser multiplos de 100.\n");
		}else{
			
			printf("Operacion aceptado \n\n");
			banco.Saldo += Depositar;
			fncBD_ActualizarDBBanco();
			
			sprintf(Descripcion,"Monto: (+) $%i" , Depositar);
			actividades.TipoDeActividad = 200;
			fncBD_RegistrarActividad("Banco: CASTIyO",
			"Deposito: Operacion aceptado",
			Descripcion);
			printf("------------[ OPERACION REALIZADO ]\n");
			
			fncBD_MostrarDatosBanco();
	
		}
		
		fncBD_DeshacerConexionDB();
		
	}else
	{
		printf("Lo siento, la cuenta es inexistente. \n");
	}
	
	EnabledOpction = true;
	BUFFERFREE;
}

