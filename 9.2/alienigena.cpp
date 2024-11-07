
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// #include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int resolver(vector<pair<int,int>> const& trabajo, int C, int F, bool& imposible) {
   int total = 0, inicio = C, i = 0;
   while (inicio < F && !imposible){
      int aux = inicio;
      while (i < trabajo.size() && trabajo[i].first <= inicio){
         if (trabajo[i].second > aux)
            aux = trabajo[i].second;
         i++;
      }
      if (aux > inicio){
         total++;
         inicio = aux;
      }
      else
         imposible = true;
   }

   return total;
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int C, F, N;
   cin >> C >> F >> N;
   if (C == 0 && F == 0 && N == 0)
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   vector<pair<int, int>> trabajos(N); 
   int c, f;
   for (int i = 0; i < N; i++)
   {
      cin >> c >> f;
      trabajos[i].second = f;
      trabajos[i].first = c; 
   }
   sort(trabajos.begin(), trabajos.end());

   bool imposible = false;
   // resolver el caso posiblemente llamando a otras funciones
   int sol = resolver(trabajos, C, F, imposible);

   // escribir la solución
   if (!imposible)
      cout << sol << "\n";
   else
      cout << "Imposible\n";
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
