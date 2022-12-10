#ifndef RECORDATORIO_H_INCLUDED
#define RECORDATORIO_H_INCLUDED

#include <string>
#include <vector>

class Recordatorio {
  public:
    Recordatorio(std::string contenido, std::string fechaCreado, std::string fechaFin, std::string nombreAutor);

    std::vector<std::string> getDatos();    

    void print();

  private:
    std::string contenido_;
    std::string fechaCreado_;
    std::string fechaFin_;
    std::string nombreAutor_;
};

#endif