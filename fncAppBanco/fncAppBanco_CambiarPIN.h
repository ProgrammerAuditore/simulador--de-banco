void fncAppBanco_CambiarPIN(){

    CLEAN;
	printf("%s", TitulosAppBanco[1]);
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

        if( PIN[0] == PIN[1] && PIN[1] != banco.PIN &&
            PIN[0] >= 111111 && PIN[0] <= 999999 ){
            
            printf("El PIN se modifico exitosamente. \n");
            banco.PIN = PIN[1];
            banco.EstadoDeCuenta = 1;
            fncBD_ActualizarDBBanco();
            Session = false;
       
        }else{
            printf("Lo siento, PIN incorrecto. \n");
        }
    
    }else{
            printf("Lo siento, PIN incorrecto. \n");
    }
	
	BUFFERFREE;

}