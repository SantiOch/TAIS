
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

 #include "DigrafoValorado.h"  // descomentar para local
 #include "IndexPQ.h"  // descomentar para local

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

template <typename T>
using Camino = vector<T>;

template <typename Valor>
class Dijkstra {
public:
   Dijkstra(DigrafoValorado<Valor> const &g, int orig) : origen(orig),
                                                         dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
      dist[origen] = 0;
      pq.push(origen, 0);
      while (!pq.empty()) {
         int v = pq.top().elem;
         pq.pop();
         for (auto a : g.ady(v))
            relajar(a);
      }
   }

   bool hayCamino(int v) const { return dist[v] != INF; }
   Valor distancia(int v) const { return dist[v]; }
   int camino(int v) const {
      return dist[v];
   }

private:
  const Valor INF = std::numeric_limits<Valor>::max();
  int origen;
   
   vector<Valor> dist;
   vector<AristaDirigida<Valor>> ulti;
   IndexPQ<Valor> pq;
   void relajar(AristaDirigida<Valor> a) {
      int v = a.desde(), w = a.hasta();
      if (dist[w] > max(dist[v], a.valor())) {
         dist[w] = max(dist[v], a.valor());
         ulti[w] = a;
         pq.update(w, dist[w]);
      }
   }
};

bool resuelveCaso() {

   // leer los datos de la entrada
   int n,m;
   cin>>n>>m;
   if (!std::cin)  // fin de la entrada
      return false;
   DigrafoValorado <int>grafo(n);
   int a,b,c;
   for (int i = 0; i < m; i++)
   {
      cin >> a >> b >> c;
      grafo.ponArista({a - 1,b - 1,c});
      grafo.ponArista({b - 1,a - 1,c});
   }
   
   cin>>a>>b;
   // resolver el caso posiblemente llamando a otras funciones
   Dijkstra<int> dj(grafo, a - 1);
   // escribir la solución
   if(dj.hayCamino(b - 1))
      cout<< dj.camino(b - 1) << "\n";
   else
      cout<<"IMPOSIBLE\n";
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
