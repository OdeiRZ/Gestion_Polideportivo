#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define FICHERO1 "Reservas.dat"
#define FICHERO2 "Clientes.dat"
#define FICHERO3 "Instalacion.dat"
#define FICHERO4 "Facturas.dat"

typedef struct {
	char cod_pista[6];
	char nombre_pista[30];
	char descripcion[50];
	char estado[20];
} tipo_pista;
  tipo_pista registro_instalacion;

typedef struct {
	long num_registros;
	char blancos[sizeof(tipo_pista)-4];
} primer_registro_instalacion;
  primer_registro_instalacion registro0_instalacion;

  
typedef struct {
	char dni[10];
	char nombre[10];
	char apellidos[20];
	char direccion[30];
	char telefono[10];
	char email[20];
	char federado[3];
} tipo_cliente;
  tipo_cliente registro_cliente;

typedef struct {
	long num_registros;
	char blancos[sizeof(tipo_cliente)-4];
} primer_registro_clientes;
  primer_registro_clientes registro0_clientes;

  
typedef struct {
	char cod_reserva[7];
	char dni[10];
	char cod_pista[6];
	char fecha[11];
	char hora[6];
} tipo_reserva;
  tipo_reserva registro_reserva;

typedef struct {
	long num_registros;
	char blancos[sizeof(tipo_reserva)-4];
} primer_registro_reservas;
  primer_registro_reservas registro0_reserva;

  
typedef struct {
	char cod_factura[7];
	char cod_reserva[7];
	char fechanow[19];
	char dni[10];
	char cod_pista[6];
	char fecha[11];
	char hora[6];
	float precio;
} tipo_factura;
  tipo_factura registro_factura;

typedef struct {
	long num_registros;
	char blancos[sizeof(tipo_factura)-4];
} primer_registro_factura;
  primer_registro_factura registro0_factura;

  
void factura_menu();
void factura_altas();
void factura_listados();
void factura_consultas();
void factura_modificaciones();
void factura_bajas();
void factura_ordenacion();
void obtener_fecha(char []);
void reserva_menu(void);
void reserva_altas(void);
void reserva_listados(void);
void reserva_consultas(void);
void reserva_modificaciones(void);
void reserva_bajas(void);
void instalacion_menu();
void instalacion_altas();
void instalacion_consultas();
void instalacion_listados();
void instalacion_modificaciones();
void instalacion_bajas();
void instalacion_ordenacion();
void cliente_menu();
void cliente_altas();
void cliente_consultas();
void cliente_listados();
void cliente_modificaciones();
void cliente_bajas();
void cliente_ordenacion();

FILE *puntero_a_archivo,*puntero_a_archivo2;
