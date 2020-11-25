// Marco Desantes Gutiérrez
// E15

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
long long int resolver(long long int number) {

    if (number > 0) {

        long long int aux_number = number / 10;
        int resto = number % 10;

        return resolver(aux_number) * 100  + resto * 10 + resto;

    }
    else return 0;

}

long long int resolver_inverso(long long int number, long long int new_number, int n) {

    if (number > 0) {
        long long int aux_number = number / 10;
        int resto = number % 10;
        long long int value = (((resto * 10) + resto) * n) + new_number;
        return resolver_inverso(aux_number, value, n * 100);
    }
    else return new_number;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int number;

    cin >> number;

    long long int sol = resolver(number);
    long long int sol_inv = resolver_inverso(number, 0, 1);
    // escribir sol
    cout << sol << " " << sol_inv << endl;
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