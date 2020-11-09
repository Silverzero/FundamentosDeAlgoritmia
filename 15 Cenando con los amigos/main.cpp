// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct solution {
    int value;
    int offset;
    int end;
};

// función que resuelve el problema
// Complejiad: O(n).
solution resolver(vector<int> const &v) {

    solution actual = { 0, 0, 0 }, best = { 0, 0, 0 };

    for (int i = 0; i < v.size(); ++i) {
        
        actual.value += v[i];
        actual.end = i;
        
        if (actual.value <= 0)
            actual = { 0, i + 1, i + 1 };
        else if ((actual.value > best.value) || (actual.value == best.value && (actual.end - actual.offset < best.end - best.offset))) 
            best = actual;

    }

    return { best.value, best.offset, best.end + 1 - best.offset };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    size_t size;
    cin >> size;

    if (!cin)
        return false;

    vector<int> v(size);

    for (int& x : v) cin >> x;

    solution sol = resolver(v);

    // escribir sol
    cout << sol.value << " " << sol.offset << " " << sol.end << endl;

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