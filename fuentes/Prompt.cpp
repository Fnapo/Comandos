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
#include <termios.h>
#include <unistd.h>   //_getc

#include "../headers/Prompt.hpp"
#include "../headers/Macros.hpp"

Prompt Prompt::separadores("\n\t\r\v ");

Prompt::Prompt() : longitud(0) {
    cadena[0] = '\0';
}

Prompt::Prompt(const Prompt& origen) : longitud(origen.longitud) {
    copiar(origen);
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

Prompt &Prompt::copiar(const Prompt& origen) {
    longitud = origen.Longitud();
    for (int indice = 0; indice < longitud; ++indice) {
        cadena[indice] = origen.cadena[indice];
    }
    cadena[longitud] = '\0';

    return *this;
}

inline void Prompt::alarma() {
    printf("\a");
}

int Prompt::kbhit() {
    int buf = 0;
    struct termios old = {0};

    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 2) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");

    return buf;
}

char Prompt::getch() {
    char buf = 0;
    struct termios old = {0};

    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");

    return buf;
}

int Prompt::operator ==(const Prompt& segunda) {
    if (longitud != segunda.longitud) {
        return 0;
    }
    for (int indice = 0; indice < longitud; ++indice) {
        if (cadena[indice] != segunda.cadena[indice]) {
            return 0;
        }
    }

    return 1;
}

void Prompt::aMay() {
    for (int indice = 0; indice < longitud; ++indice) {
        cadena[indice] = (char) toupper(cadena[indice]);
    }
}

void Prompt::aMin() {
    for (int indice = 0; indice < longitud; ++indice) {
        cadena[indice] = (char) tolower(cadena[indice]);
    }
}

void Prompt::extraer(Prompt &destino) {
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
    int itecla;
    char tecla;
    bool salida = 0;

    longitud = 0;
    cadena[0] = '\0';
    while (!salida) {
        itecla = kbhit();
        if (itecla > 255) {
            itecla = kbhit();
        } else {
            tecla = (char) itecla;
            if (!estaEntre<char>(tecla, '\0', 31) && (tecla != DELETE)) {
                if (longitud < PROMPT_LONGITUD) {
                    cout << tecla;
                    cadena[longitud++] = tecla;
                    cadena[longitud] = '\0';
                }
            } else {
                switch (tecla) {
                case '\n':
                    salida = 1;
                    break;
                case '\b':
                case DELETE:
                    if (longitud) {
                        cadena[--longitud] = '\0';
                        cout << '\b';
                        cout << ' ';
                        cout << '\b';
                    }
                    break;
                }
            }
        }
    }
    cout << endl;

    return longitud;
}
