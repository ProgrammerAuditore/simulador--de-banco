int CAMPOS_INCORRECTAS = 0;
typedef char String[250];
char ArchivoBaseDeDatos[1][250] = {"./BD/._bd_usuarios_registrados"};
char FolderBD[1][250] = {"./BD/"};
char FileBD[4][250] = {"._act_","._banco_","._user_","._tmp_"};

struct BANCO
{
    int TotalDeCampos;
	String NoTarjeta;
    String NoCuenta;
    int PIN;
    bool EstadoDeCuenta;
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
    String PATHUsuario;
    String PATHBanco;
    int bdUsuarioID;
}bdusuarios;

// TIPOS DE ACTIVIDADES
// 100 - Cuenta creado
// 200 - Deposito
// 301 - Transferencia enviado
// 302 - Transferencia recibido
// 400 - Retiro de deposito
// 700 - Compra