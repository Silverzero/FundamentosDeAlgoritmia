// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// Nombre y apellidos del estudiante
// Usuario del juez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using lli = long long int;
// Calcula un vector con los valores acumulados

/* Coste: O(1) */
lli resolver(const lli& total, const lli& right, const lli& left) {
    return total - right - left;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    size_t start, end, size, start_questions, end_questions, cases;
    lli total = 0;

    cin >> start >> end;
    if (start == 0 && end == 0) return false;

    // Lee el resto de los datos y calcula el vector de acumulados

    size = end - start + 1;

    vector<int> v(size);
    vector<lli> v_left(size);
    vector<lli> v_right(size);

    for (size_t i = 0; i < v.size(); ++i) {
        int x;
        cin >> x;
        v[i] = x;

        v_left[i] = total;
        total += x;
    }

    for (size_t i = 0; i < v_right.size(); ++i) {
        v_right[i] = total - v_left[i] - v[i];
    }

    // Lectura de las preguntas
    cin >> cases;

    for (int i = 0; i < cases; ++i) {
        
        cin >> start_questions >> end_questions;
        
        start_questions -= start;
        end_questions -= start;

        cout << resolver(total, v_right[end_questions], v_left[start_questions]) << endl;

        // Aqui codigo del estudiante
    }
    
    cout << "---\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}