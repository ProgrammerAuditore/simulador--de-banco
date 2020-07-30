// No es necesario colocar ";" al final por que es automatico
void fncBD_RegistrarActividades(String xRemitente, String xAsunto, String xDescripcion){
	
	
	// Obtener PATH temporal
	String PATHtmp;
	snprintf(PATHtmp, MAXCARACTERES * 2  ,"%s%s/%s%s",
	FolderBD[0],
	bdusuarios.NoCuenta,
	FilesBD[3],
	bdusuarios.NoTarjeta
	);

	FILE *bd = fopen(bdusuarios.PATHActividades, "r+");
	FILE *bd_tmp = fopen(PATHtmp, "w+");
	String Registro;
    String cFecha;
    
	 // Obtener la fecha
	time_t f; time(&f);
    snprintf(cFecha, MAXCARACTERES * 2 ,"%s",ctime(&f));
	
	if(bd == NULL){
		perror("fncBD_RegistrarActividades: \n");
		perror("Lo siento, BASE DE DATOS de datos de actividades no establecida. :'( \n");
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

	fprintf(bd_tmp, "%s", "// Fin del documento. No borrar ningun dato. ");
	
	fclose(bd_tmp);
	
	remove(bdusuarios.PATHActividades);
	rename(PATHtmp, bdusuarios.PATHActividades);
	
}
