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
