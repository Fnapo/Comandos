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

    cout << "Escribe una cadena: ";
    cin >> orden;
    cout << orden << endl;
    cout << "Escribe una cadena: ";
    cin >> orden;
    cout << orden << endl;

    return 0;
}

