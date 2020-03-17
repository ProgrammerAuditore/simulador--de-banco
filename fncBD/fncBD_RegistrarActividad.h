void fncBD_RegistrarActividad(String xRemitente, String xAsunto, String xDescripcion){
	
	
	// Obtener PATH temporal
	#ifdef __WIN32
		char PATHtmp[MAXCARACTERES];
		sprintf(PATHtmp,"%s%s/%s%s",
		FolderBD[0],
		bdusuarios.NoCuenta,
		FileBD[3],
		bdusuarios.NoTarjeta
		);
	#elif __linux__
		char PATHtmp[500];
		sprintf(PATHtmp,"%s%s/%s%s",
		FolderBD[0],
		bdusuarios.NoCuenta,
		FileBD[3],
		bdusuarios.NoTarjeta
		);
	#endif
	
	FILE *bd = fopen(bdusuarios.PATHActividades, "r+");
	FILE *bd_tmp = fopen(PATHtmp, "w+");
	char Registro[MAXCARACTERES];
    char cFecha[MAXCARACTERES];
    
	 // Obtener la fecha
	time_t f; time(&f);
    sprintf(cFecha,"%s",ctime(&f));
	
	if(bd == NULL){
		perror("Base de datos no econtrados...");
		exit(1);
	}
	
	GETREGISTRO(Registro, bd);
	actividades.TotalDeCampos = atoi(Registro);
	fprintf(bd_tmp,"%i;\n", actividades.TotalDeCampos + 1);
	
	for(int itemF =0; itemF < actividades.TotalDeCampos; itemF++){
		for(int itemRg = 0; itemRg < NOFILAS_DBACT; itemRg++){
				GETREGISTRO(Registro, bd);
				fprintf(bd_tmp,"%s;\n", Registro);
				//printf("%s \n", Registro);
		}
	}
	
	fclose(bd);
	
	fprintf(bd_tmp,"%i;\n", actividades.TipoDeActividad);
	
	SEPARARSTR(actividades.Fecha, cFecha,"\n");
	fprintf(bd_tmp,"%s;\n", actividades.Fecha);
	
	SEPARARSTR(actividades.Remitente, xRemitente,"\n");
	fprintf(bd_tmp,"%s;\n", actividades.Remitente);
	
	SEPARARSTR(actividades.Asunto, xAsunto,"\n");
	fprintf(bd_tmp,"%s;\n", actividades.Asunto);
	
	SEPARARSTR(actividades.Descripcion, xDescripcion,"\n");
	fprintf(bd_tmp,"%s;\n", actividades.Descripcion);
	
	fclose(bd_tmp);
	
	remove(bdusuarios.PATHActividades);
	rename(PATHtmp, bdusuarios.PATHActividades);
	
}
