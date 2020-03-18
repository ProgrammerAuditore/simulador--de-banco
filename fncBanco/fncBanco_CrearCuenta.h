int fnc_NumRandom();
int fnc_GenerarPIN();

void fncBanco_CrearCuenta(){
	
	CLEAN;
	printf("%s", TitulosBanco[1]);
	char Comandos[250];
	int UsuarioID=0;
	
	FILE *bd = fopen(ArchivoBaseDeDatos[0], "r");
    char Registro[250];
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
	CHECKEO(user.Nombres);
	BUFFERFREE;
	
	
	printf("Escribe apellido paterno: \n");
	fgets(user.ApellidoPaterno, MAXCARACTERES, stdin);
	CHECKEO(user.ApellidoPaterno);
	BUFFERFREE;

	printf("Escribe apellido materno: \n");
	fgets(user.ApellidoMaterno, MAXCARACTERES, stdin);
	CHECKEO(user.ApellidoMaterno);
	BUFFERFREE;
	
	printf("Escribe fecha de nacimiento (dd mm aaaa): \n");
	scanf("%i %i %i", &dia, &mes, &anho);
	if( (dia > 0 && dia <= 32) && (mes > 0 && mes <= 12) && 
		( (2020-anho) >= 18 && (2020-anho) <= 52 ))
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
		user.Nombres[0],
		user.ApellidoPaterno[0],
		user.ApellidoMaterno[0],
		UsuarioID
		);
		strcpy(bdusuarios.NoTarjeta, banco.NoTarjeta);
		
		// Creando No. Cuenta
		sprintf(banco.NoCuenta,"%i%i%i",
		anho, UsuarioID, NoAleatorio );
		strcpy(bdusuarios.NoCuenta, banco.NoCuenta);
		
		banco.PIN = fnc_GenerarPIN();;
		banco.EstadoDeCuenta = 0;
		banco.Saldo = 0;
		
		#ifdef __WIN32	
			// Creamos la carpeta
			sprintf(Comandos,"%s%s",FolderBD[0], banco.NoCuenta);
			mkdir(Comandos);
		#elif __linux__
			// Creamos la carpeta
			sprintf(Comandos,"%s%s",FolderBD[0], banco.NoCuenta);
			mkdir(Comandos, 0777);
		#endif
		
		// Registrar al usuario a la base de datos
		fncBD_RegistrarUsuarioDB();
		
		printf("\n------------[ CUENTA CREADO ]\n");
		fncBD_MostrarDatosBanco();
		fncBD_MostrarDatosUser();
		
	}else{
		printf("\n------------[ CUENTA NO CREADO ]\n");
	}
	
	fncBD_DeshacerConexionDB();
	BUFFERFREE;

}

int fnc_NumRandom(){
	time_t t;
	srand((unsigned) time(&t));
	return 100 + rand() % 989;
}

int fnc_GenerarPIN(){
	time_t t;
	srand((unsigned) time(&t));
	return 100000 + rand() % 998999;
}