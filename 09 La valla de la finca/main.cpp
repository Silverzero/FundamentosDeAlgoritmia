// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct solution {
    bool fix;
    int meter;
};

// función que resuelve el problema
// PRECONDICION: P.T i : 0 < i <= size() && meters <= size();
solution resolver(vector<unsigned int> const &v, size_t const &meters) {

    int rotos = 0;
    
    int offset = 0;

    for (size_t i = 0; i < meters; ++i) {
        if (v[i] == 0) rotos += 1;
    }

    int before, after, aux_rotos, actual_rotos = rotos;
    for (int i = 1; i <= v.size() - meters ; ++i) {
        before = (v[i - 1] == 0) ? 1 : 0;
        after = (v[meters - 1 + i] == 0) ? 1 : 0;

        aux_rotos = actual_rotos - before + after;

        if (aux_rotos >= rotos) {
            offset = i;   
            rotos = aux_rotos;
        }
        
        actual_rotos = aux_rotos;

    }

    return { rotos != 0, offset };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    size_t size, meter;
    cin >> size;
    if (size == 0)
        return false;

    cin >> meter;

    vector<unsigned int> v(size);
    for (unsigned int& x : v) cin >> x;

    solution sol = resolver(v, meter);

    if (!sol.fix)
        cout << "No hace falta";
    else
        cout << sol.meter;

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
