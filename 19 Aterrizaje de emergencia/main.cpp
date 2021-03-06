﻿// Marco Desantes Gutiérrez
// E15

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int plain();

// función que resuelve el problema
vector<int> resolver(vector<int> const &v, int const &offset) {

    vector<int> sol;
    
    int start     = 0;
    int last      = -1;
    int end       = 0;
    int end_value = v[0];

    for (int i = 1; i < v.size(); ++i) {
        
        if (abs(v[i] - end_value) <= 1) {
            end = i;
            end_value = v[i];
            if ((end - start + 1) >= offset && start != last){
                sol.push_back(start);
                last = start;
            }
        }
        else {
            end_value = v[i];
            start = i;
        }
    }

    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, offset;

    cin >> size >> offset;
    if (size == 0 && offset == 0)
        return false;

    vector<int> v(size);
    for (int& x : v) cin >> x;

    vector<int> sol = resolver(v, offset);

    // escribir sol
    cout << sol.size();
    
    if (sol.size() != 0){
        for (int const& x : sol) {
            cout << " " << x;
        }
    }
    cout << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}
