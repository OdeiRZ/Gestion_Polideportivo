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

int main(){
	int seleccion=1;
	int i;

	puntero_a_archivo=fopen(FICHERO4,"rb");
	if(puntero_a_archivo==NULL){
		printf("El fichero Facturas.dat esta vacio o no existe");
		getch();
		clrscr();
		puntero_a_archivo=fopen(FICHERO4,"a+b");
		fseek(puntero_a_archivo,0L,0);
		registro0_factura.num_registros=0L;
		for(i=0;i<sizeof(tipo_factura)-4;i++)
			registro0_factura.blancos[i]=' ';
		fwrite(&registro0_factura,sizeof(registro0_factura),1,puntero_a_archivo);
	}
	fclose(puntero_a_archivo);

	puntero_a_archivo=fopen(FICHERO1,"rb");
	if(puntero_a_archivo==NULL){
		printf("El fichero Reservas.dat esta vacio o no existe");
		getch();
		clrscr();
		puntero_a_archivo=fopen(FICHERO1,"a+b");
		fseek(puntero_a_archivo,0L,0);
		registro0_reserva.num_registros=0L;
		for(i=0;i<sizeof(tipo_reserva)-4;i++)
			registro0_reserva.blancos[i]=' ';
		fwrite(&registro0_reserva,sizeof(registro0_reserva),1,puntero_a_archivo);
	}
	fclose(puntero_a_archivo);

	puntero_a_archivo=fopen(FICHERO2,"rb");
	if(puntero_a_archivo==NULL){
		printf("El fichero Clientes.dat esta vacio o no existe");
		getch();
		clrscr();
		puntero_a_archivo=fopen(FICHERO2,"a+b");
		fseek(puntero_a_archivo,0L,0);
		registro0_clientes.num_registros=0L;
		for(i=0;i<sizeof(tipo_cliente)-4;i++)
			registro0_clientes.blancos[i]=' ';
		fwrite(&registro0_clientes,sizeof(registro0_clientes),1,puntero_a_archivo);
	}
	fclose(puntero_a_archivo);

	puntero_a_archivo=fopen(FICHERO3,"rb");
	if(puntero_a_archivo==NULL){
		printf("El fichero Polideportivo esta vacio o no existe");
		getch();
		clrscr();
		puntero_a_archivo=fopen(FICHERO3,"a+b");
		fseek(puntero_a_archivo,0L,0);
		registro0_instalacion.num_registros=0L;
		for(i=0;i<sizeof(tipo_pista)-4;i++)
			registro0_instalacion.blancos[i]=' ';
		fwrite(&registro0_instalacion,sizeof(registro0_instalacion),1,puntero_a_archivo);
	}
	fclose(puntero_a_archivo);

	while(seleccion!=0){
		clrscr();
		printf("Menu Principal\n");
		printf("1.- Instalaciones deportivas\n");
		printf("2.- Clientes\n");
		printf("3.- Reservas\n");
		printf("4.- Facturas\n");
		printf("0.- Salir\n\n");
		printf("Opcion: ");
		scanf("%d",&seleccion);
		fflush(stdin);
		switch(seleccion){
			case 1 : instalacion_menu();		  								break;
			case 2 : cliente_menu();     										break;
			case 3 : reserva_menu();    			 							break;
			case 4 : factura_menu();											break;
			case 0 : printf("\nAdios");						 					break;
			default: printf("\nElige entre 0 y 4");
					 getch();
		}
	}
	return 0;
}

/////////////-----------------INSTALACION-----------------/////////////

void instalacion_menu(){
	int seleccion=1;
	
	while(seleccion!=0){
		clrscr();
		printf("Centro Polideportivo\n");
		printf("1.- Añadir Pista\n");
		printf("2.- Ver todas las pistas\n");
		printf("3.- Buscar pista\n");
		printf("4.- Modificar pista\n");
		printf("5.- Borrar pista\n");
		printf("0.- Volver\n\n");
		printf("Opcion: ");
		scanf("%d",&seleccion);
		fflush(stdin);
		switch(seleccion){
			case 1 : instalacion_altas();										break;
			case 2 : instalacion_listados();     								break;
			case 3 : instalacion_consultas();     								break;
			case 4 : instalacion_modificaciones();								break;
			case 5 : instalacion_bajas();     									break;
			case 0 :    					   									break;
			default: printf("\nElige entre 0 y 5");
					 getch();
		}
	}
}
