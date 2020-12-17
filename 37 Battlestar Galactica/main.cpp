// Marco Desantes Gutiérrez
// E15

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct solution {
    vector<int> v;
    int changes;
};

// función que resuelve el problema
solution resolver(const vector<int> &v, const int& left, const int& right) {

    if (left == right)
        return { { v[left] }, 0 };
    else if (left + 1 == right) {
        if (v[left] < v[right])
            return { { v[left], v[right] }, 0 };
        else
            return { { v[right], v[left] }, 1 };
    }
    else {

        int changes = 0, i = 0, j = 0;
        int middle = (left + right) / 2;

        solution l = resolver(v, left, middle);
        solution r = resolver(v, middle + 1, right);

        vector<int> w(l.v.size() + r.v.size());

        while (i < l.v.size() || j < r.v.size()) {
            
            if (i < l.v.size() && j < r.v.size()) {

                if (l.v[i] < r.v[j]) {
                    w[i + j] = l.v[i];
                    i++;
                }
                else {
                    changes += (l.v.size() - i);
                    w[i + j] = r.v[j];
                    j++;
                }
            }
            else if (i < l.v.size()) {
                w[i + j] = l.v[i];
                i++;
            }
            else {
                w[i + j] = r.v[j];
                j++;
            }
        
        }

        return { w, l.changes + r.changes + changes };
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

    vector<int> v(size);

    for (int& x : v) cin >> x;

    std::cout << resolver(v, 0, v.size() - 1).changes << std::endl;

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