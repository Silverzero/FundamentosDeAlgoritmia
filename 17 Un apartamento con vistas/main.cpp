//*****************
// IMPORTANTE
//
// Marco Desantes Gutierrez
// E15
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//*******************************
// Aqui especificación de la función que resuelve el problema. 
//
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// 
// Solo un acceso a cada elemento del vector, por lo que tiene coste (O) n siendo n el numero de elementos del vectors
// 
//*******************************

struct edificio {
    string nombre;
    int altura;
    int piso;
};

// Aqui la función implementada por el alumno
vector<string> resolver(vector<edificio> const &v) {

    vector<string> sol;

    int max_altura = -1;

    for (int i = v.size() - 1; i >= 0; --i) {
        
        if (max_altura < v[i].piso) {
            sol.push_back(v[i].nombre);
        }

        if (max_altura < v[i].altura) max_altura = v[i].altura;
    }

    return sol;
}


bool resuelveCaso() {
    
    int numEdificios;
    std::cin >> numEdificios;
    if (numEdificios == 0) return false;

    // Lectura del resto de los datos
    vector<edificio> v(numEdificios);

    for (edificio& x : v) {
        cin >> x.nombre >> x.altura >> x.piso;
    }

    // LLamada a la funcion que resuelve el problema
    vector<string> sol = resolver(v);

    // Escribir el resultado
    if (sol.size() == 0) {
        cout << "Ninguno" << endl;
    }
    else {
        cout << sol.size() << endl;
        for (string const& x : sol) {
            cout << x << " ";
        }
        cout << endl;
    }

    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
