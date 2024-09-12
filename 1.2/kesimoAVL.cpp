
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * Alex Guillermo Bonilla Taco TAIS009
 * Santiago Ochoa de Zabalegui Velasco TAIS069
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

#include "set_tree.h"  // propios o los de las estructuras de datos de clase

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
   int n;
   cin>>n;
   if (n==0)
      return false;
   SetTree<int>tree;
   int elem;
   for (int i = 0; i < n; i++)
   {
      cin>>elem;
      tree.insert(elem);
   }

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   cin>>n;
   int k;
   int val;
   for (int i = 0; i < n; i++)
   {
      cin>>k;
      val = tree.kesimo(k);
      if (val != 0)
         cout << val << endl;
      else
         cout << "??\n";
   }
   cout<<"---\n";

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
