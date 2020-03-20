void fncBanco_ModificarCuenta(){
	
	CLEAN;
	printf("%s", TitulosBanco[2]);
	char NoTarjeta[MAXCARACTERES];
	char Datos[NOFILAS_DBUSER][MAXCARACTERES];

	printf("1) Introduzca el No. de tarjeta: \n");
	fgets(NoTarjeta, MAXCARACTERES, stdin);
	CHECKEO(NoTarjeta);
	BUFFERFREE;
	
	if(fncBD_VerificarCuenta(NoTarjeta)){
		fncBD_EstablecerConexionBD(false);
		// Requisito para actualizar al Path / Base de datos de 
		// << datos de usuario >>
		fncBD_ObtenerDatosBanco();

		fncBD_MostrarDatosUser();
		printf("\n------------[ MODIFICANDO DATOS PERSONALES ]\n");
		
		printf("Escribe nuevo nombre(s): \n");
		fgets( Datos[0] , MAXCARACTERES , stdin );
		MODIFICAR_DATO( user.Nombres, MAXCARACTERES , Datos[0] );
		BUFFERFREE;
		
		printf("Escribe nuevo apellido 1: \n");
		fgets( Datos[1] , MAXCARACTERES , stdin );
		MODIFICAR_DATO( user.ApellidoPaterno, MAXCARACTERES , Datos[1] );
		BUFFERFREE;
		
		printf("Escribe nuevo apellido 2: \n");
		fgets( Datos[2] , MAXCARACTERES , stdin );
		MODIFICAR_DATO( user.ApellidoMaterno, MAXCARACTERES , Datos[2] );
		BUFFERFREE;
		
		printf("------------[ NUEVOS DATOS PERSONALES ]\n");
		printf("Nombre (s): %s\n", user.Nombres);
		printf("Apellido Paterno: %s\n", user.ApellidoPaterno);
		printf("ApellidoMaterno: %s\n", user.ApellidoMaterno);
		printf("Fecha de Nacimiento: %s\n", user.FechaNacimiento);
		
		fncBD_ActualizarDBUser();
		
	}else{
		printf("Lo siento, cuenta inexistente. \n");
	}

	fncBD_DeshacerConexionDB();
	// BUFFERFREE;
	
}

