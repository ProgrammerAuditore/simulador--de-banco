void fncBanco_BloquearCuenta(){
    
    CLEAN;
	printf("%s", TitulosBanco[10]);
	char NoTarjeta[MAXCARACTERES];
	int PIN[2] = {0,0};

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		// Obtener el path de cada base de datos
		fncBD_EstablecerConexionBD(false);
		// Obtener registros de la base de datos << banco >>
		fncBD_ObtenerDatosBanco();

				// Verificar el saldo de cuenta
		if( banco.Saldo > 0  ){
				printf("\n*** ");
				printf("Lo siento, la cuenta tiene fondos. \n");	
				// Verificar el estado de cuenta
		}else if( banco.EstadoDeCuenta == ecCuentaBloqueada ){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta ya esta bloqueada. \n");
		}else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta nueva, la cuenta deberia estar (activada). \n");
		}else if( banco.EstadoDeCuenta == ecCuentaDesactivada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta desactiva, la cuenta deberia estar (activada). \n");
		}else if( banco.EstadoDeCuenta == ecCuentaRecuperado){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta recuperada, la cuenta deberia estar (activada). \n");
		}else{

            printf("2) Introduzca PIN de la cuenta: \n");
            scanf("%i", &PIN[0]);
            BUFFERFREE;

            printf("3) Confirmar PIN de la cuenta: \n");
            scanf("%i", &PIN[1]);
            BUFFERFREE;

            if( NUEVO_PIN(PIN[1]) ){
                printf("\n*** ");
                printf("Lo siento, PIN debe ser de 6 digitos. \n");
            }else if( PIN[1] != PIN[0] ){
                printf("\n*** ");
                printf("Lo siento, PIN no coinciden. \n");
            }else if( PIN[1] != banco.PIN ){
                printf("\n*** ");
                printf("Lo siento, PIN incorrecto. \n");
            }else{
                // Cambiar estado de cuenta a :
                // cuenta bloqueada
                banco.EstadoDeCuenta = ecCuentaBloqueada;
                
                // Actualizar la base de datos << banco >>
				// de la cuenta
                fncBD_ActualizarDBBanco();
                
                printf("\nNOTA:\n");
                printf("La cuenta %s \n", banco.NoCuenta);
                printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
                printf("Se bloqueo exitosamente. \n");
            }
        }
	}else
	{
		printf("Lo siento, la cuenta es inexistente. \n");
	}

	fncBD_DeshacerConexionDB();
	//BUFFERFREE;

}