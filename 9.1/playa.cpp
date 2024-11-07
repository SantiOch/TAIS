
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

// #include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Hotel {
  int oeste;
  int este;
  
  bool operator<(const Hotel& otro) const {
    return este < otro.este || (este == otro.este && oeste < otro.oeste);
  }
};

int resolver(vector<Hotel>& hoteles) {
  
  sort(hoteles.begin(), hoteles.end());
  
  int total = 1;
  int fin = hoteles[0].este;
  
  for(int i = 1; i < hoteles.size(); i++) {
    if(hoteles[i].oeste >= fin) {
      total++;
      fin = hoteles[i].este;
    }
  }
  
  return total;
}

bool resuelveCaso() {

   // leer los datos de la entrada
  int n;
  cin >> n;
  if (n == 0)  // fin de la entrada
      return false;
   
  vector<Hotel> hoteles(n);
  
  for(int i = 0; i < n; i++) {
    cin >> hoteles[i].oeste >> hoteles[i].este;
  }
  
  int sol;
   // resolver el caso posiblemente llamando a otras funciones
   sol = resolver(hoteles);
   // escribir la solución
   cout << sol << "\n";
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
