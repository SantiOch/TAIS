
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#ifndef DOMJUDGE
#include "../../../Plantillas Juez/teoria/Digrafo.h" // descomentar para local
#endif
#ifdef DOMJUDGE
#include "Digrafo.h" // descomentar para juez
#endif
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using Camino = vector<int>;

class CicloDirigido
{
public:
   CicloDirigido(Digrafo const &g) : visit(g.V(), false), ant(g.V()),
                                     apilado(g.V(), false), imposible(false)
   {
      for (int v = 0; v < g.V(); ++v)
         if (!visit[v])
            dfs(g, v);
   }
   bool esImposible() const { return imposible; }
   Camino const &ciclo() const { return _ciclo; }

private:
   std::vector<bool> visit;   // visit[v] = ¿se ha alcanzado a v en el dfs?
   std::vector<int> ant;      // ant[v] = vértice anterior en el camino a v
   std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
   Camino _ciclo;             // ciclo dirigido (vacío si no existe)
   bool imposible;
   void dfs(Digrafo const &g, int v)
   {
      apilado[v] = true;
      visit[v] = true;
      for (int w : g.ady(v))
      {
         if (!visit[w]) { // encontrado un nuevo vértice, seguimos
            ant[w] = v;
            dfs(g, w);
         }
         else if (apilado[w])
         { // hemos detectado un ciclo
            // se recupera retrocediendo

            int cont = 0;
            for (int x = v; x != w; x = ant[x])
               cont++;

            if (cont % 2 == 1) {
               imposible = true;
               break;
            }
         }
      }
      apilado[v] = false;
   }
};

bool resuelveCaso()
{

   // leer los datos de la entrada
   int n, m;
   cin >> n >> m;
   if (!std::cin) // fin de la entrada
      return false;
   Digrafo grafo(n);
   int a,b;
   
   for (int i = 0; i < m; i++)
   {
      cin>>a>>b;
      grafo.ponArista(a-1,b-1);
      grafo.ponArista(b-1,a-1);
   }
   
   // resolver el caso posiblemente llamando a otras funciones

   bool sol = CicloDirigido(grafo).esImposible();
   // escribir la solución
   if (sol)
      cout << "SI\n";
   else
      cout << "NO\n";
   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso())
      ;

      // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
