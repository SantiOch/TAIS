
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <unordered_set>
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

long long int resolver(int num, int suma) {
   
  long long int sumatorio = 0;
  long long int mitad = suma / 2;
  long long int restantes = 0;
  
  if(num > mitad) {
    
    sumatorio += (mitad * (mitad + 1)) / 2;
    restantes = num - mitad;
    
    long long int m = suma;
    long long int n = suma + restantes - 1;
    
    sumatorio += ((n * n - m * m + n + m) / 2);
    
  } else sumatorio += ((num * (num + 1)) / 2);
  
  return sumatorio;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int n,s;
   cin >> n >> s;
   if (!std::cin)  // fin de la entrada
      return false;
   long long int sol;
   // resolver el caso posiblemente llamando a otras funciones
   sol = resolver(n,s);
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
