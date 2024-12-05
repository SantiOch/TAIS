
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
using namespace std;

#include "Matriz.h"

/*@ <answer>
 
 El problema se resuelve con programacion dinamica de forma recursiva, N es el numero de caracteres de la palabra 1 y M es el numero de
 caracteres de la palabra 2.
 Siendo i el indice de la palabra 1 y j el indice de la palabra 2.
 *Definicion
 Adn(i,j) = cantidad maxima que se consigue al insertar o no insertar caracteres para comparar cada letra de la palabra 1 con la palabra 2
 y obtener una puntuacion respecto a la matriz de puntuaciones.
 
 *Caso base
 Adn(i,j)=0 si i = 0 y j = 0
 *Caso recursivo
 Adn(i,j) = max(Adn(i - 1, j) + punt[i][4], Adn(i,j - 1) + punt[i][4], Adn(i - 1, j - 1) + punt[i][j])
 
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================

int eventos(int n, int total, vector<int> &v) {
  
  vector<int> sol(total / 2 + 1, 0);
  
  for (int i = 0; i < n; i++) {
    for (int j = total / 2; j > 0; j--) {
      if (j >= v[i]) sol[j] = max(sol[j], sol[j - v[i]] + v[i]);
    }
  }

  return total - sol[total / 2];
}

//@ <answer>

bool resuelveCaso() {
  
  int n;
  cin >> n;
  
  if (!cin) return false;
  
  vector<int> v;
  
  int num, total = 0;
  for(int i = 0; i < n; i++) {
    cin >> num;
    v.push_back(num);
    total += num;
  }
  
  int sol = eventos(n, total, v);
 
  cout << sol << "\n";
  
  return true;
}


//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
int main() {
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  while(resuelveCaso());
  
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif
  return 0;
}
