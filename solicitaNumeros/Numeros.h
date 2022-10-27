#ifndef Numeros_h
#define Numeros_h
#include <iostream>

using namespace std;
/**
 * Clase Numeros 
 */
class Numeros
{
private:
    int cantidadNumeros;
    int numeros[];

public:

    /**
     * SolicitarCantidad()
     * Solicita cantidad de numeros que tendra la lista
     * E: Cantidad de numeros mediante consola
     * S: Almacena la cantidad de numeros que debe solicitar
     * R: Ninguna
     */
    void solicitarCantidad(){
        cout << "¿Cuantos numeros desea solicitar ?:\t";
        cin >> this->cantidadNumeros;
    }



    /**
     * solicitarNumeros()
     * Solicita los numeros correspondientes a cada posición
     * E: Valor de cada posición mediante consola
     * S: Almacena los valores ingresados en una lista
     * R: Los valores deben de ser de tipo entero
     */
    void solicitarNumeros(){
        for (int i = 0; i <= this->cantidadNumeros-1; i++)
        {
            cout << "Ingrese el numero en la posicicion ["+to_string(i)+"]:\t";
            cin >> this->numeros[i];
        }
        cout << "Se han ingresado todos los numeros\n\n";
        
    }



    /**
     * imprimirLista()
     * Imprime los valores de una lista y su posición de manera invertida
     * E: Ninguna
     * S: Impresión en consola de la lista
     * R: Ninguna 
     */
    void imprimirLista(){
        cout << "Imprimiendo los numeros\n";
        for(int i = this->cantidadNumeros-1; i>=0;i--){
            cout << "Numero en la posicicion ["+to_string(i)+"]:\t"+to_string(this->numeros[i])+"\n";

        }    
    }
};
#endif