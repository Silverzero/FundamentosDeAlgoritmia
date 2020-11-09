// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado
// O(v + m) APROX a O(n) ->  siendo n el tamaño del vector de tiradas y m el valor maximo de la tirada


// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 

// PRECONDICION: v.size() > 0 && P.T v[i] : 0 <= i < v.size() : v[i] <= maximoValores
vector<int> resolver(vector<int> const& v, int maximoValores) {
    
    vector<int> aux(maximoValores + 1, 0);
    vector<int> sol;

    int max = 0, times = 0;

    for (int const &x : v) {
        aux[x] += 1;
    }

    for (size_t i = aux.size() - 1; i > 0; --i) {
        if (aux[i] > times) {
            if (sol.size() > 0) sol.clear();
            times = aux[i];
            sol.push_back(i);
        }
        else if (aux[i] == times) {
            sol.push_back(i);
        }
    }

    return sol;
}
// PREDICADO MAX : 
// POSTCONDICION : P.T sol[i] : 0 <= i < sol.size() : aux[sol[i]] == MAX()

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    vector<int> v(numTiradas);
    for (int& i : v) cin >> i;
    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces

    vector<int> sol = resolver(v, valorMax);

    // Escribir los valores del vector que ha calculado resolver
    for (size_t i = 0; i < sol.size(); ++i) {
        cout << sol[i];
        if (i < sol.size() - 1) cout << " ";
    }
    
    cout << endl;

    return true;
}

int main() {

    #ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt    
    #endif

    while (resuelveCaso())
        ;

    #ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    #endif

    return 0;
}