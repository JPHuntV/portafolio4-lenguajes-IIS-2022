#ifndef vacuna_h
#define vacuna_h

#include <iostream>
#include <string.h>

using namespace std;

//Clase Vacuna
class Vacuna
{
private:
    string pais;
    string nombre;
    int dosisAplicadas;

public:
    /**
     * Constructor de la clase Vacuna
     * E:
     *  pais: pais de la vacuna
     *  nombre: nombre de la vacuna
     *  dosisAplicadas: dosis que han sido aplicadas
     * 
     * S: Un objeto Vacuna
     * R: Ninguna 
     */
    Vacuna(string pais, string nombre, int dosisAplicadas)
    {
        this->pais = pais;
        this->nombre = nombre;
        this->dosisAplicadas = dosisAplicadas;
    }

    /**
     * Imprime la información de una vacuna
     * 
     * E: Ninguna
     * S: Imprime en consola la información de una vacuna
     * R: Ninguna
     * 
     */
    void printVacuna(){
        cout << "Pais: " << this->pais << endl;
        cout << "Nombre: " << this->nombre << endl;
        cout << "Dosis aplicadas: " << this->dosisAplicadas << endl;
    }

    // getters y setters
    string getPais(){
        return this->pais;
    }

    void setPais(string pais){
        this->pais = pais;
    }

    string getNombre(){
        return this->nombre;
    }

    void setNombre(string nombre){
        this->nombre = nombre;
    }

    int getDosis(){
        return this->dosisAplicadas;
    }

    void setDosis(int dosis){
        this->dosisAplicadas = dosis;
    }

};

#endif