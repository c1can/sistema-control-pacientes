#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <hpdf.h>


struct Paciente {
    std::string numeroIdentificacion;
    std::string nombreCompleto;
    int edad;
    std::string genero;
    std::string direccion;
    std::string numeroCelular;
    std::string fechaIngreso;
    std::string diagnostico;
    bool activo;
  };

void generarReportePacientesPDF(const std::vector<Paciente>& pacientes) {
    // Crear un nuevo documento PDF
    HPDF_Doc pdf = HPDF_New(NULL, NULL);
    if (!pdf) {
        std::cerr << "Error al crear el PDF." << std::endl;
        return;
    }

    // Crear una nueva página
    HPDF_Page page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    // Establecer la fuente y el tamaño
    HPDF_Font font = HPDF_GetFont(pdf, "Helvetica", NULL);
    HPDF_Page_SetFontAndSize(page, font, 12);

    // Escribir el encabezado
    HPDF_Page_BeginText(page);
    HPDF_Page_MoveTextPos(page, 50, 750); // Posicionar el texto en la página
    HPDF_Page_ShowText(page, "REPORTE GENERAL DE PACIENTES ACTIVOS");
    HPDF_Page_MoveTextPos(page, 0, -30); // Mover la posición del texto hacia abajo

    bool hayPacientesActivos = false;

    // Iterar sobre los pacientes y agregar solo los activos
    for (const Paciente& paciente : pacientes) {
        if (paciente.activo) {
            hayPacientesActivos = true;

            // Crear una lista de los datos del paciente, cada línea se agrega por separado
            std::vector<std::string> infoPaciente = {
                "DPI: " + paciente.numeroIdentificacion,
                "Nombre: " + paciente.nombreCompleto,
                "Edad: " + std::to_string(paciente.edad),
                "Genero: " + paciente.genero,
                "Direccion: " + paciente.direccion,
                "Celular: " + paciente.numeroCelular,
                "Fecha Ingreso: " + paciente.fechaIngreso,
                "Diagnostico: " + paciente.diagnostico
            };

            // Mostrar cada línea de información del paciente en el PDF
            for (const std::string& linea : infoPaciente) {
                HPDF_Page_ShowText(page, linea.c_str());
                HPDF_Page_MoveTextPos(page, 0, -20); // Mover hacia abajo para la siguiente línea
            }

            // Espacio entre pacientes
            HPDF_Page_MoveTextPos(page, 0, -20);
        }
    }

    if (!hayPacientesActivos) {
        HPDF_Page_ShowText(page, "No hay pacientes activos en este momento.");
    }

    HPDF_Page_EndText(page);

    // Guardar el archivo en disco
    HPDF_SaveToFile(pdf, "reporte_pacientes.pdf");

    // Limpiar memoria
    HPDF_Free(pdf);

    std::cout << "Reporte generado exitosamente: reporte_pacientes.pdf" << std::endl;
}

  //---funciones principales del sistema---

  void cargarPacientesDesdeBaseDeDatos(std::vector<Paciente>& pacientes) {
    std::ifstream archivo("pacientes.txt");
    if (archivo.is_open()) {
        Paciente paciente;
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.find("DPI: ") != std::string::npos) {
                paciente.numeroIdentificacion = linea.substr(5);
            } else if (linea.find("Nombre: ") != std::string::npos) {
                paciente.nombreCompleto = linea.substr(8);
            } else if (linea.find("Edad: ") != std::string::npos) {
                paciente.edad = std::stoi(linea.substr(6));
            } else if (linea.find("Género: ") != std::string::npos) {
                paciente.genero = linea.substr(8);
            } else if (linea.find("Dirección: ") != std::string::npos) {
                paciente.direccion = linea.substr(11);
            } else if (linea.find("Celular: ") != std::string::npos) {
                paciente.numeroCelular = linea.substr(9);
            } else if (linea.find("Fecha de Ingreso: ") != std::string::npos) {
                paciente.fechaIngreso = linea.substr(17);
            } else if (linea.find("Diagnóstico: ") != std::string::npos) {
                paciente.diagnostico = linea.substr(13);
            } else if (linea.find("Activo: ") != std::string::npos) {
                paciente.activo = (linea.substr(8) == "1");
            } else if (linea.find("-------------------------------") != std::string::npos) {
                pacientes.push_back(paciente);
            }
        }
        archivo.close();
    }
}

  void guardarPacienteEnArchivo(const Paciente& paciente) {
    std::ofstream archivo("pacientes.txt", std::ios::app); // Abre el archivo en modo append (adición)
    
    if (archivo.is_open()) {
        archivo << "DPI: " << paciente.numeroIdentificacion << "\n";
        archivo << "Nombre: " << paciente.nombreCompleto << "\n";
        archivo << "Edad: " << paciente.edad << "\n";
        archivo << "Género: " << paciente.genero << "\n";
        archivo << "Dirección: " << paciente.direccion << "\n";
        archivo << "Celular: " << paciente.numeroCelular << "\n";
        archivo << "Fecha de Ingreso: " << paciente.fechaIngreso << "\n";
        archivo << "Diagnóstico: " << paciente.diagnostico << "\n";
        archivo << "Activo: " << paciente.activo << "\n";
        archivo << "-------------------------------\n"; 
        archivo.close(); 
        std::cout << "Paciente guardado en el archivo con exito.\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar los pacientes.\n";
    }
}

  void agregarPaciente(std::vector<Paciente> & pacientes, std::string identificacion, std::string nombre, int edad, std::string genero, std::string direccion, std::string numero, std::string fecha, std::string diagnostico) {
      Paciente nuevoPaciente = {identificacion, nombre, edad, genero, direccion, numero, fecha, diagnostico, true};
      
    pacientes.push_back(nuevoPaciente);
    std::cout<<"Se ingreso un nuevo paciente: \n";

    guardarPacienteEnArchivo(nuevoPaciente);
  };


