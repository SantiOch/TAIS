
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
using namespace std;

 #include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */
 
struct Nodo {
  long long int distN;
  long long int distS;
  long long int diferencia;
  bool operator<(const Nodo b)const {
    return diferencia<b.diferencia;
  }
};
class camiones_reparto
{
private:
  const long long int INF = numeric_limits<long long int>::max();
  vector<long long int> distancias;
  vector<long long int> distanciasI;
  vector<Arista<int>> ulti;
  GrafoValorado<int> grafo;
  IndexPQ<long long int> pq;
  bool haySolucion;
  long long int minimoCoste;
  void relajar(Arista<int> a,int v, vector<long long int>&dist)
  {
      int w = a.otro(v);
     if (dist[w] > dist[v] + a.valor())
     {
        dist[w] = dist[v] + a.valor();
        ulti[w] = a;
        pq.update(w, dist[w]);
     }
  };
  
   void dijkstra(int origen,vector<long long int>&dist,GrafoValorado<int>& g) 
   {
      dist[origen] = 0;
      pq.push(origen, 0);
      while (!pq.empty()){
         int v = pq.top().elem;
         pq.pop();
         for (auto a : g.ady(v))
            if ((origen == 0 && v != g.V() - 1) || (origen == g.V() - 1 && v != 0))
               relajar(a, v, dist);
      }
   };
public:
   bool hayCamino(){return haySolucion;}
   long long int camino(){return minimoCoste;};
   camiones_reparto(GrafoValorado<int> g):grafo(0),distancias(g.V(),INF),distanciasI(g.V(),INF),pq(g.V()),ulti(g.V()),haySolucion(true),minimoCoste(0){
      this->grafo=g;
      dijkstra(0,distancias,grafo);
      dijkstra(g.V()-1,distanciasI,grafo);
      int contN=0,contS=0;
      priority_queue<Nodo>nodos_ordenados;
      for (int i = 1; i < distancias.size()-1; i++)
      {
         nodos_ordenados.push({distancias[i],distanciasI[i],abs(distancias[i]-distanciasI[i])});
      }
      while (!nodos_ordenados.empty())
      {
         Nodo n = nodos_ordenados.top();
         nodos_ordenados.pop();
         if (n.distN < n.distS){
            if (contN < (g.V()-2) / 2){
               contN++;
               minimoCoste += n.distN;
            }
            else{
               contS++;
               minimoCoste += n.distS;
            }
         }
         else{
            if (contS < (g.V()-2) / 2){
               contS++;
               minimoCoste += n.distS;
            }
            else{
               contN++;
               minimoCoste += n.distN;
            }
         }
      }
   }
};
// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
   GrafoValorado<int> grafo(cin,1);
   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   camiones_reparto r(grafo);
   // escribir la solución
      cout<<r.camino()<<"\n";

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
