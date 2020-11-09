// Marco Desantes
// E15

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado

using namespace std;

using psi = std::pair<char, int>;

// Recibe un vector con los datos de entrada del problema
// Modifica este vetor dejando en las primeras posiciones 
// las cintas azules, luego las verdes y uego las rojas
// NO se puede utilizar sort
// p es la primera posicion de una cinta verde, q es la ultima posicion de una cinta verde
void particion(std::vector<psi>& v, int& p, int& q) {

    int k;

    p = 0, k= 0,
    q = (int) v.size() - 1;

    while (k <= q) {
        
        if (v[p].first == 'a') ++p, ++k; // elemento del indice izquierdo correcto
        else if (v[q].first == 'r') --q; // elemento del indice derecho correcto
        else {
            if (v[k].first == 'a') {
                swap(v[k], v[p]);
                ++p;
                ++k;
            }
            else if (v[k].first == 'r') {
                swap(v[k], v[q]);
                --q;
            }
            else ++k;
            
        }

    }

}


// Entrada y salida de datos
bool resuelveCaso() {
    
    // Lectura de los datos de entrada
    int numCintas;
    std::cin >> numCintas;
    if (!std::cin) return false;
    std::vector<psi> v(numCintas); // nombre y alturas
    for (psi& n : v) {
        std::cin >> n.first >> n.second;
    }
    // LLamada a la función paticion
    int p, q;
    particion(v, p, q);
    // Ordena cada parte para la salida de datos
    std::sort(v.begin(), v.begin() + p);
    std::sort(v.begin() + p, v.begin() + 1 + q);
    std::sort(v.begin() + 1 + q, v.end());
    // Escribe las cintas azules
    std::cout << "Azules:";
    for (int i = 0; i < p; ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    // Escribe la segunda parte
    std::cout << "Verdes:";
    for (int i = p; i <= q; ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    // Escribe la tercera parte
    std::cout << "Rojas:";
    for (int i = q + 1; i < v.size(); ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
