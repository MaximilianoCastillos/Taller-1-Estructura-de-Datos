#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string n = "", int e = 0);
    virtual ~Persona();

    string getNombre() const;
    int getEdad() const;
    void setNombre(string n);
    void setEdad(int e);

    virtual void mostrarInfo() const;
};

#endif