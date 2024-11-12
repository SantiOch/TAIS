
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
struct tCuerda
{
   int longitud;
   int coste;
};

tuple<bool, int, int, int> calcularCuerdas(vector<tCuerda> const &cuerdas, int L){
   
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int N,L;
   cin >> N >> L;
   if (!std::cin)  // fin de la entrada
      return false;
   vector<tCuerda> cuerdas(N);
   for (size_t i = 0; i < N; i++)
   {
      cin >> cuerdas[i].longitud >> cuerdas[i].coste;
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   auto[posible,manerasTotales,minimoCuerdas,minimoCoste] = calcularCuerdas(cuerdas,L);
   // escribir la solución
   if (posible)
      cout << "SI " << manerasTotales << " " << minimoCuerdas << " " << minimoCoste << "\n";
   else
      cout << "NO" << "\n";
   
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
