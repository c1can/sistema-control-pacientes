# Proyecto final de clase de Algoritmos

## Descripcion

En un hospital, es fundamental llevar un control eficiente de los pacientes para garantizar una atención
médica de calidad. El sistema debe permitir gestionar la información de los pacientes, facilitando el
ingreso, la modificación, la eliminación y la visualización de los datos. Además, debe ser posible
generar reportes y archivos de impresión para registros oficiales y análisis

### Objetivos del Proyecto
- Ingreso de Paciente
- Modificación de Datos del Paciente
- Eliminar Paciente
- Reporte General de Todos los Pacientes
- Generar Archivo de Impresión
- Salir del Sistema

## Integrantes

- Esli Carlos Emmanuel Reyes Can
- Zule
- Luis

## Documentacion

Para poder ejecutar el programa tenemos que tener instalado el compilador g++ de GNU
## Instalación

Actualizar los repositorios
```bash
sudo apt update
sudo apt upgrade

```
INSTALAR LIBHARU
-
Descargar las dependencias necesarias
```bash
 sudo apt install build-essential cmake
```
```bash
 sudo apt install libhpdf-dev
```


Clonar este repositorio

```bash
  git clone https:/c1can/github/sistemapacientes
  cd sistemapacientes
```
### Compilar el código
```bash
 g++ test.cpp -lhpdf -o test
```
```bash
 ./test
```

## Capturas de pantalla

A continuacion se muestran algunas capturas de pantalla de algunas de las funcionalidades del programa.

Menu Principal:
El menu Principal cuenta con 6 opciones de las cuales siempre se mostraran en bucle hasta que el usuario ingrese la tecla no. 6.

![Menu Principal](https://github.com/c1can/sistema-control-pacientes/blob/main/capturas/Captura%20de%20pantalla%202024-10-27%20004434.png)

Reporte general de los pacientes:
Se muestra un breve reporte general de los pacientes donde se itera sobre el vector original donde se almacenan todos los pacientes y se mostraran media vez su propiedad activo se encuentre un true de lo contrario aparecera una referencia al usuario eliminado con su DPI.

![Reporte general de los pacientes](https://github.com/c1can/sistema-control-pacientes/blob/main/capturas/Captura%20de%20pantalla%202024-10-27%20005640.png)


Descarga del reporte general de los pacientes:
Se descargara un archivo PDF con el formato presentado en la captura de la pantalla, solo se mostraran los pacientes que tengan la propiedad activo a true.

![Descargar reporte general de los pacientes](https://github.com/c1can/sistema-control-pacientes/blob/main/capturas/Captura%20de%20pantalla%202024-10-27%20005803.png)
