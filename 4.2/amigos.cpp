
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>

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

int recorreGrafo(const Grafo& g, int verticeAct, vector<bool>& verticesVisitados) {
  verticesVisitados[verticeAct] = true;
  int amigos = 1;
  for (int i: g.ady(verticeAct)) {
    if (!verticesVisitados[i]) {
      int amigosAdyacentes = recorreGrafo(g, i, verticesVisitados);
      amigos += amigosAdyacentes;
    }
  }
  return amigos;
}

int resolver(const Grafo &g) {
  vector<bool> verticesVisitados(g.V(), false);
  int mayorGrupo = 0;
  for (int i = 0; i < g.V(); ++i) if (!verticesVisitados[i]) mayorGrupo = max(mayorGrupo, recorreGrafo(g, i, verticesVisitados));
  return mayorGrupo;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  
  // leer los datos de la entrada
  int vertices, aristas;
  
  cin >> vertices >> aristas;
  
  Grafo g(vertices);
  
  int p1, p2;
  
  for (int i = 0; i < aristas; i++) {
    cin >> p1 >> p2;
    g.ponArista(--p1, --p2); // Me lanza excepción si no lo hago asi
  }

  cout << resolver(g) << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.


int main() {

#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   

#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
