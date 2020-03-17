void fncBD_EstablecerConexionBD(bool verConexion){
	
	int conexion=0;
	//printf("%s %s \n", bdusuarios.NoCuenta, bdusuarios.NoTarjeta);
	
	snprintf(bdusuarios.PATHUsuario, MAXCARACTERES * 2 ,"%s%s/%s%s",
	FolderBD[0],
	bdusuarios.NoCuenta,
	FileBD[2],
	bdusuarios.NoTarjeta
	);
	
	FILE *PATHUsuario = fopen(bdusuarios.PATHUsuario, "r");
	if(PATHUsuario == NULL){
		perror("Lo siento, BASE DE DATOS de datos de usuario no establecida. :).\n");
		exit(1);
	}else{ conexion++; }
	fclose(PATHUsuario);
	
	snprintf(bdusuarios.PATHActividades, MAXCARACTERES * 2 ,"%s%s/%s%s",
	FolderBD[0],
	bdusuarios.NoCuenta,
	FileBD[0],
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
	FileBD[1],
	bdusuarios.NoTarjeta
	);
	
	FILE *PATHABanco = fopen(bdusuarios.PATHBanco, "r");
	if(PATHABanco == NULL){
		perror("Lo siento, BASE DE DATOS de datos de banco no establecida. :).\n");
		exit(1);
	}else{ conexion++; }
	fclose(PATHABanco);
	
	if( conexion == 3){
		printf("------------[ CONEXION ESTABLECIDA ]\n");
		if(verConexion)
			fncBD_MostrarConexionDB();
	}
}
