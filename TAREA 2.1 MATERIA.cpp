#include <iostream>
#include <string>

using namespace std;

class Materia {
private:
  int clave;
  string nombre;
  string profesorTit;
  string libroTexto;

public:
  // Constructor
  Materia(int clave, string nombre, string profesorTit, string libroTexto)
      : clave(clave),
        nombre(nombre),
        profesorTit(profesorTit),
        libroTexto(libroTexto) {}

  // Getters
  int getClave() const { return clave; }
  string getNombre() const { return nombre; }
  string getProfesorTit() const { return profesorTit; }
  string getLibroTexto() const { return libroTexto; }

  // Setters
  void setClave(int clave) { this->clave = clave; }
  void setProfesorTit(string profesorTit) { this->profesorTit = profesorTit; }

  // Sobrecarga de operadores
  bool operator==(const Materia& other) const {
    return clave == other.clave && nombre == other.nombre &&
           profesorTit == other.profesorTit && libroTexto == other.libroTexto;
  }

  bool operator!=(const Materia& other) const { return !(*this == other); }

  bool operator<(const Materia& other) const { return clave < other.clave; }

  bool operator>(const Materia& other) const { return clave > other.clave; }

  Materia operator+(const Materia& other) const {
    return Materia(clave + other.clave, nombre + other.nombre,
                  profesorTit + other.profesorTit, libroTexto + other.libroTexto);
  }

  friend istream& operator>>(istream& input, Materia& materia);
  friend ostream& operator<<(ostream& output, const Materia& materia);
};

istream& operator>>(istream& input, Materia& materia) {
  cout << "Ingrese la clave: ";
  input >> materia.clave;

  cout << "Ingrese el nombre: ";
  input >> materia.nombre;

  cout << "Ingrese el profesor titular: ";
  input >> materia.profesorTit;

  cout << "Ingrese el libro de texto: ";
  input >> materia.libroTexto;

  return input;
}

ostream& operator<<(ostream& output, const Materia& materia) {
  output << "Clave: " << materia.clave << endl;
  output << "Nombre: " << materia.nombre << endl;
  output << "Profesor Titular: " << materia.profesorTit << endl;
  output << "Libro de Texto: " << materia.libroTexto << endl;

  return output;
}

int main() {
  // Declarar objetos Materia
  Materia Programacion(101, "Programacion", "Ramon Pulido",
                      "Introduccion a la Programacion");
  Materia BasesDatos(102, "Bases de Datos", "Antonia Jimenez",
                      "Sistemas de Gestion de Bases de Datos");

  int opcion;

  do {
    cout << "\nMenú:" << endl;
    cout << "1. Cambiar la clave de la materia de Programación" << endl;
    cout << "2. Cambiar el nombre del maestro de la materia Bases de Datos" << endl;
    cout << "3. Imprimir todos los datos de la materia Bases de Datos" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    switch (opcion) {
      case 1: {
        int nuevaClave;
        cout << "Ingrese la nueva clave para la materia de Programacion: ";
        cin >> nuevaClave;
        Programacion.setClave(nuevaClave);
        cout << "Clave actualizada correctamente." << endl;
        break;
      }
      case 2: {
        string nuevoProfesor;
        cout << "Ingrese el nuevo nombre del maestro para Bases De Datos: ";
        cin.ignore();
        getline(cin, nuevoProfesor);
        BasesDatos.setProfesorTit(nuevoProfesor);
        cout << "Nombre del maestro actualizado correctamente." << endl;
        break;
      }
      case 3: {
        cout << "\nDatos de la materia BasesDatos:" << endl;
        cout << BasesDatos;
        break;
      }
      case 4:
        cout << "Saliendo del programa..." << endl;
        break;
      default:
        cout << "Opción inválida. Por favor, intente de nuevo." << endl;
    }
  } while (opcion != 4);

  return 0;
}
