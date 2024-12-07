
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
using namespace std;

#include "Matriz.h"

/*@ <answer>
 El problema se resuelve con programación dinámica. Se trata de un problema similar al de la mochila, en el que se tiene que tiene que
 maximizar la duracion de los eventos en una sala con un tiempo de duracion total / 2, ya que cuanto mas cerca esten los eventos de la
 mitad del tiempo total, menor sera la diferencia entre la duracion de los eventos en cada aula.
 Siendo i el numero de eventos y j el tiempo total.

 *Definicion
 Even(i,j) = Maximo tiempo de duracion de los eventos en una sala con un tiempo total de j e i eventos.
 
 *Caso base
 Even(0,j) = 0
 Even(i,0) = 0

 *Caso recursivo
 Even(i,j) = Max(Even(i-1,j), Even(i-1,j - v[i]) + v[i]) si j >= v[i] -> Se puede coger el evento i
 Even(i,j) = Even(i-1,j) si j < v[i] -> No se puede coger el evento i
 
 La llamada inicial es Even(n, total / 2) siendo n el numero de eventos y total el tiempo total de duracion de los eventos.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================

int eventos(int n, int total, vector<int> &v) {
  
  int m = total / 2;
  
  vector<int> sol(m + 1, 0);
  
  for (int i = 0; i < n; i++) {
    for (int j = m; j > 0; j--) {
      if (j >= v[i]) sol[j] = max(sol[j], sol[j - v[i]] + v[i]);
    }
  }
  
  return total - sol[m];
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
