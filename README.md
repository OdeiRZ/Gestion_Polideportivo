# Gestión Polideportivo

Aplicación de consola en C para gestionar un polideportivo: instalaciones deportivas, clientes, reservas y facturas, con persistencia en ficheros binarios.

## Características

- Menú principal con acceso a cuatro módulos independientes: Instalaciones, Clientes, Reservas y Facturas.
- Alta, listado, consulta, modificación y baja de registros en cada módulo (CRUD completo).
- Persistencia en ficheros binarios (`Instalacion.dat`, `Clientes.dat`, `Reservas.dat`, `Facturas.dat`) usando `fread`/`fwrite` con acceso directo por posición (`fseek`).
- Búsqueda de registros por número o por código mediante búsqueda binaria sobre los ficheros ordenados.
- Ordenación de registros (burbuja) tras cada alta o baja para mantener los ficheros ordenados por código.
- Integridad referencial básica entre módulos: no permite borrar una instalación o un cliente si tiene reservas asociadas, y ofrece crear una factura al confirmar una reserva.
- Cada fichero incluye un registro de cabecera (registro "0") que almacena el número total de registros.

## Tecnologías

- C (estándar, con `conio.h` para entrada/salida de consola en Windows/DOS)

## Instalación / Cómo ejecutarlo

Requiere un compilador de C compatible con `conio.h` (por ejemplo Turbo C, Dev-C++, o MinGW con una librería `conio` compatible en Windows):

```
gcc Gestion_Polideportivo.c -o Gestion_Polideportivo -lconio
./Gestion_Polideportivo
```

Al ejecutarse por primera vez, el programa crea automáticamente los cuatro ficheros de datos si no existen.

Ejercicio académico que practica el manejo de ficheros binarios con registros de longitud fija en C, incluyendo búsqueda binaria y ordenación sobre disco.

## Seguridad

Sustituidas todas las llamadas a `gets()` (sin comprobación de límites, vulnerable a desbordamiento de buffer) por una función `leer_linea()` basada en `fgets()` acotada al tamaño del buffer de destino.

## Licencia

GPL versión 3 (ver archivo [LICENSE](LICENSE)).
