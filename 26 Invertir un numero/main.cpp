// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

// función que resuelve el problema
void resolver(unsigned int& number, unsigned int& solution) {

    unsigned int aux_number = number / 10;
    int complementario = (number % 10);

    solution = solution * 10 + complementario;
    if(aux_number  != 0)
        resolver(aux_number, solution);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    unsigned int number;
    cin >> number;

    if (number == 0)
        return false;

    unsigned int sol = 0;
    resolver(number, sol);

    // escribir sol
    cout << sol << endl;

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
