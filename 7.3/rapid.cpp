
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
template <typename Valor>
class Dijkstra
{
public:
   Dijkstra(GrafoValorado<Valor> const &g, int orig) : origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
      dist[origen] = 0;
      pq.push(origen, 0);
      while (!pq.empty())
      {
         int v = pq.top().elem;
         pq.pop();
         for (auto a : g.ady(v))
            relajar(a);
      }
   }

   bool hayCamino(int v) const { return dist[v] != INF; }
   
   Valor distancia(int v) const { return dist[v]; }
   
   string camino(int ini,int fin){
      Arista<Valor> a;
      list<string> cam;
      for (a = ulti[fin]; a.uno() != ini; a = ulti[a.otro(a.uno())]) {
         cam.push_front(to_string(a.uno()));
         cam.push_front(" -> ");
      }
      cam.push_front(to_string(fin));
      
      string ret = "";
      for(string s: cam) {
         ret.append(s);
      }

      return ret;
   }

private:
   const Valor INF = std::numeric_limits<Valor>::max();
   int origen;
   std::vector<Valor> dist;
   std::vector<Arista<Valor>> ulti;
   IndexPQ<Valor> pq;
   void relajar(Arista<Valor> a)
   {
      int v = a.uno(), w = a.otro(v);
      if (dist[w] > dist[v] + a.valor())
      {
         dist[w] = dist[v] + a.valor();
         ulti[w] = a;
         pq.update(w, dist[w]);
      }
   }
};
bool resuelveCaso() {

   // leer los datos de la entrada
   int n,c,k,ini,fin;
   cin>>n>>c;
   if (!std::cin)  // fin de la entrada
      return false;
   GrafoValorado<int> g(n);
   int a, b, v;
   for(int i=0;i<c;i++){
      cin>>a>>b>>v;
      g.ponArista({a-1,b-1,v});
   }

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   cin>>k;
   for(int i=0;i<k;i++){
      cin>>ini>>fin;
      Dijkstra<int> d(g,ini-1);
      if(d.hayCamino(fin-1)){
         cout<<d.distancia(fin-1)<<": ";
         cout<<d.camino(ini-1,fin-1)<<"\n";
      }else{
         cout<<"NO LLEGAN\n";
      }
      
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
