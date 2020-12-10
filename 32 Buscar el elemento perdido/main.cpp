// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> a, vector<int> b, int astart, int aend, int bstart, int bend) {

    if (astart == aend) {
        return a[astart];
    }
    else if (bstart == bend) {
       
        if (a[astart] == b[bstart])
            return a[aend];
        else
            return a[astart];

    }
    else if (bstart + 1 == bend) {

        if (a[astart] != b[bstart])
            return a[astart];
        else if (a[aend] != b[bend])
            return a[aend];
        else
            return a[astart + 1];

    }
    else {

        int middle = (astart + aend) / 2;

        if (a[middle] == b[middle])
            return resolver(a, b, middle, aend, middle, bend);
        else
            return resolver(a, b, astart, middle, bstart, middle);

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size;
    cin >> size;

    vector<int> a(size);
    vector<int> b(size - 1);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int sol = resolver(a, b, 0, a.size() - 1, 0, b.size() - 1);

    // escribir sol
    cout << sol << endl;
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