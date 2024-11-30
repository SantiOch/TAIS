
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <utility>
#include <climits>
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

//@ <answer>

const int INF = INT_MAX - 100000;

int divi(int N, int P, const vector<int>& v, const vector<int>& c) {
  
  vector<int> sol(P + 1, INF);
  sol[0] = 0;
  
  for (int i = 0; i < N; i++) {
    for (int j = P; j >= 0; j--) {
      for (int k = 0; k <= c[i] && k * v[i] <= j; k++) {
        sol[j] = min(sol[j], sol[j - k * v[i]] + k);
      }
    }
  }
  
  return sol[P];
}

bool resuelveCaso() {
  
  int n;
  cin >> n;
  
  if(!cin) return false;
  
  vector<int> v1(n);
  vector<int> v2(n);
  
  for (int i = 0; i < n; i++) {
    cin >> v1[i];
  }
  
  for (int i = 0; i < n; i++) {
    cin >> v2[i];
  }
  
  int p;
  cin >> p;
  
  int divis = divi(n, p, v1, v2);
  
  if (divis == INF) cout << "NO\n";
  else cout << "SI " << divis << "\n";
  
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
