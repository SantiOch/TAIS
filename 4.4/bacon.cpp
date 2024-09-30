
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

 #include "grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
   int p;
   cin>>p;
   if (!std::cin)  // fin de la entrada
      return false;
   unordered_map<string,unordered_set<string>>grafo;
   string pelicula,actor;
   int num_act;
   for (int i = 0; i < p; i++)
   {
      cin>>pelicula;
      grafo.insert_or_assign(pelicula);
      cin>>num_act;
      unordered_set<string>actores_pelicula;
      for (int j = 0; j < num_act; j++)
      {
         cin>>actor;
         actores_pelicula.insert(actor);

      }
      
   }
   
   // resolver el caso posiblemente llamando a otras funciones

   // escribir la solución

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
