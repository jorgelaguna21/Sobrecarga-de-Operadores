#include <iostream>
#include <string>

using namespace std;

class Empleado {
private:
  int ClaveEmpleado;
  string Nombre;
  string Domicilio;
  float Sueldo;
  string ReportaA;

public:
  // Constructor
  Empleado(int clave, string nombre, string domicilio, float sueldo, string reportaA) : ClaveEmpleado(clave), Nombre(nombre), Domicilio(domicilio), Sueldo(sueldo), ReportaA(reportaA) {}

  // Getters
  int getClaveEmpleado() const { return ClaveEmpleado; }
  string getNombre() const { return Nombre; }
  string getDomicilio() const { return Domicilio; }
  float getSueldo() const { return Sueldo; }
  string getReportaA() const { return ReportaA; }

  // Setters
  void setDomicilio(string nuevoDomicilio) { Domicilio = nuevoDomicilio; }
  void setSueldo(float nuevoSueldo) { Sueldo = nuevoSueldo; }
  void setReportaA(string nuevoReportaA) { ReportaA = nuevoReportaA; }

  // Sobrecarga de operadores
  bool operator==(const Empleado& otro) const {
    return ClaveEmpleado == otro.ClaveEmpleado;
  }

  bool operator!=(const Empleado& otro) const {
    return ClaveEmpleado != otro.ClaveEmpleado;
  }

  bool operator<(const Empleado& otro) const {
    return ClaveEmpleado < otro.ClaveEmpleado;
  }

  bool operator>(const Empleado& otro) const {
    return ClaveEmpleado > otro.ClaveEmpleado;
  }

  // Sobrecarga11  N de operador de inserción (<<) para salida
  friend ostream& operator<<(ostream& salida, const Empleado& empleado) {
    salida << "ClaveEmpleado: " << empleado.ClaveEmpleado << endl;
    salida << "Nombre: " << empleado.Nombre << endl;
    salida << "Domicilio: " << empleado.Domicilio << endl;
    salida << "Sueldo: " << empleado.Sueldo << endl;
    salida << "ReportaA: " << empleado.ReportaA << endl;
    return salida;
  }

  // Sobrecarga de operador de extracción (>>) para entrada
  friend istream& operator>>(istream& entrada, Empleado& empleado) {
    cout << "Ingrese la clave del empleado: ";
    entrada >> empleado.ClaveEmpleado;
    cout << "Ingrese el nombre del empleado: ";
    entrada.ignore(); // Ignorar el carácter de nueva línea
    getline(entrada, empleado.Nombre);
    cout << "Ingrese el domicilio del empleado: ";
    getline(entrada, empleado.Domicilio);
    cout << "Ingrese el sueldo del empleado: ";
    entrada >> empleado.Sueldo;
    cout << "Ingrese a quien reporta el empleado: ";
    entrada.ignore(); // Ignorar el carácter de nueva línea
    getline(entrada, empleado.ReportaA);
    return entrada;
  }

  // Sobrecarga de operador de suma (+) para agregar sueldo
  Empleado operator+(float incremento) const {
    Empleado nuevoEmpleado(*this);
    nuevoEmpleado.Sueldo += nuevoEmpleado.Sueldo * (incremento / 100);
    return nuevoEmpleado;
  }

};

int main() {
  // Declaración de los objetos Empleado
  Empleado JefePlanta(1, "Luis Hernandez", "Calle 123", 50000, "Gerente General");
  Empleado JefePersonal(2, "Carlos Rodriguez", "Avenida 456", 40000, "Jefe Planta");

  int opcion;
  do {
    cout << "\nMenu de opciones:\n";
    cout << "1. Cambiar domicilio\n";
    cout << "2. Actualizar sueldo\n";
    cout << "3. Imprimir datos\n";
    cout << "4. Cambiar nombre de quien reporta \n";
    cout << "5. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
      case 1: {
        int clave;
        string nuevoDomicilio;
        cout << "Ingrese la clave del empleado: ";
        cin >> clave;
        cin.ignore(); // Ignorar el carácter de nueva línea
        cout << "Ingrese el nuevo domicilio: ";
        getline(cin, nuevoDomicilio);
        if (JefePlanta.getClaveEmpleado() == clave) {
          JefePlanta.setDomicilio(nuevoDomicilio);
          cout << "Domicilio actualizado exitosamente.\n";
        } else if (JefePersonal.getClaveEmpleado() == clave) {
          JefePersonal.setDomicilio(nuevoDomicilio);
          cout << "Domicilio actualizado exitosamente.\n";
        } else {
          cout << "Clave de empleado no encontrada.\n";
        }
        break;
      }
      case 2: {
        int clave;
        float incremento;
        cout << "Ingrese la clave del empleado: ";
        cin >> clave;
        cout << "Ingrese el porcentaje de incremento: ";
        cin >> incremento;
        if (JefePlanta.getClaveEmpleado() == clave) {
          JefePlanta = JefePlanta + incremento;
          cout << "Sueldo actualizado exitosamente.\n";
        } else if (JefePersonal.getClaveEmpleado() == clave) {
          JefePersonal = JefePersonal + incremento;
          cout << "Sueldo actualizado exitosamente.\n";
        } else {
          cout << "Clave de empleado no encontrada.\n";
        }
        break;
      }
      case 3: {
        int clave;
        cout << "Ingrese la clave del empleado: ";
        cin >> clave;
        if (JefePlanta.getClaveEmpleado() == clave) {
          cout << JefePlanta;
        } else if (JefePersonal.getClaveEmpleado() == clave) {
          cout << JefePersonal;
        } else {
          cout << "Clave de empleado no encontrada.\n";
        }
        break;
      }
      case 4: {
        int clave;
        string nuevoReportaA;
        cout << "Ingrese la clave del empleado: ";
        cin >> clave;
        cin.ignore(); // Ignorar el carácter de nueva línea
        cout << "Ingrese el nombre de la persona a quien reporta: ";
        getline(cin, nuevoReportaA);
        if (JefePlanta.getClaveEmpleado() == clave) {
          JefePlanta.setReportaA(nuevoReportaA);
          cout << "Nombre de quien reporta actualizado exitosamente.\n";
        } else if (JefePersonal.getClaveEmpleado() == clave) {
          JefePersonal.setReportaA(nuevoReportaA);
          cout << "Nombre de quien reporta actualizado exitosamente.\n";
        } else {
          cout << "Clave de empleado no encontrada.\n";
        }
        break;
      }
      case 5:
        cout << "Saliendo del programa...\n";
        break;
      default:
        cout << "Opcion invalida.\n";
    }
  } while (opcion != 5);

  return 0;
}
