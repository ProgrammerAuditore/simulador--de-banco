void fncBanco_ConfigurarCuenta(){
    
    CLEAN;
	printf("%s", TitulosBanco[13]);
    int opcion;

	printf("#1 > Activar cuenta  \n");
	printf("#2 > Desactivar cuenta  \n");
	printf("#3 > Bloquear cuenta  \n");
	printf("#4 > Eliminar cuenta  \n");
    printf("#0 > Volver al menu principal  \n");
    printf("Selecciona una opcion: ");
    scanf("%i", &opcion);
    BUFFERFREE;

    switch (opcion)
    {
        case 0: break; break;
        case 1: fncBanco_ActivarCuenta(); break;
        case 2: fncBanco_DesactivarCuenta(); break;
        case 3: fncBanco_BloquearCuenta(); break;
        case 4: fncBanco_EliminarCuenta(); break;
        default:
        printf("Lo siento, opcion incorrecta. \n");
    }
    
    if( opcion != 0 )
	    BUFFERFREE;
}