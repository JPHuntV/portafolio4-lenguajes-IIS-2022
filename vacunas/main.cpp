#include <iostream>
#include <list>
#include <string.h>
#include <algorithm>
#include "Vacuna.h"

using namespace std;

list<Vacuna> listaVacunas;

void agregarVacuna();
void menuPrincipal();
void menuEstadisticas();
string getPaisMasDosis();
int getPaisMasDosisAux(Vacuna vacuna);
void getCantidadPaisesVacuna();
int getCantidadPaisesVacunaAux(string vacuna);

/**
 * Main
 * 
 * Ejecuta el programa
 * E: Ninguna
 * S: Llamada al menu principal
 * R: Ninguna
 */
int main()
{
    menuPrincipal();
    return 0;
}



/**
 * menuPrincipal
 * 
 * Muestra y redirige a una serie de opciones
 * E: Numero de la opción mediante consola
 * S: Llamada a la función correspondiente de la opción seleccionada
 * R: Debe seleccionarse una opción disponible
 * 
 */
void menuPrincipal()
{
    int opcion;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\nMenu vacunas" << endl;
        cout << "1. Agregar vacuna" << endl;
        cout << "2. Estadisticas" << endl;
        cout << "3. Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarVacuna();
            system("pause>nul"); // Pausa
            break;
        case 2:
            menuEstadisticas();
            break;
        case 3:
            repetir = false;
            break;
        }
    } while (repetir);
}



/**
 * menuEstadisticas
 * 
 * Muestra y redirige a una serie de opciones
 * E: Numero de la opción mediante consola
 * S: Llamada a la función correspondiente de la opción seleccionada
 * R: Debe seleccionarse una opción disponible
 * 
 */
void menuEstadisticas()
{
    int opcion;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\nEstadisticas" << endl;
        cout << "1. Pais con mas dosis aplicadas" << endl;
        cout << "2. Cantidad de paises por vacuna" << endl;
        cout << "3. Ver primero y ultimo" << endl;
        cout << "4. Volver" << endl;
        cout << "5. Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "El pais con mas dosis aplicadas es: " + getPaisMasDosis() << endl;
            system("pause>nul");
            break;
        case 2:
            cout << "Cantidad de paises por vacuna";
            getCantidadPaisesVacuna();
            system("pause>nul");
            break;
        case 3:
            cout << "Primero: " << endl;
            listaVacunas.front().printVacuna();
            cout << "\n\nUltimo: " << endl;
            listaVacunas.back().printVacuna();
            system("pause>nul");
            break;
        case 4:
            repetir = false;
            break;
        case 5:
            exit(0);
            break;
        }
    } while (repetir);
}



/**
 * agregarVacuna
 * 
 * Agrega una nueva vacuna a la lista de vacunas
 * E: Información de la vacuna mediante consola
 * S: Inserta vacuna en listaVacunas
 * R: Cantidad de dosis debe ser numerico
 * 
 */
void agregarVacuna()
{
    string pais;
    string nombre;
    int dosisAplicadas;
    cout << "Agregar una nueva vacuna";

    cin.ignore();
    cout << "\nPais: ";
    getline(cin,pais);

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Dosis aplicadas: ";
    cin >> dosisAplicadas;

    Vacuna vacuna = Vacuna(pais, nombre, dosisAplicadas);
    listaVacunas.push_back(vacuna);

    cout << "Se ha insertado la vacuna" << endl;
}



/**
 * getPaisMasDosis
 * 
 * Indica cual es el pais con más dosis aplicadas
 * E: Ninguna
 * S: Pais con más dosis aplicadas
 * R: La lista debe tener elementos
 * 
 */
string getPaisMasDosis()
{
    string paisMayor;
    int cant = 0;
    for(Vacuna i : listaVacunas){
        int cantTemp = getPaisMasDosisAux(i);
        if(cantTemp >= cant){
            paisMayor = i.getPais();
        }
    }
    return paisMayor;
}



/**
 * getPaisMasDosisAux
 * 
 * Indica la cantidad de dosis de una vacuna para un pais
 * E: un objeto vacuna
 * S: Cantidad de dosis aplicadas
 * R: El objeto debe tener información
 */
int getPaisMasDosisAux(Vacuna vacuna){
    int cantidad = 0;
    for(Vacuna i :listaVacunas){
        if(i.getPais() == vacuna.getPais()){
            cantidad+= vacuna.getDosis();
        }
    }
    return cantidad;
}


/**
 * getCantidadPaisesVacuna
 * 
 * Indica la cantidad de paises que han aplicado cada vacuna
 * 
 * E: Ninguna
 * S: Cantidad de paises que han aplicado una vacuna
 * R: Ninguna
 * 
 */
void getCantidadPaisesVacuna(){
    list<string> visitados = {};
    for(Vacuna i : listaVacunas){
        if(find(visitados.begin(), visitados.end(), i.getNombre()) == visitados.end()){
            cout << "\nVacuna: "<< i.getNombre() << "\tCantidad de paises: " << to_string(getCantidadPaisesVacunaAux(i.getNombre()))<<endl;
            visitados.push_back(i.getNombre());
        }
    }
}


/**
 * getCantidadPaisesVacunaAux
 * 
 * Cuenta la cantidad paises en los que se ha aplicado una vacuna
 * E: Una vacuna
 * S: Cantidad de paises donde se ha aplicado
 * R: ninguna
 */
int getCantidadPaisesVacunaAux(string vacuna){
    int cantidad = 0;
    for(Vacuna i : listaVacunas){
        if(i.getNombre() == vacuna ){
            cantidad ++;
        }
    }
    return cantidad;
}