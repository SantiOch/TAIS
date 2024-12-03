
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

#ifndef DOMJUDGE
    #include "Matriz.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "Matriz.h" // descomentar para juez
#endif
/*@ <answer>

   El problema se resuelve con programacion dinamica de forma recursiva, N es el numero de caracteres de la palabra.
   Siendo N == j en la recurrencia, para la forma general.
   Siendo i  el inicio de la palabra en la recurrencia, para la foma general.
   Por lo tanto, i el inicio de la subpalabra y j el final de la subpalabra.

   *Definicion
   Aibofobia(i,j)=Aibofobia(i+1,j-1) === cantidad minima de caracteres que se deben añadir para que la palabra final sea un palindromo
   *Casos base
   Aibofobia(i,j)=0 si i==j //intervalo cerrado
   Aibofobia(i,j)=0 si i+1==j //intervalo abierto

   *Casos recursivos
   Aibofobia(i,j)=|Aibofobia(i+1,j-1) si palabra[i]==palabra[j]
                  |1+min(Aibofobia(i+1,j),Aibofobia(i,j-1)) si palabra[i]!=palabra[j]

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
const int INF = 1000000000;

int minCuts(const vector<int> &cuts, int length) {
  int n = cuts.size();
  Matriz<int> dp(n, n, 0);

  for (int d = 2; d <= n; d++) {
    for (int i = 0; i < n - d; i++) {
      int j = i + d;
      int minCost = INF;
      for (int k = i + 1; k < j; k++) {
        minCost = min(minCost, dp[i][k] + dp[k][j] + (2 * (cuts[j] - cuts[i])));
      }
      dp[i][j] = minCost;
    }
  }

  return dp[0][n - 1];
}

bool resuelveCaso() {
  int length, numCuts;

  cin >> length >> numCuts;

  if (length == 0 && numCuts == 0)
    return false;

  vector<int> cuts(numCuts + 2, 0);
  cuts[0] = 0;
  cuts[numCuts + 1] = length;

  for (int i = 1; i <= numCuts; i++) {
    cin >> cuts[i];
  }

  cout << minCuts(cuts, length) << "\n";

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
