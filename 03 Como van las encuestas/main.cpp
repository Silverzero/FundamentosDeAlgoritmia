// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <vector>

using namespace std;

struct solution {
    int sum;
    int size;
};

// función que resuelve el problema
solution resolver(const vector<int> & v, const int & size) {

    int sum = 0, min, times = 0;

    min = v[0];

    if (size == 1 || size == 0) {
        return { 0, 0 };
    }

    for (int x : v) {
        
        sum += x;

        if (x < min) {
            min = x;
            times = 1;
        } else if (x == min) {
            times += 1;
        }

    }

    sum = sum - min * times;

    return { sum, (size - times) };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size;
    cin >> size;
    vector<int> v(size);

    for (int & x : v) cin >> x;

    solution sol = resolver(v, size);

    // escribir sol
    cout << sol.sum << " " << sol.size << endl;

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