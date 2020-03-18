void fncAppBanco_DatosPersonales(){
    
	CLEAN;
	printf("%s", TitulosAppBanco[3]);

	printf("Nombre (s): %s\n", user.Nombres);
	printf("Apellido Paterno: %s\n", user.ApellidoPaterno);
	printf("ApellidoMaterno: %s\n", user.ApellidoMaterno);
	printf("Fecha de Nacimiento: %s\n", user.FechaNacimiento);

	BUFFERFREE;	

}