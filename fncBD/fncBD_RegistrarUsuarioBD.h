void fncBD_RegistrarUsuarioDB(){
	FILE *bd = fopen(ArchivoBaseDeDatos[0], "r+");
	char Registro[250];
	
	if( bd == NULL){
		perror("Base de datos no encontrado... \n");
		exit(1);
	}
	
	GETREGISTRO(Registro, bd);
	bdusuarios.TotalDeCampos = atoi(Registro);
	
	int itemF = 0, itemRg = 0;
	for(itemF=0; itemF <  bdusuarios.TotalDeCampos; itemF++){
		for(itemRg =0; itemRg < NOFILAS_BDUSUARIOS; itemRg++){
			GETREGISTRO(Registro, bd);
			//printf("%s \n", Registro);
		}
	}
	
	fprintf(bd,"\n");
	fprintf(bd,"%s; \n", bdusuarios.NoTarjeta );
	fprintf(bd,"%s;   ", bdusuarios.NoCuenta );
	
	// Registrar el numero de registros
	rewind(bd);
	fprintf(bd, "%i;", bdusuarios.TotalDeCampos + 1 );
	fclose(bd);
	
	fncBD_CrearBDActividades();
	fncBD_CrearBDBanco();
	fncBD_CrearBDUsuario();
	
}