//---validacione menu principal---
int validarOpcion() {
    int opcion;
    while (true) {
        std::cin >> opcion;

        if (opcion < 1 || opcion > 6) {
            std::cout << "Ingrese una opcion valida (1-6): ";
        } else {
            break;
        }
    }
    return opcion;
}


//----validaciones opcion 1-----
  std::string validarIdentificacion() {
    std::string identificacion;
    while (true) {
        std::getline(std::cin, identificacion);

        // Limitar la longitud mínima y máxima del nombre
        if (identificacion.length() != 13) {
            std::cout << "Ingrese un numero de DPI valido (13 digitos): ";
        } else {
            break;
        }
    }
    return identificacion;
}

std::string validarNombre() {
    std::string nombre;
    while (true) {
        std::getline(std::cin, nombre);

        if (nombre.length() < 3 || nombre.length() > 50) {
            std::cout << "Ingrese un nombre valido (3-50 caracteres): ";
        } else {
            break;
        }
    }
    return nombre;
}

int validarEdad() {
    int edad;
    while (true) {
        std::cin >> edad;

        if (edad < 18 || edad > 120) {
            std::cout << "Ingrese una edad valida (18-120): ";
        } else {
            break;
        }
    }
    return edad;
}

std::string validarGenero() {
    std::string genero;
    while (true) {
        std::getline(std::cin, genero);

        if (genero.length() < 1 || genero.length() > 1) {
            std::cout << "Ingrese un genero valido (1 caracter): ";
        }else if( genero != "M" && genero != "F") {
            std::cout << "Ingrese un genero valido (M/F): ";
        }
         else {
            break;
        }
    }
    return genero;
}
std::string validarDireccion() {
    std::string direccion;
    while (true) {
        std::getline(std::cin, direccion);

        if (direccion.length() < 3 || direccion.length() > 100) {
            std::cout << "Ingrese una direccion valida (3-100 caracteres): ";
        } else {
            break;
        }
    }
    return direccion;
}
std::string validarNumero() {
    std::string numero;
    while (true) {
        std::getline(std::cin, numero);

        if (numero.length() < 8 || numero.length() > 8) {
            std::cout << "Ingrese un numero de celular valido (8 digitos): ";
        } else {
            break;
        }
    }
    return numero;
}
std::string validarFecha() {
    std::string fecha;
    while (true) {
        std::getline(std::cin, fecha);

        if (fecha.length() < 10 || fecha.length() > 10) {
            std::cout << "Ingrese una fecha valida (dd/mm/aaaa): ";
        } else {
            break;
        }
    }
    return fecha;
}
std::string validarDiagnostico() {
    std::string diagnostico;
    while (true) {
        std::getline(std::cin, diagnostico);

        if (diagnostico.length() < 3 || diagnostico.length() > 100) {
            std::cout << "Ingrese un diagnostico valido (3-100 caracteres): ";
        } else {
            break;
        }
    }
    return diagnostico;
}

