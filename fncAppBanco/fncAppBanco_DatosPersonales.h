void fncAppBanco_DatosPersonales(){
    
	CLEAN;
	printf("%s", TitulosAppBanco[3]);

	fncBD_MostrarDatosUser();

	BUFFERFREE;	

}