// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> v, int start, int end, int number) {

    if (start == end || start + 1 == end) {
        
        if (v[start] == number + start)
            return v[start];
        else if (v[end] == number + end)
            return v[end];
        else
            return -1;

    }
    else {

        int middle = (start + end) / 2;

        int evaluate_left = abs(v[middle - 1] - (middle - 1) - number);

        int evaluate_right = abs(v[middle + 1] - (middle + 1) - number);

        if (evaluate_left < evaluate_right)
            return resolver(v, start, middle, number);
        else
            return resolver(v, middle, end, number);

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
    // leer los datos de la entrada
    int size, number;
    cin >> size >> number;

    vector<int> v(size);

    for (int& x : v)
        cin >> x;


    int sol = resolver(v, 0, v.size() - 1, number);

    // escribir sol
    if (sol == -1)
        cout << "NO" << endl;
    else
        cout << sol << endl;

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