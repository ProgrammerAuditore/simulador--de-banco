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
		
		
		if( banco.EstadoDeCuenta == -1 ){
			printf("\nNOTA:\n");
			printf("Lo sentimos, esta cuenta esta bloqueada. \n");
			printf("Acude al banco para desbloqueardo. \n");
			SessionIntentos = 0;
			fncBD_DeshacerConexionDB();
		}else{
			printf("2) Introduzca el PIN: \n");
			scanf("%i", &PIN);
			BUFFERFREE;

			if( PIN == banco.PIN ){
				Session = true;
				Cuenta = banco.EstadoDeCuenta;
				SessionIntentos = 0;
			}else{
				
				// Contar los intetos fallidos
				// printf("1>[%s] --- 2>[%s] \n", GuardaCuenta, NoTarjeta);
				if( fnc_CompararString(GuardaCuenta, NoTarjeta) ){
					SessionIntentos++;
				}else{ SessionIntentos = 1; }

				if( SessionIntentos == 3){
					banco.EstadoDeCuenta = -1;
					fncBD_ActualizarDBBanco();
					printf("\nNOTA:\n");
					printf("Lo siento, la cuenta esta bloqueada. \n");
					printf("Intentos fallidos %i. \n", SessionIntentos);
				}else{
					printf("\nNOTA:\n");
					printf("Lo siento, PIN incorrecto. \n");
					printf("Intentos disponible %i. \n", 3 - SessionIntentos);
					strcpy(GuardaCuenta, banco.NoTarjeta);
				}

				fncBD_DeshacerConexionDB();	
			}
		}
	}else
	{
		printf("\nNOTA:\n");
		printf("Lo siento, la cuenta es inexistente. \n");
		fncBD_DeshacerConexionDB();
	}
	
	BUFFERFREE;

}
