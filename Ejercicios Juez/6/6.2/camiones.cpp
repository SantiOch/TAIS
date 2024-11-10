
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

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
 
 //Coste
 
 @ </answer> */
// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


void dfs(const GrafoValorado<int>& grafo, int interseccion, vector<bool>& visitados, int anchuraMinima) {
 
  visitados[interseccion] = true;
  
  for (auto arista : grafo.ady(interseccion)) {
    if (arista.valor() >= anchuraMinima) {
    
      int otraInterseccion = arista.otro(interseccion);
      
      if (!visitados[otraInterseccion]) {
        dfs(grafo, otraInterseccion, visitados, anchuraMinima);
      }
    }
  }
}

bool puedeCircularCamion(const GrafoValorado<int>& grafo) {

  int origen, destino, anchuraCamion;
  cin >> origen >> destino >> anchuraCamion;
  vector<bool> visitados(grafo.V(), false);

  dfs(grafo, origen - 1, visitados, anchuraCamion);
  
  return visitados[destino - 1];
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int numIntersecciones, numCalles;
  cin >> numIntersecciones >> numCalles;
  
  if (!std::cin)  // fin de la entrada
    return false;
  
  GrafoValorado<int> grafo(numIntersecciones);
  int interseccion1, interseccion2, anchuraMaxima;
  
  for (int i = 0; i < numCalles; i++) {
    cin >> interseccion1 >> interseccion2 >> anchuraMaxima;
    grafo.ponArista({ interseccion1 - 1 , interseccion2 - 1, anchuraMaxima });
  }
  
  int numConsultas;
  cin >> numConsultas;
  
  for (int i = 0; i < numConsultas; i++) {
    cout << (puedeCircularCamion(grafo) ? "SI\n" : "NO\n");
  }

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
