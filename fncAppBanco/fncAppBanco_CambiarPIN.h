void fncAppBanco_CambiarPIN(){

    CLEAN;
	printf("%s", TitulosAppBanco[0]);
	int PIN[2] = {0,0};

	printf("1) Introduzca PIN ( actual ) de 6 digitos: \n");
	scanf("%i", &PIN[0]);
	BUFFERFREE;

    if( PIN[0] == banco.PIN){
        
        printf("2) Introduzca PIN nuevo de 6 digitos: \n");
	    scanf("%i", &PIN[0]);
	    BUFFERFREE;

        printf("3) Confirmar PIN nuevo de 6 digitos: \n");
	    scanf("%i", &PIN[1]);
	    BUFFERFREE;

        if( CHECKEO_PIN(PIN[1]) ){
            MOSTRAR_MSGO_ERROR("Lo siento, PIN (nuevo) debe ser de 6 digitos.");
        }else if(PIN[1] == banco.PIN){
            MOSTRAR_MSGO_ERROR("Lo siento, PIN (nuevo) no deber ser igual al anterior.");
        }else if(PIN[1] != PIN[0]){
            MOSTRAR_MSGOPERACION("Lo siento, PIN (nuevo) no coinciden.");
        }else{
            
            // Al cambiar el PIN la cuenta se activa
            printf("El PIN se modifico exitosamente. \n");
            banco.PIN = PIN[1];
            banco.EstadoDeCuenta = ecCuentaActivada;
            fncBD_ActualizarDBBanco();
            Session = false;
       
        }

    }else MOSTRAR_MSGOPERACION("Lo siento, PIN incorrecto.");

	BUFFERFREE;

}