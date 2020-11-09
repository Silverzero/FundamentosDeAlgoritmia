// Marco Desantes Gutiérrez
// E15

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int> & v, const size_t & offset) {

    int max = INT_MIN;
    bool sol = true;

    if ( v.size() - 1 == offset || v.size() == 1) {
        return sol;
    }

    for (size_t i = 0; i < v.size() && sol; ++i) {
        
        if ( i <= offset && v[i] >= max ) {
            max = v[i];
        } else if ( i > offset && max >= v[i] ) {
            sol = false;
        }

    }

    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    size_t size;
    size_t offset;

    cin >> size >> offset;

    vector<int> v(size);

    for (int& x : v) {
        cin >> x;
    }

    bool sol = resolver(v, offset);
    // escribir sol
    cout << (sol ? "SI" : "NO") << endl;


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}