#include "Paciente.h"
#include <iostream>
using namespace std;

Paciente::Paciente(string i, string n, int e, string s)
    : Persona(n, e), id(i), servicio(s) {}

Paciente::~Paciente() {}

string Paciente::getId() const { return id; }
string Paciente::getServicio() const { return servicio; }

void Paciente::setId(string i) { id = i; }
void Paciente::setServicio(string s) { servicio = s; }

void Paciente::mostrarInfo() const {
    cout << id << " - " << nombre << " (" << edad << ") -> " << servicio << endl;
}
