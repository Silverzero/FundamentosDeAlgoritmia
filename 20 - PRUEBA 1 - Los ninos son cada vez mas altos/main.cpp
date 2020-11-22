// Marco Desantes Gutierrez
// E15
// E27
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
//*******************************
// Aqui especificación de la función que resuelve el problema.
// No hay que especificar
//
//
// Aqui la justificación del coste de la función que resuelve el problema
//
// Se recorre el vector de entrada v para crear el vector de acumulados, que va a ser de tamaño medidaMax + 1,
// por lo que el recorrido del vector de entrada es lineal, luego se hacen 2 recorridos pero el coste sigue siendo N
// ya que una aprte del bucle es de 0 a interval ya que es para inicializar nuestras variables libre actual y max
// luego recorremos de interval a size y vamos restando el de la izq y sumando el de la derecha para conseguir un coste lineal
//
//*******************************
// Aqui la función implementada por el alumno
// Coste O(n) que seria la suma de coste lineal de recorrer v[] + w[]
int resolver(vector<int> const& v, int const& size, int const& interval) {
	//si supiesemos la cota menor de altura se podria optimizar
	vector<int> w(size + 1, 0);
	// coste O(n) donde n es el numero de elementos del vecor de entrada
	for (int x : v) {
		w[x] += 1;
	}
	// coste O(n) siendo n el tamaña del vector definido por la variable del programa size o medidaMax en el main();
	int max = 0;
	// de 0 a interval
	for (int i = 0; i < interval; ++i) {
		max += w[i];
	}
	int actual = max;
	// de interval a size

	for (int i = interval; i < w.size(); ++i) {
		actual = actual - w[i - interval] + w[i];
		if (actual > max) max = actual;
	}
	return max;
}

bool resuelveCaso() {
	int numMedidas, medidaMax, longIntervalo;
	cin >> numMedidas >> medidaMax >> longIntervalo;
	if (numMedidas == -1) return false;
	vector<int> v(numMedidas);
	for (int& i : v) std::cin >> i;
	// LLamada a la funcion que resuelve el problema
	int sol = resolver(v, medidaMax, longIntervalo);
	// Escribir el resultado
	cout << sol << endl;
	return true;
}
int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso())
		;
	// Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}