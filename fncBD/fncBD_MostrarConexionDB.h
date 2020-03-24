void fncBD_MostrarConexionDB(){
	
    MOSTRAR_MSGOPERACION("CONEXION");
    printf("No. de cuenta %s \n", bdusuarios.NoCuenta);
    printf("No. de tarjeta %s \n", bdusuarios.NoTarjeta);
    printf("PATH Actividades: %s \n", bdusuarios.PATHActividades);
    printf("PATH Banco: %s \n", bdusuarios.PATHBanco);
    printf("PATH Usuario: %s \n", bdusuarios.PATHUser);
    printf("Usuario ID: %i \n", bdusuarios.bdUsuarioID);

}
