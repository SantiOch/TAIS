/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"

using namespace std;

/*@ <answer>
 
 @ </answer> */

// ================================================================
// Código de la solución
// ================================================================
//@ <answer>

int dadosMatriz(int carasDado, int numeroTotal) {
  
  Matriz<int> sol(numeroTotal + 1, carasDado + 1, 0);
  
  // Caso base
  for (int i = 0; i <= carasDado; i++) sol[0][i] = 1;
  
  for (int i = 1; i <= numeroTotal; i++) {
    for (int j = 1; j <= carasDado; j++) {
      sol[i][j] = sol[i][j - 1]; // No uso el numero j
      if (i >= j) {
        sol[i][j] = sol[i][j] + sol[i - j][j]; // Uso el numero j
      }
    }
  }
  
  return sol[numeroTotal][carasDado];
}

int dadosVector(int carasDado, int numeroTotal) {
  
  vector<int> sol(numeroTotal + 1, 0);
  
  // Caso base
  sol[0] = 1;
  
  for (int i = 1; i <= carasDado; i++) {
    for (int j = i; j <= numeroTotal; j++) {
      sol[j] += sol[j - i];
    }
  }
  
  return sol[numeroTotal];
}

bool resuelveCaso() {
  
  int carasDado, numeroTotal;
  cin >> carasDado >> numeroTotal;

  //  int beneficio1 = dadosMatriz(carasDado, numeroTotal);
  int beneficio2 = dadosVector(carasDado, numeroTotal);
  
  // Imprimir la solución
  //  cout << beneficio1 << "\n";
  cout << beneficio2 << "\n";
  
  return true;
}

void resuelveFor() {
  int numCasos;
  cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
}

void resuelveWhile() {
  while(resuelveCaso());
}

int main() {
  
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  resuelveFor();
  
  
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}


//@ </answer>
// Lo que se escriba dejado de esta lÌnea ya no forma parte de la soluciÛn.
