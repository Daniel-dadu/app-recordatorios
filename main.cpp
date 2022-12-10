#include "Recordatorio/Recordatorio.cpp"

#include <ctime>
#include <fstream>

//* Funcion importante
std::vector<Recordatorio> leerRecordatorios() {
    std::string autor, fechaCreado, fechaFin, contenido;

    std::ifstream archivo;
    archivo.open("recordatorios.txt");

    std::vector<Recordatorio> recordatorios;
    
    while (archivo.peek() != std::ifstream::traits_type::eof()) {
        std::getline(archivo, autor);
        std::getline(archivo, fechaCreado);
        std::getline(archivo, contenido);
        std::getline(archivo, fechaFin);
        recordatorios.push_back(Recordatorio(contenido, fechaCreado, fechaFin, autor));
    }

    return recordatorios;
}

void imprimirRecordatorios(std::vector<Recordatorio> recordatorios) {
    int contador = 1;
    for(Recordatorio r: recordatorios) {
        std::cout << "\nRecordatorio " << contador++ << ":\n";
        r.print();
    }
}

void guardarRecordatorios(std::vector<Recordatorio> recordatorios) {
    std::ofstream archivo;
    archivo.open("recordatorios.txt");

    for(Recordatorio r: recordatorios) {
        std::vector<std::string> datos = r.getDatos();
        archivo << datos[0] << "\n"
            << datos[1] << "\n"
            << datos[2] << "\n"
            << datos[3] << "\n";
    }

    archivo.close();
}

void agregarRecordatorio() {
    std::string autor, fechaCreado, fechaFin, contenido;
    // Obtenemos la fecha de hoy
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    fechaCreado = std::to_string(now->tm_mday) + "/" 
        + std::to_string(now->tm_mon + 1) + "/"
        + std::to_string(now->tm_year + 1900);

    std::cout << "Dame el nombre del autor: ";
    std::cin.ignore();
    std::getline(std::cin, autor);
    std::cout << "Dame la fecha de fin: ";
    std::cin >> fechaFin;
    std::cout << "Dame el contenido del recordatorio (max. 15 palabras): ";
    std::cin.ignore();
    std::getline(std::cin, contenido);

    std::vector<Recordatorio> recordatorios = leerRecordatorios();
    recordatorios.push_back(Recordatorio(contenido, fechaCreado, fechaFin, autor));

    guardarRecordatorios(recordatorios);

    std::cout << "Se agregó correctamente el recordatorio:\n";
    recordatorios.back().print();
}

void eliminarRecordatorio(int pos) {
   std::vector<Recordatorio> recordatorios = leerRecordatorios();
   recordatorios.erase(recordatorios.begin() + pos - 1);
   guardarRecordatorios(recordatorios);
   std::cout << "\nSe ha eliminado el recordatorio correctamente.\n";
}

int main() {
    int opcion = 0;

    std::cout << "El menú debe tener las siguientes opciones:\n";
    std::cout << "1. Ver mis recordatorios.\n";
    std::cout << "2. Agregar un recordatorio.\n";
    std::cout << "3. Eliminar un recordatorio.\n";
    std::cout << "Opción: ";
    std::cin >> opcion;

    if (opcion == 1) {
        imprimirRecordatorios(leerRecordatorios());
    } else if (opcion == 2) {
        agregarRecordatorio();
    } else if (opcion == 3) {
        imprimirRecordatorios(leerRecordatorios());
        std::cout << "Selecciona el número del recordatorio que deseas eliminar: \n";
        int opcion2;
        std::cin >> opcion2;
        eliminarRecordatorio(opcion2);
    } else {
        std::cout << "Opción inválida\n";
    }
}