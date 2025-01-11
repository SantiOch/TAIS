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

int tableroMatriz(int filas, int columnas, const Matriz<int>& tablero) {

  Matriz<int> sol(filas, columnas, 0);
  sol[0][0] = 1; // Una forma de comenzar desde (0, 0)
  
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      
      int salto = tablero[i][j]; // Cuanto voy a saltar
      int formas = sol[i][j]; // Cuantas formas posibles tengo de llegar a esta casilla
      
      if (formas > 0) { // Si hay formas de llegar a [i][j]
        if (sol.posCorrecta(i + salto, j)) // Salto hacia abajo
          sol[i + salto][j] += formas;
        if (sol.posCorrecta(i, j + salto)) // Salto hacia la derecha
          sol[i][j + salto] += formas;
      }
    }
  }
  
  return sol[filas - 1][columnas - 1];
}

int tableroVector(int filas, int columnas, const Matriz<int>& tablero) {
  return 0;
}


bool resuelveCaso() {
  
  int filas, columnas;
  cin >> filas >> columnas;
  
  if (!cin) return false;
  
  Matriz<int> m(filas, columnas);
  
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      cin >> m[i][j];
    }
  }
  
  int beneficio1 = tableroMatriz(filas, columnas, m);
//  int beneficio2 = tableroVector(filas, columnas, m);

  // Imprimir la solución
  cout << beneficio1 << "\n";
//    cout << beneficio2 << "\n";
  
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
  
  resuelveWhile();
  
  
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}


//@ </answer>
// Lo que se escriba dejado de esta lÌnea ya no forma parte de la soluciÛn.
