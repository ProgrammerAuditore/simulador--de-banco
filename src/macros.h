// Macros
#define MAXCARACTERES 250
#define PARTITURAS ";"
#define BORRARSTR "\0"
#define BORRARNUM -1
#define NOFILAS_DBACT 5
#define NOFILAS_DBUSER 4
#define NOFILAS_BDUSUARIOS 2

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

#define CHECKEO(a) \
		strtok(a, "\n"); \
		if( ((int)strlen(a) - 1) == 0 ){ \
			printf("Campo rechazado.\n"); \
			CAMPOS_INCORRECTAS++; \
		}else{  \
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
		CHECKEO(DATO) \
		if( CAMPOS_INCORRECTAS == 0 ){ \
			snprintf(DATO_DESTINO, TAMANHOSTR, "%s" , DATO); \
		}
