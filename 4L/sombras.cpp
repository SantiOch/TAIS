
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
 Para resolver el problema, hemos creado un grafo con los datos de entrada, y resuelve sombras() calcula las distancias que tiene
 cada vertice a inicioAlex, inicioLucas, destino, llamando a bfs en cada caso. Para calcular la distancia minima, recorremos de forma
 lineal todos los vertices quedandonos con el menor sumatorio de distancias calculado.

 El coste en tiempo de resuelveSombras es de O(V + A), siendo V el numero de vertices y A el numero de aristas. 
 Porque el coste de las busquedas en anchura es de O(V + A), y hacemos 3 busquedas en anchura, que en total es 
 de 3 * O(V + A) = O(V + A). Luego hacemos un bucle que recorre todos los vertices, que tiene un coste de O(V) ya que recorre cada vertice
 una sola vez haciendo operaciones de costa constante.


 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


void bfs(int inicio, const Grafo& g, vector<int>& distancias) {
  vector<bool> visitados(g.V(), false);
  queue<int> cola;
  visitados[inicio] = true;
  cola.push(inicio);

  while (!cola.empty()) {
    int nodoActual = cola.front();
    cola.pop();

    for (int vecino : g.ady(nodoActual)) {
      if (!visitados[vecino]) {
        distancias[vecino] = distancias[nodoActual] + 1;
        visitados[vecino] = true;
        cola.push(vecino);
      }
    }
  }
}

int resuelveSombras(const int &inicioAlex, const int &inicioLucas, const int &destino, const Grafo& g) {
 
  vector<int> distanciasAlex(g.V(), 0);
  vector<int> distanciasLucas(g.V(), 0);
  vector<int> distanciasDestino(g.V(), 0);

  bfs(inicioAlex, g, distanciasAlex);
  bfs(inicioLucas, g, distanciasLucas);
  bfs(destino, g, distanciasDestino);

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
