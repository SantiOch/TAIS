
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <limits>
using namespace std;

#ifndef DOMJUDGE
   //  #include "../../../Plantillas Juez/teoria/EnterosInf.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   // #include "EnterosInf.h" // descomentar para juez
#endif
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct tGrupo {
   int tam;
   int coste;
};


int maxNumGrupos(vector<tGrupo> const &grupos, int N, int P) {
   vector<int>cantidades(P + 1, 0);
   for (int i = 1; i <= grupos.size(); i++) {
		for (int j = P; j >= grupos[i-1].coste; j--) {
         cantidades[j] = max(cantidades[j], cantidades[j - grupos[i-1].coste] + grupos[i-1].tam);
      }
	}
   return cantidades[P];
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int p ,n;
   cin >> p >> n;
   if (!std::cin)  // fin de la entrada
      return false;
   vector<tGrupo>grupos(n);
   
   for(int i = 0; i < n; i++) {
      int numero, coste;
      cin >> numero >> coste;
      grupos[i] = { numero, coste };
   }
   // resolver el caso posiblemente llamando a otras funciones
   int sol = maxNumGrupos(grupos, n, p);
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
