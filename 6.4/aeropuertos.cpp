
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
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
template <typename Valor>
class ARM_Kruskal
{
private:
   std::vector<Arista<Valor>> _ARM;
   Valor coste;
   int numero_cjtos;
public:
   Valor costeARM() const {
      return coste;
   }
  
   int num_cjtos(){
      return numero_cjtos;
   }
   std::vector<Arista<Valor>> const &ARM() const {
      return _ARM;
   }
   ARM_Kruskal(GrafoValorado<Valor> const &g) : coste(0)
   {
       PriorityQueue<Arista<Valor>> pq(g.aristas());
      ConjuntosDisjuntos cjtos(g.V());
      while (!pq.empty()) {
         auto a = pq.top();
         pq.pop();
         int v = a.uno(), w = a.otro(v);
         if (!cjtos.unidos(v, w)) {
            cjtos.unir(v, w);
            _ARM.push_back(a);
            coste += a.valor();
            if (_ARM.size() == g.V() - 1){
                break;
            }
         }
      }
      numero_cjtos=cjtos.num_cjtos();
   }
};

bool resuelveCaso() {
   int n,m,a;
   cin >> n >> m >> a;
   // leer los datos de la entrada
   if (!std::cin)  // fin de la entrada
      return false;
   GrafoValorado<int> g(n);
   // resolver el caso posiblemente llamando a otras funciones
   int x,y,c;
   for (int i = 0; i < m; i++)
   {
      cin >> x >> y >> c;
      if(c<a){  
      g.ponArista({x-1,y-1,c});
      }
   }
   ARM_Kruskal arm_k(g);
   // escribir la solución
   int coste=arm_k.costeARM()+arm_k.num_cjtos()*a;

   cout << coste << " " << arm_k.num_cjtos() << "\n";
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
