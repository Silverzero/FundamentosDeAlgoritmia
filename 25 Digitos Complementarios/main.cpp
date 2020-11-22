// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
long long int resolver(long long int &number) {

    if (number != 0) {

        long long int aux_number = number / 10;
        int complementario = 9 - (number % 10);
        
        if (aux_number == 0)
            return complementario;
        else
            return resolver(aux_number) * 10 + complementario;

    }
    else {
        return 9;
    }


}

void resolver_inverso(long long int& number, long long int& solution) {

    if (number != 0) {

        long long int aux_number = number / 10;
        int complementario = 9 - (number % 10);

        solution = solution * 10 + complementario;
        if (aux_number != 0)
            return resolver_inverso(aux_number, solution);

    }
    else {
        solution = 9;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int number;
    long long int sol_inv = 0;

    cin >> number;

    long long int sol = resolver(number);
    resolver_inverso(number, sol_inv);
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