//----fin validaciones opcion 1----- 


//funciones opcion 2
void guardarPacientesEnArchivo(const std::vector<Paciente>& pacientes) {
    std::ofstream archivo("pacientes.txt", std::ios::trunc); // Abre el archivo en modo truncar para sobrescribir
    if (archivo.is_open()) {
        for (const Paciente& paciente : pacientes) {
            archivo << "DPI: " << paciente.numeroIdentificacion << "\n";
            archivo << "Nombre: " << paciente.nombreCompleto << "\n";
            archivo << "Edad: " << paciente.edad << "\n";
            archivo << "Género: " << paciente.genero << "\n";
            archivo << "Dirección: " << paciente.direccion << "\n";
            archivo << "Celular: " << paciente.numeroCelular << "\n";
            archivo << "Fecha de Ingreso: " << paciente.fechaIngreso << "\n";
            archivo << "Diagnóstico: " << paciente.diagnostico << "\n";
            archivo << "Activo: " << paciente.activo << "\n";
            archivo << "-------------------------------\n";
        }
        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo para guardar los pacientes.\n";
    }
}

void modificarPaciente(std::vector<Paciente>& pacientes, const std::string& identificacion) {
    bool encontrado = false;
    for (Paciente& paciente : pacientes) {
        if (paciente.numeroIdentificacion == identificacion) {
            encontrado = true;

            // Modificar los datos del paciente
            std::cout << "Modificando paciente con DPI: " << identificacion << "\n";
            std::cout << "Ingrese el nuevo nombre completo: ";
            std::string nuevoNombre;
            nuevoNombre = validarNombre();
            paciente.nombreCompleto = nuevoNombre;

            std::cout << "Ingrese la nueva edad: ";
            int nuevaEdad;
            nuevaEdad = validarEdad();
            paciente.edad = nuevaEdad;

            std::cout << "Ingrese el nuevo genero: ";
            std::string nuevoGenero;
            nuevoGenero = validarGenero();
            paciente.genero = nuevoGenero;

            std::cout << "Ingrese la nueva direccion: ";
            std::string nuevaDireccion;
            nuevaDireccion = validarDireccion();
            paciente.direccion = nuevaDireccion;

            std::cout << "Ingrese el nuevo numero de celular: ";
            std::string nuevoNumero;
            nuevoNumero = validarNumero();
            paciente.numeroCelular = nuevoNumero;

            std::cout << "Ingrese la nueva fecha de ingreso: ";
            std::string nuevaFecha;
            nuevaFecha = validarFecha();
            paciente.fechaIngreso = nuevaFecha;

            std::cout << "Ingrese el nuevo diagnostico: ";
            std::string nuevoDiagnostico;
            nuevoDiagnostico = validarDiagnostico();
            paciente.diagnostico = nuevoDiagnostico;

            // Guardar los pacientes actualizados en el archivo
            guardarPacientesEnArchivo(pacientes);
            std::cout << "Paciente modificado con exito!.\n";
            break;
        }
    }

    if (!encontrado) {
        std::cout << "Paciente con DPI " << identificacion << " no encontrado.\n";
    }
}

//fin funciones opcion 2


//funciones opcion 3

