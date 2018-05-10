#define OCUPADO 0
#define LIBRE 1

#define TamU 5
#define TamP 10

typedef struct
{
    char nombre[50];
    int idUsuario;
    int edad;
    int calificacion;

    int estado;

}eUsuario;

typedef struct
{
    int idProducto;
    int idUsuario;
    int stock;
    float precio;
    char nombre[50];

    int estado;

}eProducto;


void hardcodearUsuarios(eUsuario[],int);
void hardcodearProductos(eProducto[],int);

void mostrarUsuarios(eUsuario[],int);
void mostrarProductos(eProducto[],int);
void mostrarProductosxUsuario(eUsuario[],int,eProducto[],int);

void eUsuario_mostrarUno(eUsuario);
int comprarProducto(eProducto[],int,eUsuario[],int);

int eUsuario_init(eUsuario[],int);
int eProducto_init(eProducto[],int);

int eUsuario_alta(eUsuario[],int);
int eUsuario_modificacion(eUsuario[],int);
int eUsuario_baja(eUsuario[] ,int);

int eProducto_alta(eProducto[],int,eUsuario[],int);
int eProducto_modificacion(eProducto[],int,eUsuario[],int);

int eUsuario_buscarLugarLibre(eUsuario[],int);
int eUsuario_siguienteId(eUsuario[] ,int);

int eProducto_buscarLugarLibre(eProducto[],int);
int eProducto_siguienteId(eProducto[],int);
