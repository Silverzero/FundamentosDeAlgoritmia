// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int suma(int number) {

    int aux_number = number / 10;
    int resto      = number % 10;
    
    if (aux_number > 0) {
        return resto + suma(aux_number);
    }
    else
        return resto;
}

bool resolver(int number, int suma_izq, int suma_der) {

    int aux_number = number / 10;
    int resto      = number % 10;

    int aux_suma_izq = suma_izq - resto;
    int aux_suma_der = suma_der + resto;

    bool no_zero  = resto != 0;
    bool is_right = suma_der % resto == 0;
    bool is_left  = aux_suma_izq % resto == 0;

    if (aux_number == 0)
        return no_zero && is_right && is_left;
    else
        return no_zero && is_right && is_left && resolver(aux_number, aux_suma_izq, aux_suma_der);


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int number;
    int suma_izq = 0;
    int suma_der = 0;
    cin >> number;

    suma_izq = suma(number);

    bool sol = resolver(number, suma_izq, suma_der);
    // escribir sol
    cout << (sol ? "SI" : "NO") << endl;

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