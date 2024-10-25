
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

 #include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */
class repartiendoPaquetes
{
private:
  const int INF = numeric_limits<int>::max();
  vector<int> distancias;
  vector<int> distanciasI;
  vector<AristaDirigida<int>> ulti;
   DigrafoValorado<int> grafo;
   DigrafoValorado<int> grafoI;
  IndexPQ<int> pq;
  bool haySolucion;
  int totalCamino;
  void relajar(AristaDirigida<int> a, vector<int>&dist)
  {
     int v = a.desde(), w = a.hasta();
     if (dist[w] > dist[v] + a.valor())
     {
        dist[w] = dist[v] + a.valor();
        ulti[w] = a;
        pq.update(w, dist[w]);
     }
  };
  
   void dijkstra(int origen,vector<int>&dist,DigrafoValorado<int>& g) 
   {
      dist[origen] = 0;
      pq.push(origen, 0);
      while (!pq.empty())
      {
         int v = pq.top().elem;
         pq.pop();
         for (auto a : g.ady(v))
            relajar(a,dist);
      }
   };
public:
   bool hayCamino(){return haySolucion;};
   int camino(){return totalCamino;};
   repartiendoPaquetes(DigrafoValorado<int> g,vector<int>&paqts,int o):grafo(0),grafoI(0), distancias(g.V(),INF),distanciasI(g.V(),INF),pq(g.V()),ulti(g.V()),haySolucion(true),totalCamino(0){
      this->grafo=g;
      grafoI=grafo.inverso();
      dijkstra(o,distancias,grafo);
      dijkstra(o,distanciasI,grafoI);
      for (int i = 0; i < paqts.size(); i++)
      {
         if(distancias[paqts[i]]==INF || distanciasI[paqts[i]]==INF)
            haySolucion=false;
         totalCamino+=distancias[paqts[i]]+distanciasI[paqts[i]];
      }
   };
};
// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
   int o,p;
   DigrafoValorado<int> grafo(cin,1);
   if (!std::cin)  // fin de la entrada
      return false;
   cin>>o>>p;
   vector<int> v(p);
   for (int i = 0; i < p; i++)
   {
      cin>>v[i];
      v[i]=v[i]-1;
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   repartiendoPaquetes r(grafo,v,o-1);
   // escribir la solución
   if(r.hayCamino())
      cout<<r.camino()<<"\n";
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
