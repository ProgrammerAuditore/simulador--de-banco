void fncAppBanco_CerrarSession(){
	
	CLEAN;
	printf("%s", TitulosAppBanco[2]);
	char Respuesta = 'Y';

	printf("1) ¿Estas seguro de cerrar session? (yY/nN): \n");
	scanf("%c", &Respuesta);
	BUFFERFREE;
	
	if( Respuesta == 'n' || Respuesta == 'N' ){
		printf("Cerrar session, cancelado. \n");
	}else if( Respuesta == 'Y' || Respuesta == 'y' ){
		fncBD_DeshacerConexionDB();
		Session = false;
		printf("Cerro session, exitosamente. \n");

	}else{
		printf("Lo siento, opcion incorrecta. \n");
	}
	
	BUFFERFREE;

}
