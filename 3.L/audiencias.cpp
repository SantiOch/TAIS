
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

#include "IndexPQ.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct canal {
   int minutos;
   int numero;
};

bool operator<(const canal &c1, const canal &c2) {
   return c1.minutos < c2.minutos || (c1.minutos == c2.minutos && c1.numero > c2.numero);
}

bool resuelveCaso() {
   int d,c,n;

   // leer los datos de la entrada
   cin >> d;
   if (!std::cin)  // fin de la entrada
      return false;
   cin >> c >> n;
   // resolver el caso posiblemente llamando a otras funciones
   IndexPQ<int, greater<int>> canales(c);
   vector<canal> minutos;
   int p;
   
   for (int i = 0; i < c; i++) {
      cin >> p;
      canales.push(i, p);
      minutos.push_back({0,i + 1});
   }

   // escribir la solución
   int anterior = 0, actual;
   for(int i = 0; i < n; i++) {
     
       cin >> actual;

      int num, audiencia;

      cin >> num;

      minutos[canales.top().elem].minutos += actual - anterior;

      while (num != -1) {
         cin >> audiencia;
         canales.update(num - 1, audiencia);
         cin >> num;
      }
      anterior = actual;
   }

   minutos[canales.top().elem].minutos += d - anterior;
   
   priority_queue<canal> salida;
   for (int i = 0; i < c; i++) {
      salida.push(minutos[i]);
   }
   
   for (int i = 0; i < c; i++) {
      canal c = salida.top();
      salida.pop();
      if (c.minutos != 0) cout << c.numero << " " << c.minutos << "\n";
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
