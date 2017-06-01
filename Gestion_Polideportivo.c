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

void instalacion_altas(){
	long N,desplazamiento;
	int i;

	puntero_a_archivo=fopen(FICHERO3,"r+b");
	fseek(puntero_a_archivo,0L,0);
	fread(&registro0_instalacion,sizeof(registro0_instalacion),1,puntero_a_archivo);
	N=registro0_instalacion.num_registros;

	do{
		N++;
		clrscr();
		fflush(stdin);
		printf("\nNumero de registro: ");
		printf("%ld \n",N);
		printf("\nCodigo de la pista: ");
		gets(registro_instalacion.cod_pista);
		fflush(stdin);
		printf("\nNombre de la pista: ");
		gets(registro_instalacion.nombre_pista);
		printf("\nDescripcion: ");
		gets(registro_instalacion.descripcion);
		printf("\nEstado: ");
		gets(registro_instalacion.estado);
		fflush(stdin);

		desplazamiento=N*sizeof(registro_instalacion);
		fseek(puntero_a_archivo,desplazamiento,0);
		fwrite(&registro_instalacion, sizeof(registro_instalacion),1,puntero_a_archivo);
		printf("\n¿Introducir mas pistas? (s/n): ");
	}while(getchar()=='s');

	desplazamiento=0L*sizeof(registro0_instalacion);
	fseek(puntero_a_archivo,desplazamiento,0);
	registro0_instalacion.num_registros=N;

	for(i=0;i<sizeof(tipo_pista)-4;i++)
		registro0_instalacion.blancos[i]=' ';
	fwrite(&registro0_instalacion,sizeof(registro0_instalacion),1,puntero_a_archivo);
	fclose(puntero_a_archivo);
	instalacion_ordenacion();
}

void instalacion_listados(){
	long N,desplazamiento;
	int i;

	clrscr();
	puntero_a_archivo=fopen(FICHERO3,"r+b");
	fseek(puntero_a_archivo,0L,0);
	fread(&registro0_instalacion,sizeof(registro0_instalacion),1,puntero_a_archivo);
	N=registro0_instalacion.num_registros;

	for(i=1;i<=N;i++){
		desplazamiento=i*sizeof(registro_instalacion);
		fseek(puntero_a_archivo,desplazamiento,0);
		fread(&registro_instalacion,sizeof(registro_instalacion),1,puntero_a_archivo);

		printf("Numero de registro: %d",i);
		printf("\nCodigo de la pista: %s",registro_instalacion.cod_pista);
		printf("\nNombre de la pista: %s",registro_instalacion.nombre_pista);
		printf("\nDescripcion: %s",registro_instalacion.descripcion);
		printf("\nEstado: %s\n\n",registro_instalacion.estado);
		getch();
	}
	fclose(puntero_a_archivo);
	getch();
}

