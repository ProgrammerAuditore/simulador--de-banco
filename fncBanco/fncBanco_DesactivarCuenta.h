void fncBanco_DesactivarCuenta(){
    
    CLEAN;
	printf("%s", TitulosBanco[15]);
	String NoTarjeta;
	int PIN[2] = {0,0};

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO_INPUT(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		// Obtener el path de cada base de datos
		fncBD_EstablecerConexionBD(false);
		// Obtener registros de la base de datos << banco >>
		fncBD_ObtenerDatosBanco();

				// Verificar el saldo de cuenta
		if( banco.Saldo > 0  ){
				MOSTRAR_MSGO_ERROR("Lo siento, la cuenta tiene fondos.");	
				// Verificar el estado de cuenta
		}else if( banco.EstadoDeCuenta == ecCuentaDesactivada){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta ya esta desactivada. \n");
		}else if( banco.EstadoDeCuenta == ecCuentaBloqueada ){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta bloqueada, la cuenta deberia estar (activada).  \n");
		}else if( banco.EstadoDeCuenta == ecCuentaCreadaONueva){
			printf("Lo siento, operacion rechazado. \n");
			printf("Cuenta nueva, la cuenta deberia estar (activada). \n");
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

            if( CHECKEO_PIN(PIN[1]) ){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN debe ser de 6 digitos.");
			}else if(PIN[1] != PIN[0]){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN no coinciden.");
			}else if( PIN[1] != banco.PIN ){
				MOSTRAR_MSGO_ERROR("Lo siento, PIN incorrecto.");
			}else{
                // Cambiar estado de cuenta a :
                // cuenta desactivada
                banco.EstadoDeCuenta = ecCuentaDesactivada;
                
                // Actualizar la base de datos << banco >>
				// de la cuenta
                fncBD_ActualizarDBBanco();

				// Registrar operacion
				actividades.TipoDeActividad = taConfiguracionCuenta;
				fncBD_RegistrarActividades("Banco: E&V Bank",
				"Cuenta: Desactivada", "Operacion: Aprobada");
                
                printf("\nNOTA:\n");
                printf("La cuenta %s \n", banco.NoCuenta);
                printf("con no. de tarjeta %s: \n", banco.NoTarjeta);
                printf("Se desactivo exitosamente. \n");
            }
        }
	}else{ MOSTRAR_MSGO_ERROR("Lo siento, la cuenta es inexistente."); }

	fncBD_DeshacerConexionDB();
	//BUFFERFREE;

}