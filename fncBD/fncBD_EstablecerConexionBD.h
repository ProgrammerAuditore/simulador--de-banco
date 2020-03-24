void fncBD_EstablecerConexionBD(bool verConexion){
	
	int conexion=0;
	//printf("%s %s \n", bdusuarios.NoCuenta, bdusuarios.NoTarjeta);
	
	snprintf(bdusuarios.PATHUser, MAXCARACTERES * 2 ,"%s%s/%s%s",
	FolderBD[0],
	bdusuarios.NoCuenta,
	FilesBD[2],
	bdusuarios.NoTarjeta
	);
	
	FILE *PATHUser = fopen(bdusuarios.PATHUser, "r");
	if(PATHUser == NULL){
		perror("Lo siento, BASE DE DATOS de datos de usuario no establecida. :).\n");
		exit(1);
	}else{ conexion++; }
	fclose(PATHUser);
	
	snprintf(bdusuarios.PATHActividades, MAXCARACTERES * 2 ,"%s%s/%s%s",
	FolderBD[0],
	bdusuarios.NoCuenta,
	FilesBD[0],
	bdusuarios.NoTarjeta
	);
	
	FILE *PATHActividades = fopen(bdusuarios.PATHActividades, "r");
	if(PATHActividades == NULL){
		perror("Lo siento, BASE DE DATOS de datos de actividades no establecida. :).\n");
		exit(1);
	}else{ conexion++; }
	fclose(PATHActividades);
		
	snprintf(bdusuarios.PATHBanco, MAXCARACTERES * 2 ,"%s%s/%s%s",
	FolderBD[0],
	bdusuarios.NoCuenta,
	FilesBD[1],
	bdusuarios.NoTarjeta
	);
	
	FILE *PATHABanco = fopen(bdusuarios.PATHBanco, "r");
	if(PATHABanco == NULL){
		perror("Lo siento, BASE DE DATOS de datos de banco no establecida. :).\n");
		exit(1);
	}else{ conexion++; }
	fclose(PATHABanco);
	
	if( conexion == 3){
		MOSTRAR_MSGOPERACION("CONEXION ESTABLECIDA");
		if(verConexion)
			fncBD_MostrarConexionDB();
	}
}
