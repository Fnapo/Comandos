/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: fran_
 *
 * Created on 1 de abril de 2019, 11:05
 */

#include <cstdlib>

#include "./headers/Prompt.hpp"

using namespace std;

/*
 * 
 */
int main() {
    Prompt orden("nwoennonoik lpoepopeoñk ocekkkkopk ckkkkkpkk ekpeckpkkckk"), elemento;
    char car = orden[2], car2 = orden[11], ayuda[] = "01234567890123456789";
    int lugar = 14, cuantos = 13, eliminar = 11;

    cout << "Escribe una cadena: ";
    cin >> orden;
    cout << orden << endl;
    cout << "Escribe una cadena: ";
    cin >> orden;
    cout << orden << endl;
    cout << "Es '" << car2 << "' un separador: " << (orden.esSeparador(car2) ? "SI." : "No.") << endl;
    cout << "Es '" << car << "' un separador: " << (orden.esSeparador(car) ? "SI." : "No.") << endl;
    cout << "La longitud de '" << orden << "' es: " << orden.Longitud() << "." << endl;
    orden = " 123456 ";
    cout << "La longitud de '" << orden << "' es: " << orden.Longitud() << "." << endl;
    orden.trim();
    cout << "La longitud de '" << orden << "' es: " << orden.Longitud() << "." << endl;
    cout << "El caracter " << lugar << " es: '" << orden[lugar] << "'." << endl;
    orden = "        ";
    cout << "La longitud de '" << orden << "' es: " << orden.Longitud() << "." << endl;
    orden.trim();
    cout << "La longitud de '" << orden << "' es: " << orden.Longitud() << "." << endl;
    elemento = orden = ayuda;
    orden.copiarN(elemento, cuantos);
    cout << "Copiando " << cuantos << " chars de: '" << orden << "' en: '" << elemento << "'." << endl;
    elemento = orden = ayuda;
    elemento.eliminarN(eliminar);
    cout << "Eliminando " << eliminar << " chars de: '" << orden << "' pasando a: '" << elemento << "'." << endl;
    orden = "         ";
    cout << "La cadena: '" << orden << "'." << endl;
    orden.extraer(elemento);
    cout << "Se convierte en: '" << orden << "' y extrae '" << elemento << "'." << endl;
    orden = "01234";
    cout << "La cadena: '" << orden << "'." << endl;
    orden.extraer(elemento);
    cout << "Se convierte en: '" << orden << "' y extrae '" << elemento << "'." << endl;
    orden = "0123  01234";
    cout << "La cadena: '" << orden << "'." << endl;
    orden.extraer(elemento);
    cout << "Se convierte en: '" << orden << "' y extrae '" << elemento << "'." << endl;
    orden = "abcDñ";
    cout << "La cadena: '" << orden << "'." << endl;
    orden.aMay();
    cout << "Se convierte en: '" << orden << "'\n";
    orden.aMin();
    cout << "O se convierte en: '" << orden << "'\n";

    return 0;
}
