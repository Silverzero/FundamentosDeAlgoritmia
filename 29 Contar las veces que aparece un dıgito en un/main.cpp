// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int resolver(long long int number, int digit) {

    long long int aux_number = number / 10;
    int resto = number % 10;

    if (number > 0) {
        if (resto == digit)
            return 1 + resolver(aux_number, digit);
        else
            return resolver(aux_number, digit);
    }
    else {
        return 0;
    }

}

int resolver_inverso(long long int number, int digit, int times) {

    long long int aux_number = number / 10;
    int resto = number % 10;

    if (number > 0) {
        if (resto == digit)
            return resolver_inverso(aux_number, digit, times + 1);
        else
            return resolver_inverso(aux_number, digit, times);
    }
    else {
        return times;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int number;
    int digit;

    cin >> number >> digit;

    int sol = resolver(number, digit);
    int sol_inv = resolver_inverso(number, digit, 0);
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