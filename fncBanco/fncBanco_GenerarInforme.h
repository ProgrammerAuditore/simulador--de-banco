void fncBanco_GenerarInforme(){

    String strPathInfo;
	
    // Generar nombre del informe
    snprintf(strPathInfo, MAXCARACTERES * 3 , "%s%s.%s.info",
    user.ApellidoPaterno, user.ApellidoMaterno,
	banco.NoCuenta );
    
    FILE *info = fopen(strPathInfo, "w+");

	if( info == NULL){
		perror("Base de datos << banco >> no creado... \n");
	}
	
    fprintf(info, "------------[ CUENTA CREADO ] \n");
    fprintf(info, "------------[ DATOS BANCO ] \n");
	fprintf(info, "\n");
	fprintf(info, "Numero de tarjeta: %s \n", banco.NoTarjeta);
	fprintf(info, "Numero de cuenta: %s \n", banco.NoCuenta);
	fprintf(info, "PIN: %i \n", banco.PIN);
	fprintf(info, "Estado de cuenta: Cuenta nueva \n");
	fprintf(info, "Saldo: %lf \n", banco.Saldo);
	fprintf(info, "\n");
    fprintf(info, "------------[ DATOS PERSONALES ] \n");
	fprintf(info, "\n");
    fprintf(info, "Nombre (s): %s \n", user.Nombres);
	fprintf(info, "Apellido Paterno: %s \n", user.ApellidoPaterno);
	fprintf(info, "Apellido Materno: %s \n", user.ApellidoMaterno);
	fprintf(info, "Fecha de nacimiento: %s \n", user.FechaNacimiento);
	fprintf(info, "\n");
    fprintf(info, "------------[ Informe Banco E&V ]");

	printf("Informe guardado en %s \n", strPathInfo);
	
	fclose(info);	
	
}