//*****************
// IMPORTANTE
//
// Marco Desantes Gutiérrez
// E15
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct sol {
    int max;
    int first;
    int last;
};

//*******************************
// Aqui explicacion de la función que resuelve el problema. 
//
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// 
// 
// 
//*******************************


// Aqui la función implementada por el alumno para resolver el problema
sol resolver(vector<int> const& v, int const &corte) {
    
    sol sol = { 0,0,0 };
    int actual_max;

    for (int i = 0; i < corte; ++i) {
        sol.max += v[i];
    }

    actual_max = sol.max;

    for (int i = corte; i < v.size(); ++i) {
        
        actual_max = actual_max + v[i] - v[i - corte];

        if (actual_max > sol.max) sol = { actual_max , i + 1 - corte, i + 1 - corte };
        else if (actual_max == sol.max) sol.last = i + 1 - corte;
    }

    return sol;

}


// Resuelve cada caso de la entrada
bool resuelveCaso() {
    // Lectura de los datos
    int numKilometros, longitudTramo;
    cin >> numKilometros >> longitudTramo;
    if (numKilometros == 0 && longitudTramo == 0) return false;
    vector<int> v(numKilometros); // nombre y altura
    for (int& n : v) cin >> n;
    // LLamada a la funcion que resuelve el problema
    sol sol = resolver(v, longitudTramo);

    // Escribir el resultado
    cout << sol.max << " " << sol.first << " " << sol.last << endl;

    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}