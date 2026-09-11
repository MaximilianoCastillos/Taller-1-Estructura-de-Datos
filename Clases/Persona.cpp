#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona(string n, int e) : nombre(n), edad(e) {}

Persona::~Persona() {}

string Persona::getNombre() const { return nombre; }
int Persona::getEdad() const { return edad; }

void Persona::setNombre(string n) { nombre = n; }
void Persona::setEdad(int e) { edad = e; }

void Persona::mostrarInfo() const {
    cout << nombre << " Tiene: " << edad << " años" << endl;
}
