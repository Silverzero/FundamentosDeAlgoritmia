// Marco Desantes Gutiérrez
// E15

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, int left, int right, int depth, int max_depth) {

    if (depth == max_depth) {
        int suma = 0;
        for (int i = left; i <= right; ++i) suma += v[i];
        return suma;
    }
    else {
        int middle = (left + right) / 2;
        int sol_izq = resolver(v, left, middle, depth + 1, max_depth);
        int sol_der = resolver(v, middle + 1, right, depth + 1, max_depth);

        if (depth < max_depth) return max(sol_izq, sol_der);
        else return min(sol_izq, sol_der);
        
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, travel;

    cin >> size >> travel;

    if (size == 0 && travel == 0)
        return false;

    vector<int> v(size);
    for (int& x : v) cin >> x;

    int sol = resolver(v, 0, v.size() - 1, 1, travel);

    // escribir sol
    cout << sol << endl;

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
