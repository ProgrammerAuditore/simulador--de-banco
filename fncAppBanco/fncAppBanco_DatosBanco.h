void fncAppBanco_DatosBanco(){
    
	CLEAN;
	printf("%s", TitulosAppBanco[4]);

	printf("Numero de tarjeta: %s\n", banco.NoTarjeta);
	printf("Numero de cuenta: %s\n", banco.NoCuenta);
	printf("PIN: ***** \n");
	printf("Saldo: %.2lf \n", banco.Saldo);
	printf("Total de operaciones: %i \n", actividades.TotalDeCampos);
	
	if( banco.EstadoDeCuenta == 1 )
		printf("Estado de cuenta: Activo \n");
	if( banco.EstadoDeCuenta == 0 )
		printf("Estado de cuenta: Bloqueado \n");

	BUFFERFREE;	

}