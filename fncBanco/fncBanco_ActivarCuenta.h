void fncBanco_ActivarCuenta(){
        
    CLEAN;
	printf("%s", TitulosBanco[8]);
	char NoTarjeta[MAXCARACTERES];
	int PIN[2] = {0,0};

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		fncBD_EstablecerConexionBD(false);
		fncBD_ObtenerDatosBanco();

		printf("2) Introduzca PIN de la cuenta: \n");
	    scanf("%i", &PIN[0]);
	    BUFFERFREE;

        printf("3) Confirmar PIN de la cuenta: \n");
	    scanf("%i", &PIN[1]);
	    BUFFERFREE;

		if( NUEVO_PIN(PIN[1]) ){
            printf("\n*** ");
            printf("Lo siento, PIN debe ser de 6 digitos. \n");
        }else if(PIN[1] != PIN[0]){
            printf("\n*** ");
            printf("Lo siento, PIN no coinciden. \n");
        }else if( PIN[1] != banco.PIN ){
            printf("\n*** ");
            printf("Lo siento, PIN incorrecto. \n");
        }else if( banco.EstadoDeCuenta == 1 ){
            printf("\n*** ");
            printf("Lo siento, la cuenta esta activa. \n");
        }else{
			banco.EstadoDeCuenta = 1;
            fncBD_ActualizarDBBanco();
			
            printf("\nNOTA:\n");
            printf("La cuenta %s \n", banco.NoCuenta);
            printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
            printf("Se activo exitosamente. \n");
        }

	}else
	{
		printf("Lo siento, la cuenta es inexistente. \n");
	}

	fncBD_DeshacerConexionDB();
	//BUFFERFREE;

}