
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
#include <unordered_map>
using namespace std;

#ifndef DOMJUDGE
    #include "../../../Plantillas Juez/teoria/Matriz.h"  // descomentar para local
    #include "../../../Plantillas Juez/teoria/EnterosInf.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "Matriz.h" // descomentar para juez
   #include "EnterosInf.h" // descomentar para juez
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
EntInf maximoGrado(Matriz<EntInf> &matriz) {
   int n = matriz.numfils();
   for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (matriz[i][k] + matriz[k][j] < matriz[i][j]) {
               matriz[i][j] = matriz[i][k] + matriz[k][j];
            }
         }
      }
   }
   EntInf max = 0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (matriz[i][j] == Infinito) {
            return Infinito;
         }
         max = std::max(max, matriz[i][j]);
      }
   }
   return max;
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int p, r;
   cin >> p >> r;
   if (!std::cin)  // fin de la entrada
      return false;
   unordered_map<string, int> personas;
   Matriz<EntInf> matriz(p, p, Infinito);
   for (int i = 0; i < r; i++) {
      string p1, p2;
      cin >> p1 >> p2;
      if (personas.count(p1) == 0) {
         personas[p1] = personas.size();
      }
      if (personas.count(p2) == 0) {
         personas[p2] = personas.size();
      }
      matriz[personas[p1]][personas[p2]] = 1;
      matriz[personas[p2]][personas[p1]] = 1;
   }
   //rellenamos diagonal de ceros
   for (int i = 0; i < p; i++) {
      matriz[i][i] = 0;
   }
   // resolver el caso posiblemente llamando a otras funciones
   EntInf sol=maximoGrado(matriz);
   // escribir la solución
   if(sol==Infinito){
      cout << "DESCONECTADA\n";
   }else{
      cout << sol << '\n';
   }
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
