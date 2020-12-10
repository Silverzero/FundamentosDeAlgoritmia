// Marco Desantes Gutiérrez
// E15

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using matrix = vector<vector<int>>;

struct solution {
    bool ok;
    int total;
};

// función que resuelve el problema
solution resolver(vector<int> v, int left, int right) {

    if (left == right){ // un elemento
        return { true, v[left] };
    }
    else if (left + 1 == right) { // 2 elementos
        return { v[left] < v[right], v[left] + v[right] };
    }
    else {
        
        int middle = (left + right) / 2;

        solution l = resolver(v, left, middle);
        solution r = resolver(v, middle + 1, right);

        return { l.ok && r.ok && l.total < r.total, l.total + r.total };

    }

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int row, col;
    cin >> row;

    if (!cin)
        return false;

    cin >> col;

    matrix m(row, vector<int>(col));
    
    for (vector<int> &x : m)
        for (int& v : x)
            cin >> v;

    bool sol = true;
    
    // escribir sol
    for (size_t i = 0; i < m.size() && sol; ++i)
        sol = resolver(m[i], 0, m[i].size() - 1).ok;

    cout << (sol ? "SI" : "NO") << std::endl;

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