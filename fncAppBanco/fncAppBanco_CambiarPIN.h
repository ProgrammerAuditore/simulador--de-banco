void fncAppBanco_CambiarPIN(){

    CLEAN;
	printf("%s", TitulosAppBanco[0]);
	int PIN[2] = {0,0};

	printf("1) Introduzca PIN ( actual ): \n");
	scanf("%i", &PIN[0]);
	BUFFERFREE;

    if( PIN[0] == banco.PIN){
        
        printf("2) Introduzca PIN nuevo: \n");
	    scanf("%i", &PIN[0]);
	    BUFFERFREE;

        printf("3) Confirmar PIN nuevo: \n");
	    scanf("%i", &PIN[1]);
	    BUFFERFREE;

        if( NUEVO_PIN(PIN[1]) ){
            printf("\n*** ");
            printf("Lo siento, PIN (nuevo) debe ser de 6 digitos. \n");
        }else if(PIN[1] == banco.PIN){
            printf("\n*** ");
            printf("Lo siento, PIN (nuevo) no deber ser igual al anterior. \n");
        }else if(PIN[1] != PIN[0]){
            printf("\n*** ");
            printf("Lo siento, PIN (nuevo) no coinciden. \n");
        }else{
            
            printf("El PIN se modifico exitosamente. \n");
            banco.PIN = PIN[1];
            banco.EstadoDeCuenta = 1;
            fncBD_ActualizarDBBanco();
            Session = false;
       
        }

    }else{
        printf("\n*** ");
        printf("Lo siento, PIN incorrecto. \n");
    }
	
	BUFFERFREE;

}