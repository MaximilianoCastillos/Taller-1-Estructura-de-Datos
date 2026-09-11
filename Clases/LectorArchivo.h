#ifndef LECTORARCHIVO_H
#define LECTORARCHIVO_H

#include "Paciente.h"
#include <string>

class LectorArchivo {
public:
    LectorArchivo();
    ~LectorArchivo();

    Paciente** cargarPacientes(string nombreArchivo, int& cantidad);
};

#endif