void instalacion_consultas(){
	long N,desplazamiento,numreg,cen,der,izq;
	char buscar[6];
	int busq=1,sw;

	puntero_a_archivo=fopen(FICHERO3,"r+b");
	fseek(puntero_a_archivo,0L,0);
	fread(&registro0_instalacion, sizeof(registro0_instalacion),1,puntero_a_archivo);
	N=registro0_instalacion.num_registros;

	puntero_a_archivo=fopen(FICHERO3,"rb");
	while(busq!=0){
		clrscr();
		printf("Busqueda");
		printf("\n1.- Nº Registro");
		printf("\n2.- Codigo de la pista");
		printf("\n0.- Volver");
		printf("\nOpcion: ");
		scanf("%d",&busq);
		fflush(stdin);
		switch(busq){
			case 1 : {
				clrscr();
				printf("Nº de Registro a buscar: ('Fin'=Salir)");
				scanf("%ld",&numreg);
				fflush(stdin);
				if(numreg<=N && numreg>0){
					clrscr();
					desplazamiento=numreg*sizeof(registro_instalacion);
					fseek(puntero_a_archivo,desplazamiento,0);
					fread(&registro_instalacion,sizeof(registro_instalacion),1,puntero_a_archivo);
					printf("Numero de registro: %ld",numreg);
					printf("\nCodigo de la pista: %s",registro_instalacion.cod_pista);
					printf("\nNombre de la pista: %s",registro_instalacion.nombre_pista);
					printf("\nDescripcion: %s",registro_instalacion.descripcion);
					printf("\nEstado: %s",registro_instalacion.estado);
				} else
					printf("Nº de Registro no encontrado");
				getch();
			}	break;
			case 2 : {
				do{
					clrscr();
					printf("Codigo de pista a buscar: ('Fin'=Salir) ");
					gets(buscar);
					fflush(stdin);
					clrscr();

					if(strncmp(buscar,"Fin",strlen(buscar))!=0){
						sw=0;
						izq=1;
						der=N;
						do{
							cen=(izq+der)/2;
							desplazamiento=cen*sizeof(registro_instalacion);
							fseek(puntero_a_archivo,desplazamiento,0);
							fread(&registro_instalacion,sizeof(registro_instalacion),1,puntero_a_archivo);

							if(strncmp(buscar,registro_instalacion.cod_pista,strlen(buscar))==0 || izq>=der){
								sw=1;
								if(strncmp(buscar,registro_instalacion.cod_pista,strlen(buscar))==0){
									printf("\nCodigo de la pista: %s",registro_instalacion.cod_pista);
									printf("\nNombre de la pista: %s",registro_instalacion.nombre_pista);
									printf("\nDescripcion: %s",registro_instalacion.descripcion);
									printf("\nEstado: %s",registro_instalacion.estado);
								}
								else
									printf("Codigo de pista no encontrada");
								getch();
							} else {
								if(strncmp(buscar,registro_instalacion.nombre_pista,strlen(buscar))<0)
									der=cen-1;
								else
									izq=cen+1;
								//cen=(izq+der)/2;             
							}
						}while(!sw);
					}
				}while(strncmp(buscar,"Fin",strlen(buscar))!=0);
			} 	break;
			case 0 : 	break;
			default: 	
				printf("\nElige entre 0 - 2");
				getch();
		}
	}
	fclose(puntero_a_archivo);
}

void instalacion_modificaciones(){
	long N,desplazamiento;
	char nombre[6],eleccion;
	int seleccion=1,sw,sw2,i;

	puntero_a_archivo=fopen(FICHERO3,"r+b");
	fseek(puntero_a_archivo,0L,0);
	fread(&registro0_instalacion, sizeof(registro0_instalacion),1,puntero_a_archivo);
	N=registro0_instalacion.num_registros;

	do{
		sw2=1;clrscr();
		printf("Codigo de pista a modificar (Salir='Fin'): ");
		gets(nombre);
		fflush(stdin);
		if(strncmp(nombre,"Fin",strlen(nombre))!=0){
			sw=0;
			for(i=1;i<=N;i++){
				desplazamiento=i*sizeof(registro_instalacion);
				fseek(puntero_a_archivo,desplazamiento,0);
				fread(&registro_instalacion, sizeof(registro_instalacion),1,puntero_a_archivo);
				if(strncmp(nombre,registro_instalacion.cod_pista,strlen(nombre))==0){
					sw=1;
					clrscr();
					printf("Numero de registro: %d",i);
					printf("\nCodigo de la pista: %s",registro_instalacion.cod_pista);
					printf("\nNombre de la pista: %s",registro_instalacion.nombre_pista);
					printf("\nDescripcion: %s",registro_instalacion.descripcion);
					printf("\nEstado: %s",registro_instalacion.estado);

					printf("\n\n¿Modificar el Registro? (s/n): ");
					scanf("%c",&eleccion);
					fflush(stdin);
					if(eleccion=='s'){
						do{
							clrscr();
							printf("Numero de registro: %d",i);
							printf("\nCodigo de la pista: %s",registro_instalacion.cod_pista);
							printf("\nNombre de la pista: %s",registro_instalacion.nombre_pista);
							printf("\nDescripcion: %s",registro_instalacion.descripcion);
							printf("\nEstado: %s",registro_instalacion.estado);

							printf("\n\n1.- Modificar nombre de la pista\n");
							printf("2.- Modificar descripcion\n");
							printf("3.- Modificar estado\n");;
							printf("0.- Volver\n\n");
							printf("Opcion: ");
							scanf("%d",&seleccion);
							fflush(stdin);
							switch(seleccion){
								case 1 : {
									fflush(stdin);
									printf("\nInserte nuevo nombre de la pista: ");
									gets(registro_instalacion.nombre_pista);
								}	break;
								case 2 : {
									fflush(stdin);
									printf("\nInserte nueva descripcion: ");
									gets(registro_instalacion.descripcion);
								}	break;
								case 3 : {
									fflush(stdin);
									printf("\nInserte nuevo estado: ");
									gets(registro_instalacion.estado);
								}	break;
								case 0 : {
									desplazamiento=i*sizeof(registro_instalacion);
									fseek(puntero_a_archivo,desplazamiento,0);
									fwrite(&registro_instalacion,sizeof(registro_instalacion),1,puntero_a_archivo);
									printf("\nRegistro Modificado correctamente");
									getch();
								}	break;
								default: 	
									printf("\nElige entre 0 y 3");
									getch();
							}
						}while(seleccion!=0);
					}
				}
			}
		} else
			sw2=0;
		if(!sw){
			printf("Codigo de pista no encontrado");
			getch();
		}
	}while(sw2);
	fclose(puntero_a_archivo);
}

