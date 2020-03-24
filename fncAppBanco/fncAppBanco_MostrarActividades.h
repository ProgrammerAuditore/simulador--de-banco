void fncAppBanco_MostrarActividades(){
    
    CLEAN;
	printf("%s", TitulosAppBanco[5]);
	int codigo = 0;
	
	printf("Tipos de actividades disponibles: \n");
	printf("#1 > Depositos  \n");
	printf("#2 > Retiros  \n");
	printf("#3 > Transferencias enviado  \n");
	printf("#4 > Transferencias recibido  \n");
	printf("#5 > Compras  \n");
	printf("#6 > Configuracion de la cuenta  \n");
	printf("#7 > Notificaciones del banco  \n");
	printf("#0 > Todos  \n");
	printf("Selecciona el tipo de actividad a mostrar: ");
	scanf("%i", &codigo);
	BUFFERFREE;

	switch (codigo)
	{
		case 1: fncBD_MostrarDatosActividades(taDeposito); break;
		case 2: fncBD_MostrarDatosActividades(taRetiro); break;
		case 3: fncBD_MostrarDatosActividades(taTransferenciaEnviado); break;
		case 4: fncBD_MostrarDatosActividades(taTransferenciaRecibido); break;
		case 5: fncBD_MostrarDatosActividades(taCompra); break;
		case 6: fncBD_MostrarDatosActividades(taConfiguracionCuenta); break;
		case 7: fncBD_MostrarDatosActividades(taNotificacionBanco); break;
		case 0: fncBD_MostrarDatosActividades(0); break;
		default: printf("Lo siento, opcion incorrecto. \n");
	}

	BUFFERFREE;	
    
}