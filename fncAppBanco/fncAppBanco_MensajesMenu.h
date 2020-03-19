void fncAppBanco_MensajesMenu(){
	
	printf("%s",TitulosAppBanco[0]);

	if(!Session){
		// Si aun no se inicia session
		printf("#1 > Iniciar session  \n");
		printf("#0 > Salir del programa  \n");
	
	}else{

		if(banco.EstadoDeCuenta == 0){
			// Si la cuenta es nueva obligamos al usuario
			// a cambiar el PIN generado por el banco
			printf("Hemos detectado que esta cuenta es nueva, \n");
			printf("es necesario que cambie el PIN de la cuenta, \n");
			printf("para poder activarlo y usar la tarjeta. \n");
			printf("#1 > Cerrar session  \n");
			printf(" x > Cambiar PIN \n");			
		}
		else 
		{
			printf("Bienvenido: %s %s %s \n", 
			user.Nombres, user.ApellidoPaterno, user.ApellidoMaterno );
			printf("#1 > Cerrar session  \n");
			printf("#2 > Datos personales  \n");
			printf("#3 > Datos banco \n");
			printf("#4 > Mostrar actividades \n");	
			printf("#5 > Consultar saldo \n");	
		}

	}
	
}
