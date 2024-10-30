
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
int victorias(vector<int>&actuales, vector<int>&antiguos){
 
  int totalUsadas = 0;
  int i = 0, j = 0;

  sort(actuales.begin(),actuales.end());
  sort(antiguos.begin(),antiguos.end());
  
  while(i < actuales.size() && j < antiguos.size()) {
    if(actuales[i] == antiguos[j] || actuales[i] + 1 == antiguos[j]) {
      totalUsadas++;
      i++;
      j++;
    }
    else if (actuales[i] > antiguos[j]) j++;
    else i++;
  }
  
  return actuales.size() - totalUsadas;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int n, m;
   cin>>n >> m;
   if (!std::cin)  // fin de la entrada
      return false;
   vector<int>actuales(n);
   vector<int>antiguos(m);
   // resolver el caso posiblemente llamando a otras funciones
   for (int i = 0; i < n; i++)
   {
     cin >> actuales[i];
   }
      
   for (int i = 0; i < m; i++)
   {
     cin >> antiguos[i];
   }
  int sol = victorias(actuales, antiguos);
   // escribir la solución
   cout<<sol<<"\n";
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
