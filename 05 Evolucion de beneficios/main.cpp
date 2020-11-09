// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct field {
    int year;
    int value;
};

// función que resuelve el problema
vector<int> resolver(const vector<field> &v) {

    vector<int> solution;

    int current_year = v[0].year, current_value = v[0].value;

    for (size_t i = 1; i < v.size(); ++i) {

        if (current_value < v[i].value) {
            solution.push_back(v[i].year);
        }

        if (current_value < v[i].value) {
            current_year = v[i].year;
            current_value = v[i].value;
        }

    }

    return solution;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    size_t start, end, size;
    cin >> start >> end;

    size = end - start + 1;
    vector<field> v(size);

    for (size_t i = 0; i < v.size(); ++i) {
        
        field x;

        x.year = start + i;
        cin >> x.value;
        
        v[i] = x;

    }
    
    vector<int> sol = resolver(v);

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