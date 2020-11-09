// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> & v, const vector<int> & w) {

    vector<int> sol;

    if (v.size() == 0)
        return w;
    else if (w.size() == 0)
        return v;

    size_t i = 0, j = 0;
    
    while (i < v.size() && j < w.size()) {
        
        if (v[i] < w[j]) {
            sol.push_back(v[i]);
            ++i;
        }
        else if (v[i] == w[j]) {
            sol.push_back(v[i]);
            ++i;
            ++j;
        }
        else {
            sol.push_back(w[j]);
            ++j;
        }

    }

    if ( i == v.size() ) {
        for (size_t k = j; k < w.size(); ++k) sol.push_back(w[k]);
    }
    else if (j == w.size()) {
        for (size_t k = i; k < v.size(); ++k) sol.push_back(v[k]);
    }

    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    size_t size;

    cin >> size;
    vector<int> v(size);
    
    cin >> size;
    vector<int> w(size);

    for (int& x : v) {
        cin >> x;
    }

    for (int& x : w) {
        cin >> x;
    }

    vector<int> sol = resolver(v, w);
    
    // escribir sol
    cout << sol[0];

    for (size_t i = 1; i < sol.size(); ++i) {
        cout << " " << sol[i];
    }

    cout << endl;

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