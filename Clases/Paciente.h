#ifndef PACIENTE_H
#define PACIENTE_H

#include "Persona.h"

class Paciente : public Persona {
private:
    string id;
    string servicio;

public:
    Paciente(string i = "", string n = "", int e = 0, string s = "");
    ~Paciente();

    string getId() const;
    string getServicio() const;
    void setId(string i);
    void setServicio(string s);

    void mostrarInfo() const override;
};

#endif
