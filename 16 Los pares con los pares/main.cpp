// Marco Desantes Gutiérrez
// E15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool isEven(int value) { return value % 2 == 0; }

void resolver(vector<int> &v) {

    int offset = 0;
    int i = 0;

    while(i < v.size()) {
        
        bool even        = isEven(v[i]);
        bool offset_even = isEven(offset);
        bool offset_value_even = isEven(v[offset]);

        if (offset_even != offset_value_even) {

            if (even == offset_even) {
                swap(v[offset], v[i]);
                offset++;
            }
            else {
                ++i;
            }
        }
        else {
            offset++;
            if (i < offset) i = offset;
            else ++i;
        }

    }

    v.resize(offset - (offset % 2) );

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    size_t size;
    cin >> size;

    if (!cin)
        return false;

    vector<int> v(size);
    for (int& x : v) cin >> x;

    resolver(v);

    for (size_t i = 0; i < v.size(); ++i){
        cout << v[i];
        if (i != v.size() - 1) cout << " ";
    }

    cout << endl;

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