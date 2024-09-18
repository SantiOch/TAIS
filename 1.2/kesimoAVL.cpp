
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <memory>
#include <exception>
#include <stdexcept>
using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se ha modificado las funciones privadas de inserta(), otaIzq(), rotaDer() del TreeSet_AVL.h,
 para que tam_i tenga su valor correcto.
 La funcion kesimo comprueba que el valor acumulado al sumar los tam_i segun se va recorriendo los nodos hijos,
 sea igual al valor kesimo. Si es asi se abra encontrado y se devuelve el valor k-esimo.
 El caso especial de que el valor k sea mayor que el numero de elementos o que sea un arbol vacio se controla dentro de resulve caso()
 el valor devuelto es 0

 El coste de la solucion es O(log n) en el peor de los casos, ya que se recorre un arbol que es AVL.
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
   Set<int>tree;
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
      if (k>tree.size()||tree.empty()){
         cout << "??\n";
      }else{
      val = tree.kesimo(k);//O(log n)
         cout << val << endl;
         
      }
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
