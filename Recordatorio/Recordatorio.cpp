#include "Recordatorio.h"

#include <iostream>

Recordatorio::Recordatorio(std::string contenido, std::string fechaCreado, std::string fechaFin, std::string nombreAutor) :
    contenido_(contenido), 
    fechaCreado_(fechaCreado), 
    fechaFin_(fechaFin), 
    nombreAutor_(nombreAutor) {}


std::vector<std::string> Recordatorio::getDatos() {
    return std::vector<std::string>{nombreAutor_, fechaCreado_, contenido_, fechaFin_};
}

void Recordatorio::print() {
    std::cout << "Autor: " << nombreAutor_
              << "\nFecha de creación: " << fechaCreado_
              << "\nRecordatorio: " << contenido_
              << "\nFecha de fin: " << fechaFin_ << "\n";
}