// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> &v) {

    sort(v.begin(), v.end());

    int max_value = v[0];
    int max_times = 1;

    int actual_value = v[0];
    int actual_times = 1;

    for (int i = 1; i < v.size(); ++i) {
        
        if (actual_value == v[i]) {
            ++actual_times;

            if (actual_times > max_times) {
                max_times = actual_times;
                max_value = actual_value;
            }

        }
        else {
            actual_value = v[i];
            actual_times = 1;
        }
    }

    return max_value;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long unsigned int size;
    
    cin >> size;
    if (size == -1)
        return false;

    vector<int> v(size);

    for (int& x : v) cin >> x;

    int sol = resolver(v);

    cout << sol << endl;
    // escribir sol

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
