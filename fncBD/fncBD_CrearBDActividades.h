void fncBD_CrearBDActividades(){
	
	// Crear la base de datos de actividades
	snprintf(bdusuarios.PATHActividades, MAXCARACTERES * 2 ,"%s%s/%s%s",
	FolderBD[0], banco.NoCuenta,
	FilesBD[0], banco.NoTarjeta);
	
	FILE *bd = fopen(bdusuarios.PATHActividades, "w+");
	String cFecha;
	
	if( bd == NULL){
		perror("Base de datos << actividades >> no creado... \n");
	}	 
	
	// Obtener la fecha
	time_t f; time(&f);
    snprintf(cFecha, MAXCARACTERES * 2 , "%s",ctime(&f));
	SEPARARSTR(cFecha, cFecha,"\n");
	
	fprintf(bd,"1;   // No. de operaciones \n");
	fprintf(bd,"%i; // Tpo de actividad \n", taNotificacionBanco );
	fprintf(bd,"%s; // Fecha \n", cFecha);
	fprintf(bd,"Banco: E&V Bank;  // Remitente \n");
	fprintf(bd,"Cuenta: Creada; // Asunto \n");
	fprintf(bd,"Operacion: Aprobada; // Descripcion \n");
	fprintf(bd, "%s", "// Fin del documento. No borrar ningun dato. ");
	//fprintf(bd,"Monto: (+) $0.00; // Descripcion \n");
	
	fclose(bd);	
}