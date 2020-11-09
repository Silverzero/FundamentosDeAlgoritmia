// Marco Desantes Gutiérrez
// E15

#include <vector>
#include <fstream>
#include <iostream>
 
using namespace std;


void resolver(vector<int> const &datos, const int& valoresIguales) {

	int longitud = 0;
	int total_llanos = 0;
	vector<int> posicion_llano;
	int max_longitud = 0;
	int maximo = datos[datos.size() - 1];

	// Recorrido lineal O(n)
	for (int i = datos.size() - 1; i >= 0; --i) {

		if (datos[i] >= maximo) {

			if (datos[i] > maximo) {
				longitud = 1;
				maximo = datos[i];
			}
			else {

				++longitud;

				if (longitud >= valoresIguales) {

					if (longitud == valoresIguales) {
						++total_llanos;
						posicion_llano.push_back(i + (longitud - 1));
					}

					if (longitud > max_longitud)
						max_longitud = longitud;

				}

			}

		}
		else
			longitud = 0;

	}

	cout << max_longitud << " " << total_llanos << " ";

	for (int& i : posicion_llano)
		cout << i << " ";

	cout << endl;

}

bool resuelveCaso() {

	int elementos, valoresIguales;
	cin >> elementos >> valoresIguales;

	if (!cin)
		return false;

	vector<int> datos(elementos);

	for (int& e : datos)
		cin >> e;

	resolver(datos, valoresIguales);

	return true;

}

int main() {

#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
#endif

	return 0;

}