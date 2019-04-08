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
#include <cstring>

#include "../headers/Comandos.hpp"

const char Comandos::separadores[] = "\n\t\r\v ";

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

Comandos Comandos::separar() {
    Comandos salida;

    trim();


    return salida;
}

void Comandos::rTrim() {
    while (longitud > 0 && esSeparador(cadena[longitud - 1])) {
        cadena[--longitud] = '\0';
    }
}

void Comandos::lTrim() {
    int cuantos = 0;

    while (esSeparador(cadena[cuantos])) {
        ++cuantos;
    }
    eliminarN(cuantos);
}

void Comandos::trim() {
    rTrim();
    lTrim();
}

void Comandos::copiarN(Comandos& destino, int cuantos) {
    cuantos = (cuantos <= 0 ? 0 : (cuantos >= longitud ? longitud : cuantos));
    destino = "";
    for (int indice = 0; indice < cuantos; ++indice) {
        destino.cadena[indice] = cadena[indice];
    }
    destino.longitud = cuantos;
}

void Comandos::eliminarN(int cuantos) {
    cuantos = (cuantos <= 0 ? 0 : (cuantos >= longitud ? longitud : cuantos));
    for (int indice = cuantos; indice <= longitud; ++indice) {
        cadena[indice - cuantos] = cadena[indice];
    }
    longitud -= cuantos;
}

int Comandos::esSeparador(char caracter) {
    int salida = 0;
    Comandos separador("\n\t\t\v ");

    for (int indice = 0; indice < separador.longitud; ++indice) {
        salida = (caracter == separador.cadena[indice]);
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
