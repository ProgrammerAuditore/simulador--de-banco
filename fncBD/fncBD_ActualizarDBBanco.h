void fncBD_ActualizarDBBanco(){
	
	FILE *bd_tmp = fopen(bdusuarios.PATHBanco,"w+");
		
	if( bd_tmp == NULL){
		perror("fncBD_ActualizarDBBanco: \n");
		perror("Error la base de datos no encontrados...");
		exit(1);
	}
	
	fprintf(bd_tmp,"%s;\n", banco.NoTarjeta);
	fprintf(bd_tmp,"%s;\n", banco.NoCuenta);
	fprintf(bd_tmp,"%i;\n", banco.PIN);
	fprintf(bd_tmp,"%i;\n", banco.EstadoDeCuenta);
	fprintf(bd_tmp,"%lf;", banco.Saldo);
	
	fclose(bd_tmp);	
	
}