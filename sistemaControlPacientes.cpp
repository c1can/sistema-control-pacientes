#include <iostream>
#include <vector>
#include <string>

struct Paciente {
    std::string numeroIdentificacion;
    std::string nombreCompleto;
    int edad;
    std::string genero;
    std::string direccion;
    std::string numeroCelular;
    std::string fechaIngreso;
    std::string diagnostico;

  };

  void agregarPaciente(std::vector<Paciente> & pacientes, std::string identificacion, std::string nombre, int edad, std::string genero, std::string direccion, std::string numero, std::string fecha, std::string diagnostico) {
      Paciente nuevoPaciente = {identificacion, nombre, edad, genero, direccion, numero, fecha, diagnostico};
      
    pacientes.push_back(nuevoPaciente);
    std::cout<<"Se ingreso un nuevo paciente: \n";
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

int main() {
  //estructura de datos original
  std::vector<Paciente> pacientes;

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

    }else if(opcion == 3) {
      std::cout<<"OPCION 3\n";
    }else if(opcion == 4) {
      std::cout<<"OPCION 4\n";
    }else if(opcion == 5) {
      std::cout<<"OPCION 5\n";
    }
  }while(opcion != 6);
};