void instalacion_bajas(){
	long N,N2,desplazamiento;
	char cod[6],eleccion;
	int sw,sw2,i,j;

	puntero_a_archivo=fopen(FICHERO3,"r+b");
	fseek(puntero_a_archivo,0L,0);
	fread(&registro0_instalacion, sizeof(registro0_instalacion),1,puntero_a_archivo);
	N=registro0_instalacion.num_registros;

	do{
		sw2=1;
		clrscr();
		puntero_a_archivo=fopen(FICHERO3,"r+b");
		printf("Codigo de pista a eliminar (Salir='Fin'): ");
		gets(cod);
		fflush(stdin);
		if(strncmp(cod,"Fin",strlen(cod))!=0){
			sw=0;
			for(i=1;i<=N;i++){
				desplazamiento=i*sizeof(registro_instalacion);
				fseek(puntero_a_archivo,desplazamiento,0);
				fread(&registro_instalacion, sizeof(registro_instalacion),1,puntero_a_archivo);
				if(strncmp(cod,registro_instalacion.cod_pista,strlen(cod))==0){
					sw=1;
					clrscr();
					printf("\nCodigo de la pista: %s",registro_instalacion.cod_pista);
					printf("\nNombre de la pista: %s",registro_instalacion.nombre_pista);
					printf("\nDescripcion: %s",registro_instalacion.descripcion);
					printf("\nEstado: %s",registro_instalacion.estado);

					printf("\n\n¿Eliminar el registro? (s/n): ");
					scanf("%c",&eleccion);
					fflush(stdin);
					if(eleccion=='s'){
						sw=3;
						puntero_a_archivo2=fopen(FICHERO1,"rb");
						fseek(puntero_a_archivo2,0L,0);
						fread(&registro0_reserva,sizeof(registro0_reserva),1,puntero_a_archivo2);
						N2=registro0_reserva.num_registros;

						for(j=1;j<=N2;j++){
							desplazamiento=j*sizeof(registro_reserva);
							fseek(puntero_a_archivo2,desplazamiento,0);
							fread(&registro_reserva,sizeof(registro_reserva),1,puntero_a_archivo2);

							if(strcmp(registro_reserva.cod_pista,cod)==0){
								sw=2;
								printf("\nNo se puede eliminar una pista con reserva");
								printf("\n\n¿Desea eliminar reservas? (s/n) ");
								scanf("%c",&eleccion);fflush(stdin);
								if(eleccion=='s')
									reserva_bajas();
								break;
							}
						}	
						fclose(puntero_a_archivo2);
                  
						if(sw==2)
							break;

						if(sw==3){
							desplazamiento=N*sizeof(registro_instalacion);
							fseek(puntero_a_archivo,desplazamiento,0);
							fread(&registro_instalacion, sizeof(registro_instalacion),1,puntero_a_archivo);

							desplazamiento=i*sizeof(registro_instalacion);
							fseek(puntero_a_archivo,desplazamiento,0);
							fwrite(&registro_instalacion, sizeof(registro_instalacion),1,puntero_a_archivo);

							N--;

							fseek(puntero_a_archivo,0L,0);
							registro0_instalacion.num_registros=N;
							for(i=0;i<sizeof(tipo_pista)-4;i++)
								registro0_instalacion.blancos[i]=' ';
							fwrite(&registro0_instalacion,sizeof(registro0_instalacion),1,puntero_a_archivo);
							fclose(puntero_a_archivo);

							printf("\nRegistro eliminado");
							instalacion_ordenacion();
							getch();
							break;
						}		
					}
				}
			}
		} else
			sw2=0;
		if(!sw){
			printf("Codigo de pista no encontrado");
			getch();
		}
	}while(sw2);
	fclose(puntero_a_archivo);
}

