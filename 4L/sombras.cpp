
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

#include "Grafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>
 

 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int resuelveSombras(const int &inicioAlex, const int &inicioLucas, const int &destino, const Grafo& g) {
  
  int nodosAlcanzables = 1;
  
  queue<int> cola;
  vector<bool> visitadosAlex(g.V());
  vector<bool> visitadosLucas(g.V());
  vector<bool> visitadosDestino(g.V());
  vector<int> distanciasAlex(g.V(), 0);
  vector<int> distanciasLucas(g.V(), 0);
  vector<int> distanciasDestino(g.V(), 0);
  
  visitadosAlex[inicioAlex] = true;
  cola.push(inicioAlex);

  while (!cola.empty()) {
    int nodoActual = cola.front();
    cola.pop();
    
    for (int vecino: g.ady(nodoActual)) {
      if (!visitadosAlex[vecino]) {
        distanciasAlex[vecino] = distanciasAlex[nodoActual] + 1;
        visitadosAlex[vecino] = true;
        cola.push(vecino);
      }
    }
  }

  visitadosLucas[inicioLucas] = true;
  cola.push(inicioLucas);
   
    while (!cola.empty()) {
    int nodoActual = cola.front();
    cola.pop();
    
    for (int vecino: g.ady(nodoActual)) {
      if (!visitadosLucas[vecino]) {
        distanciasLucas[vecino] = distanciasLucas[nodoActual] + 1;
        visitadosLucas[vecino] = true;
        cola.push(vecino);
      }
    }
  }

  visitadosDestino[destino] = true;
  cola.push(destino);

    while (!cola.empty()) {
    int nodoActual = cola.front();
    cola.pop();
    
    for (int vecino: g.ady(nodoActual)) {
      if (!visitadosDestino[vecino]) {
        distanciasDestino[vecino] = distanciasDestino[nodoActual] + 1;
        visitadosDestino[vecino] = true;
        cola.push(vecino);
      }
    }
  }

  int minVal = INT_MAX;
    for (int i = 0; i < g.V(); i++) {
        int suma = distanciasAlex[i] + distanciasLucas[i] + distanciasDestino[i];
        minVal = min(minVal, suma);
    }
  
  return minVal;
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int nodos;
  int conexiones;
  int iniAlex,iniLucas,destino;
  cin >> nodos;
  
  if (!cin)  // fin de la entrada
    return false;
  
  Grafo g(nodos);
  
  cin >> conexiones >> iniAlex >> iniLucas >> destino;
  
  for (int i = 0; i < conexiones; ++i) {
    int n1, n2;
    cin >> n1 >> n2;
    g.ponArista(--n1, --n2);
  }

  int total = resuelveSombras(iniAlex - 1, iniLucas - 1, destino - 1, g);

  // Esribir solucion
  cout << total << "\n";
  
  
  return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  while (resuelveCaso());
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
