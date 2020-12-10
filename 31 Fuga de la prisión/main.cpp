#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

/*
 * Complejidad: O( n * log(n) )
 */

char resolver(const std::vector<char>& v, const int& left, const int& right) {

	if (left + 1 == right)
		return v[left] + 1;
	else {
		
		int middle = (right + left) / 2;

		if ( (v[left] - left) != (v[middle] - middle) )
			return resolver(v, left, middle);
		else
			return resolver(v, middle, right);
	}

}

void resuelveCaso() {

	char last;
	char first;

	cin >> first >> last;

	vector<char> v(last - first);

	for (char& x : v) cin >> x;

	if (v[0] != first)
		cout << first << endl;
	else if (v[v.size() - 1] != last)
		cout << last << endl;
	else
		cout << resolver(v, 0, v.size() - 1) << endl;

}

int main() {

#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	int cases;
	cin >> cases;

	for (int i = 0; i < cases; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
#endif
	return 0;
}