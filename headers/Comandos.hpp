/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comandos.hpp
 * Author: fran_
 *
 * Created on 1 de abril de 2019, 11:12
 */

#ifndef COMANDOS_HPP
#define COMANDOS_HPP

#include <iostream>

#define COMANDO_LONGITUD 50

/*
 * Clase para trabajar con cadenas cortas (COMANDO_LONGITUD caracteres como máximo).
 */
using namespace std;

class Comandos {
public:
    Comandos();
    Comandos(const Comandos& origen);
    Comandos(const char *origen);

    virtual ~Comandos();

    /**
     * 
     * Indica si caracter es un separador (1) o no (0).
     * 
     * @param {int} caracter
     * @return {int}
     * 
     */
    static int esSeparador(char caracter);

    /**
     * 
     * Devuelve los separadores habituales.
     * 
     * @return {Comandos}
     * 
     */
    static Comandos Separadores() {
        return separadores;
    }

    /**
     * 
     * Tras hacer un trim() actúa como la función strtok con los
     * separadores habituales.
     * 
     * @return {Comandos}
     * 
     */
    Comandos separar();

    inline char operator[](int indice) const {
        if (indice < 0 || indice >= longitud) {
            return '\0';
        }

        return cadena[indice];
    }

    inline operator const char *() {
        return cadena;
    }

    inline friend ostream& operator<<(ostream &out, const Comandos &origen) {
        out << origen.cadena;

        return out;
    }

    /**
     * 
     * Copia en destino los primeros cuantos elementos.
     * 
     * @param {Comandos} destino
     * @param {int} cuantos
     * 
     */
    void copiarN(Comandos &destino, int cuantos);

    /**
     * 
     * Elimina los primeros cuantos elementos.
     * 
     * @param cuantos
     * 
     */
    void eliminarN(int cuantos);

    /**
     * 
     * Esta función y el operador >> están pensados para stdin(cin) o para 
     * ficheros con longitud de línea menor que COMANDO_LONGITUD.
     * leer devuelve el número de caracteres leídos.
     * 
     * @param {istream &} in
     * @return {int}
     * 
     */
    int leer(istream &in);

    friend inline istream& operator>>(istream &in, Comandos &salida) {
        salida.leer(in);

        return in;
    }

    /**
     * 
     * Las funciones típicas de cadenas:
     * trim, lTrim, rTrim.
     * 
     */
    void trim();
    void lTrim();
    void rTrim();

    inline int Longitud() const {
        return longitud;
    }
private:
    char cadena[COMANDO_LONGITUD + 1];
    int longitud;
    static const char separadores[];
};

#endif /* COMANDOS_HPP */
