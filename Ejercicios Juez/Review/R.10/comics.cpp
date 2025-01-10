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
#include "PriorityQueue.h"
#include <stack>

using namespace std;

/*@ <answer>
 
 @ </answer> */

// ================================================================
// Código de la solución
// ================================================================
//@ <answer>

struct Comparator {
   bool operator()(const stack<int>& s1, const stack<int>& s2) const {
    return s1.top() < s2.top();
  }
};

int comics(int minimo, PriorityQueue<stack<int>, Comparator>& pq) {
  
  int posicion = 1;
  
  while (!pq.empty()) {
    
    stack<int> pila = pq.top(); pq.pop();
  
    if (pila.top() == minimo) {
      break;
    }
    
    pila.pop();
    
    if (!pila.empty()){
      pq.push(pila);
    }
    
    posicion++;
  }
  
  
  return posicion;
}

bool resuelveCaso() {

  PriorityQueue<stack<int>, Comparator> pq;
  
  int numPilas;
  cin >> numPilas;
  
  if (!cin) return false;
  int minimo = numeric_limits<int>::max();
  
  for (int i = 0; i < numPilas; i++) {
    stack<int> p;
    int n;
    cin >> n;
    for(int j = 0; j < n; j++) {
      int num;
      cin >> num;
      minimo = min(minimo, num);
      p.push(num);
    }
    pq.push(p);
  }

  cout << comics(minimo, pq) << "\n";
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
// Lo que se escriba dejado de esta lÌnea ya no forma parte de la solución
