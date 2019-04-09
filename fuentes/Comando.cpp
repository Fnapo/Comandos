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

#include "../headers/Comando.hpp"

const char Comando::separadores[] = "\n\t\r\v ";

Comando::Comando() : longitud(0) {
    cadena[0] = '\0';
}

Comando::Comando(const Comando& origen) : longitud(origen.longitud) {
    for (int indice = 0; indice < longitud; ++indice) {
        cadena[indice] = origen.cadena[indice];
    }
}

Comando::Comando(const char* origen) : longitud(0) {
    while (longitud < COMANDO_LONGITUD && origen[longitud] != '\0') {
        cadena[longitud] = origen[longitud];
        ++longitud;
    }
    cadena[longitud] = '\0';
}

Comando::~Comando() {
    longitud = 0;
    cadena[0] = '\0';
}

Comando Comando::separar() {
    Comando salida;

    trim();


    return salida;
}

void Comando::rTrim() {
    while (longitud > 0 && esSeparador(cadena[longitud - 1])) {
        cadena[--longitud] = '\0';
    }
}

void Comando::lTrim() {
    int cuantos = 0;

    while (esSeparador(cadena[cuantos])) {
        ++cuantos;
    }
    eliminarN(cuantos);
}

void Comando::trim() {
    rTrim();
    lTrim();
}

void Comando::copiarN(Comando& destino, int cuantos) {
    destino = "";
    if (cuantos < 1 || cuantos > longitud) {
        return;
    }
    for (int indice = 0; indice < cuantos; ++indice) {
        destino.cadena[indice] = cadena[indice];
    }
    destino.cadena[cuantos] = '\0';
    destino.longitud = cuantos;
}

void Comando::eliminarN(int cuantos) {
    if (cuantos < 1 || cuantos > longitud) {
        return;
    }
    for (int indice = cuantos; indice <= longitud; ++indice) {
        cadena[indice - cuantos] = cadena[indice];
    }
    longitud -= cuantos;
}

int Comando::esSeparador(char caracter) {
    int salida = 0;
    Comando separador("\n\t\t\v ");

    for (int indice = 0; indice < separador.longitud; ++indice) {
        salida = (caracter == separador.cadena[indice]);
        if (salida) {
            break;
        }
    }

    return salida;
}

int Comando::leer(istream &in) {
    Comando aux;

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
