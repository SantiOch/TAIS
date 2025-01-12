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
  
  -------------------------------------------- Comentario general -------------------------------------------

  El problema se resuelve con programacion dinamica, ya que podemos ver que el problema
  se puede dividir en subproblemas mas pequeños (llegar al mismo numero con un dado de menos caras).
  Se ha implementado la solucion con dos funciones, una que usa una matriz y otra que usa un vector, 
  siendo esta ultima mas eficiente en espacio.
  
  --------------------------------------------- Llamada inicial ---------------------------------------------

  La llamada inicial es dadosVector(carasDado, numeroTotal). Siendo carasDado el numero de caras del dado
  y numeroTotal el numero al que queremos llegar.

  ----------------------------------------------- Definicion ------------------------------------------------

  dados(i, j) es el numero de formas de llegar al numero j con un dado de i caras.
  
  ------------------------------------------------ Caso base ------------------------------------------------

  dados(0, 0) = 1 -> Si no hay caras, solo hay una forma de llegar al 0
  dados(i, 0) = 1 -> Si queremos llegar al 0, solo hay una forma de hacerlo, no usar ninguna cara
  dados(0, j) = 0 -> Si no hay caras, no hay forma de llegar a un numero distinto de 0

  --------------------------------------------- Caso Recursivo ----------------------------------------------

  dados(i, j) = dados(i, j - 1) + dados(i - 1, j - i) si i <= j
  dados(i, j) = dados(i, j - 1)                       si i > j

  -------------------------------------------------- Coste --------------------------------------------------

  El coste de la solucion es O(N * M) siendo N el numero al que queremos llegar y M el numero de caras del dado.
  El coste en espacio es O(N * M) tambien, en el caso de la solucion con matriz, y O(N) en el caso de la solucion
  con vector. Siendo N el numero al que queremos llegar y M el numero de caras del dado.
 
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

  //  int dadosConMatriz = dadosMatriz(carasDado, numeroTotal);
  int dadosConVector = dadosVector(carasDado, numeroTotal);
  
  // Imprimir la solución
  //  cout << dadosConMatriz << "\n";
  cout << dadosConVector << "\n";
  
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
