// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> v, int start, int end) {

    if (start >= end) //vector vacio
        return min(v[start], v[end]);
    else if(start + 1 == end) //vector de 1 elemento
        return min(v[start], v[end]);
    else {
        int middle = (start + end) / 2;

        if (v[middle - 1] < v[middle])
            return resolver(v, start, middle);
        else
            return resolver(v, middle, end);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size;

    cin >> size;

    if (!cin)
        return false;

    vector <int> v(size);

    for (int& x : v) cin >> x;

    int sol = resolver(v, 0, v.size() - 1);

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