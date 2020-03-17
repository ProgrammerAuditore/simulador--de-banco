void fncBD_ObtenerDatosCuenta(){
    
    FILE *bd = fopen( bdusuarios.PATHUsuario ,"r");
    char Registro[250];

    if(bd == NULL){
        perror("Lo siento, BASE DE DATOS de datos de actividades no establecida. :).\n");
        exit(1);
    }

    // GETREGISTRO(Registro, bd);
    // user.TotalDeCampos = atoi(Registro);

    GETREGISTRO(Registro, bd);
    strcpy(user.Nombres,Registro); 

    GETREGISTRO(Registro, bd);
    strcpy(user.ApellidoPaterno,Registro);

    GETREGISTRO(Registro, bd);
    strcpy(user.ApellidoMaterno,Registro);

    GETREGISTRO(Registro, bd);
    strcpy(user.FechaNacimiento, Registro);

    fclose(bd);
}