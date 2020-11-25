// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
unsigned long long int resolver(unsigned int number, vector<unsigned long long int>& v) {

     if (v[number] == 0 && number != 0){
         v[number] = resolver(number - 1, v) + resolver(number - 2, v);
     }

     return v[number];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    unsigned int number;
    cin >> number;

    if (!cin)
        return false;

    vector<unsigned long long int> v(90, 0);
    v[0] = 0;
    v[1] = 1;

    unsigned long long int sol = resolver(number, v);

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