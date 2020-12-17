// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct solution {
    bool winner;
    int result;
    int round;
};

// función que resuelve el problema
solution resolver(const vector<string>& v, int left, int right, int round) {

    if (left + 1 == right) {

        return {
            v[left] != "NP" || v[right] != "NP",
            v[left] != "NP" && v[right] != "NP",
            1
        };

        /*
        if (v[left] == "NP" && v[right] == "NP")
            return { false , 0, 1 };
        else if (v[left] == "NP" && v[right] != "NP" || v[left] != "NP" && v[right] == "NP")
            return { true, 0 , 1 };
        else if (v[left] != "NP" && v[right] != "NP")
            return { true, 1, 1 };
        */

    }else {

        int middle = (left + right) / 2;

        solution sol_izq = resolver(v, left, middle, round);
        solution sol_der = resolver(v, middle + 1, right, round);
        
        if (sol_izq.round < round)
            
            return {
                sol_izq.winner || sol_der.winner,
                sol_izq.result + sol_der.result + (sol_izq.winner && sol_der.winner),
                sol_izq.round + 1
            };
            
            /*
            if (!sol_izq.winner && !sol_der.winner)
                return { false, sol_izq.result + sol_der.result, sol_izq.round + 1 };
            else if (!sol_izq.winner && sol_der.winner || sol_izq.winner && !sol_der.winner)
                return { true, sol_izq.result + sol_der.result, sol_izq.round + 1 };
            else if (sol_izq.winner && sol_der.winner)
                return { true, sol_izq.result + sol_der.result + 1, sol_izq.round + 1 };
            */

        else

            return { 
                sol_izq.winner || sol_der.winner,
                sol_izq.result + sol_der.result,
                sol_izq.round + 1 
            };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, round;
    
    cin >> size;

    if (!cin)
        return false;

    cin >> round;

    vector<string> v(size);

    for (string& x : v) cin >> x;

    int sol = resolver(v, 0, v.size() - 1, round).result;

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