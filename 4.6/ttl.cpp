
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "Grafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int resuelveTTL(int inicio, const int &ttl, const Grafo& g) {
  
  int nodosAlcanzables = 1;
  
  queue<int> cola;
  vector<bool> visitados(g.V());
  vector<int> distancias(g.V());
  
  distancias[inicio] = 0;
  visitados[inicio] = true;
  cola.push(inicio);
  
  while (!cola.empty()) {
    int nodoActual = cola.front();
    cola.pop();
    
    for (int vecino: g.ady(nodoActual)) {
      if (!visitados[vecino] && distancias[nodoActual] + 1 <= ttl) {
        nodosAlcanzables++;
        distancias[vecino] = distancias[nodoActual] + 1;
        visitados[vecino] = true;
        cola.push(vecino);
      }
    }
  }
  
  return g.V() - nodosAlcanzables;
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int nodos;
  int conexiones;
  
  cin >> nodos;
  
  if (!cin)  // fin de la entrada
    return false;
  
  Grafo g(nodos);
  
  cin >> conexiones;
  
  for (int i = 0; i < conexiones; ++i) {
    int n1, n2;
    cin >> n1 >> n2;
    g.ponArista(--n1, --n2);
  }
  
  int k, inicio, ttl;
  
  cin >> k;
  
  for (int i = 0; i < k; ++i) {
    cin >> inicio >> ttl;
    int total = resuelveTTL(inicio - 1, ttl, g);
    
    // Esribir solucion
    cout << total << "\n";
  }
  
  cout << "---\n";
  
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
