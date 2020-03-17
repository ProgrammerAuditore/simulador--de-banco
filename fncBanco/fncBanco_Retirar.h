void fncBanco_Retirar(){
	CLEAN;
	printf("%s", TitulosBanco[5]);
	char NoTarjetaCuenta[MAXCARACTERES];
	char Descripcion[MAXCARACTERES];
	int Retirar=0;

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjetaCuenta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjetaCuenta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjetaCuenta)){
		
		printf("1) Introduzca la cantidad a retirar \n");
		scanf("%i", &Retirar);
		BUFFERFREE;
		
		fncBD_EstablecerConexionBD(false);
		fncBD_ObtenerDatosBanco();
		
		if( banco.EstadoDeCuenta == 0){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta bloqueda.\n");
		}else if(Retirar < 0 || Retirar%100 != 0 || Retirar == 0){
			printf("Lo siento, operacion rechazado. \n");
			printf("Debe ser multiplos de 100.\n");
		}else if(Retirar > banco.Saldo ){
			printf("Lo siento, operacion rechazado. \n");
			printf("Fondo insuficiente.\n");
		}else{
			
			printf("Operacion aceptado \n\n");
			banco.Saldo -= Retirar;
			fncBD_ActualizarDBBanco();
			
			sprintf(Descripcion,"Monto: (+) $%i" , Retirar);
			actividades.TipoDeActividad = 400;
			fncBD_RegistrarActividad("Banco: CASTIyO",
			"Retiro: Operacion aceptado",
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

