// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct solucion {
    int numero = INT_MIN;
    int veces  = INT_MIN;
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    solucion solucion;
    int dato;
    int centinela = 0;

    cin >> dato;
    while (dato != centinela) {
        
        if (dato > solucion.numero) {
            solucion.numero = dato;
            solucion.veces = 1;
        }
        else if (solucion.numero == dato) {
            solucion.veces += 1;
        }
        
        cin >> dato;
    }
    // escribir sol
    cout << solucion.numero << " " << solucion.veces << endl;

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