
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <limits>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>
 
 Para resolver el problema, creamos un grafo valorado con los datos de entrada,
 siendo los vertices los pueblos, y las aristas son las carreteras que unen
 los pueblos. Despues, leemos los pueblos de origen, hacemos un solo dijkistra 
 metiendo al comienzo de la cola todos los origenes con distancia cero.
 Despues de relajar comprobaremos si la distancia al otro vertice es menor o
 igual que la distancia maxima permitida y guardamos el nodo en un unoredered_set llamado visitados.
 Por ultimo, mostramos por pantalla, la solucion que es el tamaño del unoredered_set visitados.
 
 El coste es de O((A log V)+((V+v.size()) log V)), siendo A las aristas del grafo, V los vertices por teoria y v.size()
 el numero de vertices de origen que metemos en la cola. Por lo tanto el coste sera el maximo entre O(A log V) y O((V+v.size()) log V)
 El coste en espacio adicional es de O(V);
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Caminos {
private:
  
  const int INF = numeric_limits<int>::max();
  vector<int> dist;
  GrafoValorado<int> grafo;
  IndexPQ<int> pq;
  unordered_set<int> visitados;
  int distMax;
  
  void relajar(Arista<int> arista, int vertice) {
    int otroVertice = arista.otro(vertice);
    
    if (dist[otroVertice] > dist[vertice] + arista.valor()) {
      dist[otroVertice] = dist[vertice] + arista.valor();
      pq.update(otroVertice, dist[otroVertice]);
    }
  }
  
  void dijkstra(vector<int> origenes) {
    dist = vector<int>(grafo.V(), INF);
    for(int origen: origenes) {
      if (!visitados.count(origen)) visitados.insert(origen);
      dist[origen] = 0;
      pq.push(origen, 0);
    }
    while (!pq.empty()) {
      int vertice = pq.top().elem; pq.pop();
      for (auto arista : grafo.ady(vertice)) {
        relajar(arista, vertice);
        if(dist[arista.otro(vertice)] <= distMax && !visitados.count(arista.otro(vertice))) {
          visitados.insert(arista.otro(vertice));
        }
      }
    }
  }
  
public:
  
  Caminos(int numVertices, int numAristas,int dist) : grafo(numVertices), dist(numVertices, INF), pq(numVertices),distMax(dist) {
    int vertice1, vertice2, valor;
    for (int i = 0; i < numAristas; i++) {
      cin >> vertice1 >> vertice2 >> valor;
      grafo.ponArista({ vertice1 - 1, vertice2 - 1, valor });
    }
  }
  
  void numPueblos(vector<int> a){
    dijkstra(a);
  }
  int numPueblosTotales(){
    return visitados.size();
  }
};
bool resuelveCaso() {
  
  // leer los datos de la entrada
  int d,p,c,b;
  cin >> d >> p >> c;
  if (!std::cin)  // fin de la entrada
    return false;
  Caminos camino(p,c,d);
  cin >> b;
  // resolver el caso posiblemente llamando a otras funciones
  vector<int> v;
  for (int i = 0; i < b; i++) {
    int a;
    cin >> a;
    v.push_back(a - 1);
  }
  
  camino.numPueblos(v);
  
  // escribir la solución
  cout << camino.numPueblosTotales()<<"\n";
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
