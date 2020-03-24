bool fncBD_VerificarCuenta(String xCuenta){
    
    FILE *bd = fopen(ArchivoBaseDeDatos[0],"r");
    String Registro;
    bool SiExiste = false;

    if( bd == NULL){
        perror("Lo siento, BASE DE DATOS de datos de registro no establecida. :).\n");
        exit(1);
    }

    GETREGISTRO(Registro, bd);
    bdusuarios.TotalDeCampos = atoi(Registro);
    
    for(int bdTotal = 1; bdTotal <= bdusuarios.TotalDeCampos; bdTotal++){
        for(int itemRg=0; itemRg < 2; itemRg++){
			
			GETREGISTRO(Registro, bd);
            //printf(">>>>  %i>(%i>[%s]) \n", bdTotal, itemRg, Registro);
            
			if(fnc_CompararString(xCuenta, Registro) == 1){
                // La cuenta si existe
                bdusuarios.bdUsuarioID = bdTotal;
                SiExiste = true;
				//printf("------------------- \n");
				//printf("<< La cuenta si existe: %i >> \n", bdusuarios.bdUsuarioID);
				//printf("No. Tarjeta: %s \n", Registro);
				strcpy(bdusuarios.NoTarjeta, Registro);
				
				GETREGISTRO(Registro, bd);
				//printf("No. Cuenta: %s \n", Registro);
				//printf("------------------- \n");
				strcpy(bdusuarios.NoCuenta, Registro);
            }
        }
		if(SiExiste) break;
    }

    fclose(bd);
    return (SiExiste);

}
