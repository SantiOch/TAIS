
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

bool es_valida(int i, int j, int f, int c){
   return i>=0 && i<f && j>=0 && j<c;
}

void recorrer_contiguos(int a, int b, int f, int c, ConjuntosDisjuntos&manchas,unordered_set<int>&representantes,int &tam){
   bool es_nuevo=true;
   for (int i = a-1; i <= a+1; i++)
   {
      for(int j = b-1; j <= b+1; j++)
      {
         if(es_valida(i, j, f, c))
         {
            int r=manchas.buscar(i*c+j);
            if(representantes.count(r)!=0){
               es_nuevo=false;
               manchas.unir(a*c+b, r);
               tam=max(manchas.cardinal(r),tam);
            }
         }
      }
   }
   if (es_nuevo)
   {
      representantes.insert(a * c + b);
   }
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int f, c;
   cin >> f >> c;
   if (!std::cin)  // fin de la entrada
      return false;
   ConjuntosDisjuntos manchas(f*c);
   unordered_set<int>representantes;
   char casilla;
   int tam_maximo=0;
   for (int i = 0; i < f; i++)
   {
      for (int j = 0; j < c; j++)
      {
         cin >> casilla;
         if(casilla=='#')
         {
            recorrer_contiguos(i, j, f, c, manchas, representantes, tam_maximo);
         }
      }
      
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   int n;
   cin >> n;
   cout << tam_maximo << ' ';
   for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      recorrer_contiguos(a-1, b-1, f, c, manchas, representantes, tam_maximo);
      cout << tam_maximo << ' ';
   }
   cout << '\n';
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
