
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
class ARM_Kruskal {
private:
  int tam;
  int cuerda;
  bool llega;
public:
  
  int longCuerda() const {
    return cuerda;
  }
  
  bool llegaFinal() {
    return llega;
  }
  
  ARM_Kruskal(GrafoValorado<int> const& g) : tam(0), cuerda(0), llega(g.V() == 1) {
    PriorityQueue<Arista<int>> pq(g.aristas());
    ConjuntosDisjuntos cjtos(g.V());
    while (!pq.empty()) {
      auto a = pq.top(); pq.pop();
      int v = a.uno(), w = a.otro(v);
      if (!cjtos.unidos(v,w)) {
        cjtos.unir(v, w);
        tam++;
        cuerda = max(cuerda, a.valor());
        if (tam == g.V() - 1) {
          llega = true;
          break;
        }
      }
    }
  }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int n,p;
  cin>> n >> p;
  
  if (!std::cin)  // fin de la entrada
    return false;
  
  GrafoValorado<int>g(n);
  
  // resolver el caso posiblemente llamando a otras funciones
  int v, w, coste;
  
  for (int i = 0; i < p; i++) {
    cin >> v >> w >> coste;
    g.ponArista({v - 1, w - 1, coste});
  }
  
  ARM_Kruskal tarzan(g);
  
  
  // escribir la solución
  if (tarzan.llegaFinal()) {
    cout << tarzan.longCuerda() << "\n";
  } else cout << "Imposible\n";
  
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
