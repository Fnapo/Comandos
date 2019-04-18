/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Macros.hpp
 * Author: fran_
 *
 * Created on 15 de abril de 2019, 19:41
 */

#ifndef MACROS_HPP
#define MACROS_HPP

/*
 * min y max en stl_algobase
 */

/**
 * 
 * @param T uno
 * @param T dos
 * @return el mínimo de uno y dos
 * 
 */
template <typename T> inline T minT(const T uno, const T dos) {
    return (uno < dos ? uno : dos);
}

/**
 * 
 * @param T uno
 * @param T dos
 * @return el máximo de uno y dos.
 * 
 */
template <typename T> inline T maxT(const T uno, const T dos) {
    return (uno > dos ? uno : dos);
}

/**
 * 
 * Ajusta numero entre minimo y maximo, ambos inclusive.
 * 
 * @param T numero
 * @param T minimo
 * @param T maximo
 * @return devuelve el número ajustado.
 * 
 */
template <typename T> inline T ajustaEntre(T &numero, const T minimo, const T maximo) {
    T min = minT(minimo, maximo), max = maxT(minimo, maximo);

    numero = (numero < min ? min : (numero > max ? max : numero));

    return numero;
}

/**
 * 
 * Indica si numero está entre minino y maximo, ambos inclusive.
 * 
 * @param T numero
 * @param T minimo
 * @param T maximo
 * @return bool
 * 
 */
template <typename T> inline bool estaEntre(const T numero, const T minimo, const T maximo) {
    T min = minT(minimo, maximo), max = maxT(minimo, maximo);

    return (numero < min ? 0 : (numero > max ? 0 : 1));
}

#endif /* MACROS_HPP */

