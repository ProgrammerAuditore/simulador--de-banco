void fncBD_ActualizarBDUsuariosRegistrados(){
	
	String _pathbd_tmp ;
	snprintf(_pathbd_tmp, MAXCARACTERES, "%s%s", FolderBD[0] ,FilesBD[3]);

	FILE *bd = fopen(ArchivoBaseDeDatos[0], "r+");
	FILE *bd_tmp = fopen(_pathbd_tmp, "w+");

	int Rgfilas = 0;
	String Registro;
	
	if( bd == NULL){
		perror("fncBD_ActualizarBDUsuariosRegistrados: \n");
		perror("Base de datos << registo de usuarios >> no encontrado... \n");
		exit(1);
	}
	
	GETREGISTRO(Registro, bd);
	const int filaTotal = atoi(Registro);

	rewind( bd_tmp );
	fprintf( bd_tmp, "%i;    // Total de usuarios \n" , (filaTotal - 1) );

	int itemF = 0, itemRg = 0;
	for(itemF = 0; itemF < filaTotal; itemF++){
		for(itemRg = 0; itemRg < NOFILAS_BDUSUARIOS; itemRg++){
			Rgfilas++;
			
			GETREGISTRO(Registro, bd);
			
			if( fnc_CompararString(Registro, banco.NoTarjeta) || 
				fnc_CompararString(Registro, banco.NoCuenta)
			) continue;


			if(Rgfilas == 1){
				fprintf(bd_tmp ,"%s; // RgAnterior>%i // El primero \n", Registro, Rgfilas);
			}else if( Rgfilas == (filaTotal * NOFILAS_BDUSUARIOS) ){
				fprintf(bd_tmp ,"%s; //  RgAnterior>%i // El ultimo \n", Registro, Rgfilas); 
			}else{
				fprintf(bd_tmp ,"%s; // RgAnterior>%i \n", Registro, Rgfilas);
			}

		}
	}
	
	fprintf(bd_tmp, "%s", "// Fin del documento. No borrar ningun dato. ");

	fclose(bd);
	fclose(bd_tmp);
	remove(ArchivoBaseDeDatos[0]);
	rename(_pathbd_tmp, ArchivoBaseDeDatos[0]);

}
