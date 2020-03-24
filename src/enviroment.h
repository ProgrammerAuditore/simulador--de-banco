int CAMPOS_INCORRECTAS = 0;
typedef char String[250];
char ArchivoBaseDeDatos[1][250] = {"./BD/._bd_usuarios_registrados"};
char FolderBD[1][250] = {"./BD/"};
char FilesBD[4][250] = {"._act_","._banco_","._user_","._tmp_"};
String _banner_;

// ESTADOS DE CUENTA
// -2 - Cuenta bloqueada
// -1 - Cuenta desactivada
//  0 - Cuenta creado / nueva
//  1 - Cuenta activada
//  2 - Cuenta recuperado

enum EstadosDeCuenta { 
    ecCuentaBloqueada = -2,
    ecCuentaDesactivada,
    ecCuentaCreadaONueva,
    ecCuentaActivada,
    ecCuentaRecuperado,
};

// TIPOS DE ACTIVIDADES
// 100 - Cuenta creado
// 200 - Deposito
// 301 - Transferencia enviado
// 302 - Transferencia recibido
// 400 - Retiro de deposito
// 700 - Compra
// 1000 - Notificacion del banco

enum TiposDeActiviades { 
    taDeposito = 200,
    taTransferenciaEnviado = 301,
    taTransferenciaRecibido = 302,
    taRetiro = 400,
    taCompra = 700,
    taConfiguracionCuenta = 1000,
    taNotificacionBanco = 5500
};

struct BANCO
{
    int TotalDeCampos;
	String NoTarjeta;
    String NoCuenta;
    int PIN;
    int EstadoDeCuenta;
	double Saldo;
}banco;


struct USER
{
    int TotalDeCampos;
    String Nombres;
    String ApellidoPaterno;
    String ApellidoMaterno;
    String FechaNacimiento;
}user;

struct ACTIVIDADES
{
    int TotalDeCampos;
    int TipoDeActividad;
    String Fecha;
    String Remitente;
    String Asunto;
    String Descripcion;
}actividades;

struct BDUSUARIOS
{
    int TotalDeCampos;
    String NoCuenta;
    String NoTarjeta;
    String PATHActividades;
    String PATHUser;
    String PATHBanco;
    int bdUsuarioID;
}bdusuarios;
