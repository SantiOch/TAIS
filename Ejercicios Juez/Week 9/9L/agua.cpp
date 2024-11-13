
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

struct Nodo {
  int distN;
  int distS;
  int diferencia;
  bool operator<(const Nodo b)const {
    return diferencia<b.diferencia;
  }
};

class Caminos {
private:
  
  const int INF = numeric_limits<int>::max();
  vector<int> distNor;
  vector<int> distSur;
  GrafoValorado<int> grafo;
  IndexPQ<int> pq;
  
  void relajar(Arista<int> arista, int vertice, bool esPrim) {
    int otroVertice = arista.otro(vertice);

    if (esPrim)
    {
      if (distNor[otroVertice] > distNor[vertice] + arista.valor())
      {
        distNor[otroVertice] = distNor[vertice] + arista.valor();
        pq.update(otroVertice, distNor[otroVertice]);
      }
    }
    else {
      if (distSur[otroVertice] > distSur[vertice] + arista.valor()) {
        distSur[otroVertice] = distSur[vertice] + arista.valor();
        pq.update(otroVertice, distSur[otroVertice]);
      }
    }
  }

  void dijkstra(int origen) {
    bool esPrim = origen == 0;
    if (esPrim) {
      distNor[origen] = 0;
    } else {
      distSur[origen] = 0;
    }
    pq.push(origen, 0);
    while (!pq.empty()) {
      int vertice = pq.top().elem; pq.pop();
      for (auto arista : grafo.ady(vertice)) {
        relajar(arista, vertice, esPrim);
      }
    }
  }
  
public:
  
  Caminos(int numVertices, int numAristas) : grafo(numVertices), distNor(numVertices, INF), distSur(numVertices, INF), pq(numVertices) {
    int vertice1, vertice2, valor;
    for (int i = 0; i < numAristas; i++) {
      cin >> vertice1 >> vertice2 >> valor;
      grafo.ponArista({ vertice1 - 1, vertice2 - 1, valor });
    }
  }

  int minimoAgua(int pueblos) {
    int aguaNorte = 0;
    int aguaSur = 0;
    int total = 0;

    priority_queue<Nodo> ordenados;
    for (int i = 0; i < distNor.size(); i++) {
      ordenados.push({distNor[i], distSur[i], abs(distNor[i] - distSur[i])});
    }

    while(!ordenados.empty()) {
      
      Nodo n = ordenados.top(); ordenados.pop();

      if (n.distN < n.distS) {
        if (aguaNorte < pueblos/2) {
          aguaNorte++;
          total += n.distN;
        } else {
          aguaSur++;
          total += n.distS;
        }
      } else {
        if (aguaSur < pueblos/2) {
          aguaSur++;
          total += n.distS;
        } else {
          aguaNorte++;
          total += n.distN;
        }
      }
    }
    return total;
  }
  
  void numPueblos(int a){
    dijkstra(0);
    dijkstra(a);
  }

};
bool resuelveCaso() {
  
  // leer los datos de la entrada
  int d,p,c,b;
  cin >> d >> p;
  if (!std::cin)  // fin de la entrada
    return false;
  Caminos camino(d,p);
  
  // resolver el caso posiblemente llamando a otras funciones
  camino.numPueblos(d-1);
  camino.minimoAgua(d-1);
  
  // escribir la solución
  cout << camino.minimoAgua(d - 1)<<"\n";
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
