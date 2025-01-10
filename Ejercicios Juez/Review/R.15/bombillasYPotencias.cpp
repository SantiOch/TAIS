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
#include <limits>
#include "Matriz.h"

using namespace std;

/*@ <answer>
 
 @ </answer> */

// ================================================================
// Código de la solución
// ================================================================
//@ <answer>

const int INF = numeric_limits<int>::max() -100000;

// First  -> Coste
// Second -> Potencia
pair<int,int> bombillasMatriz(int pMax, int pMin, const vector<int>& potencias, const vector<int>& costes) {
  
  int N = costes.size();
  Matriz<int> sol(N + 1, pMax + 1, INF);
  sol[0][0] = 0;
  
  for (int i = 1; i <= N; i++) {
    sol[i][0] = 0;
    for (int j = 1; j <= pMax; j++) {
      if (potencias[i-1] > j) {
        sol[i][j] = sol[i-1][j];
      } else{
        sol[i][j] = min(sol[i-1][j], sol[i][j - potencias[i-1]] + costes[i - 1]);
      }
    }
  }
  
  int coste = INF, potencia = INF;
  
  for(int i = pMin; i <= pMax; i++) {
    if (sol[N][i] != INF) {
      if (sol[N][i] < coste) {
        coste = sol[N][i];
        potencia = i;
      }
    }
  }

  return { coste, potencia };
}

bool resuelveCaso() {
 
  int N, PMax, PMin;
  cin >> N >> PMax >> PMin;
  
  if (!cin) return false;
  
  vector<int> potencias(N);
  vector<int> costes(N);
  
  // Leer las potencias y los costes
  for (int i = 0; i < N; ++i) cin >> potencias[i];
  for (int i = 0; i < N; ++i) cin >> costes[i];
  
  // First  -> Coste
  // Second -> Potencia
  auto [coste, potencia] = bombillasMatriz(PMax, PMin, potencias, costes);

  // Resultado
  if (coste == INF) {
    cout << "IMPOSIBLE\n";
  } else {
    cout << coste << " " << potencia << "\n";
  }
  
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
