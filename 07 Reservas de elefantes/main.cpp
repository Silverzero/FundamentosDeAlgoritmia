// Marco Desantes Gutiérrez
// E15

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema

// Coste 0 (n x m)

// Precondicion: { v.size() >= 0 && w.size() >= 0 }
vector<unsigned long int> resolver(vector<unsigned long int> &v, vector<unsigned long int> & w) {

    vector<unsigned long int> sol;

    if (v.size() == 0 || w.size() == 0)
        return sol;
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    size_t last = 0;
    bool flag;
    for (unsigned long int const &x : v) {
        
        flag = false;
        for (size_t j = last; !flag && j < w.size(); ++j) {
           
            if (x == w[j]) {
                sol.push_back(x);
                flag = true;
                last = j + 1;
            } else if( x < w[j]){
                flag = true;
                last = j;
            }

        }

    }

    return sol;
}

// NO ACABADA
// Pertenece (v, x) = E x : 0 <= i < v.size() : v[i] == x
// OrdenadoAsc(w) = V x : 0 <= i < w.size()
// Postcondicion: V x : Pertenece (v,x) && Pertenece (w,x) && Pertenece (z,x)


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<unsigned long int> v;
    vector<unsigned long int> w;

    unsigned long int x;

    cin >> x;
    while (x != 0) {
        v.push_back(x);
        cin >> x;
    }

    cin >> x;
    while (x != 0) {
        w.push_back(x);
        cin >> x;
    }

    vector<unsigned long int> sol = resolver(v, w);

    // escribir sol
    for (size_t i = 0; i < sol.size(); ++i) {
        cout << sol[i];
        if (i != sol.size() - 1) cout << " ";
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