/*
Jean Hunt
2018265223
Portafolio 4
solicitaNumeros: Lee una cantidad de numeros a solicitar, luego solicita al usuario cada uno de los
    numeros indicando la posición que está solicitando, luego imprime los valores invertidos
*/

#include <iostream>
#include "Numeros.h"

using namespace std;
/**
 * Solicita n cantidad de numeros a ingresar
 * luego solicita n numeros e imprime cada uno de ellos
 * indicando su posicón (en reversa)
 */
int main(){
    Numeros numeros;
    numeros.solicitarCantidad();
    numeros.solicitarNumeros();
    numeros.imprimirLista();
    return 0;
}