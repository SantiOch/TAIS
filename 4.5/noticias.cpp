
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
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int recorreGrafo(const Grafo& g, vector<bool>& verticesVisitados,vector<int> &adyacentes, int verticeAct) {

  int amigos = 1;

  for (int i: g.ady(verticeAct)) {
    if (!verticesVisitados[i]) {
      verticesVisitados[i] = true;
      amigos += recorreGrafo(g, verticesVisitados, adyacentes, i);
      adyacentes.push_back(i);
    }
  }

  return amigos;
}

void resolver(const Grafo &g, vector<bool>&  verticesVisitados, vector<int>& solucion) {
   vector<int> adyacentes;
  for(int i = 0; i < g.V(); i++) {
    if (!verticesVisitados[i]) {
      verticesVisitados[i] = true;
      solucion[i] = recorreGrafo(g, verticesVisitados, adyacentes, i);
      auto it = adyacentes.begin();
      while(it != adyacentes.end()) {
        solucion[*it] = solucion[i];
        it = adyacentes.erase(it);
      }
    }
  }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  
  // leer los datos de la entrada
  int vertices, grupos;
  
  cin >> vertices;
  
  if (!cin) return false;
  
  cin >> grupos;
  
  Grafo g(vertices);
  
  int p1, p2;
  
  for (int i = 0; i < grupos; i++) {
    int nPersonas;
    cin >> nPersonas;

    int p1 = 0;

    if (nPersonas != 0) {
      cin >> p1;
    }

    for (int j = 1; j < nPersonas; j++) {
      cin >> p2;
      g.ponArista(p1 - 1, p2 - 1);
      p1 = p2;
    }
  }

  vector<bool> verticesVisitados(vertices, false);
  vector<int> solucion(vertices, 0);

  resolver(g, verticesVisitados, solucion);

  for (int i = 0; i < vertices; i++) {
    cout << solucion[i] << " ";
  }

  cout << "\n";
  
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
