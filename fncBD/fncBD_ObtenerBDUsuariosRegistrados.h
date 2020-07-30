void fncBD_ObtenerBDUsuariosRegistrados(){

    FILE *bd = fopen(ArchivoBaseDeDatos[0],"r");
    String Registro;
	int bdTotal = 0;

    if( bd == NULL){
        perror("fncBD_ObtenerBDUsuariosRegistrados: \n");
        perror("Lo siento, BASE DE DATOS de << registros de cuentas >>  no establecida. :'( \n");
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