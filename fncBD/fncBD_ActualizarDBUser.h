void fncBD_ActualizarDBUser(){
	
	// Crear la base de datos de usuario
	sprintf(bdusuarios.PATHUsuario,"%s%s/%s%s",
	FolderBD[0], banco.NoCuenta,
	FileBD[2], banco.NoTarjeta);
	
	FILE *bd = fopen(bdusuarios.PATHUsuario, "w+");
	
	if( bd == NULL){
		perror("Base de datos << usuario >> no creado... \n");
	}
	
	fprintf(bd, "%s; // Nombres \n", user.Nombres);
	fprintf(bd, "%s; // Apellido 1 \n", user.ApellidoPaterno);
	fprintf(bd, "%s; // Apellido 2 \n", user.ApellidoMaterno);
	fprintf(bd, "%s; // Fecha de nacimiento ", user.FechaNacimiento);
	
	fclose(bd);		
	
}