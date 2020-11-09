
// Marco Desantes Gutiérrez
// E15

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado



// Coste del algoritmo utilizado



// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int const& alturaNave, int& posIni, int& posFin){

    posFin = 0;

    int best_size = 0;
    int actual_size = 0;;

    for (int i = 0; i < v.size(); ++i) {

        if (v[i] > alturaNave) { // El elemento continua la racha
            
            ++actual_size;
            
            if (best_size < actual_size) { // Mejora la racha anterior
                best_size = actual_size;
                posFin = i;    
            }

        }
        else 
            actual_size = 0; // Se rompe la racha
    }

    posIni = posFin - best_size + 1;

}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
