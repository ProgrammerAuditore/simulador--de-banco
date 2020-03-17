void fncBD_CrearBDActividades(){
	
	// Crear la base de datos de actividades
	sprintf(bdusuarios.PATHActividades,"%s%s/%s%s",
	FolderBD[0], banco.NoCuenta,
	FileBD[0], banco.NoTarjeta);
	
	FILE *bd = fopen(bdusuarios.PATHActividades, "w+");
	char cFecha[MAXCARACTERES];
	
	if( bd == NULL){
		perror("Base de datos << actividades >> no creado... \n");
	}	 
	
	// Obtener la fecha
	time_t f; time(&f);
    sprintf(cFecha,"%s",ctime(&f));
	SEPARARSTR(cFecha, cFecha,"\n");
	
	fprintf(bd,"1;   // No. de operaciones \n");
	fprintf(bd,"100; // Tpo de actividad \n");
	fprintf(bd,"%s; // Fecha \n", cFecha);
	fprintf(bd,"Banco: E&V;  // Remitente \n");
	fprintf(bd,"Cuenta: creada; // Asunto \n");
	fprintf(bd,"Monto: (+) $0.00; // Descripcion \n");
	
	fclose(bd);	
}