void eliminarPaciente(std::vector<Paciente>& pacientes, const std::string& identificacion) {
    bool encontrado = false;
    for (Paciente& paciente : pacientes) {
        if (paciente.numeroIdentificacion == identificacion) {
            encontrado = true;
            paciente.activo = false;
            guardarPacientesEnArchivo(pacientes);
            std::cout << "Paciente eliminado con exito.\n";
            break;
        }
    }

    if (!encontrado) {
        std::cout << "Paciente con DPI " << identificacion << " no encontrado.\n";
    }
}

//fin funciones opcion 3

//funciones opcion 4
void desplegarReporteGeneral(const std::vector<Paciente>& pacientes) {
    std::cout << "----REPORTE GENERAL DE PACIENTES----\n";
    for (const Paciente& paciente : pacientes) {

        if(paciente.activo){
            std::cout << "DPI: " << paciente.numeroIdentificacion << "\n";
            std::cout << "Nombre: " << paciente.nombreCompleto << "\n";
            std::cout << "Edad: " << paciente.edad << "\n";
            std::cout << "Genero: " << paciente.genero << "\n";
            std::cout << "Direccion: " << paciente.direccion << "\n";
            std::cout << "Celular: " << paciente.numeroCelular << "\n";
            std::cout << "Fecha de Ingreso: " << paciente.fechaIngreso << "\n";
            std::cout << "Diagnostico: " << paciente.diagnostico << "\n";
            std::cout << "-------------------------------\n";
        }else {
            std::cout << "El paciente con DPI: " << paciente.numeroIdentificacion << " ha sido eliminado de la lista principal.\n";
            std::cout << "-------------------------------\n";
        }
    }
}


int main() {
  //estructura de datos original
  std::vector<Paciente> pacientes;
  //la idea de está funcion es que inicialize el vector pacientes con los datos que se encuentran en el archivo pacientes.txt
  cargarPacientesDesdeBaseDeDatos(pacientes);

  int opcion;

  do {
    std::cout<<"----MENU SISTEMA DE PACIENTES----\n";
    std::cout<<"1. Agregar paciente\n";
    std::cout<<"2. Editar paciente\n";
    std::cout<<"3. Eliminar un paciente\n";
    std::cout<<"4. Visualizar reporte general\n";
    std::cout<<"5. Descargar un reporte general de los pacientes\n";
    std::cout<<"6. Salir\n";
    std::cout<<"----FIN DEL MENU----\n";
    opcion = validarOpcion();
    std::cin.ignore();

    if(opcion == 1) {
      int edad;
      std::string dpi,nombre,numero, genero,direccion, fechaIngreso, diagnostico;
      
      std::cout<<"Ingrese su numero de identificacion (DPI): \n";
      dpi = validarIdentificacion();
      std::cout<<"Ingrese su nombre completo: \n";
      nombre = validarNombre();
      std::cout<<"Ingrese su edad: \n";
      edad = validarEdad();
      std::cout<<"Ingrese su genero M/F: \n";
      genero = validarGenero();
      std::cout<<"Ingrese su direccion: \n";
      direccion = validarDireccion();
      std::cout<<"Ingrese su numero de celular: \n";
      numero = validarNumero();
      std::cout<<"Ingrese su fecha de ingreso: \n";
      fechaIngreso = validarFecha();
      std::cout<<"Ingrese el diagnostico del paciente: \n";
      diagnostico = validarDiagnostico();

      agregarPaciente(pacientes, dpi, nombre, edad, genero, direccion, numero, fechaIngreso, diagnostico);

    }else if(opcion == 2) {
      std::string id;

      std::cout<<"Ingrese el DPI del paciente a modificar: \n";
      id = validarIdentificacion();

      modificarPaciente(pacientes, id);

    }else if(opcion == 3) {
      std::string id;

      std::cout<<"Ingrese el DPI del paciente a eliminar: \n";
      id = validarIdentificacion();

      eliminarPaciente(pacientes, id);

    }else if(opcion == 4) {
      desplegarReporteGeneral(pacientes);

    }else if(opcion == 5) {
      generarReportePacientesPDF(pacientes);
    }
  }while(opcion != 6);
};
