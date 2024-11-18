
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
#include <limits>
using namespace std;

#ifndef DOMJUDGE
    #include "../../../Plantillas Juez/teoria/EnterosInf.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "EnterosInf.h" // descomentar para juez
#endif//  #include "EnterosInf.h"  // descomentar para juez

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
const long long int INF = numeric_limits<long long int>::max() - 10000;
struct tCuerda
{
   int longitud;
   int coste;
};

tuple<bool, long long int,long long int,long long int> calcularCuerdas(vector<tCuerda> const &cuerdas, int L){
	vector<long long int>formas(L + 1, 0);
	vector<long long int>cantidades(L + 1, INF);
	vector<long long int>costes(L + 1, INF);
	formas[0] = 1;
	cantidades[0] = 0;
	costes[0] = 0;

	for (int i = 1; i < cuerdas.size(); i++) {
		for (int j = L; j >= cuerdas[i].longitud; j--) {
         formas[j] = formas[j] + formas[j - cuerdas[i].longitud];
         cantidades[j] = min(cantidades[j], cantidades[j - cuerdas[i].longitud] + 1);
         costes[j] = min(costes[j], costes[j - cuerdas[i].longitud] + cuerdas[i].coste);
      }
	}
   return {formas[L] != 0 ? true : false, formas[L], cantidades[L], costes[L]};
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int N,L;
   cin >> N >> L;
   if (!std::cin)  // fin de la entrada
      return false;
   vector<tCuerda> cuerdas(N+1);
   for (int i = 1; i < N+1; i++)
   {
      cin >> cuerdas[i].longitud >> cuerdas[i].coste;
   }
   // resolver el caso posiblemente llamando a otras funciones
   auto [posible, manerasTotales, minimoCuerdas, minimoCoste] = calcularCuerdas(cuerdas, L);
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