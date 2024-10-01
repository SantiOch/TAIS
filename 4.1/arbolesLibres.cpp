
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Grafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 Para comprobar si un grafo es un árbol libre, primero, se ha consruido el grafo con grafo.h.
 Después, se ha creado una función resolver() que recibe el grafo y llama a recorrerGrafo(), para que recursivamente lo recorra
 y vaya marcando los vértices visitados. Si el número de vértices visitados es igual al número de vértices del grafo y 
 el número de aristas es igual al número de vértices - 1, entonces es un árbol libre.

 El coste del algoritmo es O(V), donde V es el número de vértices que recorre la función recorrerGrafo().
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void recorreGrafo(const Grafo& g, int verticeAct, vector<bool>& verticesVisitados, int& nVisitados) {
  verticesVisitados[verticeAct] = true;
  for (int i : g.ady(verticeAct)) {
    if (!verticesVisitados[i]) {
      recorreGrafo(g, i, verticesVisitados, nVisitados);
      nVisitados++;
    }
  }
}

bool resolver(const Grafo &g) {
  vector<bool> verticesVisitados(g.V(), false);
  int nVisitados = 1;
  recorreGrafo(g, 0, verticesVisitados, nVisitados);
  return nVisitados == g.V() && (g.A() == g.V() - 1); // he visitado todos los vertices y el numero de aristas es el numero de vertices - 1
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  
  // leer los datos de la entrada
  int vertices, aristas;
  
  cin >> vertices;
  
  if (!cin) return false;
  
  cin >> aristas;
  
  Grafo g(vertices);
  
  int p1, p2;
  
  for (int i = 0; i < aristas; i++) {
    cin >> p1 >> p2;
    g.ponArista(p1, p2);
  }

  cout << (resolver(g) ? "SI" : "NO") << "\n";
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
