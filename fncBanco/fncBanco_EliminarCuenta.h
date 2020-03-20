void fncBanco_EliminarCuenta(){

    CLEAN;
	printf("%s", TitulosBanco[7]);
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
        }if( banco.EstadoDeCuenta  != -1  ){
            printf("\n*** ");
            printf("Lo siento, la cuenta aun esta activa. \n");
        }else if( banco.Saldo > 0  ){
            printf("\n*** ");
            printf("Lo siento, la cuenta tiene fondos. \n");
        }else if( PIN[1] == banco.PIN ){

			remove(bdusuarios.PATHActividades);
			remove(bdusuarios.PATHBanco);
			remove(bdusuarios.PATHUsuario);
			
			#ifdef __WIN32
				ELIMINAR_DIR("rmdir /S /Q" , banco.NoCuenta);
			#elif __linux__
				ELIMINAR_DIR("rm -R -f" , banco.NoCuenta);
			#endif

			fncBD_ActualizarUsuariosBD();
			printf("\nNOTA:\n");
            printf("La cuenta %s \n", banco.NoCuenta);
            printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
            printf("Se elimino exitosamente. \n");
		
		}else{
			printf("Lo siento, PIN incorrecto. \n");
        }
		
	}else
	{
		printf("Lo siento, la cuenta es inexistente. \n");
	}

	fncBD_DeshacerConexionDB();
	BUFFERFREE;

}