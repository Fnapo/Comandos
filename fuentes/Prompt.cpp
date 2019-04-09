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

#include "../headers/Prompt.hpp"

Prompt Prompt::separadores("\n\t\r\v ");

Prompt::Prompt() : longitud(0) {
    cadena[0] = '\0';
}

Prompt::Prompt(const Prompt& origen) : longitud(origen.longitud) {
    for (int indice = 0; indice < longitud; ++indice) {
        cadena[indice] = origen.cadena[indice];
    }
}

Prompt::Prompt(const char* origen) : longitud(0) {
    while (longitud < PROMPT_LONGITUD && origen[longitud] != '\0') {
        cadena[longitud] = origen[longitud];
        ++longitud;
    }
    cadena[longitud] = '\0';
}

Prompt::~Prompt() {
    longitud = 0;
    cadena[0] = '\0';
}

void Prompt::separar(Prompt &destino) {
    int cuantos;

    trim();
    for (cuantos = 0; cuantos < longitud; ++cuantos) {
        if (esSeparador(cadena[cuantos])) {
            break;
        }
    }
    copiarN(destino, cuantos);
    eliminarN(cuantos);
}

void Prompt::rTrim() {
    while (longitud > 0 && esSeparador(cadena[longitud - 1])) {
        cadena[--longitud] = '\0';
    }
}

void Prompt::lTrim() {
    int cuantos = 0;

    while (esSeparador(cadena[cuantos])) {
        ++cuantos;
    }
    eliminarN(cuantos);
}

void Prompt::trim() {
    rTrim();
    lTrim();
}

void Prompt::copiarN(Prompt& destino, int cuantos) {
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

void Prompt::eliminarN(int cuantos) {
    if (cuantos < 1 || cuantos > longitud) {
        return;
    }
    for (int indice = cuantos; indice <= longitud; ++indice) {
        cadena[indice - cuantos] = cadena[indice];
    }
    longitud -= cuantos;
}

int Prompt::esSeparador(char caracter) {
    for (int indice = 0; indice < separadores.longitud; ++indice) {
        if ((caracter == separadores[indice])) {
            return 1;
        }
    }

    return 0;
}

int Prompt::leer(istream &in) {
    Prompt aux;

    in.getline(cadena, PROMPT_LONGITUD + 1);
    longitud = 0;
    while (cadena[longitud] != '\0') {
        ++longitud;
    }
    while (in.fail()) {
        in.clear();
        in.getline(aux.cadena, PROMPT_LONGITUD + 1);
    }

    return longitud;
}
