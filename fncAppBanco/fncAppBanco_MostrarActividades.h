void fncAppBanco_MostrarActividades(){
    
    CLEAN;
	printf("%s", TitulosAppBanco[5]);
	int codigo = 0;
	

	printf("Tipos de actividad disponible. \n");
	printf("#1 > Depositos  \n");
	printf("#2 > Retiros  \n");
	printf("#3 > Transferencias enviado  \n");
	printf("#4 > Transferencias recibido  \n");
	printf("#5 > Compras  \n");
	printf("#0 > Todos  \n");
	printf("Selecciona el tipo de actividad a mostrar: ");
	scanf("%i", &codigo);
	BUFFERFREE;

	switch (codigo)
	{
		case 1: fncBD_MostrarActividades(200); break;
		case 2: fncBD_MostrarActividades(400); break;
		case 3: fncBD_MostrarActividades(301); break;
		case 4: fncBD_MostrarActividades(302); break;
		case 5: fncBD_MostrarActividades(700); break;
		case 0: fncBD_MostrarActividades(0); break;
		default: printf("Lo siento, opcion incorrecto. \n");
	}

	BUFFERFREE;	
    
}