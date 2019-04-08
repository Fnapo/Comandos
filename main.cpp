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

#include "headers/Comandos.hpp"

using namespace std;

/*
 * 
 */
int main() {
    Comandos orden("nwoennonoik lpoepopeoñk ocekkkkopk ckkkkkpkk ekpeckpkkckk");
    char car = orden[2], car2 = orden[11];
    int lugar = 14;

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

    return 0;
}

