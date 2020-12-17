// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct solution {
    bool ok   = false;
    int left = 0;
    int right   = 0;
};

// función que resuelve el problema
solution resolver(const vector<int>& v, const vector<int>& w, int left, int right, solution inter) {
    
    if (left > right) return inter;
    else {
        
        int middle = (left + right) / 2;
        if (v[middle] == w[middle]) return { true, middle, middle };
        else if (v[middle] < w[middle]) {
            inter.left = middle;
            return resolver(v, w, middle + 1, right, inter);
        }
        else {
            inter.right = middle;
            return resolver(v, w, left, middle - 1, inter);
        }
    
    
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size;

    cin >> size;

    if (size == 0)
        return false;

    vector<int> v(size);
    for (int& x : v) cin >> x;

    vector<int> w(size);
    for (int& x : w) cin >> x;

    solution sol = resolver(v, w, 0, size - 1, {false, -1, size} );

    // escribir sol
    if (sol.ok)
        cout << "SI " << sol.left << endl;
    else
        cout << "NO " << sol.left << " " << sol.right << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}
