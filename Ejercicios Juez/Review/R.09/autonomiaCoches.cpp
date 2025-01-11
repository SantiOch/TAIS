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
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

/*@ <answer>
 
 @ </answer> */

// ================================================================
// Código de la solución
// ================================================================
//@ <answer>

class Carreteras {
private:
  int tam;
  int carreteraMasLarga;
  bool llega;
public:
  
  int longCarretera() const {
    return carreteraMasLarga;
  }
  
  bool llegaFinal() {
    return llega;
  }
  
  Carreteras(GrafoValorado<int> const& g) : tam(0), carreteraMasLarga(0), llega(g.V() == 1) {
    PriorityQueue<Arista<int>> pq(g.aristas());
    ConjuntosDisjuntos cjtos(g.V());
    while (!pq.empty()) {
      auto a = pq.top(); pq.pop();
      int v = a.uno(), w = a.otro(v);
      if (!cjtos.unidos(v,w)) {
        cjtos.unir(v, w);
        tam++;
//        cuerda = max(cuerda, a.valor());
        if (tam == g.V() - 1) {
          llega = true;
          carreteraMasLarga = a.valor();
          break;
        }
      }
    }
  }
};

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int n,p;
  cin>> n >> p;
  
  if (!std::cin)  // fin de la entrada
    return false;
  
  GrafoValorado<int>g(n);
  
  // resolver el caso posiblemente llamando a otras funciones
  int v, w, coste;
  
  for (int i = 0; i < p; i++) {
    cin >> v >> w >> coste;
    g.ponArista({v - 1, w - 1, coste});
  }
  
  Carreteras carreteras(g);
  
  // escribir la solución
  if (carreteras.llegaFinal()) {
    cout << carreteras.longCarretera() << "\n";
  } else cout << "Imposible\n";
  
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
