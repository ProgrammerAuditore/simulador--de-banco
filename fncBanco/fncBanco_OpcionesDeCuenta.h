void fncBanco_OpcionesDeCuenta(){
   
    CLEAN;
	printf("%s", TitulosBanco[14]);
    int opcion;

	printf("#1 > Buscar cuenta  \n");
	printf("#2 > Modificar cuenta  \n");
	printf("#3 > Recuperar cuenta  \n");
	printf("#0 > Volver al menu principal  \n");
    printf("Selecciona una opcion: ");
    scanf("%i", &opcion);
    BUFFERFREE;

    switch (opcion)
    {
        case 0: break; break;
        case 1: fncBanco_BuscarCuenta(); break;
        case 2: fncBanco_ModificarCuenta(); break;
        case 3: fncBanco_RecuperarCuenta(); break;
        default:
        printf("Lo siento, opcion incorrecta. \n");
    }
    
    if( opcion != 0 )
	    BUFFERFREE;
}