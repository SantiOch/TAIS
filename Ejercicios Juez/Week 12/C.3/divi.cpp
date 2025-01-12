
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
 
  El problema se resuelve con programacion dinamica de forma recursiva, N es el numero total de monedas y P es el precio que queremos obtener.
  Siendo i el indice de la moneda actual y j el precio que queremos obtener.
  
  La llamada inicial es divi(N, P).

  *Definicion
  Divi(i, j) es el minimo de monedas que se necesitan para obtener j euros con i diferentes tipos de monedas, 
  siendo i el indice de la moneda actual y j el dinero que se quiere obtener.
  
  *Caso base
  Divi(i, 0) = 0
  Divi(0, 𝑗) = infinito 

  *Caso recursivo
  Divi(i, j) = min { k + divi(i - 1, j - k * v[i]) | 0 <= k <= min { c[i], j div v[i] } } 
 
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
