void fncBanco_CrearCuenta(){
	
	CLEAN;
	printf("%s", TitulosBanco[1]);
	String Comandos;
	int UsuarioID=0;
	
	FILE *bd = fopen(ArchivoBaseDeDatos[0], "r");
    String Registro;
	int NoAleatorio = 0, dia, mes, anho;

    if( bd == NULL){
        perror("Lo siento, BASE DE DATOS de datos de registro no establecida. :).\n");
        exit(1);
    }
	
	GETREGISTRO(Registro, bd);
    bdusuarios.TotalDeCampos = atoi(Registro); 
	NoAleatorio = fnc_NumRandom();
	fclose(bd);

	printf("Escribe nombre(s): \n");
	fgets(user.Nombres, MAXCARACTERES, stdin);
	CHECKEO_INPUT(user.Nombres);
	BUFFERFREE;
	
	
	printf("Escribe apellido paterno: \n");
	fgets(user.ApellidoPaterno, MAXCARACTERES, stdin);
	CHECKEO_INPUT(user.ApellidoPaterno);
	BUFFERFREE;

	printf("Escribe apellido materno: \n");
	fgets(user.ApellidoMaterno, MAXCARACTERES, stdin);
	CHECKEO_INPUT(user.ApellidoMaterno);
	BUFFERFREE;
	
	printf("Escribe fecha de nacimiento (dd mm aaaa): \n");
	scanf("%i %i %i", &dia, &mes, &anho);

	// Verificar la fecha de nacimiento
	if( (dia > 0 && dia <= 32) &&
		(mes > 0 && mes <= 12) && 
		( ( ANHO_ACTUAL  - anho )  >  MENOR_EDAD_APROBADO && 
		  ( ANHO_ACTUAL  - anho )  <  MAYOR_EDA_APROBADO ))
	{
		sprintf( user.FechaNacimiento,"%i/%i/%i", dia, mes, anho);
		printf("Campo aceptado.\n");
	}else{
		printf("Campo rechazado.\n");
		CAMPOS_INCORRECTAS++;
	} BUFFERFREE; 
	
	if(CAMPOS_INCORRECTAS == 0){
		
		// Obtener Id del usuario
		UsuarioID = (bdusuarios.TotalDeCampos + 1) * 103;
		
		// Creando No. Tarjera
		sprintf(banco.NoTarjeta,"%i-%c%c%c-%i",
		anho,
		toupper(user.Nombres[0]),
		toupper(user.ApellidoPaterno[0]),
		toupper(user.ApellidoMaterno[0]),
		UsuarioID
		);
		strcpy(bdusuarios.NoTarjeta, banco.NoTarjeta);
		
		// Creando No. Cuenta
		sprintf(banco.NoCuenta,"%i%i%i",
		anho, UsuarioID, NoAleatorio );
		strcpy(bdusuarios.NoCuenta, banco.NoCuenta);
		
		banco.PIN = fnc_GenerarPIN();
		banco.EstadoDeCuenta = ecCuentaCreadaONueva;
		banco.Saldo = 0;
		
		#ifdef __WIN32	
			// Creamos la carpeta
			sprintf(Comandos,"%s%s",FolderBD[0], banco.NoCuenta);
			mkdir(Comandos);
		#elif __linux__
			// Creamos la carpeta
			snprintf(Comandos, MAXCARACTERES * 2 ,"%s%s",FolderBD[0], banco.NoCuenta);
			mkdir(Comandos, 0777);
		#endif
		
		// Registrar al usuario a la base de datos
		fncBD_RegistrarBDUsuariosRegistrados();
		
		MOSTRAR_MSGOPERACION("CUENTA CREADO");
		
		MOSTRAR_MSGOPERACION("DATOS BANCO");
		fncBD_MostrarDatosBanco();
		
		MOSTRAR_MSGOPERACION("DATOS PERSONALES");
		fncBD_MostrarDatosUser();
		
	}else{
		MOSTRAR_MSGOPERACION("CUENTA NO CREADO");
	}
	
	fncBD_DeshacerConexionDB();
	BUFFERFREE;

}