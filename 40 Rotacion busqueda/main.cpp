// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int break_vector(const vector<int>& v, int left, int right) {

    if (left > right) return -1;
    else if (left == right) return left;
    else if (left + 1 == right) {
        if (v[left] < v[right])
            return left;
        else
            return right;
    } else {
        int middle = (left + right) / 2;
        if (v[middle] >= v[left]) return break_vector(v, middle, right);
        else return break_vector(v, left, middle - 1);
    }

}

bool resolver(const vector<int>& v, int left, int right, int value) {

    if (left > right) return false;
    else {
        
        int middle = (left + right) / 2;
        if (v[middle] == value) return true;
        else if (v[middle] > value) return resolver(v, left, middle - 1, value);
        else return resolver(v, middle + 1, right, value);
    
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, value;
    
    cin >> size;

    if (size == -1)
        return false;

    cin >> value;

    vector<int> v(size);

    for (int& x : v) cin >> x;

    int corte = break_vector(v, 0, v.size() - 1);

    bool sol = resolver(v, 0, corte, value) || resolver(v, corte, v.size() - 1, value);

    // escribir sol
    cout << (sol ? "SI" : "NO") << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}
