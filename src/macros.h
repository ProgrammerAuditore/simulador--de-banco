// Macros
#define MAXCARACTERES 500
#define PARTITURAS ";"
#define BORRARSTR "\0"
#define BORRARNUM -1
#define NOFILAS_DBACT 5
#define NOFILAS_DBUSER 4
#define NOFILAS_BDUSUARIOS 2
#define ANHO_ACTUAL 2020
#define MENOR_EDAD_APROBADO 18
#define MAYOR_EDA_APROBADO 50

#ifdef __linux__
	#define CLEAN system("clear");
#elif __WIN32
	#define CLEAN system("cls");
#endif

#define BUFFERFREE if(getchar() != '\n') \
					while(getchar() != '\n');

#define OPTIONERROR \
	printf("Lo siento, opcion incorrecta."); \
	BUFFERFREE;	\

#define OPTION( Key, fnc ) \
	if(Key){ fnc(); }else{ OPTIONERROR; }

#define CHECKEO_INPUT(a) \
		strtok(a, "\n"); \
		if( ((int)strlen(a) - 1) == 0 ){ \
			printf("Campo rechazado.\n"); \
			CAMPOS_INCORRECTAS++; \
		}else{  \
			CAMPOS_INCORRECTAS = 0; \
			printf("Campo aceptado.\n"); \
		}

#define DESICION(VERDAD, FALSO) \
		if( CAMPOS_INCORRECTAS == 0){ \
			VERDAD; \
		}else{  \
			FALSO; \
		} \
		CAMPOS_INCORRECTAS=0;

#define GETREGISTRO(STR_DESTINO, BD) \
	fgets(STR_DESTINO, MAXCARACTERES, BD); \
    strtok(STR_DESTINO, PARTITURAS);

#define SEPARARSTR(STR_DESTINO, STR, DELIMITADOR) \
    sprintf(STR_DESTINO,"%s",STR); \
	strtok(STR_DESTINO,DELIMITADOR);

#define MODIFICAR_DATO(DATO_DESTINO, TAMANHOSTR , DATO) \
		CHECKEO_INPUT(DATO) \
		if( CAMPOS_INCORRECTAS == 0 ){ \
			snprintf(DATO_DESTINO, TAMANHOSTR, "%s" , DATO); \
		}

#define CHECKEO_PIN(PIN1) \
	( !(PIN1 >= 111111 && PIN1 <= 999999) ? true : false )

#define ELIMINAR_DIR( ComandoOS ,PathDir ) \
	String _dir; \
	snprintf(_dir, MAXCARACTERES * 2, "%s \"%s%s\"", ComandoOS , FolderBD[0], PathDir ); \
	system(_dir);

//  Mostrar mensaje de operacion - Solo texto
#define MOSTRAR_MSGOPERACION( Mensaje ) \
	sprintf( _banner_, "\n------------[ %s ]\n", Mensaje); \
	printf("%s", _banner_); \
	strcpy( _banner_ ,"\0");

// Mostrar mensaje de error de operacion - Solo texto
#define MOSTRAR_MSGO_ERROR( Mensaje ) \
	sprintf( _banner_, "\n*** %s \n", Mensaje); \
	printf("%s", _banner_); \
	strcpy( _banner_ ,"\0");
