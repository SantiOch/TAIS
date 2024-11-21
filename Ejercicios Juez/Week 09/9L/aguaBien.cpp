
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "DigrafoValorado.h"
#include "IndexPQ.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */
 

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig), dist(g.V(), INF), pq(g.V()) {
		dist[origen] = 0;
		pq.push(origen, 0);

		while (!pq.empty()) {
			long long int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}

	Valor distancia(long long int v) {
		return dist[v];
	}

private:
	const Valor INF = std::numeric_limits<Valor>::max();
	long long int origen;
	std::vector<Valor> dist;
	IndexPQ<Valor> pq;
	void relajar(AristaDirigida<Valor> a) {
		long long int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
		}
	}
};

struct resta {
	long long int diferencia;
	long long int vertice;

	bool operator<(const resta& otro) {
		return diferencia > otro.diferencia;
	}
};

bool resuelveCaso() {
	long long int N, M;
	cin >> N >> M;

	if (!std::cin)  // fin de la entrada
		return false;

	DigrafoValorado<long long int> g(N);
	long long int v, w, valor;
	for (int i = 0; i < M; i++) {
		cin >> v >> w >> valor;
		g.ponArista({ v - 1, w - 1, valor });
		g.ponArista({ w - 1, v - 1, valor });
	}

	Dijkstra<long long int> d1(g, 0);
	Dijkstra<long long int> d2(g, N - 1);

	vector<resta> diferencias(N-2);

	long long int camiones1 = (N - 2) / 2;
	long long  int camiones2 = (N - 2) / 2;
	
	for (int i = 1; i < N - 1; i++) {
		diferencias[i - 1] = {abs(d1.distancia(i)- d2.distancia(i)), i};
	}

	sort(diferencias.begin(), diferencias.end());

	long long int coste = 0;

	for (int i = 0; i < diferencias.size(); i++) {
		if (camiones1 > 0 && d1.distancia(diferencias[i].vertice) < d2.distancia(diferencias[i].vertice)) {
			camiones1--;
			coste += d1.distancia(diferencias[i].vertice) * 2;
		}
		else if (camiones2 > 0 && d2.distancia(diferencias[i].vertice) < d1.distancia(diferencias[i].vertice)) {
			camiones2--;
			coste += d2.distancia(diferencias[i].vertice) * 2;
		}
		else if (camiones1 > 0) {
			coste += d1.distancia(diferencias[i].vertice) * 2;
		}
		else if (camiones2 > 0) {
			coste += d2.distancia(diferencias[i].vertice) * 2;
		}
	}

	cout << coste << '\n';

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
