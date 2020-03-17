void fncBD_ObtenerRegistroDB(){

    FILE *bd = fopen(ArchivoBaseDeDatos[0],"r");
    char Registro[250];
	int bdTotal = 0;

    if( bd == NULL){
        perror("Lo siento, BASE DE DATOS de datos de registro no establecida. :).\n");
        exit(1);
    }

	GETREGISTRO(Registro, bd);
    bdusuarios.TotalDeCampos = atoi(Registro);

    for(bdTotal = 1; bdTotal <= bdusuarios.TotalDeCampos; bdTotal++){
        if(bdTotal == bdusuarios.bdUsuarioID){
			
            //printf("");
            // Obtenr No. de Tarjeta
            GETREGISTRO(Registro, bd);
            printf("%s \n", Registro);
            strcpy(bdusuarios.NoTarjeta, Registro);

            // Obtenr No. de Cuenta
            GETREGISTRO(Registro, bd);
            printf("%s \n", Registro);
            strcpy(bdusuarios.NoCuenta, Registro);
            
            break;
        }else{
            for(int itemRg=0; itemRg < (bdTotal * NOFILAS_BDUSUARIOS); itemRg++){
                GETREGISTRO(Registro, bd);
            }
        }
    }

    fclose(bd);

}