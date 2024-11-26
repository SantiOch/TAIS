
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#ifndef DOMJUDGE
    #include "../../../Plantillas Juez/teoria/Matriz.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "Matriz.h" // descomentar para juez
#endif
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int come(Matriz<int> & matriz, const vector<int>& cubos,const int i,const int j) {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	if (matriz[i][j] != -1) return matriz[i][j];

	if (i == j) matriz[i][j] = cubos[i];
	else if (i > j) matriz[i][j] = 0;
	else {
		if (cubos[i + 1] > cubos[j]) {
			x1 = i + 2; y1 = j;
		}
		else {
			x1 = i + 1; y1 = j - 1;
		}
		if (cubos[j - 1] > cubos[i]) {
			y2 = j - 2; x2 = i;
		}
		else {
			x2 = i + 1; y2 = j - 1;
		}

		 matriz[i][j] = max(cubos[i] + come(matriz, cubos, x1, y1), cubos[j] + come( matriz, cubos, x2, y2));
	}
	return  matriz[i][j];
}
bool  resuelveCaso() {

	int N;
	cin >> N;
	if (N == 0) return false;
	vector<int> cubos(N);
	for (int i = 0; i < N; i++) {
		cin >> cubos[i];
	}

	Matriz<int> matriz(N+1,N+1,-1);
	cout << come( matriz, cubos, 0, N - 1) << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
