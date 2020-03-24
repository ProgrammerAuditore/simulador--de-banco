void fncBD_ObtenerDatosBanco(){
    
    FILE *bd = fopen( bdusuarios.PATHBanco ,"r");
	FILE *bdact = fopen( bdusuarios.PATHActividades , "r");

    String Registro;

    if(bd == NULL || bdact == NULL){
        perror("Lo siento, BASE DE DATOS de datos de banco no establecida. :).\n");
        exit(1);
    }
	
	// Banco
    GETREGISTRO(Registro, bd);
    strcpy(banco.NoTarjeta,Registro); 

    GETREGISTRO(Registro, bd);
    strcpy(banco.NoCuenta,Registro); 

    GETREGISTRO(Registro, bd);
    banco.PIN = atoi(Registro);

    GETREGISTRO(Registro, bd);
    banco.EstadoDeCuenta = atoi(Registro);

    GETREGISTRO(Registro, bd);
    banco.Saldo = atof(Registro);
	
	// Actividades
	GETREGISTRO(Registro, bdact);
	actividades.TotalDeCampos = atoi(Registro);

    fclose(bd);
	fclose(bdact);
	
}