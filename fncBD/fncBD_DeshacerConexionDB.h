void fncBD_DeshacerConexionDB(){
	
	// Borrar datos user
	strcpy(user.Nombres, BORRARSTR);
	strcpy(user.ApellidoPaterno, BORRARSTR);
	strcpy(user.ApellidoMaterno, BORRARSTR);
	strcpy(user.FechaNacimiento, BORRARSTR);
	
	
	// Borrar datos actividades
	actividades.TipoDeActividad = BORRARNUM;
	strcpy(actividades.Fecha, BORRARSTR);
	strcpy(actividades.Remitente, BORRARSTR);
	strcpy(actividades.Asunto, BORRARSTR);
	strcpy(actividades.Descripcion, BORRARSTR);
	
	// Borrar datos bancos
	strcpy(banco.NoCuenta, BORRARSTR);
	strcpy(banco.NoTarjeta, BORRARSTR);
	banco.PIN = BORRARNUM;
	banco.EstadoDeCuenta = BORRARNUM;
	banco.Saldo = BORRARNUM;
	
	// Borrar datos BDusuarios
	strcpy(bdusuarios.NoCuenta, BORRARSTR);
	strcpy(bdusuarios.NoTarjeta, BORRARSTR);
	strcpy(bdusuarios.PATHActividades, BORRARSTR);
	strcpy(bdusuarios.PATHUser, BORRARSTR);
	strcpy(bdusuarios.PATHBanco, BORRARSTR);
	bdusuarios.bdUsuarioID = BORRARNUM;
	
}