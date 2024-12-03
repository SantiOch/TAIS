
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

#include "Matriz.h"

/*@ <answer>
 
  El problema se resuelve con programacion dinamica de forma recursiva, N es el numero de caracteres de la palabra 1 y M es el numero de
  caracteres de la palabra 2.
  Siendo i el indice de la palabra 1 y j el indice de la palabra 2.
  
  La llamada inicial es adn(N, M).

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

int calcularIndice(char c) {
  switch (c) {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    default:  return 4;
  }
}

int adn(int n, int m, string s1, string s2, const Matriz<int>& punt) {
  Matriz<int> sol(n + 1, m + 1, 0);
  
  for (int i = 1; i <= n; i++) {
    sol[i][0] = punt[calcularIndice(s1[i - 1])][4] + sol[i - 1][0];
  }
  
  for (int j = 1; j <= m; j++) {
    sol[0][j] = punt[4][calcularIndice(s2[j - 1])] + sol[0][j - 1];
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int indiceI = calcularIndice(s1[i - 1]);
      int indiceJ = calcularIndice(s2[j - 1]);
      
      sol[i][j] = max(
                      punt[indiceI][4] + sol[i - 1][j],
                      max(
                          punt[4][indiceJ] + sol[i][j - 1],
                          punt[indiceI][indiceJ] + sol[i - 1][j - 1]
                          )
                      );
    }
  }
  
  return sol[n][m];
}

void resuelveCaso() {
  
  Matriz<int> punt(5,5,0);
  
  for(int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> punt[i][j];
    }
  }
  
  int num;
  cin >> num;
  string s1;
  string s2;
  
  for (int i = 0; i < num; i++) {
    cin >> s1 >> s2;
    cout << adn(s1.size(), s2.size(), s1, s2, punt) << "\n";
  }
}
//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
int main() {
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  unsigned int numCasos;
  cin >> numCasos;
  for (int i = 0; i < numCasos; ++i) {
    resuelveCaso();
  }
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif
  return 0;
}
