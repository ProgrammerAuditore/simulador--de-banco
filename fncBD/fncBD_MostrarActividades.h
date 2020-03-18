void fncBD_MostrarActividades(int xAct){
	
	FILE *bd = fopen(bdusuarios.PATHActividades,"r");
	char Registro[MAXCARACTERES];
	int Coincidencias=0;
	
	if( bd == NULL){
		perror("Adios");
		exit(1);
	}
	
	GETREGISTRO(Registro, bd);
	actividades.TotalDeCampos = atoi(Registro);
	//printf("------------[ ACTIVIDADES ]\n");
	printf("################################################ \n");
	//printf("%i > Total de registros analizar \n", actividades.TotalDeCampos);
	
	
	if( xAct == 0 ){
		for(int itemF = 0; itemF < actividades.TotalDeCampos; itemF++ ){
			GETREGISTRO(Registro, bd);
			//printf("%s \n", Registro);
			GETREGISTRO(Registro, bd);
			printf("%s \n", Registro);
			GETREGISTRO(Registro, bd);
			printf("%s \n", Registro);
			GETREGISTRO(Registro, bd);
			printf("%s \n", Registro);
			GETREGISTRO(Registro, bd);
			printf("%s \n", Registro);
			printf("################################################ \n");
		}
	}else{
		for(int itemF = 0; itemF < actividades.TotalDeCampos; itemF++ ){
			for(int itemRg=0; itemRg < NOFILAS_DBACT; itemRg++){		
				GETREGISTRO(Registro, bd);
				if( atoi(Registro) != xAct ){
					GETREGISTRO(Registro, bd);
					GETREGISTRO(Registro, bd);
					GETREGISTRO(Registro, bd);
						GETREGISTRO(Registro, bd);
					continue;
				}		
				//printf("%s \n", Registro);
				GETREGISTRO(Registro, bd);
				printf("%s \n", Registro);
				GETREGISTRO(Registro, bd);
				printf("%s \n", Registro);
				GETREGISTRO(Registro, bd);
				printf("%s \n", Registro);
				GETREGISTRO(Registro, bd);
				printf("%s \n", Registro);
				printf("################################################ \n");
				Coincidencias++;
			}
		}
		printf("Coincidencias encontradas: %i \n", Coincidencias);	
	}
	
	fclose(bd);
	
}