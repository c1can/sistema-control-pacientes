#include <iostream>
#include <vector>
#include <string>

struct Paciente {
    int numeroIdentificacion;
    std::string nombreCompleto;
    int edad;
    std::string genero;
    std::string direccion;
    int numeroCelular;
    std::string fechaIngreso;
    std::string diagnostico;

  };

  void agregarPaciente(std::vector<Paciente> & pacientes, int identificacion, std::string nombre, int edad, std::string genero, std::string direccion, int numero, std::string fecha, std::string diagnostico) {
      Paciente nuevoPaciente = {identificacion, nombre, edad, genero, direccion, numero, fecha, diagnostico};
      
    pacientes.push_back(nuevoPaciente);
    std::cout<<"Se ingreso un nuevo paciente: \n";
  };

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
    std::cin >> opcion;

    if(opcion == 1) {
      int dpi,edad,numero;
      std::string nombre,genero,direccion, fechaIngreso, diagnostico;
      
      std::cout<<"Ingrese un su numero de Identificaciòn (DPI): \n";
      std::cin>>dpi;
      std::cout<<"Ingrese su nombre completo: \n";
      std::cin>>nombre;
      std::cout<<"Ingrese su edad: \n";
      std::cin>>edad;
      std::cout<<"Ingrese su genero: \n";
      std::cin>>genero;
      std::cout<<"Ingrese su direccion: \n";
      std::cin>>direccion;
      std::cout<<"Ingrese su numero de celular: \n";
      std::cin>>numero;
      std::cout<<"Ingrese su fecha de ingreso: \n";
      std::cin>>fechaIngreso;
      std::cout<<"Ingrese el diagnostico del paciente: \n";
      std::cin>>diagnostico;

      agregarPaciente(pacientes, dpi, nombre, edad, genero, direccion, numero, fechaIngreso, diagnostico);

    }else if(opcion == 2) {
      std::cout<<"OPCION 2\n";
    }else if(opcion == 3) {
      std::cout<<"OPCION 3\n";
    }else if(opcion == 4) {
      std::cout<<"OPCION 4\n";
    }else if(opcion == 5) {
      std::cout<<"OPCION 5\n"
    }
  }while(opcion != 6);
};
