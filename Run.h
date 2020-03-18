// Archivos de Cabecera C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#ifdef __WIN32
    #include <io.h>
#elif __linux__
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

// Archivos de Cabecera  - SRC
#include "enviroment.h"
#include "macros.h"
#include "fnc_CompararString.h"
#include "fnc_FechaCorrecto.h"