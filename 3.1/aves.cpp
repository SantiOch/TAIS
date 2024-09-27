
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

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
   long long int edad, parejas;

   cin >> edad >> parejas;

   if (edad == 0 && parejas == 0)
      return false;

   priority_queue<long long int> mini;
   priority_queue<long long int,vector<long long int>, greater<long long int>> maxi;
   
   maxi.push(edad);

   for (long long int i = 0; i < parejas; i++) {
      long long int p1, p2, medio;
      cin >> p1 >> p2;
      medio = maxi.top();
      if(p1 < medio)
         mini.push(p1);
      else maxi.push(p1);
      
      if(p2 < medio)
         mini.push(p2);
      else maxi.push(p2);
     
     long long int tamMaxi, tamMini;
     tamMaxi = maxi.size();
     tamMini = mini.size();
      
     while(abs(tamMaxi - tamMini) > 1) {
         long long int topDeLaColaQueToque;
         if (maxi.size() > mini.size()) {
            topDeLaColaQueToque = maxi.top();
            maxi.pop();
            mini.push(topDeLaColaQueToque);
         } else {
            topDeLaColaQueToque = mini.top();
            mini.pop();
            maxi.push(topDeLaColaQueToque);
         }
         tamMaxi = maxi.size();
         tamMini = mini.size();
      }
      long long int mostrar = (maxi.size() > mini.size()) ? maxi.top(): mini.top();
      cout << mostrar << " ";
   }
   cout << "\n";
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
