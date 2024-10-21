
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

using namespace std;

#include "GrafoValorado.h"
#include "IndexPQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
class Caminos {
private:
    
  const int INF = numeric_limits<int>::max();
    vector<int> dist;
    vector<int> numCam;
    GrafoValorado<int> grafo;
    IndexPQ<int> pq;

    void relajar(Arista<int> arista, int vertice) {
      int otroVertice = arista.otro(vertice);
        
      if (dist[otroVertice] > dist[vertice] + arista.valor()) {
            dist[otroVertice] = dist[vertice] + arista.valor();
            numCam[otroVertice] = numCam[vertice];
            pq.update(otroVertice, dist[otroVertice]);
        } else if (dist[otroVertice] == dist[vertice] + arista.valor()) {
            numCam[otroVertice] += numCam[vertice] ;
        }
    }

    void dijkstra(int origen) {
        dist[origen] = 0;
        numCam[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int vertice = pq.top().elem; pq.pop();
            for (auto arista : grafo.ady(vertice)) {
                relajar(arista, vertice);
            }
        }
    }

public:
    
  Caminos(int numVertices, int numAristas) : grafo(numVertices), dist(numVertices, INF), numCam(numVertices, 0), pq(numVertices) {
        int vertice1, vertice2, valor;
        for (int i = 0; i < numAristas; i++) {
            cin >> vertice1 >> vertice2 >> valor;
            grafo.ponArista({ vertice1 - 1, vertice2 - 1, valor });
        }
    }

    int numCaminos() {
        dijkstra(0);
        return numCam[grafo.V() - 1];
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numVertices, numAristas;
    cin >> numVertices >> numAristas;
    if (!cin)  // fin de la entrada
        return false;
    
    Caminos caminos(numVertices, numAristas);
    cout << caminos.numCaminos() << '\n';
   
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