void instalacion_ordenacion(){
	tipo_pista registro2;
	long N,desplazamiento,i,j;
	int sw;

	puntero_a_archivo=fopen(FICHERO3,"r+b");
	fseek(puntero_a_archivo,0L,0);
	fread(&registro0_instalacion,sizeof(registro0_instalacion),1,puntero_a_archivo);
	N=registro0_instalacion.num_registros;

	for(i=1;i<=N-1;i++){
		sw=0;
		for(j=1;j<=N-i;j++)   {
			desplazamiento=j*sizeof(registro_instalacion);
			fseek(puntero_a_archivo,desplazamiento,0);
			fread(&registro_instalacion,sizeof(registro_instalacion),1,puntero_a_archivo);

			desplazamiento=(j+1)*sizeof(registro2);
			fseek(puntero_a_archivo,desplazamiento,0);
			fread(&registro2,sizeof(registro2),1,puntero_a_archivo);       

			if(strcmp(registro2.cod_pista,registro_instalacion.nombre_pista)<0){
				desplazamiento=j*sizeof(registro2);
				fseek(puntero_a_archivo,desplazamiento,0);
				fwrite(&registro2,sizeof(registro2),1,puntero_a_archivo);

				desplazamiento=(j+1)*sizeof(registro_instalacion);
				fseek(puntero_a_archivo,desplazamiento,0);
				fwrite(&registro_instalacion,sizeof(registro_instalacion),1,puntero_a_archivo);
				sw=1;
			}
		}
		if(sw==0)
			break;
	}
	fclose(puntero_a_archivo);
}

/////////////-----------------CLIENTE-----------------/////////////

void cliente_menu(){
	int seleccion=1;

	while(seleccion!=0){
		clrscr();
		printf("Menu Clientes\n");
		printf("1.- Añadir cliente\n");
		printf("2.- Ver todos los clientes\n");
		printf("3.- Buscar cliente\n");
		printf("4.- Modificar cliente\n");
		printf("5.- Borrar cliente\n");
		printf("0.- Volver\n\n");
		printf("Opcion: ");
		scanf("%d",&seleccion);
		fflush(stdin);
		switch(seleccion){
			case 1 : cliente_altas();		  								break;
			case 2 : cliente_listados();     								break;
			case 3 : cliente_consultas();     								break;
			case 4 : cliente_modificaciones();								break;
			case 5 : cliente_bajas();     									break;
			case 0 : 					   					     			break;
			default: printf("\nElige entre 0 y 5");
			getch();
		}
	}
}
