/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comandos.cpp
 * Author: fran_
 * 
 * Created on 1 de abril de 2019, 11:12
 */

#include <stddef.h>

#include "../headers/Comandos.hpp"

Comandos::Comandos() : longitud(0) {
    cadena[0] = '\0';
}

Comandos::Comandos(const Comandos& origen) : longitud(origen.longitud) {
    for (int indice = 0; indice < longitud; ++indice) {
        cadena[indice] = origen.cadena[indice];
    }
}

Comandos::Comandos(const char* origen) : longitud(0) {
    while (longitud < COMANDO_LONGITUD && origen[longitud] != '\0') {
        cadena[longitud] = origen[longitud];
        ++longitud;
    }
    cadena[longitud] = '\0';
}

Comandos::~Comandos() {
    longitud = 0;
    cadena[0] = '\0';
}

int Comandos::esSeparador(int caracter) {
    int salida = 0;
    int separadores[] = {'\n', '\t', '\r', '\v', ' '};

    for (int indice; indice < separadores; ++indice) {
        salida = (caracter == separadores[indice]);
        if (salida) {
            break;
        }
    }

    return salida;
}

int Comandos::leer(istream &in) {
    Comandos aux;

    in.getline(cadena, COMANDO_LONGITUD + 1);
    longitud = 0;
    while (cadena[longitud] != '\0') {
        ++longitud;
    }
    while (in.fail()) {
        in.clear();
        in.getline(aux.cadena, COMANDO_LONGITUD + 1);
    }

    return longitud;
}