#include "LectorArchivo.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

LectorArchivo::LectorArchivo() {}
LectorArchivo::~LectorArchivo() {}

Paciente** LectorArchivo::cargarPacientes(string nombreArchivo, int& cantidad) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: el archivo no existe." << endl;
        cantidad = 0;
        return nullptr;
    }

    string linea;
    cantidad = 0;
    Paciente** lista = new Paciente*[100]; // tamaño fijo simple para empezar

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id, nombre, edadStr, servicio;
        if (!getline(ss, id, ';') || !getline(ss, nombre, ';') ||
            !getline(ss, edadStr, ';') || !getline(ss, servicio, ';')) {
            cout << "Error: línea inválida." << endl;
            continue;
        }

        int edad;
        try {
            edad = stoi(edadStr);
        } catch (...) {
            cout << "Error: edad inválida." << endl;
            continue;
        }

        // Validar servicio
        string serviciosValidos[8] = {
            "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
            "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
        };
        bool valido = false;
        for (int i = 0; i < 8; i++) {
            if (servicio == serviciosValidos[i]) {
                valido = true;
                break;
            }
        }
        if (!valido) {
            cout << "Error: servicio inválido." << endl;
            continue;
        }

        // Validar duplicados (simple)
        bool duplicado = false;
        for (int i = 0; i < cantidad; i++) {
            if (lista[i]->getId() == id) {
                duplicado = true;
                break;
            }
        }
        if (duplicado) {
            cout << "Error: ID duplicado." << endl;
            continue;
        }

        lista[cantidad++] = new Paciente(id, nombre, edad, servicio);
    }

    archivo.close();
    return lista;
}
