
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
#include <list>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
#include <queue>

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
class MejorCamino {
private:
  const int INF = numeric_limits<int>::max();
  vector<int> distanciaBFS;
  vector<pair<int, int>> distancias;
  GrafoValorado<int> grafo;
  IndexPQ<pair<int, int>> pq;
  
  void relajar(Arista<int> calle, int interseccion) {
    int otraInterseccion = calle.otro(interseccion);
    if (distancias[otraInterseccion].first > distancias[interseccion].first + calle.valor()) {
      distancias[otraInterseccion].first = distancias[interseccion].first + calle.valor();
      distancias[otraInterseccion].second = distancias[interseccion].second + 1;
      pq.update(otraInterseccion, distancias[otraInterseccion]);
    }
    else if (distancias[otraInterseccion].first == distancias[interseccion].first + calle.valor() &&
             distancias[otraInterseccion].second > distancias[interseccion].second + 1) {
      distancias[otraInterseccion].second = distancias[interseccion].second + 1;
      pq.update(otraInterseccion, distancias[otraInterseccion]);
    }
  }
  
  void Dijkstra(int origen) {
    distancias[origen] = {0, 0};
    pq.push(origen, {0, 0});
    while (!pq.empty()) {
      int interseccion = pq.top().elem;
      pq.pop();
      for (auto calle : grafo.ady(interseccion))
        relajar(calle, interseccion);
    }
  }
  
  void bfs(int origen) {
    distanciaBFS[origen] = 0;
    queue<int> cola;
    cola.push(origen);
    while (!cola.empty()) {
      int interseccion = cola.front();
      cola.pop();
      for (auto calle : grafo.ady(interseccion)) {
        int otraInterseccion = calle.otro(interseccion);
        if (distanciaBFS[otraInterseccion] == INF) {
          distanciaBFS[otraInterseccion] = distanciaBFS[interseccion] + 1;
          cola.push(otraInterseccion);
        }
      }
    }
  }
  
public:
  bool hayCamino(int destino) {
    return distanciaBFS[destino] != INF;
  }
  
  int distancia(int destino) {
    return distancias[destino].first;
  }
  
  bool esMejorDistancia(int destino) {
    return distancias[destino].second == distanciaBFS[destino];
  }
  
  MejorCamino(GrafoValorado<int> grafo, int n, int origen) : grafo(0), distanciaBFS(n, INF), pq(n), distancias(n, {INF, 0}) {
    this->grafo = grafo;
    bfs(origen);
    Dijkstra(origen);
  }
};

bool resuelveCaso() {
  // leer los datos de la entrada
  int numIntersecciones, numCalles;
  cin >> numIntersecciones >> numCalles;
  if (!cin)  // fin de la entrada
    return false;
  int interseccion1, interseccion2, longitud;
  GrafoValorado<int> ciudad(numIntersecciones);
  for (int i = 0; i < numCalles; ++i) {
    cin >> interseccion1 >> interseccion2 >> longitud;
    ciudad.ponArista({ interseccion1 - 1, interseccion2 - 1, longitud });
  }
  
  int numConsultas;
  cin >> numConsultas;
  while (numConsultas != 0) {
    int origen, destino;
    cin >> origen >> destino;
    MejorCamino camino(ciudad, numIntersecciones, origen - 1);
    if (camino.hayCamino(destino - 1)) {
      cout << camino.distancia(destino - 1) << " ";
      if (camino.esMejorDistancia(destino - 1)) {
        cout << "SI\n";
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "SIN CAMINO\n";
    }
    numConsultas--;
  }
  
  cout << "---\n";
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
