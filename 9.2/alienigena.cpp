
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
#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

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
   int C,F,N;
   cin >>C>>F>>N;
   if (C == 0 && F == 0 && N == 0)
      return false;


   // resolver el caso posiblemente llamando a otras funciones
   ConjuntosDisjuntos intervalo(F-C);
   int c, f;
   for (int i = 0; i < N; i++)
   {
      cin>>c>>f;
      if(c<C)c=0;
      else c=c-C;
      if(f>F)f=F-C;
      else f=f-C;
      if(!intervalo.unidos(c,f-1))
         intervalo.unir(c,f-1);
   }
   
   // escribir la solución

   bool encontrado = false, descartado = false;
   int i = 0,cont=0;
   while (!encontrado && !descartado)
   {
      int j = intervalo.buscar(i);
      if (j == i && j != F - C)
         descartado = true;
      else if (j == F - C)
         encontrado = true;
      else
         i = j + 1;

      cont++;
   }
   if(encontrado)cout<<cont<<"\n";
   else cout<<"IMPOSIBLE\n";
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
