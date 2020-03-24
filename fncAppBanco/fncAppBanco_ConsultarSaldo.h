void fncAppBanco_ConsultarSaldo(){

    CLEAN;
	printf("%s", TitulosAppBanco[9]);
	int PIN[2] = {0,0};

        printf("2) Introduzca PIN de la cuenta: \n");
	    scanf("%i", &PIN[0]);
	    BUFFERFREE;

        printf("3) Confirmar PIN de la cuenta: \n");
	    scanf("%i", &PIN[1]);
	    BUFFERFREE;

        if( CHECKEO_PIN(PIN[1]) ){
			MOSTRAR_MSGO_ERROR("Lo siento, PIN debe ser de 6 digitos.");
		}else if(PIN[1] != PIN[0]){
			MOSTRAR_MSGO_ERROR("Lo siento, PIN no coinciden.");
		}else if( PIN[1] != banco.PIN ){
			MOSTRAR_MSGO_ERROR("Lo siento, PIN incorrecto.");
		}else{

            printf("\nNOTA:\n");
            printf("El saldo de la cuenta %s  \n", banco.NoCuenta);
            printf("con no. de tarjeta %s es: \n", banco.NoTarjeta);
            printf("Saldo: %.2lf \n", banco.Saldo);
       
        }

	BUFFERFREE;

}